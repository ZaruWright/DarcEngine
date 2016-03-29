//                                         
//   _____         _                       
//  |   __|___ ___|_|___ ___   ___ ___ ___ 
//  |   __|   | . | |   | -_|_|  _| . | . |
//  |_____|_|_|_  |_|_|_|___|_|___|  _|  _|
//            |___|               |_| |_|  
//						
//	Ascii Art (Rectangles) from: http://patorjk.com/software/taag/
//
//	Author: ZaruWright
//
#include <iostream>

#include "Engine.h"
#include "Graphics/Graphics.h"


namespace DarcEngine {

	CEngine& CEngine::getInstance()
	{
		static CEngine instance; // Guaranteed to be destroyed.
								 // Instantiated on first use.
		return instance;
	} // getInstance

	void CEngine::init(const DarcGraphics::GraphicEngines &graphicEngine)
	{
		std::cout << "Initializing Darc Engine..." << std::endl;
        DarcGraphics::CGraphics::init(graphicEngine);
		//DarcGraphics::COpenGl::getInstance().init();
	} // init

};