CMAKE_MINIMUM_REQUIRED(VERSION 4.4)
PROJECT(cpp)

# Add executable.
ADD_EXECUTABLE(main)

# Set the source root folder.
# Otherwise #include "X" will not find "src/X"
TARGET_INCLUDE_DIRECTORIES(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Add source files.
SET(dirs addone twosum
  city ciudad stadt class
  array vector
  kette print quicksort swap
  combine graph matrix
  reference
  comb pairlist
  combinatoric
  abacus subabacus
  combinationabacus
  independentset)

FOREACH(dir ${dirs})
    ADD_SUBDIRECTORY(${dir})
ENDFOREACH()

# Add main function.
TARGET_SOURCES(main PRIVATE
  subabacus/factory/Main.cpp
)
