#include "cgate/cgate.hpp"

#include "SDL2/SDL_platform.h"

#include <stdio.h>

int main(int argc, char** argv)
{
    cgate::LoggerFactory::createConsoleLogger("file1");
    cgate::LoggerFactory::createConsoleLogger("file2");
    cgate::LoggerFactory::fatal(0, "FATAL ERROR : %s", "I am to good for this shit !!!");

    getchar();
    return 0;
}
