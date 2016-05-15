//                                                       
//   _____         _         _____                   _   
//  |   __|___ ___|_|___ ___|     |___ ___ ___ ___  | |_ 
//  |   __|   | . | |   | -_|   --| . |  _| -_|_ -|_|   |
//  |_____|_|_|_  |_|_|_|___|_____|___|_| |___|___|_|_|_|
//            |___|                                      
//					
//	Ascii Art (Rectangles) from: http://patorjk.com/software/taag/
//
//	Author: ZaruWright
//
#ifndef UTILITIES_ENGINE_CORES_H
#define UTILITIES_ENGINE_CORES_H

#include <iostream>

namespace DarcUtilities
{
	/**
	We do the class to can access later to the strings with
	the enumerator defined in cpp file.
	*/
	class CEngineCores{
	public:
		static std::string engineCores[];
	};

	/**
	Enumeration of all Darc Engine cores
	*/
	enum EEngineCore{
		ENGINE,
		GRAPHICS,
		UTILITIES
	};
}

#endif // UTILITIES_LOG_H