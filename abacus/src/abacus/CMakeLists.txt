TARGET_SOURCES(main PRIVATE
  Abacus.cpp
  Abacus.h
)

SET(dirs factory)

FOREACH(dir ${dirs})
    ADD_SUBDIRECTORY(${dir})
ENDFOREACH()
