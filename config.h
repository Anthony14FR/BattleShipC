#define WINDOW_WIDTH 640  // X
#define WINDOW_HEIGHT 480 // Y
#define GRID_SIZE 10 // Plus utilisé
#define BOARD_SIZE 10 // Taille du Board

// Constantes des couleurs basiques
const SDL_Color Red = {255, 0, 0};
const SDL_Color Green = {0, 255, 0};
const SDL_Color Blue = {0, 0, 255};
const SDL_Color White = {255, 255, 255};
const SDL_Color Black = {0, 0, 0};

char board1[BOARD_SIZE][BOARD_SIZE];
char board2[BOARD_SIZE][BOARD_SIZE];

// structure d'un bateau
typedef struct
{
    int size;
    int count;
} Ship;

// Nombre de bateau de chaque taille
Ship ships[] = {
    {2, 1},
    {3, 2},
    {4, 1},
    {5, 1},
};


// Variables de présentation

char shipChar = 'o'; // Pour voir les bateaux #WallHack