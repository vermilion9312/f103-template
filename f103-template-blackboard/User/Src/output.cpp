/*
 * output.cpp
 *
 *  Created on: Aug 10, 2025
 *      Author: vermi
 */




#include <output.hpp>

static inline void set_gpio(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) noexcept
{
	GPIOx->BSRR = GPIO_Pin;
}

static inline void reset_gpio(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) noexcept
{
	GPIOx->BSRR = (uint32_t)GPIO_Pin << 16;
}

Output::Output(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, OutputType type)
: GPIOx(GPIOx),
  GPIO_Pin(GPIO_Pin),
  type(type),
  state(false)
{
    if (type == OutputType::ACTIVE_LOW)
    {
    	set_gpio(GPIOx, GPIO_Pin);
    }
    else
    {
    	reset_gpio(GPIOx, GPIO_Pin);
    }
}

void Output::turn_on(void)
{
	if (state) return;
	state = true;

	if (type == OutputType::ACTIVE_LOW)
	{
		reset_gpio(GPIOx, GPIO_Pin);
	}
	else
	{
		set_gpio(GPIOx, GPIO_Pin);
	}
}

void Output::turn_off(void)
{
	if (!state) return;
	state = false;

	if (type == OutputType::ACTIVE_LOW)
	{
		set_gpio(GPIOx, GPIO_Pin);
	}
	else
	{
		reset_gpio(GPIOx, GPIO_Pin);
	}
}

void Output::toggle(void)
{
	state ? turn_off() : turn_on();
}

bool Output::is_on(void)
{
	return state;
}
