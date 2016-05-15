//                               
//   __                          
//  |  |   ___ ___   ___ ___ ___ 
//  |  |__| . | . |_|  _| . | . |
//  |_____|___|_  |_|___|  _|  _|
//            |___|     |_| |_|  
//					
//	Ascii Art (Rectangles) from: http://patorjk.com/software/taag/
//
//	Author: ZaruWright
//
#ifndef UTILITIES_LOG_H
#define UTILITIES_LOG_H

#include "EngineCores.h"

namespace DarcUtilities
{
	/**
	Function to log something on Darc Engine.
	*/
	void darcLog(EEngineCore core, std::string message);
}

#endif // UTILITIES_LOG_H