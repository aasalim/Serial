#include "Serial.h"

/**
 * @brief Static pointer to the Serial_t structure representing the serial communication interface.
 *
 * This static pointer is used internally to reference the serial communication interface.
 */
static Serial_t _serial;

bool Serial_Init()
{
    /**
     * @brief Check if hardware setup is successful.
     */
    if (!serialSetup_Hook(&_serial)) {
        return false;
    }

    /**
     * @brief Set up the ring buffer for the serial communication interface.
     */
    RingBuffer_Setup(_serial.ringBuffer);

    /**
     * @brief Return true to indicate successful initialization.
     */
    return true;
}

uint8_t writeByte(uint8_t byte)
{
    /**
     * @brief Write the byte to the serial communication interface using the associated ring buffer.
     * @return The number of bytes successfully written (1 if successful, 0 if the ring buffer is
     * full).
     */
    return (uint8_t)RingBuffer_Write(_serial.ringBuffer, byte);
}

uint8_t writeBytes(const uint8_t* buffer, uint8_t size)
{
    /**
     * @brief Variable to track the number of bytes successfully written.
     */
    uint8_t i;

    /**
     * @brief Iterate through the array of bytes and write each byte to the serial interface.
     */
    for (i = 0; i < size; i++) {
        /**
         * @brief Check if the ring buffer is full before writing each byte.
         */
        if (!RingBuffer_Write(_serial.ringBuffer, *(buffer++))) {
            break;
        }
    }

    /**
     * @brief Return the number of bytes successfully written to the serial interface.
     */
    return i;
}

int16_t readByte()
{
    /**
     * @brief Variable to store the read byte.
     */
    uint8_t byte;

    /**
     * @brief Attempt to read a byte from the serial interface using the associated ring buffer.
     */
    if (!RingBuffer_Read(_serial.ringBuffer, &byte)) {
        /**
         * @brief Return -1 if the ring buffer is empty.
         */
        return -1;
    }

    /**
     * @brief Return the read byte as a signed 16-bit integer.
     */
    return (int16_t)byte;
}

int16_t peekByte()
{
    /**
     * @brief Variable to store the peeked byte.
     */
    uint8_t byte;

    /**
     * @brief Attempt to peek at the next byte in the serial interface using the associated ring
     * buffer.
     */
    if (!RingBuffer_Peek(_serial.ringBuffer, &byte)) {
        /**
         * @brief Return -1 if the ring buffer is empty.
         */
        return -1;
    }

    /**
     * @brief Return the peeked byte as a signed 16-bit integer.
     */
    return (int16_t)byte;
}

int16_t availableBytes()
{
    /**
     * @brief Return the number of available bytes in the serial interface using the associated ring
     * buffer.
     */
    return (int16_t)RingBuffer_Size(_serial.ringBuffer);
}
