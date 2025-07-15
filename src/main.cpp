#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>

void ButtonCallback(Fl_Widget* widget, void*) {
    Fl_Button* btn = (Fl_Button*)widget;
    btn->label("Clicked!");
}

int main(int argc, char **argv) {
    Fl_Window *window = new Fl_Window(340, 180, "FLTK Example");

    Fl_Button *button = new Fl_Button(110, 70, 120, 40, "Click Me");

    button->callback(ButtonCallback);

    window->end();

    window->show(argc, argv);

    return Fl::run();
}
