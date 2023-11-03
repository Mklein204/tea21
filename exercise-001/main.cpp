#include <fmt/chrono.h>
#include <fmt/format.h>

#include <iostream>
#include <random>

#include "CLI/CLI.hpp"
#include "config.h"

// .bss segment
int foo;
int bss_c;

// .data segment
int data = 4711;
int data_new = 4096;

// .rodata segment
const int rodata = 42;
const int rodata_new = 128;

auto main(int argc, char **argv) -> int
{
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */

    int bsp;
    fmt::print("Value of variable foo {} address of variable foo {}\n",foo, fmt::ptr(&foo) );
    fmt::print("Value of variable bbs_c {} address of variable bss_c {}\n",bss_c, fmt::ptr(&bss_c) );
    fmt::print("Value of variable data {} address of variable data {}\n",data, fmt::ptr(&data) );
    fmt::print("Value of variable data_new {} address of variable data_new {}\n",data_new, fmt::ptr(&data_new) );
    fmt::print("Value of variable rodata {} address of variable rodata {}\n",rodata, fmt::ptr(&rodata) );
    fmt::print("Value of variable rodata_new {} address of variable rodata_new {}\n",rodata_new, fmt::ptr(&rodata_new) );
    fmt::print("Value of variable bsp {} address of variable bsp {}\n",bsp, fmt::ptr(&bsp) );
    return 0; /* exit gracefully*/
}
