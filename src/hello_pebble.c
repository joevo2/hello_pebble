#include <pebble.h>

static Window *s_main_window;

static void main_window_load(Window *window) {

}

static void main_window_unload(Window *window) {

}

static void init() {
  //Create main Window element and assign to pointer
  s_main_window = window_create();

  //Set handler to manage the element inside the window
  window_set_window_handlers(s_main_window,(WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });

  //Show the window on the watch, with animated=true
  window_stack_push(s_main_window, true);
}

static void deinit() {
  //Destroy Window
  window_destroy(s_main_window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
