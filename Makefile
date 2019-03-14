# 
# Fichier pour compiler le projet
#
# commandes : 
#   make mm15 			: compile le projet
#   make ind FILE=toto.c	: indente le fichier toto.c
#   make clean			: efface les fichiers inutiles
#   make purge			: efface l'executable
#

# Tools
CC=gcc 

IND=indent \
     -nbad -bap -nbc -bl -bli2 -bls -ncdb -nce -di2 \
     -ndj -nfc1 -nfcb -i2 -ip5 -lp -pcs -psl \
     -nsc -nsob

# Files
CSRC=mm15io.c mm15search.c mm15solve.c mm15build.c mm15.c
HSRC=mm15types.h mm15io.h mm15search.h mm15solve.h mm15build.h 

#OBJ=$(subst .c,.o,$(CSRC))
OBJ=mm15io.o mm15search.o mm15solve.o mm15build.o mm15.o

# Targets
mm15: $(OBJ) 
	$(CC) -Wall -o $@ $(OBJ)

ind: 
	$(IND) $(FILE)

iall: $(CSRC) $(HSRC)
	$(foreach f,$(HSRC),$(IND) $f;)
	$(foreach f,$(CSRC),$(IND) $f;)

clean:
	rm -f *~ $(OBJ) *.BAK

purge: clean
	rm mm15

.SUFFIXES: .c .o

%.o: %.c
	$(CC) -Wall -c -o $@ $<

