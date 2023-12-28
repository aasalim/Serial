#include "MocksSerial.h"
#include "Serial.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <spdlog/spdlog.h>

using testing::_;
using testing::DoAll;
using testing::Return;
using testing::SetArgPointee;
MocksSerial* pMocksSerial = 0;

class SerialUnitTest : public ::testing::Test {
protected:
    // Setup code that will be called before each test
    void SetUp() override
    {
        spdlog::default_logger_raw()->set_level(spdlog::level::debug);
        // Initialize resources, if needed
        pMocksSerial = &Serial;
        EXPECT_CALL(Serial, serialSetup_Hook(_)).WillOnce(Return(true));
        Serial_Init();
    }

    // Teardown code that will be called after each test
    void TearDown() override
    {
        // Clean up resources, if needed
    }
    int16_t result;
    MocksSerial Serial;
};

TEST_F(SerialUnitTest, Test_Serial_Init_Hardware_Setup_False)
{
    /* Arrange */
    EXPECT_CALL(Serial, serialSetup_Hook(_)).WillOnce(Return(false));

    /* Act */
    result = Serial_Init();

    /* Assert */
    EXPECT_EQ(result, false);
}
TEST_F(SerialUnitTest, Test_Serial_Init_Hardware_Setup_True)
{
    /* Arrange */
    EXPECT_CALL(Serial, serialSetup_Hook(_)).WillOnce(Return(true));

    /* Act */
    result = Serial_Init();

    /* Assert */
    EXPECT_EQ(result, true);
}
TEST_F(SerialUnitTest, Test_Serial_Write_Byte)
{
    /* Arrange */

    /* Act */
    result = writeByte(0xAA);

    /* Assert */
    EXPECT_EQ(result, 1);
}
TEST_F(SerialUnitTest, Test_Serial_Write_Byte_Overflow)
{
    /* Arrange */

    /* Act */
    for (int i = 0; i < 64; i++) {
        result = writeByte(0xAA);
    }

    /* Assert */
    EXPECT_EQ(result, 0);
}
TEST_F(SerialUnitTest, Test_Serial_Write_Bytes)
{
    /* Arrange */
    const char buffer[] = "Hello World\r\n";

    /* Act */
    result = writeBytes((uint8_t*)buffer, sizeof(buffer));

    /* Assert */
    EXPECT_EQ(result, 14);
}
TEST_F(SerialUnitTest, Test_Serial_Write_Bytes_Overflow)
{
    /* Arrange */
    const char buffer[] = "Hello World\r\n";
    for (int i = 0; i < 60; i++) {
        result = writeByte(0xAA);
    }

    /* Act */
    result = writeBytes((uint8_t*)buffer, sizeof(buffer));

    /* Assert */
    EXPECT_EQ(result, 3);
}
TEST_F(SerialUnitTest, Test_Serial_Read_Byte)
{
    /* Arrange */
    writeByte(0xAA);

    /* Act */
    result = readByte();

    /* Assert */
    EXPECT_EQ(result, 0xAA);
}
TEST_F(SerialUnitTest, Test_Serial_Read_Byte_Empty)
{
    /* Arrange */

    /* Act */
    result = readByte();

    /* Assert */
    EXPECT_EQ(result, -1);
}
TEST_F(SerialUnitTest, Test_Serial_Peek_Byte)
{
    /* Arrange */
    writeByte(0xAA);

    /* Act */
    result = peekByte();

    /* Assert */
    EXPECT_EQ(result, 0xAA);
}
TEST_F(SerialUnitTest, Test_Serial_Peek_Byte_Empty)
{
    /* Arrange */

    /* Act */
    result = peekByte();

    /* Assert */
    EXPECT_EQ(result, -1);
}
TEST_F(SerialUnitTest, Test_Serial_availableBytes_Empty)
{
    /* Arrange */

    /* Act */
    result = availableBytes();

    /* Assert */
    EXPECT_EQ(result, 0);
}
TEST_F(SerialUnitTest, Test_Serial_availableBytes_Filled)
{
    /* Arrange */
    writeByte(0xAA);
    writeByte(0xAA);
    writeByte(0xAA);
    writeByte(0xAA);

    /* Act */
    result = availableBytes();

    /* Assert */
    EXPECT_EQ(result, 4);
}