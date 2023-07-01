#include "jgpio/led.h"
#include "gtest/gtest.h"

TEST(testLED, TestValidGPIOValue)
{
    jgpio::LED testLed = jgpio::LED(18);
}