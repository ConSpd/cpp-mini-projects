#include "AppSystem.h"
#include "Application.h"
#include "Game.h"
#include "DeskApp.h"
#include "Developer.h"
#include "Rating.h"
#include <vector>

int main(int argc,char** argv){
    AppSystem app;

    // Προσθήκη Κατασκευαστή
    char codedev[] = "Microsoft";
    Developer dv(codedev,1594,"microsoft@yahoo.com");
    char codedev1[] = "Blizzard";
    Developer dv2(codedev1,6575,"blizzard@gmail.com");
    app.addDeveloper(dv);
    app.addDeveloper(dv2);
    
    // Προσθήκη Παιχνιδιού
    char code[] = "46787";
    Game g1(code,"Doom",11,dv2,13.56,true,"Action");
    char code1[] = "684351";
    Game g2(code1,"COD",15,dv2,15.56,true,"Mystery");
    char code2[] = "359842";
    Game g3(code2,"Minecraft",8,dv2,11.56,true,"Creative");
    char code31[] = "115244";
    Game g4(code31,"Tetris",7,dv2,0,false,"Retro");
    app.addNewGame(g1);
    app.addNewGame(g2);
    app.addNewGame(g3);
    app.addNewGame(g4);
    
    // Προσθήκη Desktop Application
    std::vector<std::string> v;
    v = {"txt","pdf","html"};
    char code3[] = "321654";
    DeskApp dsk1(code3,"VIM",11,dv,14.5,v);
    app.addNewDeskApp(dsk1);    
    v = {"doc","ppt"};
    char code4[] = "653841";
    DeskApp dsk2(code4,"Gedit",5,dv,0,v);
    app.addNewDeskApp(dsk2);
    v = {"txt",};
    char code5[] = "358475";
    DeskApp dsk3(code5,"Notepad",6,dv,0,v);
    app.addNewDeskApp(dsk3);        

    // Προσθήκη Rating και αξιολόγιση εφαρμογών
    Rating r1("Kostas","Tough Game",3.5);
    Rating r2("Nikos","Good Graphics",4.7);
    Rating r3("Elena","Useful App",4.5);
    Rating r4("Ioanna","Nice Plot",4.1);
    Rating r5("Kostas","Must Have",5);
    Rating r6("Kostas","Amazing!",5);
    app.addRating(r1,g1);
    app.addRating(r2,g2);
    app.addRating(r3,dsk1);
    app.addRating(r4,g3);
    app.addRating(r5,dsk1);
    app.addRating(r6,g2);

    // Αλλαγή Name, Price & Code σε Application
    char code41[] = "123456";
    app.changeCode(dsk1,code41);
    app.changeName(g2,"Counter Strike");
    app.changePrice(g2,5.0);

    // Επιστροφή δωρεάν εφαρμογών
    std::cout <<"List of Free DeskApps: " << std::endl;
    std::cout <<"----------------------" << std::endl;
    app.freeApps();
    for(int i=0;i<app.freeApps().size();i++)
        app.freeApps()[i]->Show();
    

    // Επιστροφή Κορυφαίων Παιχνιδιών (Stars > 4)
    std::cout <<"List of Top Games: " << std::endl;
    std::cout <<"------------------" << std::endl;
    app.topGames();
    for(int i=0;i<app.topGames().size();i++)
        app.topGames()[i]->Show();


    // Διαγραφή Κατασκευαστή
    std::cout << "---------\nAll Apps:\n" << "---------" << std::endl;
    app.Show();
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Apps After Deleting Developer:" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    app.deleteDeveloper(dv);
    app.Show();

    // Report σε Stream
    std::cout << "---------\nRatings:\n" << "---------" << std::endl;
    app.report(std::cout,g1);
    std::cout << std::endl;
    app.report(std::cout,g2);
    std::cout << std::endl;
    app.report(std::cout,dsk1);

    // Εξαγωγή σε Αρχείο
    app.exportData();
}
