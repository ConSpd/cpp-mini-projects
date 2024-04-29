#include <iostream>
#include <fstream>
#include "AppSystem.h"

AppSystem::AppSystem(){};

void AppSystem::addNewGame(Game& x)
{   
    Apps.push_back(&x); // Προσθέτει στον πίνακα Apps το παιχνίδι
    Apps.at(Apps.size() - 1)->Type = 1;  // Τype = 1 για να ξεχωρίζει τα Games απο τα Αpps. 
}

void AppSystem::addNewDeskApp(DeskApp &x){
    Apps.push_back(&x); // Προσθετει στον πίνακα Apps την εφαρμογή
    Apps.at(Apps.size() - 1)->Type = 2; // Τype = 1 για Game, Τype = 2 για Αpp
}

void AppSystem::Show(){    //Εμφανίζει τα ονόματα των εφαρμογών που έχει (Για διευκόλυνση)
    for (int i=0;i<Apps.size();i++)
        std::cout << Apps[i]->Name << std::endl;
}

void AppSystem::addDeveloper(Developer &x){    
    Devs.push_back(&x);
}

void AppSystem::addRating(Rating &r,Application &app){
    app.Rates+=r.Stars; // To attribute Rates είναι ένα sum των αστεριών
    app.Stars.push_back(r.Stars); // Το attribute Stars είναι πίνακας με τα αστέρια
    app.numOfRatings++; // Πόσες αξιολογίσεις έχει συνολικά
    app.Rating.push_back(r.Comments); // Προσθήκη σχολίων
    r.AppCode = app.Code; // Aποθηκεύει τον κωδικό εφαρμογής για ανάκτηση απο αρχείο
    r.App = &app; // Σε ποιο app έγινε ο σχολιασμός
    Raters.push_back(&r);
}

void AppSystem::changeCode(Application &x,char* Code){
    x.Code = Code;
}
void AppSystem::changeName(Application &x,std::string Name){
    x.Name = Name;
}
void AppSystem::changePrice(Application &x,float Price){
    x.Price = Price;
}

std::vector<Application*> AppSystem::freeApps(){
    std::vector<Application*> freeApp;
    for(int i=0;i<Apps.size();i++){        
        if((Apps[i]->Price == 0) && (Apps[i]->Type == 2)) // Αν η τιμή είναι 0 && το App είναι Type 2 δηλαδή εφαρμογή
            freeApp.push_back(Apps[i]);
    }
    return freeApp; // Επιστρέφει τον vector που δημιουργήσαμε
}

std::vector<Application*> AppSystem::topGames(){
    std::vector<Application*> topG;
    for(int i=0;i<Apps.size();i++){ // Περνάει απο όλα τα Apps
        if(Apps[i]->Type == 1){ // Ελέγχει αν το App είναι Game
            if((Apps[i]->Rates / Apps[i]->numOfRatings)>4)
                topG.push_back(Apps[i]);
        }
    }
    return topG;
}

AppSystem::~AppSystem(){}

void AppSystem::deleteDeveloper(Developer &x){
    for (int i=0;i<Apps.size();i++){
        if (x.Code == Apps[i]->Dev->Code){
            Apps.erase(Apps.begin()+i);
            i--;
        }
    }
}

void AppSystem::report(std::ostream &x,Application &appl){
    if(appl.Type == 1){ // Ελέγχει αν η εφαρμογή είναι Game
        std::cout << "Game - " << appl.Name << " - Rating: " << std::endl;
        for(int i=0;i < appl.Stars.size();i++){ // appl.Stars είναι το vector με τα αστέρια του object
            x << appl.Stars[i] << " Stars, \"" << appl.Rating[i] << "\"" << std::endl;
        }
    }else{
        std::cout << "Desktop Application - " << appl.Name << " - Rating: " << std::endl;
        for(int i=0;i < appl.Stars.size();i++){
            x << appl.Stars[i] << " Stars, \"" << appl.Rating[i] << "\"" << std::endl;
        }
    }    
}

void AppSystem::exportData(){
    
    try{    
        std::ofstream devFile("devData.txt",std::ios::out|std::ios::trunc);
        std::ofstream ratingFile("ratingData.txt",std::ios::out|std::ios::trunc);
        std::ofstream gameFile("gameData.txt",std::ios::out|std::ios::trunc);
        std::ofstream appFile("appData.txt",std::ios::out|std::ios::trunc);        
        if(!devFile.is_open()) throw 1;
        if(!ratingFile.is_open()) throw 1;
        if(!gameFile.is_open()) throw 1;
        if(!appFile.is_open()) throw 1;

        for(int i=0;i<Devs.size();i++) // Εξαγωγή των Developers
        devFile << Devs[i]->Code << " " << Devs[i]->Name << " " << Devs[i]->Email << std::endl;
        
        for (int i=0;i<Raters.size();i++){ // Των Σχολίων
            Raters[i]->toString(ratingFile);
        }
        
        
        for(int i=0;i<Apps.size();i++){ // Των Applications, επίσης κοιτάει για το αν το app είναι game ή deskapp ώστε να αποθηκευτούν σε διαφορετικά αρχεία
            if(Apps[i]->Type == 1){         
                Apps[i]->toString(gameFile);   
                gameFile << std::endl;
            }else{
                Apps[i]->toString(appFile);
                appFile << std::endl;
            }
        }

        devFile.close();
        ratingFile.close();
        gameFile.close();
        appFile.close();    
    }catch(int &x){
        std::cout << "Could not open file, error: " << x << std::endl;
    }
}

/*** Import Data αλλά δεν έχει υλοποιηθεί λειτουργία */ 
void AppSystem::importData(){
    try{
        std::ifstream devFile("devData.txt",std::ios::in);
        std::ifstream ratingFile("ratingData.txt",std::ios::in);
        std::ifstream gameFile("gameData.txt",std::ios::in);
        std::ifstream appFile("appData.txt",std::ios::in);
        if(!devFile.is_open()) throw 1;
        if(!ratingFile.is_open()) throw 1;
        if(!gameFile.is_open()) throw 1;
        if(!appFile.is_open()) throw 1;

        devFile.close();
        ratingFile.close();
        gameFile.close();
        appFile.close();
    }catch(int &x){
        std::cout << "Can't open file, error:" << x <<std::endl;
    }
    
    
    
    
    

}