add_test([=[HelloTest.BasicAssertions]=]  D:/programming/projects/cpp-labs/notlabs/hash_table/cmake-build-debug/hash_table_test.exe [==[--gtest_filter=HelloTest.BasicAssertions]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[HelloTest.BasicAssertions]=]  PROPERTIES WORKING_DIRECTORY D:/programming/projects/cpp-labs/notlabs/hash_table/cmake-build-debug SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  hash_table_test_TESTS HelloTest.BasicAssertions)
