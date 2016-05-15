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

#include "Engine.h"
#include "Time.h"

#include "Utilities/Log.h"

#include "Graphics/Graphics.h"
#include "Graphics/OpenGl.h"
#include <string>

namespace DarcEngine {

	CEngine& CEngine::getInstance()
	{
		static CEngine instance; // Guaranteed to be destroyed.
								 // Instantiated on first use.
		return instance;
	} // getInstance

	void CEngine::init(const DarcGraphics::GraphicEngines &graphicEngine)
	{
		DarcUtilities::darcLog(DarcUtilities::ENGINE, "Initializing Darc Engine...");
		
        //DarcGraphics::CGraphics::init(graphicEngine);
		//DarcGraphics::CGraphics::getInstance()
		if (graphicEngine == DarcGraphics::GraphicEngines::OPENGL)
			DarcGraphics::COpenGl::getInstance();

		DarcGraphics::CGraphics::getInstance()->init();

		// The last thing we do is init the Time.
		DarcEngine::CTime::init();

		// Starts to run app
		//run();

	} // init

	void CEngine::release()
	{
		DarcUtilities::darcLog(DarcUtilities::ENGINE, "Release Darc Engine...");
		DarcGraphics::CGraphics::getInstance()->release();

	} // release

	void CEngine::run()
	{
		// To init time
		CTime::getInstance().elapsedTime();
		float newElapsedTime = 0;
		float elapsedTime = 0;
		float fps = 0;
		unsigned int frames = 0;
		while (!exit)
		{
			++frames; // Add a new frame

			newElapsedTime = CTime::getInstance().elapsedTime(); // Get the elapsed time
			elapsedTime += newElapsedTime;
			fps += newElapsedTime;

			//DarcGraphics::CGraphics::getInstance().tick(newElapsedTime);

			#ifdef _DEBUG 
			while (fps >= 1)
			{
				DarcUtilities::darcLog(DarcUtilities::ENGINE, "FPS: " + std::to_string(frames));
				DarcUtilities::darcLog(DarcUtilities::ENGINE, "Elapsed Time: " + std::to_string(elapsedTime));
				frames = 0;
				fps = 0;
			} 
			#endif
		}
	} // run

};