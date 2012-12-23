#include "headers.h"
#include "ObjectManager.h"

ObjectManager::ObjectManager() {}

ObjectManager::~ObjectManager()
{
    std::for_each(_gameObjects.begin(), _gameObjects.end(), GameObjectDeallocator());
}

void ObjectManager::Add(std::string name, VisibleObject *gameObject)
{
    _gameObjects.insert(MapItem (name, gameObject));
}

void ObjectManager::Remove(std::string name)
{
    ObjMap::iterator result = _gameObjects.find(name);

    if (result!= _gameObjects.end()){
        delete result->second;
        _gameObjects.erase(result);
    }

}

int ObjectManager::Count() const
{
    return _gameObjects.size();
}

VisibleObject* ObjectManager::Get(std::string name) const
{
    ObjMap::const_iterator result = _gameObjects.find(name);
    if (result == _gameObjects.end())
        return NULL;
    return result->second;
}

void ObjectManager::DrawAll(sf::RenderWindow &window)
{
    ObjMap::const_reverse_iterator i = _gameObjects.rbegin();

    while(i!=_gameObjects.rend()){
        i->second->Draw(window);
        i++;
    }
}

void ObjectManager::UpdateAll(float elapsedTime){
    ObjMap::const_iterator i = _gameObjects.begin();

    while(i!=_gameObjects.end()){
        i->second->Update(elapsedTime);
        i++;
    }
}
