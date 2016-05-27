//                                       
//   _____                               
//  |   __|___ ___ ___ ___   ___ ___ ___ 
//  |__   |  _| -_|   | -_|_|  _| . | . |
//  |_____|___|___|_|_|___|_|___|  _|  _|
//                              |_| |_|  
//						
//	Ascii Art (Rectangles) from: http://patorjk.com/software/taag/
//
//	Author: ZaruWright
//

#include "Scene.h"

#include "Utilities/Log.h"

namespace DarcGraphics
{

	CScene& CScene::getInstance()
	{
		static CScene instance; // Guaranteed to be destroyed.
		// Instantiated on first use.
		return instance;
	} // getInstance

	void CScene::addEntity(IEntity* entity)
	{
		// Only in debug check if there are entities with
		// the same name.
		#ifdef _DEBUG
		std::string entityName = entity->getName();
		for (IEntity* ent : _entities)
		{
			DarcUtilities::darcAssert(entityName != ent->getName(), std::string("You can't add two entities with the same name. CScene::addEntity"));
		}
		#endif

		// Add the entity
		_entities.push_back(entity);

	} // addEntity

	void CScene::tick()
	{
		for (IEntity* entity : _entities)
		{
			entity->draw();
		}
	} // tick
}