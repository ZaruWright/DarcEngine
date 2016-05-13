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
#include "Engine/Engine.h"

namespace DarcGraphics{

    class COpenGl : public CGraphics{
	public:
		/**
		Returns the class instance
		*/
		static COpenGl& getInstance();
    
	protected:
        /**
        Constructor by default.
        */
        COpenGl() = default;
        
        /**
        Destructor by default.
        */
        ~COpenGl() = default;
        
        /**
        OpenGl initialization.
        */
		void init() override;

		/**
		OpenGl release
		*/
		void release() override;

		/**
		Update graphics
		*/
		void tick(float msecs) override;

	private:
	};

}

#endif // GRAPHICS_OPENGL_H