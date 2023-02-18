// Permet d'afficher un texte
void showText(char *text, int x, int y, TTF_Font *font, SDL_Surface *screen, SDL_Color textColor)
{
    SDL_Surface *message = TTF_RenderText_Solid(font, text, textColor);
    SDL_Rect textLocation = {x, y, 0, 0};
    SDL_BlitSurface(message, NULL, screen, &textLocation);
    SDL_UpdateRect(screen, 0, 0, 0, 0);
    SDL_FreeSurface(message);
}

// Permet d'afficher un texte avec un cooldown
void showTextWithDelay(char *text, int x, int y, TTF_Font *font, SDL_Surface *screen, SDL_Color textColor, int sec)
{
    SDL_Surface *message = TTF_RenderText_Solid(font, text, textColor);
    SDL_Rect textLocation = {x, y, 0, 0};
    SDL_BlitSurface(message, NULL, screen, &textLocation);
    SDL_UpdateRect(screen, 0, 0, 0, 0);
    SDL_FreeSurface(message);
    sleep(sec);
    SDL_Color BckColor = {0, 0, 0};
    SDL_Surface *message2 = TTF_RenderText_Solid(font, text, BckColor);
    SDL_Rect textLocation2 = {x, y, 0, 0};
    SDL_BlitSurface(message2, NULL, screen, &textLocation2);
    SDL_UpdateRect(screen, 0, 0, 0, 0);
    SDL_FreeSurface(message2);
}

// Affiche le Board1 (Gauche)
void printBoard1(char board[BOARD_SIZE][BOARD_SIZE], TTF_Font *font, SDL_Surface *screen)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == 'o')
                showText("o", (25 * i) + 20, (25 * j) + 110, font, screen, Blue);
            else if (board[i][j] == 'e')
            {
                if (shipChar == 'o')
                {
                    showText("o", (25 * i) + 20, (25 * j) + 110, font, screen, Blue);
                }
                else if (shipChar == 'e')
                {
                    showText("e", (25 * i) + 20, (25 * j) + 110, font, screen, Blue);
                }
            }
            else if (board[i][j] == 'm')
                showText("u", (25 * i) + 20, (25 * j) + 110, font, screen, Blue);
            else if (board[i][j] == 'x')
                showText("x", (25 * i) + 20, (25 * j) + 110, font, screen, Red);
        }
        printf("\n");
    }
}

// Affiche le Board2 (Droite)
void printBoard2(char board[BOARD_SIZE][BOARD_SIZE], TTF_Font *font, SDL_Surface *screen)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == 'o')
                showText("o", (25 * i) + 375, (25 * j) + 110, font, screen, Green);
            else if (board[i][j] == 'e')
            {
                if (shipChar == 'o')
                {
                    showText("o", (25 * i) + 375, (25 * j) + 110, font, screen, Green);
                }
                else if (shipChar == 'e')
                {
                    showText("e", (25 * i) + 375, (25 * j) + 110, font, screen, Green);
                }
            }
            else if (board[i][j] == 'm')
                showText("u", (25 * i) + 375, (25 * j) + 110, font, screen, Green);
            else if (board[i][j] == 'x')
                showText("x", (25 * i) + 375, (25 * j) + 110, font, screen, Red);
        }
        printf("\n");
    }
}

// Nettoie le Board1 (Gauche)
void clearBoard1(char board[BOARD_SIZE][BOARD_SIZE], TTF_Font *font, SDL_Surface *screen)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == 'o')
                showText("o", (25 * i) + 20, (25 * j) + 110, font, screen, Black);
            else if (board[i][j] == 'e')
            {
                if (shipChar == 'o')
                {
                    showText("o", (25 * i) + 20, (25 * j) + 110, font, screen, Black);
                }
                else if (shipChar == 'e')
                {
                    showText("e", (25 * i) + 20, (25 * j) + 110, font, screen, Black);
                }
            }
            else if (board[i][j] == 'm')
                showText("u", (25 * i) + 20, (25 * j) + 110, font, screen, Black);
            else if (board[i][j] == 'x')
                showText("x", (25 * i) + 20, (25 * j) + 110, font, screen, Black);
        }
        printf("\n");
    }
}

// Nettoie le Board2 (Droite)
void clearBoard2(char board[BOARD_SIZE][BOARD_SIZE], TTF_Font *font, SDL_Surface *screen)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == 'o')
                showText("o", (25 * i) + 375, (25 * j) + 110, font, screen, Black);
            else if (board[i][j] == 'e')
            {
                if (shipChar == 'o')
                {
                    showText("o", (25 * i) + 375, (25 * j) + 110, font, screen, Black);
                }
                else if (shipChar == 'e')
                {
                    showText("e", (25 * i) + 375, (25 * j) + 110, font, screen, Black);
                }
            }
            else if (board[i][j] == 'm')
                showText("u", (25 * i) + 375, (25 * j) + 110, font, screen, Black);
            else if (board[i][j] == 'x')
                showText("x", (25 * i) + 375, (25 * j) + 110, font, screen, Black);
        }
        printf("\n");
    }
}
