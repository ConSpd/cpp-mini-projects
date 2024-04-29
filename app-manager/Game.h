#ifndef Game_h
#define Game_h

#include <iostream>
#include <string>
#include "Application.h"
#include "Developer.h"


class Game:public Application{
    private:
        bool isOnline; // Είναι Online
        std::string Genre; // Είδος
    public:
        Game(char*, std::string,int,Developer&,float,bool,std::string);
        ~Game();
        void Show();
        void toString(std::ostream&);
        friend class AppSystem;
};
#endif