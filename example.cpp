/*# MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#*/

#include <iostream>
#include "StringTools.hpp"

int main() {
	std::string betweenstr("#Hello developers!?");
	std::cout << stringtools::GetBetweenString(betweenstr, "#", "?") << "\n";
	return 0;
}
