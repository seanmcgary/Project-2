/*
** test program for cmp_part()
**
*/
#include <stdio.h>
#include <sys/types.h>

#include "types.h"

#include "parts.h"

/*
** Prototype for cmp_part() routine
*/

int cmp_part( Part *i1, Part *i2 );

/*
** run cmp_part(i1,i2) and print a result based on its return value
*/

void test( char *expect, Part *i1, char *name1, Part *i2, char *name2 ) {
	int n;

	/* run the test */

	n = cmp_part( i1, i2 );

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
	test( "<", &js1, "js1", &js3, "js3" );

	test( ">", &js2, "js2", &js1, "js1" );
	test( "=", &js2, "js2", &js2, "js2" );
	test( ">", &js2, "js2", &js3, "js3" );

	test( ">", &js3, "js3", &js1, "js1" );
	test( "<", &js3, "js3", &js2, "js2" );
	test( "=", &js3, "js3", &js3, "js3" );

	test( "<", &fs1, "fs1", &js1, "js1" );
	test( "<", &fs1, "fs1", &tj1, "tj1" );

	test( ">", &js1, "js1", &fs1, "fs1" );
	test( ">", &tj1, "tj1", &fs1, "fs1" );

	/*
	** expand here with additional tests
	*/

	return( 0 );

}
