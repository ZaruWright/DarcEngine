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

#include "Application/DarcApplication.h"

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

	void CEngine::init(const DarcGraphics::GraphicEngines &graphicEngine, DarcApplication::IDarcApplication& app)
	{
		DarcUtilities::darcLog(DarcUtilities::ENGINE, std::string("Initializing Darc Engine..."));

		// Set the Graphic Engine that we want to use.
		if (graphicEngine == DarcGraphics::GraphicEngines::OPENGL)
			DarcGraphics::COpenGl::getInstance();
		else if (graphicEngine == DarcGraphics::GraphicEngines::OGRE3D)
			DarcGraphics::COgre::getInstance();

		// Init Graphic Engine.
		DarcGraphics::CGraphics::getInstance()->init();

		// Set the "App engine" from the user and call to the init
		_app = &app;
		_app->init();

		// The last thing we do is init the Time.
		DarcEngine::CTime::init();

		// Starts to run app
		//run();

	} // init

	void CEngine::release()
	{
		DarcUtilities::darcLog(DarcUtilities::ENGINE, std::string("Release Darc Engine..."));

		_app->release();
		DarcGraphics::CGraphics::getInstance()->release();

		// Set to nullptr variables
		_app = nullptr;

	} // release

	void CEngine::run()
	{

		DarcGraphics::CGraphics* graphics = DarcGraphics::CGraphics::getInstance();

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
		_exit = false;
		
		while (!_exit)
		{
			newElapsedTime = CTime::getInstance().elapsedTime(); // Get the elapsed time
			accumulatedDt += newElapsedTime;
			accumulatedSecond += newElapsedTime;
			gameTime += newElapsedTime;

			while (accumulatedDt >= dt)
			{
				// tick(dt)
				_app->run(dt);
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
			
			// Update graphics
			graphics->tick();

			if (graphics->closedWindow())
				_exit = true;

		}

	} // run

};