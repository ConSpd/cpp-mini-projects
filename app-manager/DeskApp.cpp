#include <iostream>
#include "DeskApp.h"



DeskApp::DeskApp(char* Code,std::string Name,int Min_Ver,Developer& newDev,float Price,std::vector<std::string> List){
    this->Code = Code;
    this->Name = Name;
    this->Min_ver = Min_Ver;
    Dev = &newDev;
    this->Price = Price;
    for (int i=0;i<List.size();i++)
        fileTypes.push_back(List[i]);
}

void DeskApp::Show(){
    std::cout << "Code: "<< Code << std::endl;
    std::cout << "Name: " << Name << std::endl;
    std::cout << "Minimum Version: " << Min_ver << std::endl;
    std::cout << "Price: " << Price << std::endl;
    std::cout << "Types of supported files: ";

    for (int i=0;i<fileTypes.size();i++)
       std::cout << fileTypes[i] << " ";

    std::cout << "\nDeveloper: " << Dev->Name << std::endl;
    std::cout << "---------" << std::endl;    
}

void DeskApp::toString(std::ostream& x){
    x << Code << " " << Name << " " << Min_ver << " " << Price << " ";
    x << Type << " " << Dev->Code << " ";
    for(int i=0;i<fileTypes.size();i++)
        x << fileTypes[i] << " ";  
}
    
DeskApp::~DeskApp(){};