//                                                 
//   _____             _   _                       
//  |   __|___ ___ ___| |_|_|___ ___   ___ ___ ___ 
//  |  |  |  _| .'| . |   | |  _|_ -|_|  _| . | . |
//  |_____|_| |__,|  _|_|_|_|___|___|_|___|  _|  _|
//                |_|                     |_| |_|  
//						
//	Ascii Art (Rectangles) from: http://patorjk.com/software/taag/
//
//	Author: ZaruWright
//
#include "Graphics.h"
#include "Ogre.h"
#include "OpenGl.h"

#include <iostream>
#include <assert.h>

namespace DarcGraphics{
    
    GraphicEngines CGraphics::_graphicEngineUsed = GraphicEngines::NONE;

    void CGraphics::init(const GraphicEngines &graphicEngine)
    {
        std::cout << "Init Graphic Engine..." << std::endl;
        _graphicEngineUsed = graphicEngine;
        
        if (_graphicEngineUsed == GraphicEngines::OGRE3D)
            COgre::init();
        else if (_graphicEngineUsed == GraphicEngines::OPENGL)
            COpenGl::init(500,500,100,100);
        
    } // init
    
    CGraphics& CGraphics::getInstance()
    {
        assert(_graphicEngineUsed != GraphicEngines::NONE && "You must initializate at least once!!");
        
        static CGraphics instance;
        
        if (_graphicEngineUsed == GraphicEngines::OGRE3D)
            instance = COgre::getInstance();
        else if (_graphicEngineUsed == GraphicEngines::OPENGL)
            instance = COpenGl::getInstance();
        
        return instance;

    } // getInstance

	void CGraphics::tick(float msecs)
	{
	
	} // tick

}