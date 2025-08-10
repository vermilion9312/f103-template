/*
 * output.hpp
 *
 *  Created on: Aug 10, 2025
 *      Author: vermi
 */

#ifndef INC_OUTPUT_HPP_
#define INC_OUTPUT_HPP_

#include <common_include.hpp>

enum class OutputType {
	ACTIVE_LOW,
	ACTIVE_HIGH
};

class Output {
public:
	Output(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, OutputType type);

	void turn_on(void);
	void turn_off(void);
	void toggle(void);
	bool is_on(void);

private:
	GPIO_TypeDef* GPIOx;
	uint16_t      GPIO_Pin;
	OutputType    type;
	bool          state;
};


#endif /* INC_OUTPUT_HPP_ */
