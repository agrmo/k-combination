
SET(dirs list kette
  vector pairlist matrix comb
  abacus)

FOREACH(dir ${dirs})
    ADD_SUBDIRECTORY(${dir})
ENDFOREACH()
  
