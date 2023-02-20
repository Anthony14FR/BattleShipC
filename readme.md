Version: 2.1
Compile avec SDL 1.2

Pour compiler avec GCC
gcc main.c  -I. -lmingw32 -lSDLmain -lSDL -lSDL_image -lSDL_ttf  -o battleship

Pour compiler avec le MakeFile
make (pour compiler le programme)
make start (pour lancer le programme)
make clean (pour nettoyer l'executable)
