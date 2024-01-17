project(mods)

## Headers
add_library(mods-headers INTERFACE)
target_include_directories(
    mods-headers
    INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:${MCPI_SDK_INCLUDE_DIR}/mods>"
)
# SDK
install(TARGETS mods-headers EXPORT sdk DESTINATION "${MCPI_SDK_LIB_DIR}")
install(DIRECTORY "include/" DESTINATION "${MCPI_SDK_INCLUDE_DIR}/mods")

## Mods

add_library(compat SHARED src/compat/compat.c src/compat/egl.c src/compat/x11.c src/compat/bcm_host.c)
target_link_libraries(compat mods-headers reborn-patch media-layer-core)
if(NOT MCPI_HEADLESS_MODE)
    target_link_libraries(compat input home dl)
endif()

add_library(readdir SHARED src/readdir/readdir.c)

if(NOT MCPI_HEADLESS_MODE)
    add_library(input SHARED src/input/input.cpp src/input/misc.c)
    target_link_libraries(input mods-headers reborn-patch symbols media-layer-core)
endif()

if(NOT MCPI_HEADLESS_MODE)
    add_library(textures SHARED src/textures/textures.cpp)
else()
    add_library(textures SHARED src/textures/headless.cpp)
endif()
target_link_libraries(textures mods-headers reborn-patch symbols)
if(NOT MCPI_HEADLESS_MODE)
    target_link_libraries(textures media-layer-core stb_image)
endif()

add_library(override SHARED src/override/override.c)
target_link_libraries(override mods-headers reborn-patch symbols dl home)

add_library(home SHARED src/home/home.c)
target_link_libraries(home mods-headers reborn-patch symbols)

add_library(test SHARED src/test/test.c)
target_link_libraries(test mods-headers reborn-patch home)

add_library(init SHARED src/init/init.c)
target_link_libraries(init mods-headers reborn-util compat textures home test media-layer-core)
target_link_libraries(init)

if(NOT MCPI_HEADLESS_MODE)
    target_link_libraries(init input)
endif()

## Install Mods
set(MODS_TO_INSTALL init compat readdir override textures home test)

if(NOT MCPI_HEADLESS_MODE)
    list(APPEND MODS_TO_INSTALL input)
endif()
install(TARGETS ${MODS_TO_INSTALL} DESTINATION "${MCPI_INSTALL_DIR}/mods")
# SDK
install(TARGETS ${MODS_TO_INSTALL} EXPORT sdk DESTINATION "${MCPI_SDK_LIB_DIR}")
