/*
** test program for add_to_cust_list()
**
*/
#include <stdio.h>
#include <sys/types.h>

#include "types.h"

#include "customers.h"

/*
** Prototype for add_to_cust_list() routine
*/

Customer *add_to_cust_list( Customer *new );

/*
** run add_to_cust_list(new) and print a result based on its return value
*/

void test( Customer *new, Customer *expect, Customer *pred, Customer *succ ) {
	Customer *c, *prev, *curr;
	int i;

	/* run the test */

	printf( "Inserting '%s' %c%04d:\n", new->name, new->cid1, new->cid2 );

	c = add_to_cust_list( new );

	/* report the results */

	if( expect != 0 ) {	/* expected failure! */

		fputs( "\tShould be a dup:", stdout );
		if( c == 0 ) {
			puts( " NOT detected as one" );
		} else if( c == expect ) {
			puts( " OK" );
		} else {
			puts( " detected as WRONG dup" );
			printf( "\t\tShould be '%s' %c%04d, is '%s' %c%04d\n",
				expect->name, expect->cid1, expect->cid2,
				c->name, c->cid1, c->cid2 );
		}

	} else {		/* expected success! */

		puts( "\tShould be inserted into list" );
		if( c != 0 ) {
			printf( "\tDetected as DUP of '%s' %c%04d\n",
				c->name, c->cid1, c->cid2 );
		}
	}

	/* see if it was actually inserted into the list */
	prev = 0;
	curr = customers;
	while( curr && curr != new ) {
		prev = curr;
		curr = curr->next;
	}

	if( curr == 0 ) {
		fputs( "\tNot inserted into list", stdout );
		if( expect == 0 ) {
			fputs( ", but should have been", stdout );
			if( pred ) {
				printf( " with predecessor '%s' %c%04d",
					pred->name, pred->cid1, pred->cid2 );
			}
			if( succ ) {
				printf( " with successor '%s' %c%04d",
					succ->name, succ->cid1, succ->cid2 );
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
			printf( "\tPredecessor should be '%s' %c%04d,",
				pred->name, pred->cid1, pred->cid2 );
			if( prev == 0 ) {
				puts( " but is NULL" );
			} else {
				printf( " but is '%s' %c%04d\n",
					prev->name, prev->cid1, prev->cid2 );
			}
		} else {
			fputs( "\tPredecessor should be NULL," , stdout );
			if( prev == 0 ) {
				printf( "*** error, pred %08x != prev %08x\n",
					(uint32_t) pred, (uint32_t) prev );
			} else {
				printf( " but is '%s' %c%04d\n",
					prev->name, prev->cid1, prev->cid2 );
			}
		}
	}

	if( curr->next == succ ) {
		puts( "\tSuccessor is correct" );
	} else {
		if( succ != 0 ) {
			printf( "\tSuccessor should be '%s' %c%04d,",
				succ->name, succ->cid1, succ->cid2 );
			if( curr->next == 0 ) {
				puts( " but is NULL" );
			} else {
				printf( " but is '%s' %c%04d\n",
					curr->next->name, curr->next->cid1,
					curr->next->cid2 );
			}
		} else {
			fputs( "\tSuccessor should be NULL," , stdout );
			if( prev == 0 ) {
				printf( "*** error, succ %08x != curr->next %08x\n",
					(uint32_t) succ,
					(uint32_t) curr->next );
			} else {
				printf( " but is '%s' %c%04d\n",
					curr->next->name, curr->next->cid1,
					curr->next->cid2 );
			}
		}
	}

}

/*
** The test driver
*/

/* should be after Tom Jones II */
Customer rk = { 0, 0, "Kind, Richard", 5000, 0,  207, 'K', 0 };

/* should be first - before Tom Jones I */
Customer ma = { 0, 0, "Adams, Mark", 5000, 0,  998, 'A', 0 };

/* should be last - after John Smith II */
Customer dt = { 0, 0, "Taylor, Dave", 5000, 0,  7099, 'T', 0 };

int main( void ) {

	/*
	** test( new, expect, pred, succ )
	*/

	/* these should succeed */
	test( &rk, 0, &tj2, &fs1 );
	test( &dt, 0, &js2,    0 );
	test( &ma, 0,    0, &tj1 );

	/* these should fail */
	test( &fs2, &fs2, &fs1, &js1 );

	/*
	** expand here with additional tests
	*/

	return( 0 );

}
