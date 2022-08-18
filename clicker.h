#pragma once

#ifndef CLICKER_H
#define CLICKER_H
#endif

#include <iostream>
#include <string>
#include <Windows.h>
#include <cctype>

// clicker class
class clicker
{
    // variables
    bool toggle;
    bool holding;
    int cps;
    std::string button;
    char toggle_on;
    char toggle_off;

    // public methods
    public:
        // keys
        int keys[];

        // constructor
        clicker(int cps, std::string button, char toggle_on, char toggle_off, int keys[]);

        // getters
        bool is_toggled() { return this->toggle; }
        bool is_holding() { return this->holding; }
        int get_cps() { return this->cps; }
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

        void click();
        void self_destruct();
        void print_settings();
};

