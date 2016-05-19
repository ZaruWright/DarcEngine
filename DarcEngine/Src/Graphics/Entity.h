//                                 
//   _____     _   _ _         _   
//  |   __|___| |_|_| |_ _ _  | |_ 
//  |   __|   |  _| |  _| | |_|   |
//  |_____|_|_|_| |_|_| |_  |_|_|_|
//                      |___|      
//						
//	Ascii Art (Rectangles) from: http://patorjk.com/software/taag/
//
//	Author: ZaruWright
//
#ifndef GRAPHICS_ENTITY_H
#define GRAPHICS_ENTITY_H

#include <string>

namespace DarcGraphics
{
	class IEntity{
	public:
		virtual void draw() = 0;
		std::string getName() const { return _name; };

	private:
		std::string _name;

	}; // IEntity

}

#endif // GRAPHICS_ENTITY_H