#
# Created by gmakemake (Ubuntu Sep  7 2011) on Wed Oct 12 13:20:40 2011
#

#
# Definitions
#

.SUFFIXES:
.SUFFIXES:	.a .o .c .C .cpp .s .S
.c.o:
		$(COMPILE.c) $<
.C.o:
		$(COMPILE.cc) $<
.cpp.o:
		$(COMPILE.cc) $<
.S.s:
		$(CPP) -o $*.s $<
.s.o:
		$(COMPILE.cc) $<
.c.a:
		$(COMPILE.c) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%
.C.a:
		$(COMPILE.cc) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%
.cpp.a:
		$(COMPILE.cc) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%

CC =		gcc
CXX =		g++

RM = rm -f
AR = ar
LINK.c = $(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)
LINK.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS)
COMPILE.c = $(CC) $(CFLAGS) $(CPPFLAGS) -c
COMPILE.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) -c
CPP = $(CPP) $(CPPFLAGS)
########## Flags from header.mak

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


########## End of flags from header.mak


CPP_FILES =	
C_FILES =	
PS_FILES =	
S_FILES =	
H_FILES =	
SOURCEFILES =	$(H_FILES) $(CPP_FILES) $(C_FILES) $(S_FILES)
.PRECIOUS:	$(SOURCEFILES)
OBJFILES =	

#
# Main targets
#

all:	

#
# Dependencies
#


#
# Housekeeping
#

Archive:	archive.tgz

archive.tgz:	$(SOURCEFILES) Makefile
	tar cf - $(SOURCEFILES) Makefile | gzip > archive.tgz

clean:
	-/bin/rm $(OBJFILES) core 2> /dev/null

realclean:        clean
	-/bin/rm -rf 
