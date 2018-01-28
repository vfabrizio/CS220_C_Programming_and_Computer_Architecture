#ifndef _MACROS_H
#define _MACROS_H

#define BIT_MASK(n) ( (1UL << (n)) - 1 )
#define TEST_IF_ANY_SET(v, start, end) ( ((v >> end) & BIT_MASK(start-end)) > 0 )
#define TEST_IF_ALL_SET(v, start, end) ( ((v >> end) & BIT_MASK(start-end)) == BIT_MASK(start-end) )

#endif