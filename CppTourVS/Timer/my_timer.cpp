#pragma once

#include "my_timer.h"
#include <iostream>

#define OVERTIME_MIN 0.0000001


SimpleTimer::SimpleTimer() : st_name("_")
{
	start = std::chrono::high_resolution_clock::now();
	dr = end - start;
	end = std::chrono::high_resolution_clock::now();
	overtime = end - start;
};

SimpleTimer::SimpleTimer(std::string timer_name) : SimpleTimer()
{
	st_name = timer_name;
};

SimpleTimer::~SimpleTimer()
{
	duration();
};

void SimpleTimer::duration()
{
	end = std::chrono::high_resolution_clock::now();
	dr = end - start;
	std::cout << "Timer name:: "
		<< st_name
		<< ", duration = "
		<< (double)dr.count() - (double)overtime.count() - OVERTIME_MIN << "(seconds)\n";
};

double SimpleTimer::get_time()
{
	end = std::chrono::high_resolution_clock::now();
	dr = end - start;
	return ((double)dr.count() - (double)overtime.count() - OVERTIME_MIN);
};

#include <conio.h>
#include <thread>
#include <future>

symbol_animation::symbol_animation() :
	symbol('0'),
	range(10),
	anim_end(5000),
	time(0)
{};

symbol_animation::symbol_animation(char symbol) : symbol_animation()
{
	this->symbol = symbol;
};

symbol_animation::symbol_animation(int8_t range, char symbol) : symbol_animation(symbol)
{
	this->range = range;
};
	
	
void symbol_animation::set_cursor_position(int x, int y)
{
	x--;
	int xp = 0, yp = 0;
	while (yp < y) { printf("\n"); yp++; }
	while (xp < x) { printf(" "); xp++; }

};

void symbol_animation::animation_run()
{
	int posytion = 0;
	int side = 1;

	// lambda provide convenient exit when 'x' pressed
	std::future<bool> future = std::async(std::launch::async, []() {
		while (true)
		{
			if(_getch() == 'x')
			return true;
		}
		});

	while (anim_end > 0)
	{

		for (; posytion < range; posytion++)
		{
			for (int j = 0; j < posytion; j++)
			{
				printf(" ");
			}
			printf("%c", symbol);
			std::this_thread::sleep_for(std::chrono::microseconds(900));
			system("cls");
			if (future.wait_for(std::chrono::microseconds(100)) == std::future_status::ready)
			{
				return;
			}
		}

		for (; posytion > 0; posytion--)
		{
			for (int j = 0; j < posytion; j++)
			{
				printf(" ");
			}
			printf("%c", symbol);
			std::this_thread::sleep_for(std::chrono::microseconds(900));
			system("cls");

			if (future.wait_for(std::chrono::microseconds(100)) == std::future_status::ready) 
			{
				return;
			}
		}

		anim_end--;
	}
}

int symbol_animation::element_to_draw(char image[10][10UI64], const int _x, const int _y)
{
	int amount = 0;
	for (int y = 0; y < _y; y++)
	{
		for (int x = 0; x < _x; x++)
		{
			if (image[y][x] != ' ')
				amount++;
		}
	}
	return amount;
}

void symbol_animation::draw_circle()
{
	// lambda provide convenient exit when 'x' pressed
	std::future<bool> future = std::async(std::launch::async, []() {
		while (true)
		{
			if (_getch() == 'x')
				return true;
		}
		});
	const int height = 10;
	const int width = 10;
	char image[height][width] =
	{
		{' ',' ',' ','1','1','1',' ',' ',' ',' ',},
		{' ',' ',' ','1',' ','1',' ',' ',' ',' ',},
		{' ',' ','1','1',' ','1','1',' ',' ',' ',},
		{' ',' ','1',' ',' ',' ','1',' ',' ',' ',},
		{' ',' ','1',' ',' ',' ','1',' ',' ',' ',},
		{' ',' ','1',' ',' ',' ','1',' ',' ',' ',},
		{' ',' ','1',' ',' ',' ','1',' ',' ',' ',},
		{' ',' ','1','1',' ','1','1',' ',' ',' ',},
		{' ',' ',' ','1',' ','1',' ',' ',' ',' ',},
		{' ',' ',' ','1','1','1',' ',' ',' ',' ',},
	};

	//char (*)[3UI64]
	int el_to_draw = this->element_to_draw(image, height, width);
	int el_to_draw_counter = 0;
	while (true)
	{
		for (size_t el = 0; el < el_to_draw; el++) // 
		{
			// print array
			for (size_t y  = 0; y < height; y++)
			{
				for (size_t x = 0; x < width; x++)
				{	
					if (image[y][x] == ' ')
					{	
						printf(" ");
					}
					if (image[y][x] != ' ') // dr
					{
						
						if (el == el_to_draw_counter)
						{
							printf("1");
						}
						else
							printf(" ");
						el_to_draw_counter++;
					}
					else { printf(" "); }
					printf(" ");
					std::this_thread::sleep_for(std::chrono::microseconds(1));
				}
				printf("\n");
			}
			// print array
			system("cls");
			printf("press [x] to exit \n");
			el_to_draw_counter = 0;
		}
		if (future.wait_for(std::chrono::microseconds(100)) == std::future_status::ready)
			return;
	}
	
};

int my_timer() 
{
	SimpleTimer sm("Circle draw timer");
	symbol_animation sa('s');
	sa.draw_circle();
	sm.duration();
	return 0;
}