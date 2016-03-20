//                                         
//   _____             _   _           _   
//  |   __|___ ___ ___| |_|_|___ ___  | |_ 
//  |  |  |  _| .'| . |   | |  _|_ -|_|   |
//  |_____|_| |__,|  _|_|_|_|___|___|_|_|_|
//                |_|                      
//						
//	Ascii Art (Rectangles) from: http://patorjk.com/software/taag/
//
//	Author: ZaruWright
//
#ifndef GRAPHICS_GRAPHICS_H
#define GRAPHICS_GRAPHICS_H

namespace DarcGraphics{

	class CGraphics{
	public:
		/**
		Returns the class instance
		*/
		static CGraphics& getInstance();

		/**
		We do no not allow to copy the instance, we'll
		want have only one.
		*/
		CGraphics(const CGraphics &engine) = delete; // Disallowed to do a copy

		/**
		By the same reason of above, we do not allow the operator =.
		*/
		void operator=(const CGraphics &engine) = delete; // Disallowed used the operator =

		void init();

	private:
		// Constructor by default. It is private because
		// you only can get the class instance from getInstance method.
		CGraphics() = default;

		// Destructor by default
		~CGraphics() = default;
	};

}

#endif // GRAPHICS_GRAPHICS_H