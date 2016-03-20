//                                   
//   _____             _____ _   _   
//  |     |___ ___ ___|   __| | | |_ 
//  |  |  | . | -_|   |  |  | |_|   |
//  |_____|  _|___|_|_|_____|_|_|_|_|
//        |_|                        
//						
//	Ascii Art (Rectangles) from: http://patorjk.com/software/taag/
//
//	Author: ZaruWright
//
#ifndef GRAPHICS_OPENGL_H
#define GRAPHICS_OPENGL_H

#include "Graphics.h"

namespace DarcGraphics{

	class COpenGl{
	public:

		/**
		Returns the class instance
		*/
		static COpenGl& getInstance();

		/**
		We do no not allow to copy the instance, we'll
		want have only one.
		*/
		COpenGl(const CGraphics &engine) = delete; // Disallowed to do a copy

		/**
		By the same reason of above, we do not allow the operator =.
		*/
		void operator=(const CGraphics &engine) = delete; // Disallowed used the operator =

		void init();

	private:
		// Constructor by default. It is private because
		// you only can get the class instance from getInstance method.
		COpenGl::COpenGl() = default;

		// Destructor by default
		COpenGl::~COpenGl() = default;

	};

}

#endif GRAPHICS_OPENGL_H