#ifndef __SERIAL_H__
#define __SERIAL_H__
#ifdef __cplusplus
extern "C" {
#endif
#include "Print.h"
#include "RingBuffer.h"
#include "Stream.h"
#include <stdbool.h>
#include <stdint.h>
/**
 * @brief Enumeration defining serial communication configurations.
 */
typedef enum {
    SERIAL_5N1,
    SERIAL_6N1,
    SERIAL_7N1,
    SERIAL_8N1,
    SERIAL_5N2,
    SERIAL_6N2,
    SERIAL_7N2,
    SERIAL_8N2,
    SERIAL_5E1,
    SERIAL_6E1,
    SERIAL_7E1,
    SERIAL_8E1,
    SERIAL_5E2,
    SERIAL_6E2,
    SERIAL_7E2,
    SERIAL_8E2,
    SERIAL_5O1,
    SERIAL_6O1,
    SERIAL_7O1,
    SERIAL_8O1,
    SERIAL_5O2,
    SERIAL_6O2,
    SERIAL_7O2,
    SERIAL_8O2,
} SerialConfig_t;

/**
 * @brief Structure representing a serial communication interface.
 */
typedef struct {
    /**
     * @brief Ring buffer for handling incoming and outgoing data.
     */
    RingBuffer_t* ringBuffer;

    /**
     * @brief Baud rate for serial communication.
     */
    uint32_t buadrate;

    /**
     * @brief Configuration for serial communication (e.g., data bits, parity, stop bits).
     */
    SerialConfig_t config;
} Serial_t;

/**
 * @brief Initializes the serial communication interface.
 *
 * This function initializes the serial communication interface by performing hardware setup using
 * the specified _serial pointer. It also sets up the ring buffer associated with the serial
 * interface.
 *
 * @return true if initialization is successful, false otherwise.
 */
bool Serial_Init();

/**
 * @brief Writes a byte to the serial communication interface.
 *
 * This function writes a byte to the serial communication interface by using the associated ring
 * buffer.
 *
 * @param byte The byte to be written to the serial interface.
 * @return The number of bytes successfully written (1 if successful, 0 if the ring buffer is full).
 */
uint8_t writeByte(uint8_t byte);

/**
 * @brief Writes an array of bytes to the serial communication interface.
 *
 * This function writes an array of bytes to the serial communication interface using the associated
 * ring buffer.
 *
 * @param buffer Pointer to the array of bytes to be written.
 * @param size Number of bytes to be written.
 * @return The number of bytes successfully written to the serial interface.
 */
uint8_t writeBytes(const uint8_t* buffer, uint8_t size);

/**
 * @brief Reads a byte from the serial communication interface.
 *
 * This function reads a byte from the serial communication interface using the associated ring
 * buffer.
 *
 * @return The read byte as a signed 16-bit integer. Returns -1 if the ring buffer is empty.
 */
int16_t readByte();

/**
 * @brief Peeks at the next byte in the serial communication interface without removing it.
 *
 * This function peeks at the next byte in the serial communication interface using the associated
 * ring buffer without removing it from the buffer.
 *
 * @return The peeked byte as a signed 16-bit integer. Returns -1 if the ring buffer is empty.
 */
int16_t peekByte();

/**
 * @brief Returns the number of available bytes in the serial communication interface.
 *
 * This function returns the number of available bytes in the serial communication interface using
 * the associated ring buffer.
 *
 * @return The number of available bytes as a signed 16-bit integer.
 */
int16_t availableBytes();

/* Interface Function */
extern bool serialSetup_Hook(Serial_t* self);

#ifdef __cplusplus
}
#endif
#endif