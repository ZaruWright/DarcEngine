//                                         
//   _____         _                       
//  |   __|___ ___|_|___ ___   ___ ___ ___ 
//  |   __|   | . | |   | -_|_|  _| . | . |
//  |_____|_|_|_  |_|_|_|___|_|___|  _|  _|
//            |___|               |_| |_|  
//						
//	Ascii Art (Rectangles) from: http://patorjk.com/software/taag/
//
//	Author: ZaruWright
//
#include "Engine.h"
#include <iostream>

namespace Engine {

	CEngine& CEngine::getInstance()
	{
		static CEngine instance; // Guaranteed to be destroyed.
								 // Instantiated on first use.
		return instance;
	} // getInstance

	void CEngine::init()
	{
		std::cout << "Initializing Darc Engine...\n";
	}

};