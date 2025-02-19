#include <stdio.h>
#include "ship.h"


void check_fuel(int fuel_level) {
    if (fuel_level < 10) {
        printf("Уровень топлива ниже 10%%!\n");
    }
}