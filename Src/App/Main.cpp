#include <iostream>
#include "Engine/Engine.h"
#include "Graphics/Enumerators.h"

int main (int argc, char* argv[]){

	std::cout << "Funciona" << std::endl;
    DarcEngine::CEngine::getInstance().init(DarcGraphics::GraphicEngines::OPENGL);

	return 0;
}