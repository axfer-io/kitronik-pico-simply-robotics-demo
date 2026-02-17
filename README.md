# Pico C/C++ Firmware Template — Kitronik Simply Robotics (Direct PWM + PIO)

Embedded systems · Control · Debugging ⚙️  
I/O 🔌, firmware 🔧, and systems that actually run 🚀

------------------------------------------------------------------------

## Overview

This example demonstrates control of:

- Servos  
- DC motors  
- Stepper motors  

using the **Kitronik Simply Robotics board**, driven directly by the RP2040 using:

- Hardware PWM (motors)
- PIO state machines (servos)
- GPIO sequencing (steppers)

No external PWM controller is required.

The RP2040 generates all control signals internally.

------------------------------------------------------------------------

## Example Code

```cpp
#include "pico/stdlib.h"
#include "kitronik_simply_robotics.hpp"

int main() {
    stdio_init_all();
    sleep_ms(200);

    KitronikSimplyRobotics board(true);

    while (true) {

        // Servo control
        board.servos[0].goToPosition(0);
        sleep_ms(500);

        board.servos[0].goToPosition(180);
        sleep_ms(500);

        // Motor control
        board.motors[0].on('f', 60);
        sleep_ms(500);

        board.motors[0].off();
        sleep_ms(500);

        // Stepper control
        board.steppers[0].step('f');
        sleep_ms(500);
    }
}
```

------------------------------------------------------------------------

## Hardware Architecture

Control method:

| Device   | Method                |
|---------|-----------------------|
| Servos  | RP2040 PIO           |
| Motors  | RP2040 Hardware PWM  |
| Steppers| GPIO + PWM sequencing|
| Comm    | Direct GPIO (no I2C) |

------------------------------------------------------------------------

## Pin Mapping (Kitronik Simply Robotics Board)

### Motors

| Motor | Forward | Reverse |
|------|---------|---------|
| M1   | GP2     | GP5     |
| M2   | GP4     | GP3     |
| M3   | GP6     | GP9     |
| M4   | GP8     | GP7     |

### Servos

| Servo | GPIO |
|------|------|
| S0   | GP15 |
| S1   | GP14 |
| S2   | GP13 |
| S3   | GP12 |
| S4   | GP19 |
| S5   | GP18 |
| S6   | GP17 |
| S7   | GP16 |

------------------------------------------------------------------------

## Build and Flash

```bash
cmake --preset pico2-release
cmake --build --preset build-pico2-release
picotool load build/pico2-release/app.uf2 -f
picotool reboot
```

------------------------------------------------------------------------

## Control Architecture Comparison

| Feature | Simply Robotics | PCA9685 Robotics |
|--------|-----------------|------------------|
| PWM generation | RP2040 internal | External PCA9685 |
| Communication | None | I2C |
| Latency | Lowest | Low |
| CPU load | Moderate | Minimal |
| Hardware complexity | Minimal | Higher |

------------------------------------------------------------------------

## When to use this version

Use this firmware when:

- Hardware is the Kitronik Simply Robotics board  
- No PCA9685 is present  
- Direct, low-latency control is required  
- Minimal hardware complexity is desired  

Use the I2C version when external PWM expansion is required.

------------------------------------------------------------------------

## Author

**axfer-io**  
Embedded systems · Control · Debugging  
Firmware and systems that actually run.

------------------------------------------------------------------------

## License

MIT
