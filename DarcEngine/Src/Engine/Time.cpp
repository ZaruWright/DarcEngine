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
#include <iostream>

#include "Time.h"


namespace DarcEngine {

	// Declarations
	std::chrono::time_point<std::chrono::system_clock> CTime::epoch;
	std::chrono::time_point<std::chrono::system_clock> CTime::start;

	CTime& CTime::getInstance()
	{
		static CTime instance; // Guaranteed to be destroyed.
							   // Instantiated on first use.
		return instance;
	} // getInstance

	void CTime::init()
	{
		std::cout << "Init Time..." << std::endl;
		epoch = std::chrono::system_clock::now();
		start = epoch;
	} // init

	int CTime::elapsedTime()
	{
		end = std::chrono::system_clock::now();
		int elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
		start = end;
		
		return elapsedTime;
	} // elapsedTime

};