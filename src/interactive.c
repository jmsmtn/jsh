/**
 * @file interactive.c
 * @author James Martin (jamesmartin@fastmail.com)
 * @brief main interactive shell
 */

#define DEBUG // define for DEBUG_PRINTF usage

#include "interactive.h"

/**
 * @brief main interactive shell
 * 
 * @return int 
 */
int shell()
{

    char input[GLOBAL_MAX_LINE]; // max line length
    char tmpchar;                // x is a char placeholder
    int place = 0;               // what pos are we in in the input line?

    while (1)
    {

        printf("%s", GLOBAL_PROMPT); // prompt here
        place = 0;

        while ((tmpchar = getchar()) != '\n') // read until the end of the line
        {

            if (place == GLOBAL_MAX_LINE) // sanity check for a line too long
            {
                fprintf(stderr, "ERROR! Line too long! Please don't exceed %d characters.\n", GLOBAL_MAX_LINE);
                exit(EXIT_FAILURE);
            }

            input[place] = tmpchar; // add the char to the line
            place++;
        }
        input[place] = '\0'; // terminate the string

        DEBUG_PRINTF(("DEBUG: shell(): it looks like you said: '%s'\n", input));
    }

    return 0;
}