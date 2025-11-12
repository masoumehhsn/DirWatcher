# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\DirWatcher_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\DirWatcher_autogen.dir\\ParseCache.txt"
  "DirWatcher_autogen"
  )
endif()
