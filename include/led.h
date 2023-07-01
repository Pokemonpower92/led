#pragma once

namespace jgpio
{
  class LED
  {
  public:
    LED(int gpio);

    void set_high();
    void set_low();
    void blink(int miliseconds);

  private:
    int gpio;
  };
}