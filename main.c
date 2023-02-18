#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <unistd.h>
#include <config.h>
#include <setupShip.c>
#include <textDisplay.c>
#include <string.h>
#include <time.h>
#include <verifPlayer.c>

int main(int argc, char *argv[])
{
    // Défini le random
    srand(time(NULL));

    // Prépare les bateaux
    initBoard(board1);
    initBoard(board2);

    // Place les bateaux aléatoirement
    placeShips(board1);
    placeShips(board2);

    // Init de la fenêtre SDL
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    // Def de la police du Titre
    TTF_Font *titleFont = TTF_OpenFont("ASMAN.TTF", 50);
    // Def de la police du Board
    TTF_Font *font = TTF_OpenFont("OpenSans-Regular.ttf", 40);
    // Def de la police des Textes
    TTF_Font *fontPlayer = TTF_OpenFont("OpenSans-Regular.ttf", 30);

    // Création de la fenêtre SDL
    SDL_Surface *screen = SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32, SDL_HWSURFACE);

    // Titre de la fenêtre plus tentative de logo
    SDL_WM_SetCaption("BatailleNavaleUwU", "icon.ico");
    SDL_Surface *icon = IMG_Load("icon.ico");
    SDL_WM_SetIcon(icon, NULL);

    // Affichage des textes constants
    showText("Bataille Navale", 175, 20, titleFont, screen, White);
    showText("Joueur 1", 85, 80, fontPlayer, screen, Blue);
    showText("Joueur 2", 450, 80, fontPlayer, screen, Green);

    // Affichage des bateaux
    printBoard1(board1, font, screen);
    printBoard2(board2, font, screen);

    // Boucle de jeu
    SDL_Event event;
    // Variable permanente à vrai
    int running = 1;
    // Variable du à qui le tour
    int player = 1;
    // Variable tant que quelqu'un n'as pas gagné
    int playing = 1;

    char newKey = '0';
    char combinaison[] = "";

    char clicked = ';';
    while (running)
    {

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                playing = 0;
                running = 0;
                break;
                while (playing)
                {
                case SDL_MOUSEBUTTONDOWN:
                    // Def du x , y du click
                    int row = -1;
                    int column = -1;

                    // Récupère la pos du click
                    if (player == 2)
                    {
                        clicked = checkBoard1Click(event.button.x, event.button.y);
                        row = clicked / BOARD_SIZE;
                        column = clicked % BOARD_SIZE;
                    }

                    else if (player == 1)
                    {
                        clicked = checkBoard2Click(event.button.x, event.button.y);
                        row = clicked / BOARD_SIZE;
                        column = clicked % BOARD_SIZE;
                    }
                    
                    // Vérifie que le clique n'est pas en dehors d'un des deux boards
                    if (row != -1 && column != -1)
                    {
                        if (player == 1)
                        {
                            if (board2[row][column] == 'o')
                            {
                                // Loupé
                                clearBoard2(board2, font, screen);
                                board2[row][column] = 'm';
                                printBoard2(board2, font, screen);
                                player = 2;
                            }
                            else if (board2[row][column] == 'e')
                            {
                                // Coulé
                                clearBoard2(board2, font, screen);
                                board2[row][column] = 'x';
                                printBoard2(board2, font, screen);
                                
                                // Vérifie si le joueur à gagné
                                if (checkWinner(board2) == -1)
                                {
                                    playing = 0;
                                    showText("A toi de jouer", 410, 400, fontPlayer, screen, Black);
                                    showText("A toi de jouer", 50, 400, fontPlayer, screen, Black);
                                    showText("GG ! Tu as gagne !", 20, 400, fontPlayer, screen, Blue);
                                    clearBoard2(board2, font, screen);
                                    clearBoard1(board1, font, screen);
                                    shipChar = 'e';
                                    printBoard2(board2, font, screen);
                                    printBoard1(board1, font, screen);
                                    player = 3;
                                }
                                // Rejoue
                            }
                        }
                        else if (player == 2)
                        {
                            if (board1[column][row] == 'o')
                            {
                                // Loupé
                                clearBoard1(board1, font, screen);
                                board1[column][row] = 'm';
                                printBoard1(board1, font, screen);
                                player = 1;
                            }
                            else if (board1[column][row] == 'e')
                            {
                                // Coulé
                                clearBoard1(board1, font, screen);
                                board1[column][row] = 'x';
                                printBoard1(board1, font, screen);

                                // Vérifie si le joueur à gagné
                                if (checkWinner(board1) == -1)
                                {
                                    playing = 0;
                                    showText("A toi de jouer", 410, 400, fontPlayer, screen, Black);
                                    showText("A toi de jouer", 50, 400, fontPlayer, screen, Black);
                                    showText("GG ! Tu as gagne !", 380, 400, fontPlayer, screen, Green);
                                    clearBoard2(board2, font, screen);
                                    clearBoard1(board1, font, screen);
                                    shipChar = 'e';
                                    printBoard2(board2, font, screen);
                                    printBoard1(board1, font, screen);
                                    player = 3;
                                }
                                // Rejoue
                            }
                        }
                    }
                    break;
                }
            }
        }
        if (player == 1)
        {
            showText("A toi de jouer", 410, 400, fontPlayer, screen, Black);
            showText("A toi de jouer", 50, 400, fontPlayer, screen, Blue);
        }
        else if (player == 2)
        {
            showText("A toi de jouer", 50, 400, fontPlayer, screen, Black);
            showText("A toi de jouer", 410, 400, fontPlayer, screen, Green);
        }
    }

    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();

    return 0;
}
