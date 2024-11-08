#include <fmt/chrono.h>
#include <fmt/format.h>

//# define  MAX_NAME_LENGTH 25
const unsigned int MAX_NAME_LENGTH = 25; //Alternative zu Zeile 4, ist im vergleich dazu Typsicher

struct Person{
    unsigned int alter;
    float gewicht;
    char name[25];
};
auto main(int argc, char** argv) -> int
{
    Person paul;
    paul.gewicht = 47.2;
    paul.alter = 14;


    fmt::print("Hello, {}!\n", argv[0]);
    fmt::print("Paul ist {} Jahre alt! \n", paul.alter);

    Person* pPers;
    pPers = &paul;
    fmt::print("Die Person auf die der Zeiger pPers zeigt ist {} Jahre alt! \n", pPers->alter); /bei Zeiger und strukturen mit -> operieren dadurch auf Zeigervariablen zugreifen möglich/
    
    Person paula = {18, 57.0, "Paula"};
    fmt::print("Paula ist {} Jahre alt! \n", paula.alter); /18/
    pPers = &paula;
    fmt::print("Die Person auf die der Zeiger pPers zeigt ist {} Jahre alt! \n", pPers->alter); 
    /*jzt kommt 18 raus, da zeiger auf paula gewechselt wurde*/
    
    // paul.name = "Paul"; geht nicht
    char* pName = "Paul jr.";
    strncpy(paul.name, "Paul", 25); //paul.name gleich wie &paul.name[0]
    fmt::print("Der Name von Paul ist {}", paul.name); 

    *pPers = paul;
    fmt::print("Die Person auf die der Zeiger pPers zeigt ist {} Jahre alt! \n", pPers->alter);
    return 0; /* exit gracefully*/
}