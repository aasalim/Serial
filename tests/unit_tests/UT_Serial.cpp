#include "Serial.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <spdlog/spdlog.h>

using testing::_;
using testing::Return;
using testing::SetArgPointee;
class Serial : public ::testing::Test {
protected:
    // Setup code that will be called before each test
    void SetUp() override
    {
        spdlog::default_logger_raw()->set_level(spdlog::level::debug);
        // Initialize resources, if needed
    }

    // Teardown code that will be called after each test
    void TearDown() override
    {
        // Clean up resources, if needed
    }
    uint8_t result;
};
