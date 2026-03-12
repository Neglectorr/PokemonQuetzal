# Install script for directory: C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src

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

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE STATIC_LIBRARY OPTIONAL FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/mgba.lib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libmgba" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE SHARED_LIBRARY FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/mgba.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/include/mgba" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/include/mgba-util" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/mgba" TYPE FILE FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/include/mgba/flags.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./licenses" TYPE FILE FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/res/licenses/inih.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./licenses" TYPE FILE FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/res/licenses/discord-rpc.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./licenses" TYPE FILE FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/res/licenses/rapidjson.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./licenses" TYPE FILE FILES "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/res/licenses/mingw-std-threads.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES
    "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/README.md"
    "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/README_DE.md"
    "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/README_ES.md"
    "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/README_JP.md"
    "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/README_ZH_CN.md"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "mgba" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES
    "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/CHANGES"
    "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/LICENSE"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/src/debugger/cmake_install.cmake")
  include("C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/src/feature/cmake_install.cmake")
  include("C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/src/script/cmake_install.cmake")
  include("C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/src/arm/cmake_install.cmake")
  include("C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/src/core/cmake_install.cmake")
  include("C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/src/gb/cmake_install.cmake")
  include("C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/src/gba/cmake_install.cmake")
  include("C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/src/sm83/cmake_install.cmake")
  include("C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/src/util/cmake_install.cmake")
  include("C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/sdl/cmake_install.cmake")
  include("C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/qt/cmake_install.cmake")
  include("C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/test/cmake_install.cmake")

endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
if(CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_COMPONENT MATCHES "^[a-zA-Z0-9_.+-]+$")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
  else()
    string(MD5 CMAKE_INST_COMP_HASH "${CMAKE_INSTALL_COMPONENT}")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INST_COMP_HASH}.txt")
    unset(CMAKE_INST_COMP_HASH)
  endif()
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "C:/PassionProjects/GBAEmu/PokemonQuetzal/mgba_src/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
