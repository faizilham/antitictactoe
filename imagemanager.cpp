#include "headers.h"
#include "imagemanager.h"

ImageManager::ImageManager(){}

ImageManager::~ImageManager(){
    std::for_each(_images.begin(), _images.end(), ImageDeallocator());
}
void ImageManager::Add(std::string name, sf::Image *img)
{
    _images.insert(MapItem (name, img));
}
void ImageManager::Remove(std::string name)
{
    ImgMap::iterator result = _images.find(name);

    if (result!= _images.end()){
        delete result->second;
        _images.erase(result);
    }
}
int ImageManager::Count() const
{
    return _images.size();
}
sf::Image* ImageManager::Get(std::string name) const
{
    ImgMap::const_iterator result = _images.find(name);
    if (result == _images.end())
        return NULL;
    return result->second;
}
