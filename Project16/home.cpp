//
// Created by v1ew on 9/23/2022.
//
#include <iostream>
#include <sstream>

#define QUIT_STR "quit"

/*
 * Sensors:
 * - temp_in
 * - temp_out
 * - have_moving
 *
 * Auto switches:
 * - power
 * - outlets
 * - light_in
 * - light_out
 * - heating_in
 * - heating_water_sup
 * - conditioner
 *
 * Values:
 * - time
 * - light_in
 * - light_temp
 */

enum switches {
    POWER = 1,
    OUTLETS = 2,
    LIGHT_IN = 4,
    LIGHT_OUT = 8,
    HEATING_IN = 16,
    HEATING_WATER_SUP = 32,
    CONDITIONER = 64
};

// TODO: Input negative values
void check_temp_out(int &home_state, float temp_out) {
    if (temp_out < 0 && !(home_state & HEATING_WATER_SUP)) {
        home_state |= HEATING_WATER_SUP;
        std::cout << "Heating water sup turned ON\n";
    } else if ((home_state & HEATING_WATER_SUP) && temp_out > 5) {
        home_state ^= HEATING_WATER_SUP;
        std::cout << "Heating water sup turned OFF\n";
    }
}

void check_light_out(int &home_state, int time, std::string have_moving) {
    if (time > 16 || time < 5) {
        if (have_moving == "yes" && !(home_state & LIGHT_OUT)) {
            home_state |= LIGHT_OUT;
            std::cout << "Lightening garden turned ON" << std::endl;
        } else if (home_state & LIGHT_OUT && have_moving == "no") {
            home_state ^= LIGHT_OUT;
            std::cout << "Lightening garden turned OFF" << std::endl;
        }
    } else if (home_state & LIGHT_OUT) {
        home_state ^= LIGHT_OUT;
        std::cout << "Lightening garden turned OFF" << std::endl;
    }
}

void smart_home() {
    std::string input_string = "";

    float temp_in = 25, temp_out = 20;
    std::string have_moving = "no", light_in = "off";
    int home_state = 0;

    std::cout << "Get sensors data for smart home. Write '" << QUIT_STR << "' to quit\n";
    std::cout << "Data format: temp_in(float) temp_out(float) have_moving(yes/no) light_in(on/off)\n";
    std::cout << "Example: 20.1 17.9 yes on\n\n";
    for(int time = 0; input_string != QUIT_STR; ++time) {
        if (time == 24)
            time = 0;

        input_string = "";
        std::cout << "Now is " << (time < 10 ? "0" : "") << time << ":00" << std::endl;
        std::cout << "Temp In: " << temp_in << ", Temp Out: " << temp_out;
        std::cout << ", Have Moving: " << have_moving << ", Light In: " << light_in << std::endl;
        while (input_string.empty()) {
            std::getline(std::cin, input_string);
        }
        if (input_string.length() > 4) {
            std::stringstream input_stream(input_string);
            input_stream >> temp_in >> temp_out >> have_moving >> light_in;
            input_stream.flush();
        }

        check_temp_out(home_state, temp_out);
        check_light_out(home_state, time, have_moving);
    }
}
