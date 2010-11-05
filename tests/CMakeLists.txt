include_directories(. ../)
set(test_SOURCES BufferDescriptorTest.cc ChunkTest.cc IOBufferTest.cc IOManagerTest.cc ManglerTest.cc MelterTest.cc ParserTest.cc main.cc)
add_executable(tests ${test_SOURCES})

target_link_libraries(tests melter pthread gtest gmock)
ENABLE_TESTING()
ADD_TEST(tests tests)
