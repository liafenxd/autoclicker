#pragma once

#ifndef CLICKER_H
#define CLICKER_H
#endif

#include <iostream>
#include <string>
#include <Windows.h>
#include <cctype>
#include <cstdlib>
#include <time.h>

// clicker class
class clicker
{
    // variables
    bool toggle;
    bool holding;
    int min_cps;
    int max_cps;
    std::string button;
    char toggle_on;
    char toggle_off;

    // public methods
    public:
        // arrays
        int keys[];

        // constructor
        clicker(int min_cps, int max_cps, std::string button, char toggle_on, char toggle_off, int keys[]);

        // getters
        bool is_toggled() { return this->toggle; }
        bool is_holding() { return this->holding; }
        int get_min_cps() { return this->min_cps; }
        int get_max_cps() { return this->max_cps; }
        std::string get_button() { return this->button; }
        char get_toggle_on() { return this->toggle_on; }
        char get_toggle_off() { return this->toggle_off; }

        // setters
        void set_toggle(bool toggle);
        void set_holding(bool holding);

        // functions
        void set_cps();
        void set_button();
        void set_toggle_on();
        void set_toggle_off();

        int get_random_cps();
        void click();
        void self_destruct();
        void print_settings();
};

