/*
 * ultra.h
 *
 *  Created on: Oct 19, 2023
 *      Author: Ahmed
 */

#ifndef ULTRA_H_
#define ULTRA_H_

#include "std_types.h"

uint16 Ultrasonic_readDistance(void);

void Ultrasonic_edgeProcessing(void);

void Ultrasonic_init(void);

void Ultrasonic_Trigger(void);


#endif /* ULTRA_H_ */
