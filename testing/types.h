/*
** data types for project 2 test programs
**
*/
#ifndef _TYPES_H_
#define _TYPES_H_

#include <sys/types.h>
#include <stdint.h>

/*
** Definition of a customer node (based on the project 2 specification)
*/

typedef
	struct custnode {
		struct  custnode *next; /* next entry in customer list */
		void    *purchases;	/* 1st part this customer purchased */
		char    *name;		/* customer name */
		uint16_t limit;		/* maximum credit limit */
		uint16_t avail1;	/* whole part of NNNN.nn */
		uint16_t cid2;		/* numeric part of CID (cNNNN) */
		uint8_t cid1;		/* character part of CID (Cnnnn) */
		uint8_t avail2;		/* fractional part of nnnn.NN */
	}
		Customer;

/*
** Definition of a part node (based on the project 2 specification)
*/

typedef
	struct partnode {
		struct  partnode *next;	/* following entry in part list */
		void    *purchases;	/* 1st customer who bought this part */
		char    pid1;		/* first char of PID (Cc-nnn) */
		char    pid2;		/* second char of PID (cC-nnn) */
		uint16_t pid3;		/* numeric part of PID (cc-NNN) */
		uint16_t price1;	/* whole part of price (N.nn) */
		uint8_t price2;		/* fractional part of price (n.NN) */
		uint8_t avail;		/* # of this part on hand */
	}
		Part;

#endif
