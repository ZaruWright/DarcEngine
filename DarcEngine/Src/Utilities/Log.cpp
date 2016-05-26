//                       
//   __              _   
//  |  |   ___ ___  | |_ 
//  |  |__| . | . |_|   |
//  |_____|___|_  |_|_|_|
//            |___|      
//					
//	Ascii Art (Rectangles) from: http://patorjk.com/software/taag/
//
//	Author: ZaruWright
//

#include "Log.h"
#include <iostream>
#include <cassert>

namespace DarcUtilities
{
	void darcLog(EEngineCore core, const std::string& message)
	{
		#if defined(_DEBUG)

		std::cout << CEngineCores::engineCores[core].c_str() << ": " << message.c_str() << std::endl;

		#endif //defined(_DEBUG)
	} // darcLog

	void darcAssert(bool expresion, const std::string& message)
	{
		assert(expresion && message.c_str());
	} // darcAssert
}