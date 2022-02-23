/*
 * tess_utilities.h
 *
 *  Created on: Jun 18, 2021
 *      Author: Axinte Andrei
 */

#ifndef TESS_UTILITIES_H_
#define TESS_UTILITIES_H_


#define AbsValue(x) (((x)>=0) ? (x) : (-(x)))
#define Saturate(x, l, u ) (((x) <= (l)) ? (l) : (((x) >= (u)) ? (u) : (x)) )
#define Sign(x)            (((x) >= 0) ? 1 : 0)
#define ApplySign(x)       (((x) == 0) ? (-1) : (1))
#endif /* ACTUATORS_TESS_UTILITIES_H_ */
