FILE(REMOVE_RECURSE
  "test1.cpp"
  "CMakeFiles/test1.dir/test1.cpp.o"
  "CMakeFiles/test1.dir/src/heap.cpp.o"
  "CMakeFiles/test1.dir/src/mm.cpp.o"
  "CMakeFiles/test1.dir/src/thread_safe_mm.cpp.o"
  "test1.pdb"
  "test1"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang CXX)
  INCLUDE(CMakeFiles/test1.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
