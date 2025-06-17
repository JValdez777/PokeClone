//
// Created by Juan Valdez on 5/20/25.
//

#ifndef MANAGER_H
#define MANAGER_H
#include <string>
#include <map>
template <typename Enum,typename Data>
class Manager
{
    static inline std::map<Enum, Data> _dataMap;
    static void load(Enum image);
    virtual std::string getPath(Enum image) = 0;
public:
    const Data& get(Enum image);

};

///example class
// class TextureManager : public Manager<ImageEnum, sf::texture> {
//     std::string getPath(ImageEnum image);
// };
#include "Manager.cpp"
#endif //MANAGER_H
