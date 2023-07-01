cmake_minimum_required(VERSION 3.16.3)
project(led)
add_library(led src/led.cpp)
target_include_directories(led PUBLIC include)

set_target_properties(led PROPERTIES PUBLIC_HEADER ./include/led.h)
install(TARGETS led LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include/jgpio
        )

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(testLed tests/test_led.cpp)
target_link_libraries(testLed gtest_main pigpio rt pthread led)
add_test(NAME test_led COMMAND testLed)
