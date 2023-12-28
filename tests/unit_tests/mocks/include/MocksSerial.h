#ifndef __MOCK_SERIAL_H__
#define __MOCK_SERIAL_H__
#include "Serial.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <spdlog/spdlog.h>

class MocksSerial {
public:
    MOCK_METHOD(bool, serialSetup_Hook, (Serial_t * self));
    uint8_t SerialBuffer[64];
    RingBuffer_t SerialRingBuffer;
};
#endif