#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*input_tick_function_t)(unsigned char *minecraft);
void input_run_on_tick(input_tick_function_t function);

void input_set_is_right_click(int val);
void input_hide_gui();
int input_back();

void input_set_is_left_click(int val);

void input_set_mouse_grab_state(int state);

#ifdef __cplusplus
}
#endif
