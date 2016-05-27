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
		
		/**
		Constructor with a name entity.
		*/
		IEntity(const std::string& name) : _name(name){}

		/**
		Virtual method that all classes that implements IEntity 
		have to override. Here the entity paints on the window.
		*/
		virtual void draw() = 0;

		/**
		Name getter.
		*/
		std::string getName() const { return _name; };

	private:
		// Entity name
		std::string _name;

	}; // IEntity

}

#endif // GRAPHICS_ENTITY_H