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

namespace DarcGraphics{

	class CGraphics{
	
    public:

		/**
		Returns the class instance.
		*/
		static CGraphics& getInstance();

		/**
		Init our Graphic Engine depend on the user selection.
		In this moment, you can choose between "GraphicEngines::OGRE3D"
		and "GraphicEngines::OPENGL" as Graphic Engine.
		*/
		static void init(const GraphicEngines &graphicEngine);
    
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
		Update the graphic engine
		*/
		void tick(float msecs);

        // The Graphic Engine selected by the user.
        static GraphicEngines _graphicEngineUsed;

		float windowWidth;
		float windowHeight;
		float windowPositionX;
		float windowpositionY;

	};

}

#endif // GRAPHICS_GRAPHICS_H