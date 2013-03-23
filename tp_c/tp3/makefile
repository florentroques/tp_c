#Mode d'emploi

#make : compile tous les fichiers .c en .o et .asm en .o puis crée les liens vers exécutable

#crée fichier exe C à partir de toutes les sources C présentes dans le dossier
#make e=nom_de_l_executable_C

#crée fichier exe C à partir des sources voulues
#make e=nom_de_l_executable_C s="fichier1.c fichier2.c (2 fichiers à 999)"



############# VARIABLES POUR COMPILATION C ####################
#nom du linker (edition de liens .o -> .exe)
LD = gcc
#nom du compilateur (compilation .c -> .o)
CC = gcc
#liste des paramètre à passer à GCC pour la création du fichier objet
CFLAGS = -c -g -Wall -ansi -lm
#parametres pour edition de liens
OFLAGS = -lm -o
#on récupère la liste des fichiers c
SRC = $(wildcard *.c)
#on crée la liste des fichiers .o qu'on souhaite créer à partir des .c
#C_OBJS = $(patsubst %.c,%.o,$(SRC))
C_OBJS = $(SRC:.c=.o)
#on crée la liste des exécutables qu'on souhaite créer en remplaçant fichier.c par fichier
C_EXE = $(SRC:%.c=%)


ifdef e
e = $(word 1, $(ARGS))

##
# make e=nom_executable s=sources_necessaires
##
ifdef s

s= $(wordlist 2, 999, $(ARGS))
OBJS_EXE = $(patsubst %.c,%.o,$(s))
#C_OBJS = $(s:.c=.o)

all: $(e)

$(e): $(OBJS_EXE)
	@$(LD) $(OFLAGS) $@ $(OBJS_EXE) 
	
%.o:%.c
	@$(CC) $(CFLAGS) $<

clean:
	rm -f $(e) $(OBJS_EXE)

#make e
else
all: $(e)

$(e): $(C_OBJS)
	@$(LD) $(OFLAGS) $@ $(C_OBJS) 
	
%.o:%.c
	@$(CC) $(CFLAGS) $<

clean:
	rm -f $(e) $(C_OBJS)
endif

#make
else

all: ${C_EXE}

#crée dynamiquement les règles de création d'exécutables C
$(C_EXE): $(C_OBJS)
	@$(LD) $(OFLAGS) $@ $(C_OBJS)
	@chmod +x $@
		
#crée fichiers .o correspondant aux fichiers .c
%.o:%.c
	$(CC) $(CFLAGS) $<

#clean tous les exe C et les objets nécessaires au linkage des exe C
clean:
	rm -f $(C_EXE) $(C_OBJS)
endif 
