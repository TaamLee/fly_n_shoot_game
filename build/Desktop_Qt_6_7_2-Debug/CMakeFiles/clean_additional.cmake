# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/fly_n_shoot_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/fly_n_shoot_autogen.dir/ParseCache.txt"
  "fly_n_shoot_autogen"
  )
endif()
