#include <fmt/chrono.h>
#include <fmt/format.h>


auto main(int argc, char** argv) -> int
{
    fmt::print("Hello, {}!\n", argv[0]);
    return 0; /* exit gracefully*/
}
