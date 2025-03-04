#include <unistd.h>
#include <signal.h>
#include <errno.h>

#include <mods/compat/compat.h>
#include <mods/init/init.h>

#include <libreborn/libreborn.h>

#include <SDL/SDL.h>

#ifndef MCPI_HEADLESS_MODE
#include <media-layer/core.h>

#include <mods/input/input.h>
#include <mods/home/home.h>
#endif

// Mouse Cursor Is Always Invisible In Vanilla MCPI
// Because In Vanilla MCPI, The GPU Overlay Covered The Normal Mouse Cursor
HOOK(SDL_ShowCursor, int, (int toggle)) {
    ensure_SDL_ShowCursor();
    return (*real_SDL_ShowCursor)(toggle == SDL_QUERY ? SDL_QUERY : SDL_DISABLE);
}

// Intercept SDL Events
HOOK(SDL_PollEvent, int, (SDL_Event *event)) {
    // In Server Mode, Exit Requests Are Handled In src/server/server.cpp
    // Check If Exit Is Requested
#ifndef MCPI_SERVER_MODE
    if (compat_check_exit_requested()) {
        // Send SDL_QUIT
        SDL_Event new_event;
        new_event.type = SDL_QUIT;
        SDL_PushEvent(&new_event);
    }
#endif

    // Poll Events
    ensure_SDL_PollEvent();
    int ret = (*real_SDL_PollEvent)(event);

    // Handle Events
    if (ret == 1 && event != NULL) {
        int handled = 0;

#ifndef MCPI_HEADLESS_MODE
        switch (event->type) {
            case SDL_KEYDOWN: {
                // Handle Key Presses
                if (event->key.keysym.sym == SDLK_F11) {
                    media_toggle_fullscreen();
                    handled = 1;
                } else if (event->key.keysym.sym == SDLK_ESCAPE) {
                    // Treat Escape As Back Button Press (This Fixes Issues With Signs)
                    handled = input_back();
                }
                break;
            }
        }
#endif

        if (handled) {
            // Event Was Handled
            return SDL_PollEvent(event);
        }
    }

    return ret;
}

// Exit Handler
static void exit_handler(__attribute__((unused)) int data) {
    // Request Exit
    compat_request_exit();
}
void init_compat() {
    // Install Signal Handlers
    signal(SIGINT, SIG_IGN);
    struct sigaction act_sigterm;
    memset((void *) &act_sigterm, 0, sizeof (struct sigaction));
    act_sigterm.sa_flags = SA_RESTART;
    act_sigterm.sa_handler = &exit_handler;
    sigaction(SIGTERM, &act_sigterm, NULL);
}

// Store Exit Requests
static int exit_requested = 0;
int compat_check_exit_requested() {
    if (exit_requested) {
        exit_requested = 0;
        return 1;
    } else {
        return 0;
    }
}
void compat_request_exit() {
    // Request
    exit_requested = 1;
}
