# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


set(CPACK_BINARY_7Z "OFF")
set(CPACK_BINARY_IFW "OFF")
set(CPACK_BINARY_INNOSETUP "OFF")
set(CPACK_BINARY_NSIS "ON")
set(CPACK_BINARY_NUGET "OFF")
set(CPACK_BINARY_WIX "OFF")
set(CPACK_BINARY_ZIP "OFF")
set(CPACK_BUILD_SOURCE_DIRS "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src;C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build")
set(CPACK_CMAKE_GENERATOR "Ninja")
set(CPACK_COMPONENTS_ALL "Unspecified;libmgba;mgba;mgba-dev;mgba-qt;mgba-sdl")
set(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6,zlib1g,libpng16-16,libzip4|libzip5,libepoxy0,libsqlite3-0,libfreetype6,liblua5.5-0,libsdl2-2.0-0,libqt5widgets5,libqt5multimedia5")
set(CPACK_DEBIAN_PACKAGE_SECTION "games")
set(CPACK_DEB_COMPONENT_INSTALL "ON")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_FILE "C:/PassionProjects/GBAEmu/PokemonQuetzal/vcpkg/downloads/tools/cmake-3.31.10-windows/cmake-3.31.10-windows-x86_64/share/cmake-3.31/Templates/CPack.GenericDescription.txt")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_SUMMARY "mGBA built using CMake")
set(CPACK_DMG_SLA_USE_RESOURCE_FILE_LICENSE "ON")
set(CPACK_GENERATOR "NSIS")
set(CPACK_INNOSETUP_ARCHITECTURE "x64")
set(CPACK_INSTALL_CMAKE_PROJECTS "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build;mGBA;ALL;/")
set(CPACK_INSTALL_PREFIX "C:/Program Files (x86)/mGBA")
set(CPACK_MODULE_PATH "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/src/platform/cmake/")
set(CPACK_NSIS_DISPLAY_NAME "mGBA 0.11-1-b827eaf-dirty")
set(CPACK_NSIS_INSTALLER_ICON_CODE "")
set(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES64")
set(CPACK_NSIS_PACKAGE_NAME "mGBA 0.11-1-b827eaf-dirty")
set(CPACK_NSIS_UNINSTALL_NAME "Uninstall")
set(CPACK_OUTPUT_CONFIG_FILE "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/CPackConfig.cmake")
set(CPACK_PACKAGE_CONTACT "Vicki Pfau <vi@endrift.com>")
set(CPACK_PACKAGE_DEFAULT_LOCATION "/")
set(CPACK_PACKAGE_DESCRIPTION_FILE "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/README.md")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "mGBA Game Boy Advance Emulator")
set(CPACK_PACKAGE_FILE_NAME "mGBA-0.11-1-b827eaf-dirty-win64")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "mGBA 0.11-1-b827eaf-dirty")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "mGBA 0.11-1-b827eaf-dirty")
set(CPACK_PACKAGE_NAME "mGBA")
set(CPACK_PACKAGE_RELOCATABLE "true")
set(CPACK_PACKAGE_VENDOR "Vicki Pfau")
set(CPACK_PACKAGE_VERSION "0.11-1-b827eaf-dirty")
set(CPACK_PACKAGE_VERSION_MAJOR "0")
set(CPACK_PACKAGE_VERSION_MINOR "11")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_RESOURCE_FILE_LICENSE "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/LICENSE")
set(CPACK_RESOURCE_FILE_README "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/README.md")
set(CPACK_RESOURCE_FILE_WELCOME "C:/PassionProjects/GBAEmu/PokemonQuetzal/vcpkg/downloads/tools/cmake-3.31.10-windows/cmake-3.31.10-windows-x86_64/share/cmake-3.31/Templates/CPack.GenericWelcome.txt")
set(CPACK_SET_DESTDIR "OFF")
set(CPACK_SOURCE_7Z "ON")
set(CPACK_SOURCE_GENERATOR "7Z;ZIP")
set(CPACK_SOURCE_OUTPUT_CONFIG_FILE "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/CPackSourceConfig.cmake")
set(CPACK_SOURCE_ZIP "ON")
set(CPACK_SYSTEM_NAME "win64")
set(CPACK_THREADS "1")
set(CPACK_TOPLEVEL_TAG "win64")
set(CPACK_WIX_SIZEOF_VOID_P "8")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()

# Configuration for component group "base"

# Configuration for component "mgba"

SET(CPACK_COMPONENTS_ALL Unspecified libmgba mgba mgba-dev mgba-qt mgba-sdl)
set(CPACK_COMPONENT_MGBA_GROUP base)

# Configuration for component group "dev"
set(CPACK_COMPONENT_GROUP_DEV_PARENT_GROUP "base")

# Configuration for component "libmgba"

SET(CPACK_COMPONENTS_ALL Unspecified libmgba mgba mgba-dev mgba-qt mgba-sdl)
set(CPACK_COMPONENT_LIBMGBA_GROUP base)

# Configuration for component "mgba-dev"

SET(CPACK_COMPONENTS_ALL Unspecified libmgba mgba mgba-dev mgba-qt mgba-sdl)
set(CPACK_COMPONENT_MGBA-DEV_GROUP dev)

# Configuration for component group "qt"
set(CPACK_COMPONENT_GROUP_QT_PARENT_GROUP "base")

# Configuration for component "mgba-qt"

SET(CPACK_COMPONENTS_ALL Unspecified libmgba mgba mgba-dev mgba-qt mgba-sdl)
set(CPACK_COMPONENT_MGBA-QT_GROUP qt)

# Configuration for component group "sdl"
set(CPACK_COMPONENT_GROUP_SDL_PARENT_GROUP "base")

# Configuration for component "mgba-sdl"

SET(CPACK_COMPONENTS_ALL Unspecified libmgba mgba mgba-dev mgba-qt mgba-sdl)
set(CPACK_COMPONENT_MGBA-SDL_GROUP sdl)

# Configuration for component group "test"
set(CPACK_COMPONENT_GROUP_TEST_PARENT_GROUP "dev")

# Configuration for component "mgba-perf"

SET(CPACK_COMPONENTS_ALL Unspecified libmgba mgba mgba-dev mgba-qt mgba-sdl)
set(CPACK_COMPONENT_MGBA-PERF_GROUP test)

# Configuration for component "mgba-test"

SET(CPACK_COMPONENTS_ALL Unspecified libmgba mgba mgba-dev mgba-qt mgba-sdl)
set(CPACK_COMPONENT_MGBA-TEST_GROUP test)
