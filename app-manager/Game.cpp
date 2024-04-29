#include <iostream>
#include "Game.h"

Game::Game(char* Code,std::string Name,int Min_Ver,Developer& newDev,float Price,bool isOnline,std::string Genre){
           
    this->Code = Code;    
    this->Name = Name;    
    this->Min_ver = Min_Ver;
    Dev = &newDev;
    this->Price = Price;    
    this->isOnline = isOnline;    
    this->Genre = Genre;
}

void Game::Show(){
    std::cout << "Code: " << Code << std::endl;
    std::cout << "Name: " << Name << std::endl;
    std::cout << "Minimum Version: " << Min_ver << std::endl;
    std::cout << "Price: " << Price << std::endl;
    std::cout << "Is Online: " << (bool)isOnline << std::endl;
    std::cout << "Genre: " << Genre << std::endl;
    std::cout << "Developer: " << Dev->Name << std::endl;
    std::cout << "---------" << std::endl;
}

void Game::toString(std::ostream& x){
    x << Code << " " << Name << " " << Min_ver << " " << Price << " ";
    x << Type << " " << isOnline << " " << Genre << " " << Dev->Code << " ";
}


Game::~Game(){};