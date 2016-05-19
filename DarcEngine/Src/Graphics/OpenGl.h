//                                   
//   _____             _____ _   _   
//  |     |___ ___ ___|   __| | | |_ 
//  |  |  | . | -_|   |  |  | |_|   |
//  |_____|  _|___|_|_|_____|_|_|_|_|
//        |_|                        
//						
//	Ascii Art (Rectangles) from: http://patorjk.com/software/taag/
//
//	Author: ZaruWright
//
#ifndef GRAPHICS_OPENGL_H
#define GRAPHICS_OPENGL_H

#include "Graphics.h"
#include "Engine/Engine.h"

#include "GLFW/glfw3.h"

namespace DarcGraphics{

    class COpenGl : public CGraphics{
	public:
		/**
		Returns the class instance
		*/
		static COpenGl& getInstance();
    
	protected:
        /**
        Constructor by default.
        */
        COpenGl() = default;
        
        /**
        Destructor by default.
        */
        ~COpenGl() = default;
        
        /**
        OpenGl initialization.
        */
		bool init() override;

		/**
		Gives if OpenGl windows is open or not.
		*/
		bool closedWindow() override;

		/**
		To update an OpengL window we need to swap buffers and
		process the windows events.
		*/
		void updateWindow() override;

		/**
		OpenGl release
		*/
		void release() override;

		/**
		Update graphics
		*/
		void tick() override;

	private:
		GLFWwindow* _window = nullptr;
	};

}

#endif // GRAPHICS_OPENGL_H