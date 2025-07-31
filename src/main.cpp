#include "FL/Fl.h"
#include "FL/Fl_Window.h"
#include "FL/Fl_Button.h"

void on_button_click(Fl_Widget*, void*) {
    printf("Button clicked!\n");
}

int main(int argc, char** argv) {
    Fl_Window* window = new Fl_Window(340, 180, "FLTK Example");
    Fl_Button* button = new Fl_Button(110, 70, 120, 40, "Click Me");
    button->callback(on_button_click);
    window->end();
    window->show(argc, argv);
    return Fl::run();
}
