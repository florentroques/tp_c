################# Mode de fonctionnement de gcc ###############
#Compilation (gcc compile fichier.c)
#gcc -c source.c source2.c

#Edition de liens (gcc assemble des objets .o et crée un output)
#gcc source.o source2.o -o exe

#Compilation et édition de liens
#gcc source.c source2.c -o exe

#NOTE: Tous les fichiers c soivent être compilés pour l'édition
#			 de liens, y compris les fichiers c correspondant à un
#			 fichier .h inclus


###################### Mode d'emploi ##########################
#Créer un objet .o et un exécutable par fichier source c
#make

#Créer un exécutable à partir de toutes les sources c présentes dans le dossier
#make e=nom_executable

#Créer un exécutable à partir de certaines sources c
#make e=nom_executable s="fichier1.c fichier2.c (2 fichiers à 999)"


###################### VARIABLES  #############################
#Variable pour afficher ou non les exécutions du makefile
DISPLAY = false
ifeq "DISPLAY" "true"
DISPLAY =
else
DISPLAY = @
endif
#nom du linker (edition de liens .o -> exe)
LD = gcc
#nom du compilateur (compilation .c -> .o)
CC = gcc
#liste des paramètre à passer à GCC pour la création du fichier objet
CFLAGS = -c -g -Wall -ansi -lm
#parametres pour edition de liens
OFLAGS = -lm -o
#on récupère la liste des fichiers c
SRC = $(wildcard *.c)
#on crée la liste des fichiers .o qu'on souhaite créer en remplaçant fichier.c par fichier.o
#C_OBJS = $(patsubst %.c,%.o,$(SRC))
C_OBJS = $(SRC:.c=.o)
#on crée la liste des exécutables qu'on souhaite créer en remplaçant fichier.c par fichier
C_EXE = $(SRC:%.c=%)

##################### TRAITEMENT MAKE #########################

ifdef e
e = $(word 1, $(ARGS))


# make e=nom_executable s="sources"
ifdef s

s= $(wordlist 2, 999, $(ARGS))
OBJS_EXE = $(patsubst %.c,%.o,$(s))
#C_OBJS = $(s:.c=.o)

all: $(e)

$(e): $(OBJS_EXE)
	$(DISPLAY)$(LD) $(OBJS_EXE) $(OFLAGS) $@
	
%.o:%.c
	$(DISPLAY)$(CC) $(CFLAGS) $<

clean:
	rm -f $(e) $(OBJS_EXE)

#make e
else
all: $(e)

$(e): $(C_OBJS)
	$(DISPLAY)$(LD) $(C_OBJS) $(OFLAGS) $@
	
%.o:%.c
	$(DISPLAY)$(CC) $(CFLAGS) $<

clean:
	rm -f $(e) $(C_OBJS)
endif

#make
else

all: ${C_EXE}

#crée dynamiquement les règles de création d'exécutables C
$(C_EXE): $(C_OBJS)
	$(DISPLAY)$(LD) $@.o $(OFLAGS) $@
	$(DISPLAY)chmod +x $@
		
#crée fichiers .o correspondant aux fichiers .c
%.o:%.c
	$(DISPLAY)$(CC) $(CFLAGS) $<

#clean tous les exe C et les objets nécessaires au linkage des exe C
clean:
	rm -f $(C_EXE) $(C_OBJS)
endif 
