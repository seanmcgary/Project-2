ALLOCDIR =	/usr/local/pub/wrc/courses/sp1/allocate
P2DIR =		/usr/local/pub/wrc/courses/sp1/project2
CC =		gcc
AS =		as
CFLAGS =	-ggdb -std=c99 -I$(ALLOCDIR)
LIBFLAGS =	-L$(P2DIR) -lproject2 -L$(ALLOCDIR) -lallocate-ubuntu86
CLIBFLAGS =	$(LIBFLAGS)

OBJECTS =	add_to_cust_list.o add_to_part_list.o \
		cmp_cust.o cmp_part.o find_cust.o find_part.o \
		new_cust.o new_part.o

.s.o:
	$(AS) --gstabs $< -o $@

project2:	$(OBJECTS)
	$(CC) $(CFLAGS) -o project2 $(OBJECTS) $(CLIBFLAGS)

