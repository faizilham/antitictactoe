#ifndef VISIBLEOBJECT_H
#define VISIBLEOBJECT_H

#include <SFML/Graphics.hpp>
#include <iostream>


class VisibleObject{

public:
    VisibleObject(); //constructor
    virtual ~VisibleObject(); //destructor
    virtual void Load();
    virtual void Draw(sf::RenderWindow &window);
    virtual void SetPosition(float x, float y);
    virtual void Update(float elapsedTime);
    std::string getName();
    bool _visible;

protected:
    sf::Sprite _sprite;
    sf::Rect<float> _boundingBox;
    std::string _objName;
    bool _isLoaded;

};

#endif
