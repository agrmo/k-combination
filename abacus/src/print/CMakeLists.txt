SET(dirs abacus
  vector pointervector
  matrix)

FOREACH(dir ${dirs})
    ADD_SUBDIRECTORY(${dir})
ENDFOREACH()
  
