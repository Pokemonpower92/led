#include <chrono>
#include <thread>

#include "led.h"
#include "pigpio.h"

namespace jgpio {

constexpr uint32_t HIGH = 1;
constexpr uint32_t LOW = 0;

LED::LED(int gpio)
{
    // On 4-series boards only pins 0-27 are safe for user control.
    if (gpio < 0 || gpio > 27)
        throw "GPIO pin out of safe range.";

    this->gpio = gpio;
    gpioSetMode(this->gpio, PI_OUTPUT);
}

void LED::set_high()
{
    gpioWrite(this->gpio, HIGH);
}

void LED::set_low()
{
    gpioWrite(this->gpio, LOW);
}

void LED::blink(int milliseconds)
{
    if (milliseconds < 0)
        throw "Miliseconds must be positive.";

    this->set_high();
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    this->set_low();
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}
}