/*# MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#*/

#include <iostream>
#include "StringTools.hpp"

int main() {
	/*std::string betweenstr("#Hello developers!?");
	std::cout << "String between # and ? : " << stringtools::GetBetweenString(betweenstr, "#", "?") << "\n";
	std::cout << "L character count : " << stringtools::Count(betweenstr, 'l') << "\n"; */
	int a = stringtools::Counter("Hello StringTools! 1234!@#)_qASD)(#@)$dla:cma><)_", 1);
	std::cout << a;
	return 0;
}
