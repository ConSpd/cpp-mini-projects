#include "Rating.h"
#include <iostream>
#include <string>

Rating::Rating(std::string userName,std::string Comments,float Stars){
    this->userName = userName;
    this->Comments = Comments;
    this->Stars = Stars;
}

void Rating::Show(){
    std::cout << userName << std::endl;
    std::cout << Comments << std::endl;
    std::cout << Stars << std::endl;
    App->Show(); 
}

void Rating::toString(std::ostream &x){
    x << userName << " " << AppCode << " " << Stars << " " << std::endl;
    x << Comments << std::endl;
}

Rating::~Rating(){};