#include <iostream>
#include "Engine/Engine.h"

int main (int argc, char* argv[]){

	std::cout << "Funciona" << std::endl;
	DarcEngine::CEngine::getInstance().init();

	return 0;
}