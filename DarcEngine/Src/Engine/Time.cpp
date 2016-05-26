//                                   
//   _____ _                         
//  |_   _|_|_____ ___   ___ ___ ___ 
//    | | | |     | -_|_|  _| . | . |
//    |_| |_|_|_|_|___|_|___|  _|  _|
//                          |_| |_|  
//						
//	Ascii Art (Rectangles) from: http://patorjk.com/software/taag/
//
//	Author: ZaruWright
//

#include "Time.h"

#include "Utilities/Log.h"

namespace DarcEngine {

	// Declarations
	std::chrono::time_point<std::chrono::high_resolution_clock> CTime::epoch;
	std::chrono::time_point<std::chrono::high_resolution_clock> CTime::start;

	CTime& CTime::getInstance()
	{
		static CTime instance; // Guaranteed to be destroyed.
							   // Instantiated on first use.
		return instance;
	} // getInstance

	void CTime::init()
	{
		DarcUtilities::darcLog(DarcUtilities::ENGINE, std::string("Init Time..."));
		epoch = std::chrono::high_resolution_clock::now();
		start = epoch;
	} // init

	float CTime::elapsedTime()
	{
		end = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double, std::milli> fp_ms = end - start;

		//std::cout << "f()a took " << fp_ms.count() << std::endl;

		start = end;
		
		return static_cast<float>(fp_ms.count() / 1000);
	} // elapsedTime

};