//                           
//   _____ _             _   
//  |_   _|_|_____ ___  | |_ 
//    | | | |     | -_|_|   |
//    |_| |_|_|_|_|___|_|_|_|
//                           
//						
//	Ascii Art (Rectangles) from: http://patorjk.com/software/taag/
//
//	Author: ZaruWright
//
#ifndef ENGINE_TIME_H
#define ENGINE_TIME_H

#include <chrono>

namespace DarcEngine{

	class CTime{

	public:

		/**
		Returns the class instance
		*/
		static CTime& getInstance();

		/**
		We do no not allow to copy the instance, we'll
		want have only one.
		*/
		CTime(const CTime &time) = delete; // Disallowed to do a copy

		/**
		By the same reason of above, we do not allow the operator =.
		*/
		void operator=(const CTime &time) = delete; // Disallowed used the operator =

		/**
		Init time.
		*/
		static void init();

		/**
		We get the elapsed time in milliseconds since the init the Time or another elapsedTime call.
		*/
		int elapsedTime();

	private:

		// Constructor by default. It is private because
		// you only can get the class instance from getInstance method.
		CTime() = default;

		// Destructor by default
		~CTime() = default;

		// Start time
		static std::chrono::time_point<std::chrono::system_clock> epoch;

		// Used to know the elapsed time between start and end. 
		static std::chrono::time_point<std::chrono::system_clock> start;
		std::chrono::time_point<std::chrono::system_clock> end;
	};
}

#endif // ENGINE_TIME_H