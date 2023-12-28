#include "MocksSerial.h"
#ifdef __cplusplus
extern "C" {
#endif
extern MocksSerial* pMocksSerial;

bool serialSetup_Hook(Serial_t* self)
{
    pMocksSerial->SerialRingBuffer.buffer = pMocksSerial->SerialBuffer;
    pMocksSerial->SerialRingBuffer.capacity = 64;
    self->ringBuffer = &(pMocksSerial->SerialRingBuffer);

    return (pMocksSerial->serialSetup_Hook(self));
}

#ifdef __cplusplus
}
#endif
