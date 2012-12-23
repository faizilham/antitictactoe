#include "headers.h"
#include "game.h"
#include "cursor.h"

void game::start(){
    if (_state != game::uninitialized)
        return;

    _gameWindow.Create(sf::VideoMode(windowWidth,windowHeight,32), "Anti Tic-Tac-Toe",sf::Style::Close);
    _gameWindow.ShowMouseCursor(false);
    _state = game::playing;


    //load images
    sf::Image* img;

    img = new sf::Image;
    img->Create(70,70,sf::Color(200,200,200));
    _images.Add("buttonup", img);

    img = new sf::Image;
    img->Create(70,70,sf::Color(100,100,100));
    _images.Add("buttonhover", img);

    img = new sf::Image;
    img->Create(70,70,sf::Color(255,0,0));
    _images.Add("buttonred", img);

    img = new sf::Image;
    img->LoadFromFile("assets/cursordefault.png");
    _images.Add("cursordefault", img);

    img = new sf::Image;
    img->LoadFromFile("assets/icon.png");
    _gameWindow.SetIcon(32,32,img->GetPixelsPtr());
    _images.Add("icon", img);

    //load objects
    VisibleObject *fieldptr;

    fieldptr = new Cursor();
    fieldptr->Load();

    _gameObjects.Add(fieldptr->getName(), fieldptr);

    for (int i = 0; i < 25; i++)
    {
        fieldptr = new field(i+1);
        fieldptr->Load();
        fieldptr->SetPosition(210 + (80 * (i % 5)), 70 + 80 * ((int) i / 5));
        _gameObjects.Add(fieldptr->getName(), fieldptr);

        board[i] = false;
    }

    //texts
    defaultFont.LoadFromFile("assets/CALIBRI.TTF");
    subtext.SetFont(defaultFont);
    subtext.SetSize(36);
    subtext.SetPosition(320, 500);
    subtext.SetColor(sf::Color(0,0,0));

    turn = 1;
    subtext.SetText("Player 1 Turn");
    while (!isExiting()){
        gameloop();

    }
    _gameWindow.Close();
}

bool game::isExiting(){
    return _state==game::exiting;
}

void game::gameloop(){
    sf::Event e;

    while(_gameWindow.GetEvent(e))
    {
        switch(_state){
            case game::playing:
                //update screen

                _gameWindow.Clear(sf::Color(255,255,255));
                _gameObjects.UpdateAll(0);
                _gameWindow.Draw(subtext);
                _gameObjects.DrawAll(_gameWindow);

                _gameWindow.Display();

                if(isEnding()){
                    _state = game::ending;

                    int i;
                    for (i=0;i<25;i+=5){
                        if (board[i] && board[i+1] && board[i+2] && board[i+3] && board[i+4])
                            setRed(i, i+1, i+2, i+3, i+4);
                    }

                    //cek vertikal
                    for (i=0;i<5;i++){
                        if (board[i] && board[i+5] && board[i+10] && board[i+15] && board[i+20])
                            setRed(i, i+5, i+10, i+15, i+20);
                    }

                    //cek diagonal
                    if (board[0] && board[6] && board[12] && board[18] && board[24])
                        setRed(0, 6, 12, 18, 24);

                    if (board[4] && board[8] && board[12] && board[16] && board[20])
                        setRed(4, 8, 12, 16, 20);
                }

                if(e.Type == sf::Event::Closed){
                   _state = game::exiting;
                }


            break;

            case game::ending:
                //update screen

                _gameWindow.Clear(sf::Color(255,255,255));
                _gameObjects.UpdateAll(0);
                _gameWindow.Draw(subtext);
                _gameObjects.DrawAll(_gameWindow);

                _gameWindow.Display();

                if(GetInput().IsKeyDown(sf::Key::Escape)){
                    _state = game::playing;
                    int i; field *fieldptr;

                    for (i=0;i<25;i++){
                        fieldptr = (field*) _gameObjects.Get("field" + IntToStr(i+1));
                        fieldptr->clicked=false;
                        board[i] = false;
                    }

                    turn = 1;
                    subtext.SetText("Player 1 Turn");
                    subtext.SetPosition(320, 500);

                }

                if(e.Type == sf::Event::Closed){
                   _state = game::exiting;
                }


            break;
        }
    }
}
const sf::Input& game::GetInput(){
    return _gameWindow.GetInput();
}
const sf::Image& game::GetLoadedImage(std::string name){
    return *(_images.Get(name));
}

bool game::isEnding(){
    int i;

    //cek horizontal
    for (i=0;i<25;i+=5){
        if (board[i] && board[i+1] && board[i+2] && board[i+3] && board[i+4])
            return true;
    }

    //cek vertikal
    for (i=0;i<5;i++){
        if (board[i] && board[i+5] && board[i+10] && board[i+15] && board[i+20])
            return true;
    }

    //cek diagonal
    if (board[0] && board[6] && board[12] && board[18] && board[24])
        return true;

    if (board[4] && board[8] && board[12] && board[16] && board[20])
        return true;

    return false;
}
bool game::isPlaying(){
    return _state == game::playing;
}
void game::setRed(int field1, int field2, int field3, int field4, int field5){
    field *fieldptr;

    fieldptr = (field*) _gameObjects.Get("field" + IntToStr(field1 + 1));
    fieldptr->setRed();

    fieldptr = (field*) _gameObjects.Get("field" + IntToStr(field2 + 1));
    fieldptr->setRed();

    fieldptr = (field*) _gameObjects.Get("field" + IntToStr(field3 + 1));
    fieldptr->setRed();

    fieldptr = (field*) _gameObjects.Get("field" + IntToStr(field4 + 1));
    fieldptr->setRed();

    fieldptr = (field*) _gameObjects.Get("field" + IntToStr(field5 + 1));
    fieldptr->setRed();

}
void game::nextTurn()
{
    turn = (turn % 2) + 1;
    if (isEnding()){
        subtext.SetPosition(130, 500);
        subtext.SetText("Player " + IntToStr(turn) + " Win! Press Escape To Restart");
    }else{
        subtext.SetText("Player " + IntToStr(turn) + " Turn");
    }
}


game::gameState game::_state = game::uninitialized;
sf::RenderWindow game::_gameWindow;
ObjectManager game::_gameObjects;
ImageManager game::_images;
bool game::board[25];
sf::Font game::defaultFont;
sf::String game::subtext;
int game::turn;
