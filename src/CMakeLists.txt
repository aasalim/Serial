add_library(Serial STATIC Serial.c)
target_include_directories(Serial PUBLIC ${Serial_SOURCE_DIR}/include)
target_link_libraries(Serial PUBLIC RingBuffer Stream)