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

void check_temp_out(int &home_state, float temp_out) {
    if (temp_out < 0 && !(home_state & HEATING_WATER_SUP)) {
        home_state |= HEATING_WATER_SUP;
        std::cout << "Heating water sup turned ON\n";
    } else if ((home_state & HEATING_WATER_SUP) && temp_out > 5) {
        home_state &= ~HEATING_WATER_SUP;
        std::cout << "Heating water sup turned OFF\n";
    }
}

void check_light_out(int &home_state, int time, std::string have_moving) {
    if (time > 16 || time < 5) {
        if (have_moving == "yes" && !(home_state & LIGHT_OUT)) {
            home_state |= LIGHT_OUT;
            std::cout << "Lightening garden turned ON\n";
        } else if (home_state & LIGHT_OUT && have_moving == "no") {
            home_state &= ~LIGHT_OUT;
            std::cout << "Lightening garden turned OFF\n";
        }
    } else if (home_state & LIGHT_OUT) {
        home_state &= ~LIGHT_OUT;
        std::cout << "Lightening garden turned OFF\n";
    }
}

void check_home_temp(int &home_state, float temp_in) {
    if (temp_in < 22 && !(home_state & HEATING_IN)) {
        home_state |= HEATING_IN;
        std::cout << "Home heating turned ON\n";
    } else if ((home_state & HEATING_IN) && temp_in >= 25) {
        home_state &= ~HEATING_IN;
        std::cout << "Home heating turned OFF\n";
    }
    if (temp_in >= 30 && !(home_state & CONDITIONER)) {
        home_state |= CONDITIONER;
        std::cout << "Home conditioner turned ON\n";
    } else if ((home_state & CONDITIONER) && temp_in <= 25) {
        home_state &= ~CONDITIONER;
        std::cout << "Home conditioner turned OFF\n";
    }
}

void check_light_in(int &home_state, std::string light_in, int &light_temp, int time) {
    if (time >= 16 && time < 20) {
        light_temp -= (5000 - 2700) / (20 - 15);
    } else if (time == 20) {
        light_temp = 2700;
    } else if (time == 0) {
        light_temp = 5000;
    }
    if (light_in == "on" && !(home_state & LIGHT_IN)) {
        home_state |= LIGHT_IN;
        std::cout << "Lightening home turned ON\n";
    } else if (home_state & LIGHT_IN && light_in == "off") {
        home_state &= ~LIGHT_IN;
        std::cout << "Lightening home turned OFF\n";
    }
    if (home_state & LIGHT_IN) {
        std::cout << "Home light temperature is " << light_temp << std::endl;
    }
}

void smart_home() {
    std::string input_string = "";

    float temp_in = 25, temp_out = 20;
    std::string have_moving = "no", light_in = "off";
    int light_temp = 5000;
    int home_state = 0;

    std::cout << "Get sensors data for smart home. Write '" << QUIT_STR << "' to quit\n";
    std::cout << "Data format: temp_in(float) temp_out(float) have_moving(yes/no) light_in(on/off)\n";
    std::cout << "Example: 20.1 17.9 yes on\n";
    std::cin.ignore();
    for(int time = 0; input_string != QUIT_STR; ++time) {
        if (time == 24)
            time = 0;

        input_string = "";
        std::cout << "\nNow is " << (time < 10 ? "0" : "") << time << ":00" << std::endl;
        std::cout << "Temp In: " << temp_in << ", Temp Out: " << temp_out;
        std::cout << ", Have Moving: " << have_moving << ", Light In: " << light_in << std::endl;
        std::getline(std::cin, input_string);
        if (input_string.length() > 4) {
            std::stringstream input_stream(input_string);
            input_stream >> temp_in >> temp_out >> have_moving >> light_in;
        }

        check_temp_out(home_state, temp_out);
        check_light_out(home_state, time, have_moving);
        check_home_temp(home_state, temp_in);
        check_light_in(home_state, light_in, light_temp, time);
    }
}
