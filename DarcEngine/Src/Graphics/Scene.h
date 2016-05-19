//                               
//   _____                   _   
//  |   __|___ ___ ___ ___  | |_ 
//  |__   |  _| -_|   | -_|_|   |
//  |_____|___|___|_|_|___|_|_|_|
//
//						
//	Ascii Art (Rectangles) from: http://patorjk.com/software/taag/
//
//	Author: ZaruWright
//
#ifndef GRAPHICS_SCENE_H
#define GRAPHICS_SCENE_H

#include <vector>

#include "Graphics/Entity.h"

namespace DarcGraphics
{
	class CScene{
	public:

		void addEntity(IEntity* entity);

		void tick();

	private:
		std::vector<IEntity*> _entities;
	}; // CScene
}

#endif // GRAPHICS_SCENE_H