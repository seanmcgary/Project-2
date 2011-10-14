/*
** test program for new_part()
**
*/
#include <stdio.h>
#include <sys/types.h>

#include <allocate.h>

#include "types.h"

#include "parts.h"

/*
** Prototype for new_part() routine
*/

Part *new_part( char pid1, char pid2, uint16_t pid3,
		uint16_t price1, uint8_t price2, uint8_t avail );

/*
** run new_part() and print a result based on its return value
*/

void test( char pid1, char pid2, uint16_t pid3,
	   uint16_t price1, uint8_t price2, uint8_t avail ) {
	Part *p;
	int errors;

	/* run the test */

	printf( "Creating ('%c', '%c', '%03d', '%d','%d','%d'):",
		pid1, pid2, pid3, avail, price1, price2 );
	p = new_part( pid1, pid2, pid3, avail, price1, price2 );

	/* report the results */

	if( p == NULL ) {
		printf( "  Allocation failed!\n" );
	} else {
		errors = 0;
		if( p->next != 0 ) {
			printf( "\n\tnext  '0x%08x' != 0",
				(uint32_t) p->next );
			++errors;
		}
		if( p->purchases != 0 ) {
			printf( "\n\tpurch  '0x%08x' != 0",
				(uint32_t) p->purchases );
			++errors;
		}
		if( p->pid1 != pid1 ) {
			printf( "\n\tpid1   '%c' != '%c'",
				p->pid1, pid1 );
			++errors;
		}
		if( p->pid2 != pid2 ) {
			printf( "\n\tpid2   '%c' != '%c'",
				p->pid2, pid2 );
			++errors;
		}
		if( p->pid3 != pid3 ) {
			printf( "\n\tpid3   '%03d' != '%03d'",
				p->pid3, pid3 );
			++errors;
		}
		if( p->price1 != price1 ) {
			printf( "\n\tprice1 '%d' != '%d'",
				p->price1, price1 );
			++errors;
		}
		if( p->price2 != price2 ) {
			printf( "\n\tprice2 '%d' != '%02d'",
				p->price2, price2 );
			++errors;
		}
		if( p->avail != avail ) {
			printf( "\n\tavail  '%d' != %d",
				p->avail, avail );
			++errors;
		}
		if( errors == 0 ) {
			fputs( "\tOK\n", stdout );
		} else {
			putchar( '\n' );
		}
		unallocate( p );
	}

}

/*
** The test driver
*/

int main( void ) {
	int n;

	/*
	** test( pid1, pid2, pid3, price1, price2, avail )
	*/

	test( js1.pid1, js1.pid2, js1.pid3, js1.price1, js1.price2, js1.avail );
	test( js2.pid1, js2.pid2, js2.pid3, js2.price1, js2.price2, js2.avail );
	test( js3.pid1, js3.pid2, js3.pid3, js3.price1, js3.price2, js3.avail );
	test( fs1.pid1, fs1.pid2, fs1.pid3, fs1.price1, fs1.price2, fs1.avail );
	test( fs2.pid1, fs2.pid2, fs2.pid3, fs2.price1, fs2.price2, fs2.avail );
	test( tj1.pid1, tj1.pid2, tj1.pid3, tj1.price1, tj1.price2, tj1.avail );
	test( tj2.pid1, tj2.pid2, tj2.pid3, tj2.price1, tj2.price2, tj2.avail );

	/*
	** expand here with additional tests
	*/

	return( 0 );

}
