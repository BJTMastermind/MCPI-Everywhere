#include <libreborn/libreborn.h>

#include <mods/init/init.h>

#include <media-layer/core.h>

__attribute__((constructor)) static void init() {
    media_ensure_loaded();
    run_tests();
    init_compat();

#ifndef MCPI_HEADLESS_MODE
    init_input();
#endif
    init_textures();
    init_home();
}
