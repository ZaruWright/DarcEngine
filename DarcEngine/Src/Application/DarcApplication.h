//                                                                   
//   ____              _____         _ _         _   _           _   
//  |    \ ___ ___ ___|  _  |___ ___| |_|___ ___| |_|_|___ ___  | |_ 
//  |  |  | .'|  _|  _|     | . | . | | |  _| .'|  _| | . |   |_|   |
//  |____/|__,|_| |___|__|__|  _|  _|_|_|___|__,|_| |_|___|_|_|_|_|_|
//                          |_| |_|                                  
//						
//	Ascii Art (Rectangles) from: http://patorjk.com/software/taag/
//
//	Author: ZaruWright
//
#ifndef APPLICATION_DARCAPPLICATION_H
#define APPLICATION_DARCAPPLICATION_H

namespace DarcApplication
{

	class IDarcApplication
	{
	public:

		// Init the App stuff 
		virtual bool init() = 0;

		// Your Game logic updates
		virtual bool run(float secs) = 0;

		// Release the App stuff
		virtual bool release() = 0;
	};
};

#endif // APPLICATION_DARCAPPLICATION_H