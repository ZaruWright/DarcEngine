//                                           
//   _____             _____ _               
//  |     |___ ___ ___|   __| |  ___ ___ ___ 
//  |  |  | . | -_|   |  |  | |_|  _| . | . |
//  |_____|  _|___|_|_|_____|_|_|___|  _|  _|
//        |_|                       |_| |_|  
//						
//	Ascii Art (Rectangles) from: http://patorjk.com/software/taag/
//
//	Author: ZaruWright
//
#include <iostream>
#include "GL\glut.h"

#include "OpenGl.h"

namespace DarcGraphics{

	COpenGl& COpenGl::getInstance()
	{
		static COpenGl instance; // Guaranteed to be destroyed.
		// Instantiated on first use.
		return instance;
	} // getInstance

	void COpenGl::init()
	{
		std::cout << "Initializing OpenGl..." << std::endl;
		int argcp = 1;
		char* argv = {"DarcEngine"};
		glutInit(&argcp, &argv);
		std::cout << "GlutInit..." << std::endl;

	}

}