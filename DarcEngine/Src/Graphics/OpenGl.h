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

    class COpenGl : public CGraphics{
    public:
        /**
        Constructor by default.
        */
        COpenGl() = default;
        
        /**
        Destructor by default.
        */
        ~COpenGl() = default;
        
        /**
        Returns the class instance
        */
        static COpenGl& getInstance();
        
        /**
        Ogre3D initialization.
        */
        static void init();
        
	};

}

#endif // GRAPHICS_OPENGL_H