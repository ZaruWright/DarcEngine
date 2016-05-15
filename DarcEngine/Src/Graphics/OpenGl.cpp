//                                           
//   _____             _____ _               
//  |     |___ ___ ___|   __| |  ___ ___ ___ 
//  |  |  | . | -_|   |  |  | |_|  _| . | . |
//  |_____|  _|___|_|_|_____|_|_|___|  _|  _|
//        |_|                       |_| |_|  
//						
//	Ascii Art (Rectangles) from: http://patorjk.com/software/taag/
//
//	Author: ZaruWright
//

#include "GL/glut.h"

#include "OpenGl.h"

#include "Utilities/Log.h"

namespace DarcGraphics{

	DarcGraphics::CGraphics* DarcGraphics::CGraphics::_graphicInstance = nullptr;

	COpenGl& COpenGl::getInstance()
	{
		static COpenGl instance; // Guaranteed to be destroyed.
		// Instantiated on first use.
		_graphicInstance = &instance;

		return instance;
	} // getInstance

	void COpenGl::init()
	{
		DarcUtilities::darcLog(DarcUtilities::GRAPHICS, "Init OpenGl...");
	} // init

	void COpenGl::release()
	{
		DarcUtilities::darcLog(DarcUtilities::GRAPHICS, "Release OpenGl...");
	} // release

	void COpenGl::tick(float msecs)
	{
		
	} // tick

}
