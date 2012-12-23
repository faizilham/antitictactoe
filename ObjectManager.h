#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include "VisibleObject.h"

class ObjectManager{

public:
    ObjectManager();
    ~ObjectManager();
    void Add(std::string name, VisibleObject *gameObject);
    void Remove(std::string name);
    int Count() const;
    VisibleObject* Get(std::string name) const;
    void DrawAll(sf::RenderWindow &window);
    void UpdateAll(float elapsedTime);

private:
    typedef std::map<std::string, VisibleObject*> ObjMap; //map
    typedef std::pair<std::string, VisibleObject*> MapItem; //item

    ObjMap _gameObjects;

    struct GameObjectDeallocator
    {
        void operator()(const MapItem &p) const
        {
            delete p.second;
        }
    };

};

#endif
