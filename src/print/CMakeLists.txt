SET(dirs list kette
  vector pointervector
  pairlist matrix comb
  abacus subabacus)

FOREACH(dir ${dirs})
    ADD_SUBDIRECTORY(${dir})
ENDFOREACH()
  
