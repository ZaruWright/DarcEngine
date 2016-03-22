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
#include <iostream>
#include "GL/glut.h"

#include "OpenGl.h"

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);

	glLoadIdentity();
	//glMatrixMode(GL_PROJECTION);
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glScalef(1.0, 2.0, 1.0);
	glutWireCube(1.0);
	glFlush();
}

namespace DarcGraphics{

	COpenGl& COpenGl::getInstance()
	{
		static COpenGl instance; // Guaranteed to be destroyed.
		// Instantiated on first use.
		return instance;
	} // getInstance

	void COpenGl::init()
	{
		std::cout << "Initializing OpenGl..." << std::endl;
		int argcp = 1;
		char* argv = {"DarcEngine"};
		glutInit(&argcp, &argv);
		std::cout << "GlutInit..." << std::endl;
		glutInitWindowSize(500, 500);
		glutInitWindowPosition(100, 100);
		glutCreateWindow("Init my first Window");
		glutDisplayFunc(display);
		glutMainLoop();
		std::cout << "There is my first window!" << std::endl;

	}

}
