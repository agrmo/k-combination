
SET(dirs list kette
  vector pairlist matrix comb)

FOREACH(dir ${dirs})
    ADD_SUBDIRECTORY(${dir})
ENDFOREACH()
  
