//
//   _____                           _                 _
//  |   __|___ _ _ _____ ___ ___ ___| |_ ___ ___ ___  | |_
//  |   __|   | | |     | -_|  _| .'|  _| . |  _|_ -|_|   |
//  |_____|_|_|___|_|_|_|___|_| |__,|_| |___|_| |___|_|_|_|
//
//	Ascii Art (Rectangles) from: http://patorjk.com/software/taag/
//
//	Author: ZaruWright
//
#ifndef GRAPHICS_ENUMERATORS_H
#define GRAPHICS_ENUMERATORS_H

namespace DarcGraphics {
    
    /**
    Enumerator that shows the graphics engines supported by
    Darc Engine.
    */
    enum GraphicEngines {
        NONE,
        OPENGL,
        OGRE3D
    };
    
}

#endif //GRAPHICS_ENUMERATORS_H