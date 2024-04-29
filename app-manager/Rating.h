#ifndef Rating_h
#define Rating_h

#include <iostream>
#include <string>
#include "Application.h"


class Rating{
    private:
        std::string userName;
        std::string Comments;
        float Stars;
        std::string AppCode; // Κωδικός εφαρμογής, χρειάζεται για να γίνει Serialize σε αρχείο μετα
        Application* App; // Pointer στην εφαρμογή την οποία έχει αξιολογίσει
    public:
        Rating(std::string,std::string,float);
        void Show();
        void toString(std::ostream&);
        ~Rating();
        friend class AppSystem;
};





#endif