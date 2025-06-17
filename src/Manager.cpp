//
// Created by Juan Valdez on 5/20/25.
//
#ifndef MANAGER_CPP
#define MANAGER_CPP
#include "Manager.h"

template<typename Enum, typename Data>
void Manager<Enum, Data>::load(Enum image)
{
    // if (_dataMap.count(image) == 0)
    //     _dataMap.loadFromFile(getPath(image));
}

template<typename Enum, typename Data>
const Data & Manager<Enum, Data>::get(Enum image)
{
    load();
    return _dataMap.at(image);
}
#endif