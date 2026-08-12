TARGET_SOURCES(main PRIVATE
  Matrix.cpp
  Matrix.h
)

SET(dirs factory)

FOREACH(dir ${dirs})
  ADD_SUBDIRECTORY(${dir})
ENDFOREACH()
