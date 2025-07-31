#include <windows.h>
#include <future>
#include <cstdio>
#include "FL/Fl.H"
#include "FL/Fl_Window.H"
#include "FL/Fl_Button.H"

std::future<void> bg_task;
Fl_Button* button = nullptr;

void enable_cb(void* userdata) {
    Fl_Button* btn = static_cast<Fl_Button*>(userdata);
    btn->activate();
    printf("Button reactivated\n");
}

void on_button_click(Fl_Widget*) {
    if (bg_task.valid() && bg_task.wait_for(std::chrono::seconds(0)) != std::future_status::ready)
        return;

    button->deactivate();
    printf("Task started\n");

    bg_task = std::async(std::launch::async, []() {
        Sleep(2400); 
        Fl::awake(enable_cb, button);
    });
}

int main(int argc, char** argv) {
    Fl::lock(); // for multi thread
    Fl_Window* win = new Fl_Window(340, 180, "FLTK Async Button");
    button = new Fl_Button(110, 70, 120, 40, "Click Me");
    button->callback(on_button_click);
    win->end();
    win->show(argc, argv);

    return Fl::run();
}
