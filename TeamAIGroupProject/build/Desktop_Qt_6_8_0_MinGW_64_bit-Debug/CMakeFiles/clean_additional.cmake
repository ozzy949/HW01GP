# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\TeamAIGroupProject_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TeamAIGroupProject_autogen.dir\\ParseCache.txt"
  "TeamAIGroupProject_autogen"
  )
endif()
