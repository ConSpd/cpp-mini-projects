#include "Developer.h"
#include <iostream>
#include <string>

Developer::Developer(char* Name,int Code,std::string Email){
    this->Name = Name;
    this->Code = Code;
    this->Email = Email;
}

Developer::Developer(){};

void Developer::Show(){
    std::cout << "Name: " << Name << std::endl;
    std::cout << "Code: " << Code << std::endl;
    std::cout << "Email: " << Email << std::endl;
}

Developer::~Developer(){}