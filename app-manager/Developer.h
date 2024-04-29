#ifndef Developer_h
#define Developer_h

#include <iostream>
#include <string>
#include <vector>

class Application;

class Developer{
    private:
        char* Name;
        int Code;
        std::string Email;
    public:
        Developer(char*,int,std::string);
        Developer();
        ~Developer();
        void Show();
        friend class AppSystem;
        friend class Game;
        friend class DeskApp;
};

#endif