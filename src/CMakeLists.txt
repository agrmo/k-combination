CMAKE_MINIMUM_REQUIRED(VERSION 4.4)
PROJECT(cpp)

# Add executable.
ADD_EXECUTABLE(main)

# Set the source root folder.
# Otherwise #include "X" will not find "src/X"
TARGET_INCLUDE_DIRECTORIES(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Add source files.
SET(dirs array city ciudad stadt addone class
  kette print twosum quicksort swap
  combine vector graph matrix
  reference comb pairlist
  independentset combinatoric combinationabacus
  abacus)

FOREACH(dir ${dirs})
    ADD_SUBDIRECTORY(${dir})
ENDFOREACH()

# Add main function.
TARGET_SOURCES(main PRIVATE
  abacus/Main.cpp
)
