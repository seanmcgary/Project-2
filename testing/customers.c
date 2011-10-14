/*
** global Customer variables for test programs
**
*/
#include "types.h"

/*
** Some test customers
**
** Note the ordering - this keeps the compiler happy
*/

/* John Smith II */
Customer js2 = {    0, 0, "Smith, John", 5000, 0, 1235, 'S', 0 };

/* John Smith I */
Customer js1 = { &js2, 0, "Smith, John", 5000, 0, 1234, 'S', 0 };

/* Fred Smith II */
Customer fs2 = { &js1, 0, "Smith, Fred", 5000, 0, 2346, 'S', 0 };

/* Fred Smith I */
Customer fs1 = { &fs2, 0, "Smith, Fred", 5000, 0, 2345, 'S', 0 };

/* Tom Jones II */
Customer tj2 = { &fs1, 0, "Jones, Tom",  5000, 0,  121, 'J', 0 };

/* Tom Jones I */
Customer tj1 = { &tj2, 0, "Jones, Tom",  5000, 0,  120, 'J', 0 };

/* Pointer to first customer in list */
Customer *customers = &tj1;	/* Tom Jones I is first */
