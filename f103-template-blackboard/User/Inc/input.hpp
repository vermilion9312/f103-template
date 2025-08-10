/*
 * input.hpp
 *
 *  Created on: Aug 10, 2025
 *      Author: vermi
 */

#ifndef INC_INPUT_HPP_
#define INC_INPUT_HPP_

#include <common_include.hpp>

enum class InputType {
	NORMAL_OPEN,
	NORMAL_CLOSE
};

class Input {
public:
	Input(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, InputType type);

	void update(void);
	bool is_pressed(void);
	bool is_rising_edge(void);
	bool is_falling_edge(void);

private:
	GPIO_TypeDef* GPIOx;
	uint16_t      GPIO_Pin;
	InputType     type;
	bool          last_state;
	bool          state;
};


#endif /* INC_INPUT_HPP_ */
