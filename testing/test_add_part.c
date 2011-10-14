/*
** test program for add_to_part_list()
**
*/
#include <stdio.h>
#include <sys/types.h>

#include "types.h"

#include "parts.h"

/*
** Prototype for add_to_part_list() routine
*/

Part *add_to_part_list( Part *new );

/*
** run add_to_part_list(new) and print a result based on its return value
*/

void test( Part *new, Part *expect, Part *pred, Part *succ ) {
	Part *p, *prev, *curr;
	int i;

	/* run the test */

	printf( "Inserting %c%c-%03d:\n", new->pid1, new->pid2, new->pid3 );

	p = add_to_part_list( new );

	/* report the results */

	if( expect != 0 ) {	/* expected failure! */

		fputs( "\tShould be a dup:", stdout );
		if( p == 0 ) {
			puts( " NOT detected as one" );
		} else if( p == expect ) {
			puts( " OK" );
		} else {
			puts( " detected as WRONG dup" );
			printf( "\t\tShould be %c%c-%03d, is %c%c-%03d\n",
				expect->pid1, expect->pid2, expect->pid3,
				p->pid1, p->pid2, p->pid3 );
		}

	} else {		/* expected success! */

		puts( "\tShould be inserted into list" );
		if( p != 0 ) {
			printf( "\tDetected as DUP of %c%c-%03d\n",
				p->pid1, p->pid2, p->pid3 );
		}
	}

	/* see if it was actually inserted into the list */
	prev = 0;
	curr = parts;
	while( curr && curr != new ) {
		prev = curr;
		curr = curr->next;
	}

	if( curr == 0 ) {
		fputs( "\tNot inserted into list", stdout );
		if( expect == 0 ) {
			fputs( ", but should have been", stdout );
			if( pred ) {
				printf( " with predecessor %c%c-%03d",
					pred->pid1, pred->pid2, pred->pid3 );
			}
			if( succ ) {
				printf( " with successor %c%c-%03d",
					succ->pid1, succ->pid2, succ->pid3 );
			}
			putchar( '\n' );
		} else {
			puts( " and wasn't" );
		}
		return;
	}

	/* was inserted - in correct place? */
	if( prev == pred ) {
		puts( "\tPredecessor is correct" );
	} else {
		if( pred != 0 ) {
			printf( "\tPredecessor should be %c%c-%03d,",
				pred->pid1, pred->pid2, pred->pid3 );
			if( prev == 0 ) {
				puts( " but is NULL" );
			} else {
				printf( " but is %c%c-%03d\n",
					prev->pid1, prev->pid2, prev->pid3 );
			}
		} else {
			fputs( "\tPredecessor should be NULL," , stdout );
			if( prev == 0 ) {
				printf( "*** error, pred %08x != prev %08x\n",
					(uint32_t) pred, (uint32_t) prev );
			} else {
				printf( " but is %c%c-%03d\n",
					prev->pid1, prev->pid2, prev->pid3 );
			}
		}
	}

	if( curr->next == succ ) {
		puts( "\tSuccessor is correct" );
	} else {
		if( succ != 0 ) {
			printf( "\tSuccessor should be %c%c-%03d,",
				succ->pid1, succ->pid2, succ->pid3 );
			if( curr->next == 0 ) {
				puts( " but is NULL" );
			} else {
				printf( " but is %c%c-%03d\n",
					curr->next->pid1,
					curr->next->pid2,
					curr->next->pid3 );
			}
		} else {
			fputs( "\tSuccessor should be NULL," , stdout );
			if( prev == 0 ) {
				printf( "*** error, succ %08x != curr->next %08x\n",
					(uint32_t) succ,
					(uint32_t) curr->next );
			} else {
				printf( " but is %c%c-%03d\n",
					curr->next->pid1,
					curr->next->pid2,
					curr->next->pid3 );
			}
		}
	}

}

/*
** The test driver
*/

/* should be after JS-200 */
Part kt = { 0, 0, 'K', 'T', 322, 10, 21, 10 };

/* should be after TJ-461 */
Part tj = { 0, 0, 'T', 'J', 499, 10, 21, 10 };

/* should be first - before FS-001 */
Part cr = { 0, 0, 'C', 'R', 777, 10, 21, 10 };

/* should be last - after TJ-509 */
Part xs = { 0, 0, 'X', 'S', 949, 10, 21, 10 };

int main( void ) {

	/*
	** test( new, expect, pred, succ )
	*/

	/* these should succeed */
	test( &kt, 0, &js2, &tj1 );
	test( &tj, 0, &tj1, &tj2 );
	test( &xs, 0, &tj2,    0 );
	test( &cr, 0,    0, &fs1 );

	/* these should fail */
	test( &fs2, &fs2, &fs1, &js1 );

	/*
	** expand here with additional tests
	*/

	return( 0 );

}
