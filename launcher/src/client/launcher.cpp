#include <sstream>
#include <cstring>
#include <cerrno>
#include <sys/wait.h>
#include <sys/stat.h>
#include <vector>
#include <functional>
#include <algorithm>

#include <libreborn/libreborn.h>

#include "../util.h"
#include "../bootstrap.h"
#include "launcher.h"

// Launch
#define LIST_DIALOG_SIZE "400"
int main(int argc, char *argv[]) {
    // Don't Run As Root
    if (getenv("_MCPI_SKIP_ROOT_CHECK") == NULL && (getuid() == 0 || geteuid() == 0)) {
        ERR("Don't Run As Root");
    }

    // Ensure HOME
    if (getenv("HOME") == NULL) {
        ERR("$HOME Isn't Set");
    }

    // Check For Display
#ifndef MCPI_HEADLESS_MODE
    if (getenv("DISPLAY") == NULL && getenv("WAYLAND_DISPLAY") == NULL) {
        ERR("No display attached! Make sure $DISPLAY or $WAYLAND_DISPLAY is set.");
    }
#endif

    // Pre-Bootstrap
    pre_bootstrap(argc, argv);

    // Create ~/.minecraft-pi If Needed
    {
        char *minecraft_folder = NULL;
        safe_asprintf(&minecraft_folder, "%s" HOME_SUBDIRECTORY_FOR_GAME_DATA, getenv("HOME"));
        const char *const command[] = {"mkdir", "-p", minecraft_folder, NULL};
        run_simple_command(command, "Unable To Create Data Directory");
        free(minecraft_folder);
    }

    // Bootstrap
    bootstrap(argc, argv);
}
