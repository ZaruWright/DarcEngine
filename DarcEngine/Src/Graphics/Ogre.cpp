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

#include "Ogre.h"

#include "Utilities/Log.h"

namespace DarcGraphics{

	//DarcGraphics::CGraphics* DarcGraphics::CGraphics::_graphicInstance = nullptr;

	COgre& COgre::getInstance()
	{
		static COgre instance; // Guaranteed to be destroyed.
		// Instantiated on first use.
		_graphicInstance = &instance;

		return instance;
	} // getInstance

	bool COgre::init()
	{
		DarcUtilities::darcLog(DarcUtilities::GRAPHICS, std::string("Init Ogre3D..."));

		return true;
	} // init

	bool COgre::closedWindow()
	{
	
		return true;
	} // closedWindow

	void COgre::updateWindow()
	{

	} // updateWindow

	void COgre::release()
	{
		DarcUtilities::darcLog(DarcUtilities::GRAPHICS, std::string("Release Ogre3D..."));
	} // release

	void COgre::tick()
	{

	} // tick

}
