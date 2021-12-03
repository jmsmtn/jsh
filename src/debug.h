/**
 * @file debug.h
 * @author James Martin (jamesmartin@fastmail.com)
 * @brief debug helpers
 * 
 */

#ifdef DEBUG
#define DEBUG_PRINTF(x) printf x
#else
#define DEBUG_PRINTF(x) \
    do                  \
    {                   \
    } while (0)
#endif