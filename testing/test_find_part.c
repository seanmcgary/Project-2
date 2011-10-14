/*
** test program for find_part()
**
*/
#include <stdio.h>
#include <sys/types.h>

#include "types.h"

#include "parts.h"

/*
** Prototype for find_part() routine
*/

Part *find_part( char pid1, char pid2, uint16_t pid3 );

/*
** run find_part(pid1,pid2,pid3) and print a result based on its return value
*/

void test( Part *expect, char pid1, char pid2, uint16_t pid3 ) {
	Part *p;

	/* run the test */

	p = find_part( pid1, pid2, pid3 );

	/* report the results */

	printf( "Looking for %c%c-%03d, expected 0x%08x, got 0x%08x\n",
		pid1, pid2, pid3, (uint32_t) expect, (uint32_t) p );

}

/*
** The test driver
*/

int main( void ) {
	int n;

	/*
	** test( expected_result,
	**	 pid11, pid12, pid13 );
	*/

	test( &fs1, 'F', 'S',   1 );
	test( &fs2, 'F', 'S',  11 );
	test( &js1, 'J', 'S', 104 );
	test( &js2, 'J', 'S', 200 );
	test( &js3, 'J', 'S', 199 );
	test( &tj1, 'T', 'J', 461 );
	test( &tj2, 'T', 'J', 509 );

	test( 0, 'A', 'X',  99 );
	test( 0, 'F', 'S',  12 );
	test( 0, 'T', 'J', 508 );

	/*
	** expand here with additional tests
	*/

	return( 0 );

}
