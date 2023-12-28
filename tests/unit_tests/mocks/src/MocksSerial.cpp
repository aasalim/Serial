#include "MocksSerial.h"
#ifdef __cplusplus
extern "C" {
#endif
extern MocksSerial* pMocksSerial;

bool serialSetup_Hook(Serial_t* self) { return (pMocksSerial->serialSetup_Hook(self)); }

#ifdef __cplusplus
}
#endif
