# Makefile pour le projet SDL

# Compilateur
CC = gcc

# Options de compilation
CFLAGS = -I.

# Bibliothèques
LIBS = -lmingw32 -lSDLmain -lSDL -lSDL_image -lSDL_ttf

# Fichiers sources
SRCS = main.c 

# Nom de l'exécutable
EXEC = battleship

all: $(EXEC)

$(EXEC):
	$(CC) $(SRCS) $(CFLAGS) $(LIBS) $^ -o $@

start: $(OUTPUT)
	./$(EXEC)

clean:
	rm -f $(EXEC)