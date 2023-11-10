#include <fmt/chrono.h>
#include <fmt/format.h>

#include <chrono>
#include "CLI/CLI.hpp"
#include "config.h"

auto main(int argc, char **argv) -> int
{
    auto count = 20;
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */

    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c,--count",count, fmt::format("Create a vector with the given size default: {}", count));
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }
    std::vector<int> data(count);

    fmt::print("Created a vector with {} elements \n\n",count);

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */

    /* INSERT YOUR CODE HERE */

    //std::srand(std::time(nullptr));
    //int random_variable = std::rand();

    for (int i=0; i < data.size(); i++)
    {
        data[i] = rand()%100;
    }
    //fmt::print("The vector:\n[{}]\n ",fmt::join(data, ", "));

    auto start = std::chrono::system_clock::now();
    std::sort(data.begin(),data.end());
    auto end = std::chrono::system_clock::now;

    //fmt::print("The vector:\n[{}]\n ",fmt::join(data, ", "));
    
    //auto elapsed = end - start;
    //auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
    //fmt::print("Time for sort:\n[{}]\n ",end);
    return 0; /* exit gracefully*/
}
