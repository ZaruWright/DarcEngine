//                                 
//   _____         _           _   
//  |   __|___ ___|_|___ ___  | |_ 
//  |   __|   | . | |   | -_|_|   |
//  |_____|_|_|_  |_|_|_|___|_|_|_|
//            |___|                
//						
//	Ascii Art (Rectangles) from: http://patorjk.com/software/taag/
//
//	Author: ZaruWright
//
#ifndef ENGINE_ENGINE_H
#define ENGINE_ENGINE_H

#include "Graphics/Enumerators.h"

namespace DarcEngine{

	class CEngine{

	public:

		/**
		Returns the class instance
		*/
		static CEngine& getInstance();

		/**
		We do no not allow to copy the instance, we'll
		want have only one.
		*/
		CEngine(const CEngine &engine) = delete; // Disallowed to do a copy

		/**
		By the same reason of above, we do not allow the operator =.
		*/
		void operator=(const CEngine &engine) = delete; // Disallowed used the operator =
        
        /**
        Initialization of DarcEngine. Here we initialize the Graphics, Sounds, etc..
        */
		void init(const DarcGraphics::GraphicEngines &graphicEngine);

		/**
		Release all the parts of Darc Engine.
		*/
		void release();

		/**
		Starts to run the Darc Engine.
		*/
		void run();

	private:

		// Constructor by default. It is private because
		// you only can get the class instance from getInstance method.
		CEngine() = default;

		// Destructor by default
		~CEngine() = default;

		bool exit; // to exit from app

	};
}

#endif // ENGINE_ENGINE_H