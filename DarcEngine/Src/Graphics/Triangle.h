//                                       
//   _____     _             _       _   
//  |_   _|___|_|___ ___ ___| |___  | |_ 
//    | | |  _| | .'|   | . | | -_|_|   |
//    |_| |_| |_|__,|_|_|_  |_|___|_|_|_|
//                      |___|            
//						
//	Ascii Art (Rectangles) from: http://patorjk.com/software/taag/
//
//	Author: ZaruWright
//

#include "Graphics/Entity.h"

#ifndef GRAPHICS_TRIANGLE_H
#define GRAPHICS_TRIANGLE_H

namespace DarcGraphics
{
	class CTriangle : public IEntity
	{
	public:
		/**
		Constructor with an entity name
		*/
		CTriangle(const std::string& name);

		/**
		Draw method
		*/
		void draw() override;
	}; // CTriangle
}

#endif // GRAPHICS_TRIANGLE_H