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
#include "Graphics/Ogre.h"
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
		
		// Set the Graphic Engine that we want to use.
		if (graphicEngine == DarcGraphics::GraphicEngines::OPENGL)
			DarcGraphics::COpenGl::getInstance();
		else if (graphicEngine == DarcGraphics::GraphicEngines::OGRE3D)
			DarcGraphics::COgre::getInstance();

		// Init Graphic Engine
		DarcGraphics::CGraphics::getInstance()->init();

		// The last thing we do is init the Time.
		DarcEngine::CTime::init();

		// Starts to run app
		run();

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

		// Const variables
		const float dt = 1.0f/60.0f;

		// Aux variables
		float newElapsedTime = 0;
		float accumulatedDt = 0;
		float accumulatedSecond = 0;
		float gameTime = 0;
		unsigned int frames = 0;
		
		while (!exit)
		{
			newElapsedTime = CTime::getInstance().elapsedTime(); // Get the elapsed time
			accumulatedDt += newElapsedTime;
			accumulatedSecond += newElapsedTime;
			gameTime += newElapsedTime;

			while (accumulatedDt >= dt)
			{
				// tick(dt)
				++frames;
				accumulatedDt -= dt;
			}

			while (accumulatedSecond >= 1)
			{
				DarcUtilities::darcLog(DarcUtilities::ENGINE, "Frames = " + std::to_string(frames));
				DarcUtilities::darcLog(DarcUtilities::ENGINE, "Game Time = " + std::to_string(gameTime));
				frames = 0;
				accumulatedSecond -= 1;
			}
			
			// GraphicsTick
		}

	} // run

};