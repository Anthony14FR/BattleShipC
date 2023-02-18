// Initialise le Board
void initBoard(char board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = 'o';
        }
    }
}

// Vérifie si les bateaux se chevauche pas
int isValidPlacement(char board[BOARD_SIZE][BOARD_SIZE], int x, int y, int orientation, int size)
{
    if (orientation == 0)
    { // Navire horizontal
        if (y + size > BOARD_SIZE)
            return 0; // Dépasse du bord droit du tableau
        for (int i = 0; i < size; i++)
        {
            if (board[x][y + i] != 'o')
                return 0; // Chevauche un autre navire
        }
    }
    else
    { // Navire vertical
        if (x + size > BOARD_SIZE)
            return 0; // Dépasse du bord inférieur du tableau
        for (int i = 0; i < size; i++)
        {
            if (board[x + i][y] != 'o')
                return 0; // Chevauche un autre navire
        }
    }
    return 1;
}

// Place aléatoirement les bateaux
void placeShips(char board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < sizeof(ships) / sizeof(Ship); i++)
    {
        Ship s = ships[i];
        for (int j = 0; j < s.count; j++)
        {
            int orientation = rand() % 2; // 0 = horizontale, 1 = verticale
            int x, y;
            do
            {
                x = rand() % BOARD_SIZE;
                y = rand() % BOARD_SIZE;
            } while (!isValidPlacement(board, x, y, orientation, s.size)); // Vérifie que la position est valide

            if (orientation == 0)
            {
                for (int k = 0; k < s.size; k++)
                {
                    board[x][y + k] = 'e';
                }
            }
            else
            {
                for (int k = 0; k < s.size; k++)
                {
                    board[x + k][y] = 'e';
                }
            }
        }
    }
}