IDIR = ../include
CC=gcc
CFLAGS=-I. $(IDIR)


ODIR= obj
LDIR= ../lib
LIBS= -lm
_DEPS= hellomake.h
DEPS = $(patsubst %, $(ODIR)/%, $(_DEPS))
_OBJ = hellomake.- hellofunc.o
OBJ =  $(patsubst %, $(ODIR)/%, $(_OBJ))

run : src/chess
	cd src && ./chess

.PHONY: test run  clean
clean:
rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
