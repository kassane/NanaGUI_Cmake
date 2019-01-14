#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/msgbox.hpp>
#include <iostream>

#if __has_include(<windows.h>)
    #include <windows.h>
    #pragma message "Windows OS"
#endif

using namespace nana;

class My_Widget : public form
{
    place place_    {*this};
    label lab_      {*this};
    button btn_     {*this};
    msgbox msg_     {*this, "Simple - Warning", msgbox::button_t::yes_no};
    public:
        My_Widget() {
            this->caption("Simple GUI - Nana C++ Library");
            //Define a label and display a text.
            lab_.caption("Hello, <bold blue size=16>Nana C++ Library</>");
            lab_.format(true);

            //Define a button and answer the click event.
            btn_.caption("Quit");
            msg_ << "Are you sure you want to close?";
            btn_.events().click([this]{
                switch (msg_.show())
                {
                case msgbox::pick_yes:
                    this->close();
                case msgbox::pick_no:
                    break;
                default:
                    std::cerr << "[ERROR]: desconhecido!" << std::endl;
                }
    });
            //Layout management
            place_.div("vert <><<><weight=80% text><>><><weight=24<><button><>><>");
            place_["text"] << lab_;
            place_["button"] << btn_;
            place_.collocate();
        };
};

int main()
{
    #if __has_include(<windows.h>)
        FreeConsole();
    #endif

    //Define a form.
    My_Widget fmm;

    //Show the form
    fmm.show();

    exec();
}