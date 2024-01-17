#pragma once

#include <libreborn/libreborn.h>

#ifdef __cplusplus
extern "C" {
#endif

void run_tests();
void init_compat();
#ifndef MCPI_HEADLESS_MODE
void init_input();
#endif
void init_textures();
void init_home();

#ifdef __cplusplus
}
#endif
