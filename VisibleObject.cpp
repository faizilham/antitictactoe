#include "headers.h"
#include "VisibleObject.h"

VisibleObject::VisibleObject()
: _visible(true), _isLoaded(false)
{}

VisibleObject::~VisibleObject() {}

void VisibleObject::Load()
{
    _isLoaded = true;
}

void VisibleObject::Draw(sf::RenderWindow &window)
{
    if(_isLoaded && _visible)
    {
        window.Draw(_sprite);
    }
}
void VisibleObject::SetPosition(float x, float y)
{
  if(_isLoaded)
  {
    _sprite.SetPosition(x,y);
    _boundingBox.Left = x;
    _boundingBox.Right = x + _sprite.GetSize().x;
    _boundingBox.Top = y;
    _boundingBox.Bottom = y + _sprite.GetSize().y;
  }
}
std::string VisibleObject::getName()
{
    return _objName;
}
void VisibleObject::Update(float elapsedTime){

}
