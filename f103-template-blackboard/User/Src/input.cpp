/*
 * input.cpp
 *
 *  Created on: Aug 10, 2025
 *      Author: vermi
 */




#include <input.hpp>

Input::Input(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, InputType type)
: GPIOx(GPIOx),
  GPIO_Pin(GPIO_Pin),
  type(type),
  last_state(false),
  state(false)
{

}

void Input::update(void)
{
	last_state = state;

	bool raw = (GPIOx->IDR & GPIO_Pin) != 0;
	if (type == InputType::NORMAL_OPEN)
	{
		state = !raw;
	}
	else
	{
		state = raw;
	}
}

bool Input::is_pressed(void)
{
	return state;
}

bool Input::is_rising_edge(void)
{
	return (!last_state && state);
}

bool Input::is_falling_edge(void)
{
	return (last_state && !state);
}
