#ifndef DeskApp_h
#define DeskApp_h

#include <iostream>
#include <string>
#include "Application.h"
#include <vector>

class DeskApp:public Application{
    private:
        std::vector<std::string> fileTypes; // Οι τύποι αρχείων που μπορεί να χρησιμοποιήσει
    public:
        friend class AppSystem;
        DeskApp(char*, std::string,int,Developer&,float,std::vector<std::string>);
        void Show();
        void toString(std::ostream&);
        ~DeskApp();

};
#endif