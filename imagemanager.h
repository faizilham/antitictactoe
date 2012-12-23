#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H

#include <SFML/Graphics.hpp>

class ImageManager{

public:
    ImageManager();
    ~ImageManager();
    void Add(std::string name, sf::Image *img);
    void Remove(std::string name);
    int Count() const;
    sf::Image* Get(std::string name) const;

private:
    typedef std::map<std::string, sf::Image*> ImgMap; //map
    typedef std::pair<std::string, sf::Image*> MapItem; //item

    ImgMap _images;

    struct ImageDeallocator
    {
        void operator()(const MapItem &p) const
        {
            delete p.second;
        }
    };
};

#endif
