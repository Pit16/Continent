/*
 * debugowanie.h
 *
 *  Created on: 27 mar 2014
 *      Author: PiotreK
 */

#ifndef DEBUGOWANIE_H_
#define DEBUGOWANIE_H_

#define _DEBUG

#include <string>
inline void debug(string komunikat)
{
#ifdef _DEBUG
	std::cout<< "[tryb debug]" << komunikat <<std::endl;
#endif
}
#endif /* DEBUGOWANIE_H_ */
