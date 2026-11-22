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

$(ODIR)/%.o: %.c $(DEPS)
	    $(CC) -c -o $@ $< $(CFLAGS)
hellomake: $(OBJ)
$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean
clean:
rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
