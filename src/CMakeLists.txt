add_library(Serial STATIC Serial.c)
target_include_directories(Serial PUBLIC ${Serial_SOURCE_DIR}/include)