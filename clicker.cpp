#include "clicker.h"

// constructor
clicker::clicker(int min_cps, int max_cps, std::string button, char toggle_on, char toggle_off, int keys[])
{
    this->toggle = false;
    this->holding = false;
    this->min_cps = min_cps;
    this->max_cps = max_cps;
    this->button = button;
    this->toggle_on = toggle_on;
    this->toggle_off = toggle_off;
    this->keys[0] = keys[0];
    this->keys[1] = keys[1];
    this->keys[2] = keys[1];
}

// set toggle
void clicker::set_toggle(bool toggle)
{ 
    // setter
    this->toggle = toggle; 
}

// set holding
void clicker::set_holding(bool holding)
{
    // setter
    this->holding = holding; 
}

// set cps
void clicker::set_cps()
{
    // get CPS
    std::cout << "Min CPS: ";
    std::string min_cps_str;
    std::cin >> min_cps_str;

    std::cout << "Max CPS: ";
    std::string max_cps_str;
    std::cin >> max_cps_str;

    try
    {
        // set cps
        this->min_cps = std::stoi(min_cps_str);
        this->max_cps = std::stoi(max_cps_str);
    }
    catch (...)
    {
        // print error message
        std::cout << "Invalid input!" << std::endl;
        this->set_cps();
    }
}

// set button
void clicker::set_button()
{
    // get button
    std::cout << "Mouse Button (L/R): ";
    std::string button_str;
    std::cin >> button_str;

    try
    {
        // switch first character
        switch (std::tolower(button_str[0]))
        {
                // set based on case
            case 'l':
                this->button = "Left";
                this->keys[0] = VK_LBUTTON;
                this->keys[1] = MOUSEEVENTF_LEFTUP;
                this->keys[2] = MOUSEEVENTF_LEFTDOWN;
                break;
            case 'r':
                this->button = "Right";
                this->keys[0] = VK_RBUTTON;
                this->keys[1] = MOUSEEVENTF_RIGHTUP;
                this->keys[2] = MOUSEEVENTF_RIGHTDOWN;
                break;
            default:
                // print error message
                std::cout << "Invalid input!" << std::endl;
                this->set_button();
                break;
        }
    }
    catch (...)
    {
        // print error message
        std::cout << "Invalid input!" << std::endl;
        this->set_button();
    }
}

// set toggle on
void clicker::set_toggle_on()
{
    // get toggle on
    std::cout << "Toggle On (must be a letter/number): ";
    std::string toggle_on_str;
    std::cin >> toggle_on_str;

    try
    {
        // set toggle on
        this->toggle_on = std::toupper(toggle_on_str[0]);
    }
    catch (...)
    {
        // print error message
        std::cout << "Invalid input!" << std::endl;
        this->set_toggle_on();
    }
}

// set toggle off
void clicker::set_toggle_off()
{
    // get toggle on
    std::cout << "Toggle Off (must be a letter/number): ";
    std::string toggle_off_str;
    std::cin >> toggle_off_str;

    try
    {
        // set toggle on
        this->toggle_off = std::toupper(toggle_off_str[0]);
    }
    catch (...)
    {
        // print error message
        std::cout << "Invalid input!" << std::endl;
        this->set_toggle_off();
    }
}

// get random cps function
int clicker::get_random_cps()
{
    // reset random time
    srand(time(0));

    // get min and max
    int min = this->get_min_cps();
    int max = this->get_max_cps();

    // get random CPS
    int cps = (rand() % (max - min) + min) + 1;

    return cps;
}

// click function
void clicker::click()
{
    // click mouse
    mouse_event(this->keys[1], 0, 0, 0, 0);
    mouse_event(this->keys[2], 0, 0, 0, 0);
}

// self destruct function
void clicker::self_destruct()
{
    // toggle off
    this->set_toggle(false);
    system("color 0c");
    system("cls");

    // print & break
    std::cout << "Client has successfully self destructed. You can close this window." << std::endl;
}

// print settings
void clicker::print_settings()
{
    // print information
    system("cls");
    std::cout << "Min CPS: " << this->get_min_cps() << std::endl;
    std::cout << "Max CPS: " << this->get_max_cps() << std::endl;
    std::cout << "Button: " << this->get_button() << std::endl << std::endl;
    std::cout << this->get_toggle_on() << " - Toggle On" << std::endl;
    std::cout << this->get_toggle_off() << " - Toggle Off" << std::endl;
    std::cout << "Ctrl + " << this->get_toggle_off() << " - Self Destruct" << std::endl << std::endl;
    std::cout << "Hold down your left mouse button to click." << std::endl;
}