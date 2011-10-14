/*
** global Part variables for test programs
**
*/
#include "types.h"

/*
** Some test parts
**
** Note the ordering - this keeps the compiler happy
*/

/* TJ-nnn */
Part tj2 = {    0, 0, 'T', 'J', 509, 12, 21, 10 };
Part tj1 = { &tj2, 0, 'T', 'J', 461, 12, 20, 10 };

/* JS-nnn */
Part js2 = { &tj1, 0, 'J', 'S', 200, 10, 21, 10 };
Part js3 = { &js2, 0, 'J', 'S', 199, 10, 22, 10 };
Part js1 = { &js3, 0, 'J', 'S', 104, 10, 20, 10 };

/* FS-nnn */
Part fs2 = { &js1, 0, 'F', 'S',  11, 11, 21, 10 };
Part fs1 = { &fs2, 0, 'F', 'S',   1, 11, 20, 10 };

/* Pointer to first part in list */
Part *parts = &fs1;
