project(qemu)

## QEMU

# Version
set(QEMU_VERSION "8.1.3")

# Flatpak Support
set(QEMU_PATCH "")
if(MCPI_IS_FLATPAK_BUILD)
    set(QEMU_PATCH "sed" "-i" "s/libdrm/libdrm-dis/g" "<SOURCE_DIR>/meson.build")
endif()

# Build
include(ProcessorCount)
ProcessorCount(NPROC)
include(ExternalProject)
ExternalProject_Add(qemu
    URL "file://${CMAKE_CURRENT_SOURCE_DIR}/../../archives/qemu-${QEMU_VERSION}.tar.xz"
    CONFIGURE_COMMAND
        "${CMAKE_COMMAND}" "-E" "env"
        "PKG_CONFIG_LIBDIR=$ENV{PKG_CONFIG_LIBDIR}"
        "CFLAGS=-s"
        "CXXFLAGS=-s"
        "<SOURCE_DIR>/configure"
        "--prefix=${CMAKE_INSTALL_PREFIX}"
        "--cross-prefix="
        "--cc=${CMAKE_C_COMPILER}"
        "--cxx=${CMAKE_CXX_COMPILER}"
        "--disable-debug-info"
        "--target-list=arm-linux-user"
        "--without-default-features"
    USES_TERMINAL_CONFIGURE TRUE
    BUILD_COMMAND "make" "-j${NPROC}" "qemu-arm"
    USES_TERMINAL_BUILD TRUE
    INSTALL_COMMAND ""
    TEST_COMMAND ""
    PATCH_COMMAND ${QEMU_PATCH}
    BUILD_BYPRODUCTS "<BINARY_DIR>/qemu-arm"
)

# Install
ExternalProject_Get_property(qemu BINARY_DIR)
install(PROGRAMS "${BINARY_DIR}/qemu-arm" DESTINATION "${MCPI_BIN_DIR}")

# License
ExternalProject_Get_property(qemu SOURCE_DIR)
install(FILES "${SOURCE_DIR}/COPYING" DESTINATION "${MCPI_LEGAL_DIR}/qemu")
