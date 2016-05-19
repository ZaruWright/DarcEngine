//                           
//   _____               _   
//  |     |___ ___ ___  | |_ 
//  |  |  | . |  _| -_|_|   |
//  |_____|_  |_| |___|_|_|_|
//        |___|              
//					
//	Ascii Art (Rectangles) from: http://patorjk.com/software/taag/
//
//	Author: ZaruWright
//
#ifndef GRAPHICS_OGRE_H
#define GRAPHICS_OGRE_H

#include "Graphics.h"

namespace DarcGraphics{

    class COgre : CGraphics{
	public:

		/**
		Returns the class instance
		*/
		static COgre& getInstance();

	protected:
		/**
		Constructor by default.
		*/
		COgre() = default;

		/**
		Destructor by default.
		*/
		~COgre() = default;

		/**
		Ogre initialization.
		*/
		bool init() override;

		/**
		Gives if Ogre windows is open or not.
		*/
		bool closedWindow() override;

		/**
		
		*/
		void updateWindow() override;

		/**
		Ogre release
		*/
		void release() override;

		/**
		Update graphics
		*/
		void tick() override;
	private:
	};

}

#endif // GRAPHICS_Ogre_H