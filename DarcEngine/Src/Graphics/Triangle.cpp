//                                               
//   _____     _             _                   
//  |_   _|___|_|___ ___ ___| |___   ___ ___ ___ 
//    | | |  _| | .'|   | . | | -_|_|  _| . | . |
//    |_| |_| |_|__,|_|_|_  |_|___|_|___|  _|  _|
//                      |___|           |_| |_|  
//						
//	Ascii Art (Rectangles) from: http://patorjk.com/software/taag/
//
//	Author: ZaruWright
//

#include "Triangle.h"

#include "Utilities/Log.h"

#include "GLFW/glfw3.h"

namespace DarcGraphics
{
	CTriangle::CTriangle(const std::string& name) : IEntity(name) {}

	void CTriangle::draw()
	{
		glBegin(GL_TRIANGLES);
		glColor3f(1.f, 0.f, 0.f);
		glVertex3f(-0.6f, -0.4f, 0.f);
		glColor3f(0.f, 1.f, 0.f);
		glVertex3f(0.6f, -0.4f, 0.f);
		glColor3f(0.f, 0.f, 1.f);
		glVertex3f(0.f, 0.6f, 0.f);
	}
}