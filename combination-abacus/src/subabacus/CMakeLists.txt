target_sources(main PRIVATE
  Subabacus.cpp
  Subabacus.h
)

SET(dirs factory)

FOREACH(dir ${dirs})
    ADD_SUBDIRECTORY(${dir})
ENDFOREACH()
