/*
** test program for new_cust()
**
*/
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

#include <allocate.h>

#include "types.h"

#include "customers.h"

/*
** Prototype for new_cust() routine
*/

Customer *new_cust( char *name, char cid1, uint16_t cid2, uint16_t limit );

/*
** run new_cust() and print a result based on its return value
*/

void test( char *name, char cid1, uint16_t cid2, uint16_t limit ) {
	Customer *c;
	int errors;

	/* run the test */

	printf( "Create ('%c',%05d,\"%s\"):", cid1, cid2, name );
	c = new_cust( name, cid1, cid2, limit );

	/* report the results */

	if( c == NULL ) {
		printf( "  Allocation failed!\n" );
	} else {
		errors = 0;
		if( c->next != 0 ) {
			printf( "\n\tnext   '0x%08x' != 0",
				(uint32_t) c->next );
			++errors;
		}
		if( c->purchases != 0 ) {
			printf( "\n\tpurch  '0x%08x' != 0",
				(uint32_t) c->purchases );
			++errors;
		}
		if( c->name != name ) {
			printf( "\n\tname   '0x%08x' != '0x%08x'",
				(uint32_t) c->name, (uint32_t) name );
			++errors;
		}
		if( c->limit != limit ) {
			printf( "\n\tlimit  '%d' != '%d'",
				c->limit, limit );
			++errors;
		}
		if( c->avail1 != limit ) {
			printf( "\n\tavail1 '%d' != '%d'",
				c->avail1, limit );
			++errors;
		}
		if( c->cid2 != cid2 ) {
			printf( "\n\tcid2   '%05d' != '%05d'", c->cid2, cid2 );
			++errors;
		}
		if( c->cid1 != cid1 ) {
			printf( "\n\tcid1   '0x%02x' != '%c'", c->cid1, cid1 );
			++errors;
		}
		if( c->avail2 != 0 ) {
			printf( "\n\tavail2   '%02d' != 0", c->avail2 );
			++errors;
		}
		if( errors == 0 ) {
			fputs( "\tOK\n", stdout );
		} else {
			putchar( '\n' );
		}
		unallocate( c );
	}

}

/*
** The test driver
*/

int main( void ) {

	/*
	** test( cid1, cid2, name )
	*/

	test( js1.name, js1.cid1, js1.cid2, js1.limit );
	test( js2.name, js2.cid1, js2.cid2, js2.limit );
	test( fs1.name, fs1.cid1, fs1.cid2, fs1.limit );
	test( fs2.name, fs2.cid1, fs2.cid2, fs2.limit );
	test( tj1.name, tj1.cid1, tj1.cid2, tj1.limit );
	test( tj2.name, tj2.cid1, tj2.cid2, tj2.limit );

	/*
	** expand here with additional tests
	*/

	return( 0 );

}
