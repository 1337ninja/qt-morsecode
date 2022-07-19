find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)

set(TEST_SOURCES
        ../src/plaintext_morse_converter.h
        ../src/plaintext_morse_converter.cpp
        plaintext_morse_converter_test.cpp
)

set(CMAKE_AUTOMOC ON)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(MorseCode_Test MANUAL_FINALIZATION ${TEST_SOURCES})
else()
    add_executable(MorseCode_Test ${TEST_SOURCES})
endif()

target_link_libraries(MorseCode_Test PRIVATE Qt::Test)
target_include_directories(MorseCode_Test PRIVATE "../src")

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(MorseCode_Test)
endif()

add_test(NAME MorseCode_Test COMMAND MorseCode_Test)
