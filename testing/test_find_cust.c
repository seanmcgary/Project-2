/*
** test program for find_cust()
**
*/
#include <stdio.h>
#include <sys/types.h>

#include "types.h"

#include "customers.h"

/*
** Prototype for find_cust() routine
*/

Customer *find_cust( char cid1, uint16_t cid2 );

/*
** run find_cust(cid1,cid2) and print a result based on its return value
*/

void test( Customer *expect, char cid1, uint16_t cid2 ) {
	Customer *c;

	/* run the test */

	c = find_cust( cid1, cid2 );

	/* report the results */

	printf( "Looking for %c%04d, expected 0x%08x, got 0x%08x\n",
		cid1, cid2, (uint32_t) expect, (uint32_t) c );

}

/*
** The test driver
*/

int main( void ) {

	/*
	** test( expected_address, cid1, cid2 );
	*/

	test( &js1, 'S', 1234 );
	test( &js2, 'S', 1235 );
	test( &fs1, 'S', 2345 );
	test( &fs2, 'S', 2346 );
	test( &tj1, 'J', 120 );
	test( &tj2, 'J', 121 );

	test( 0, 'S', 234 );
	test( 0, 'J', 567 );
	test( 0, 'X', 9999 );

	/*
	** expand here with additional tests
	*/

	return( 0 );

}
