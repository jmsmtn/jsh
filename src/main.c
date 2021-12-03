/**
 * @file main.c
 * @author James Martin
 * @brief program entrypoint
 */

#define DEBUG

#include "main.h"

int main(int argc, char const *argv[])
{
    if (argc == 1) // no arguments - go into interactive mode
    {
        DEBUG_PRINTF(("DEBUG: main(): argc is %d - this should trigger interactive mode.\n", argc));
        shell();
    }
    return 0;
}
