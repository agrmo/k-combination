
SET(dirs list kette
  vector pointervector
  pairlist matrix comb
  abacus)

FOREACH(dir ${dirs})
    ADD_SUBDIRECTORY(${dir})
ENDFOREACH()
  
