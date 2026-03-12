# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "qt\\CMakeFiles\\mgba-qt_autogen.dir\\AutogenUsed.txt"
  "qt\\CMakeFiles\\mgba-qt_autogen.dir\\ParseCache.txt"
  "qt\\mgba-qt_autogen"
  )
endif()
