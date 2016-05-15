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

namespace DarcUtilities
{
	void darcLog(EEngineCore core, std::string message)
	{
		#ifdef _DEBUG

		std::cout << CEngineCores::engineCores[core].c_str() << ": " << message.c_str() << std::endl;

		#endif //_DEBUG
	}
}