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

#include "Enumerators.h"
#include "Engine/Engine.h"

namespace DarcGraphics{

	class CGraphics{
	
    public:

		/**
		Returns the class instance.
		*/
		static CGraphics* getInstance(){ return _graphicInstance; };
		
    protected:

		/**
		Constructor by default.
		*/
		CGraphics() = default;

		/**
		Destructor by default.
		*/
		~CGraphics() = default;

		/**
		Init our Graphic Engine depend on the user selection.
		In this moment, you can choose between "GraphicEngines::OGRE3D"
		and "GraphicEngines::OPENGL" as Graphic Engine.
		*/
		virtual void init() = 0;

		/**
		Release our Graphic Engine.
		*/
		virtual void release() = 0;

		/**
		Update the graphic engine
		*/
		virtual void tick(float msecs) = 0;

		float _windowWidth;
		float _windowHeight;
		float _windowPositionX;
		float _windowpositionY;

		static CGraphics* _graphicInstance;

		// friends
		friend class DarcEngine::CEngine;

	};

}

#endif // GRAPHICS_GRAPHICS_H