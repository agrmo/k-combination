SET(dirs vector pointervector
  matrix abacus subabacus)

FOREACH(dir ${dirs})
    ADD_SUBDIRECTORY(${dir})
ENDFOREACH()
  
