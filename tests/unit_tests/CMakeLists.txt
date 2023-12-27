
include(GoogleTest)

add_executable(SerialUnitTests UT_Serial.cpp)

target_include_directories(SerialUnitTests PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(SerialUnitTests
    PUBLIC
    GTest::gtest_main
    GTest::gmock
    spdlog::spdlog
    Serial
)

gtest_discover_tests(SerialUnitTests)
