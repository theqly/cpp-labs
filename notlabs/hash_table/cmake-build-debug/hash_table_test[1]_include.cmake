if(EXISTS "D:/programming/projects/cpp-labs/notlabs/hash_table/cmake-build-debug/hash_table_test[1]_tests.cmake")
  include("D:/programming/projects/cpp-labs/notlabs/hash_table/cmake-build-debug/hash_table_test[1]_tests.cmake")
else()
  add_test(hash_table_test_NOT_BUILT hash_table_test_NOT_BUILT)
endif()
