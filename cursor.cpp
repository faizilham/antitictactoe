#include "headers.h"
#include "cursor.h"
#include "game.h"

Cursor::Cursor()
{
    _objName = "_cursor";
}


Cursor::~Cursor() {}

void Cursor::Load(){
    _sprite.SetImage(game::GetLoadedImage("cursordefault"));

    _boundingBox.Left = 0;
    _boundingBox.Right = _sprite.GetSize().x;
    _boundingBox.Top = 0;
    _boundingBox.Bottom = _sprite.GetSize().y;

    _isLoaded = true;
}

void Cursor::Update(float elapsedTime){
    float mouseX = game::GetInput().GetMouseX();
    float mouseY = game::GetInput().GetMouseY();

    SetPosition(mouseX, mouseY);
    if (mouseX == 0 || mouseX == game::windowWidth - 1 || mouseY == 0 || mouseY == game::windowHeight - 1)
    {
        _visible = false;
    }else{
        _visible = true;
    }

}
