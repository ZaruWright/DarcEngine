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

    class COgre : public CGraphics{
    public:
        /**
        Constructor by default.
        */
        COgre() = default;
        
        /**
        Destructor by default.
        */
        ~COgre() = default;
        
        /**
        Returns the class instance
        */
        static COgre& getInstance();
        
        /**
        Ogre3D initialization.
        */
        static void init();

	};

}

#endif // GRAPHICS_Ogre_H