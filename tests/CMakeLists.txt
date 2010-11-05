include_directories(. ../)
set(test_SOURCES BufferDescriptorTest.cc ChunkTest.cc IOBufferTest.cc IOManagerTest.cc ManglerTest.cc MelterTest.cc ParserTest.cc main.cc)
add_executable(run_tests ${test_SOURCES})
target_link_libraries(run_tests melter pthread gtest gmock)

add_custom_target(test COMMAND run_tests)
add_dependencies(test run_tests)
