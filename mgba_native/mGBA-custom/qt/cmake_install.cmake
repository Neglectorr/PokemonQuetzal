# Install script for directory: C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/src/platform/qt

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/mGBA")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba-qt" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./shaders" TYPE FILE FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/qt/shaders/agb001.shader")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba-qt" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./shaders" TYPE FILE FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/qt/shaders/ags001.shader")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba-qt" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./shaders" TYPE FILE FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/qt/shaders/dslite-color.shader")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba-qt" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./shaders" TYPE FILE FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/qt/shaders/fish.shader")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba-qt" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./shaders" TYPE FILE FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/qt/shaders/gb-micro-color.shader")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba-qt" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./shaders" TYPE FILE FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/qt/shaders/gba-color.shader")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba-qt" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./shaders" TYPE FILE FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/qt/shaders/gbc-color.shader")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba-qt" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./shaders" TYPE FILE FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/qt/shaders/gbc-lcd.shader")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba-qt" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./shaders" TYPE FILE FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/qt/shaders/hq2x.shader")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba-qt" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./shaders" TYPE FILE FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/qt/shaders/lcd.shader")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba-qt" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./shaders" TYPE FILE FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/qt/shaders/mmpx.shader")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba-qt" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./shaders" TYPE FILE FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/qt/shaders/motion_blur.shader")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba-qt" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./shaders" TYPE FILE FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/qt/shaders/nds-color.shader")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba-qt" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./shaders" TYPE FILE FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/qt/shaders/nso-gba-color.shader")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba-qt" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./shaders" TYPE FILE FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/qt/shaders/nso-gbc-color.shader")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba-qt" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./shaders" TYPE FILE FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/qt/shaders/omniscale.shader")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba-qt" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./shaders" TYPE FILE FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/qt/shaders/pixelate.shader")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba-qt" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./shaders" TYPE FILE FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/qt/shaders/scale2x.shader")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba-qt" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./shaders" TYPE FILE FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/qt/shaders/scale4x.shader")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba-qt" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./shaders" TYPE FILE FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/qt/shaders/scanlines.shader")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba-qt" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./shaders" TYPE FILE FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/qt/shaders/soften.shader")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba-qt" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./shaders" TYPE FILE FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/qt/shaders/sp101-color.shader")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba-qt" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./shaders" TYPE FILE FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/qt/shaders/tv-mode.shader")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba-qt" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./shaders" TYPE FILE FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/qt/shaders/vba_pixelate.shader")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba-qt" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./shaders" TYPE FILE FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/qt/shaders/vignette.shader")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba-qt" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./shaders" TYPE FILE FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/qt/shaders/wiiu.shader")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba-qt" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./shaders" TYPE FILE FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/qt/shaders/xbr-lv2.shader")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba-qt" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./shaders" TYPE FILE FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/qt/shaders/xbr-lv3.shader")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba-qt" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE DIRECTORY FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/res/scripts")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba-qt" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/res/nointro.dat")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba-qt" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "BASH-NOTFOUND" "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/tools/deploy-win.sh" "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/qt/mGBA.exe" "${CMAKE_INSTALL_PREFIX}" "$ENV{PWD}" WORKING_DIRECTORY "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba-qt" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE EXECUTABLE FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/mGBA.exe")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/qt/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
