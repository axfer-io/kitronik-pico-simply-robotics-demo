#include "pico/stdlib.h"
#include "kitronik_simply_robotics.hpp"


int main() {
    stdio_init_all();
    sleep_ms(200);

    KitronikSimplyRobotics board(true);

    // Servo 0 a 0..180 suavecito
    while (true) {
        board.servos[0].goToPosition(0);
        sleep_ms(500);
        board.servos[0].goToPosition(180);
        sleep_ms(500);

        // Motor 0 forward 60%
        board.motors[0].on('f', 60);
        sleep_ms(500);
        board.motors[0].off();

        // Stepper 0 un paso forward
        board.steppers[1].step('f');
        sleep_ms(50);
    }
}
