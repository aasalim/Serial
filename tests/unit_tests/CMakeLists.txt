
include(GoogleTest)

add_executable(SerialUnitTests UT_Serial.cpp ${CMAKE_SOURCE_DIR}/tests/unit_tests/mocks/src/MocksSerial.cpp)

target_include_directories(SerialUnitTests PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/tests/unit_tests/mocks/include
)

target_link_libraries(SerialUnitTests
    PUBLIC
    GTest::gtest_main
    GTest::gmock
    spdlog::spdlog
    Serial
)

gtest_discover_tests(SerialUnitTests)
