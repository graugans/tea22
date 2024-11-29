#include <fmt/chrono.h>
#include <fmt/format.h>

#include "triangle.h"
//...
#include "triangle.h"

//#define MAX_NAME_LENGTH 25

const unsigned int MAX_NAME_LENGTH = 25;

struct Person {
    unsigned int alter;
    float gewicht;
    char name[MAX_NAME_LENGTH];
};

auto main(int argc, char** argv) -> int {
    Person paul;
    paul.gewicht = 47.3;
    paul.alter = 14;
    fmt::print("Hello, {}!\n", argv[0]);
    fmt::print("Paul ist {} Jahre alt!\n", paul.alter);

    Person* pPers;
    pPers = &paul;
    fmt::print("Die Person auf die der Zeiger pPers zeigt ist {} Jahre alt!\n",
        pPers->alter
    );
    Person paula = { 18, 57.0, "Paula"};
    fmt::print("Paula ist {} Jahre alt!\n", paula.alter);

    pPers = &paula;
    fmt::print("Die Person auf die der Zeiger pPers zeigt ist {} Jahre alt!\n",
        pPers->alter
    );

    //paul.name = "Paul";
    const char* pName = "Paul jr.";
    strncpy(paul.name,"Paul jr. der zweite",MAX_NAME_LENGTH);
    fmt::println("Der Name von Paul ist: {}",paul.name);

    paul = paula;
    fmt::println("Der Name von Paul ist: {}",paul.name);

    *pPers = paul;
     fmt::print("Die Person auf die der Zeiger pPers zeigt ist {} Jahre alt!\n",
        pPers->alter
    );

    Triangle* trig = newTriangle();

    fmt::println("Side a of the triangle trig {}",trig->side_a);
    fmt::println("Side a of the triangle trig {}",trig->side_b);
    fmt::println("Side c of the triangle trig {}",trig->side_c);

    // Speicherloch
    //trig = newTriangle();

    // Richtig
    freeTriangle(trig);
    trig = newTriangleWithValues(42,34,56);

    fmt::println("The perimeter is: {}", perimeter(trig));
    return 0; /* exit gracefully*/
}
