/*
** test program for cmp_cust()
**
*/
#include <stdio.h>
#include <sys/types.h>

#include "types.h"

#include "customers.h"

/*
** Prototype for cmp_cust() routine
*/

int cmp_cust( Customer *p1, Customer *p2 );

/*
** run cmp_cust(p1,p2) and print a result based on its return value
*/

void test( char *expect, Customer *p1, char *name1, Customer *p2, char *name2 ) {
	int n;

	/* run the test */

	n = cmp_cust( p1, p2 );

	/* report the results */

	printf( "%s :: %s, expected %s, got ", name1, name2, expect );
	if( n < 0 )		puts( "<" );
	else if ( n == 0 ) 	puts( "=" );
	else			puts( ">" );

}

/*
** The test driver
*/

int main( void ) {
	int n;

	/*
	** test( expected_result,
	**	 first_item, first_item_name,
	**	 second_item, second_item_name );
	*/

	test( "=", &js1, "js1", &js1, "js1" );
	test( "<", &js1, "js1", &js2, "js2" );
	test( ">", &js2, "js2", &js1, "js1" );

	test( "=", &fs1, "fs1", &fs1, "fs1" );
	test( "<", &fs1, "fs1", &fs2, "fs2" );
	test( ">", &fs2, "fs2", &fs1, "fs1" );

	test( "=", &tj1, "tj1", &tj1, "tj1" );
	test( "<", &tj1, "tj1", &tj2, "tj2" );
	test( ">", &tj2, "tj2", &tj1, "tj1" );

	/*
	** expand here with additional tests
	*/

	return( 0 );

}
