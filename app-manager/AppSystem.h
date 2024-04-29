#ifndef AppSystem_h
#define AppSystem_h

#include <iostream>
#include "Application.h"
#include "Game.h"
#include "DeskApp.h"
#include "Developer.h"
#include "Rating.h"

class AppSystem{
    private:
        std::vector<Application*> Apps; // Πίνακας Εφαρμογών
        std::vector<Developer*> Devs; // Πίνακας Κατασκευαστών
        std::vector<Rating*> Raters; // Πίνακας αξιολογήσεων
    public:
        AppSystem();
        ~AppSystem();
        void addNewGame(Game&);
        void addNewDeskApp(DeskApp&);
        void addDeveloper(Developer&);
        void addRating(Rating&,Application&);
        void changeName(Application&,std::string);
        void changePrice(Application&,float);
        void changeCode(Application&,char*);
        std::vector<Application*> freeApps(); // Εμφάνιση δωρεάν εφαρμογών
        std::vector<Application*> topGames();  // Εμφάνιση κορυφαίων παιχνιδιών > 4 αστέρια
        void deleteDeveloper(Developer&); 
        void report(std::ostream&,Application&);
        void exportData(); // Serialize σε αρχείο
        void importData(); // Δεν έχει υλοποιηθεί
        void Show(); // Μέθοδος για διευκόλυνση που εμφανίζει τα στοιχεία στο stdout
};
#endif