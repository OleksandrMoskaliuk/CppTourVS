#pragma once
#ifndef MY_TIMER_H
#define MY_TIMER_H

#include <chrono>
#include <string>

int my_timer();

class SimpleTimer 
{
private:
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> dr;
	std::chrono::duration<float> overtime;
	std::string st_name;
public:
	SimpleTimer();
	SimpleTimer(std::string timer_name);
	~SimpleTimer();
	void duration();
	double get_time();
};


class symbol_animation
{
private:
	char symbol;
	int8_t range;
	int anim_end;
	float time;
private:
	int element_to_draw(char image[10][10UI64], const int _x, const int _y);
public:
	symbol_animation();
	symbol_animation(char symbol);
	symbol_animation(int8_t range, char symbol);
	void set_cursor_position(int x, int y);
	void animation_run();
	void draw_circle();
};

#endif // !MY_TIMER_H
