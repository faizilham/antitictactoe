#include "headers.h"
#include "field.h"
#include "game.h"

field::field(int id)
{
    field_no = id - 1;
    clicked = false;
    _objName = "field" + IntToStr(id);
}


field::~field() {}

void field::Load(){
    _sprite.SetImage(game::GetLoadedImage("buttonup"));

    _boundingBox.Left = 0;
    _boundingBox.Right = _sprite.GetSize().x;
    _boundingBox.Top = 0;
    _boundingBox.Bottom = _sprite.GetSize().y;

    _isLoaded = true;
}

void field::Update(float elapsedTime){
    float mouseX = game::GetInput().GetMouseX();
    float mouseY = game::GetInput().GetMouseY();

    sf::Vector2<float> pos = sf::Vector2f(mouseX, mouseY);

    if (game::isPlaying()){
        if (pos.x > _boundingBox.Left && pos.x < _boundingBox.Right && pos.y > _boundingBox.Top && pos.y < _boundingBox.Bottom){
            _sprite.SetImage(game::GetLoadedImage("buttonhover"));

            if(game::GetInput().IsMouseButtonDown(sf::Mouse::Left) && !clicked){
                clicked = true;
                game::board[field_no] = true;
                game::nextTurn();
            }
        }else{
            if (!clicked)
                _sprite.SetImage(game::GetLoadedImage("buttonup"));
            else
                _sprite.SetImage(game::GetLoadedImage("buttonhover"));
        }
    }
}
void field::setRed(){
    _sprite.SetImage(game::GetLoadedImage("buttonred"));
}
