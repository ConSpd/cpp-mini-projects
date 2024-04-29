#ifndef Application_h
#define Application_h

#include <iostream>
#include <string>
#include <vector>
#include "Developer.h"


class Application{
    protected:
        char* Code; // Κωδικός Εφαρμογής
        std::string Name; // Λεκτικό Εφαρμογής
        int Min_ver; // Ελάχιστη έκδοση Λογισμικού
        Developer* Dev; // Pointer σε Κατασκευαστή
        std::vector<std::string> Rating; // Πίνακας αξιολογίσεων
        std::vector<float> Stars; // Πίνακας αστεριών 
        float Rates;  // Σύνολο αστεριών για διευκόλυνση
        int numOfRatings; // Σύνολο αξιολογήσεων
        float Price; // Τιμή
        int Type; // Τύπος Εφαρμογής. 1 = Game, 2 = DeskApp
    public:
        friend class AppSystem;
        friend class Rating;
        Application();
        virtual void Show() = 0;    // Απλά για διευκόλυνση να εμφανίζει τα attributes
        virtual void toString(std::ostream&) = 0; // Η toString χρησιμοποιείται εδώ για να βγάλει με
        ~Application();                                // συγκεκριμένο τρόπο τα attributes του object σε αρχείο
};
#endif