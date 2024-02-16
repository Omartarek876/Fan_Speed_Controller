/*
 * Macros.h
 *
 *  Created on: Feb 15, 2024
 *      Author: omar tarek
 */

#ifndef INC_MACROS_H_
#define INC_MACROS_H_

#define CLR_BIT(REG,BIT) REG &= ~(1<<BIT)
#define SET_BIT(REG,BIT) REG |= (1<<BIT)
#define TOG_BIT(REG,BIT) REG ^= (1<<BIT)
#define GET_BIT(REG,BIT) ((REG>>BIT)&1)


#endif /* INC_MACROS_H_ */
