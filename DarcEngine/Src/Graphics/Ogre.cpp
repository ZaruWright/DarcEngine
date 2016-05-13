//                                   
//   _____                           
//  |     |___ ___ ___   ___ ___ ___ 
//  |  |  | . |  _| -_|_|  _| . | . |
//  |_____|_  |_| |___|_|___|  _|  _|
//        |___|             |_| |_|  
//						
//	Ascii Art (Rectangles) from: http://patorjk.com/software/taag/
//
//	Author: ZaruWright
//
#include <iostream>
#include "Ogre.h"

namespace DarcGraphics{

	//DarcGraphics::CGraphics* DarcGraphics::CGraphics::_graphicInstance = nullptr;

	COgre& COgre::getInstance()
	{
		static COgre instance; // Guaranteed to be destroyed.
		// Instantiated on first use.
		_graphicInstance = &instance;

		return instance;
	} // getInstance

	void COgre::init()
	{
		std::cout << "Init Ogre3D..." << std::endl;
	} // init

	void COgre::release()
	{
		std::cout << "Release Ogre3D..." << std::endl;
	} // release

	void COgre::tick(float msecs)
	{

	} // tick

}
