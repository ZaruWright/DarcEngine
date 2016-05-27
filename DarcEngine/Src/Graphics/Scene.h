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

		/**
		Returns the class instance
		*/
		static CScene& getInstance();

		/**
		We do no not allow to copy the instance, we'll
		want have only one.
		*/
		CScene(const CScene &scene) = delete; // Disallowed to do a copy

		/**
		By the same reason of above, we do not allow the operator =.
		*/
		void operator=(const CScene &scene) = delete; // Disallowed used the operator =

		/**
		Add an entity to the scene.
		*/
		void addEntity(IEntity* entity);

		void tick();

	protected:

		CScene() = default;

		

	private:
		std::vector<IEntity*> _entities;

	}; // CScene
}

#endif // GRAPHICS_SCENE_H