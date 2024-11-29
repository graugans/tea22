#include <fmt/chrono.h>
#include <fmt/format.h>

#include "statemachine.h"

auto main(int argc, char** argv) -> int
{
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", argv[0]);

    Event_t test[] = {
        EV_ENDSCHALTER_OBEN,
        EV_TASTE,
        EV_ENDSCHALTER_UNTEN,
    };
    int i = 0;

    MyState_t* machine = myStatemachine_create();

    for (i = 0; i < sizeof(test) / sizeof(Event_t); i++)
    {
        myStatemachine_handle(machine, test[i]);
    }

    myStatemachine_free(machine);
    return 0; /* exit gracefully*/
}
