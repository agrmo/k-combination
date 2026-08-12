CMAKE_MINIMUM_REQUIRED(VERSION 4.4)
PROJECT(cpp)

# Add executable.
ADD_EXECUTABLE(main)

# Set the source root folder.
# Otherwise #include "X" will not find "src/X"
TARGET_INCLUDE_DIRECTORIES(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Add source files.
SET(dirs addone twosum
  class array vector
  city ciudad stadt pueblo
  kette print quicksort swap
  combine graph matrix
  reference
  comb pairlist
  combinatoric
  abacus subabacus
  combinatoricabacus
  independentset)

FOREACH(dir ${dirs})
    ADD_SUBDIRECTORY(${dir})
ENDFOREACH()

# Add main function.
TARGET_SOURCES(main PRIVATE
  pueblo/Main.cpp
)
