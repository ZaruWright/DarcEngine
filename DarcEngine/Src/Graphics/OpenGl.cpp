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

#include "OpenGl.h"

#include "Scene.h"

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

	bool COpenGl::init()
	{
		DarcUtilities::darcLog(DarcUtilities::GRAPHICS, std::string("Init OpenGl..."));

		// Initialize the library
		if (!glfwInit())
			return false;

		// Create a windowed mode window and its OpenGL context
		_window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
		if (!_window)
		{
			glfwTerminate();
			return false;
		}

		// Make the window's context current
		glfwMakeContextCurrent(_window);

		return true;
	} // init

	bool COpenGl::closedWindow()
	{
		return glfwWindowShouldClose(_window) == 1;
	} // closedWindow

	void COpenGl::repaintWindow()
	{
		float ratio;
		int width, height;

		glfwGetFramebufferSize(_window, &width, &height);
		ratio = width / (float)height;

		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
		glMatrixMode(GL_MODELVIEW);
	}

	void COpenGl::updateWindow()
	{
		// End painting
		glEnd();

		// Swap front and back buffers 
		glfwSwapBuffers(_window);

		// Poll for and process events 
		glfwPollEvents();
	} // updateWindow

	void COpenGl::release()
	{
		DarcUtilities::darcLog(DarcUtilities::GRAPHICS, std::string("Release OpenGl..."));

		// Delete OpenGl stuff
		glfwDestroyWindow(_window);
		glfwTerminate();

	} // release

	void COpenGl::tick()
	{
		repaintWindow();
		CScene::getInstance().tick();
		updateWindow();
	} // tick

}
