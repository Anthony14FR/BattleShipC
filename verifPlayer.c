// Vérifie si le clique est dans le Board 1
int checkBoard1Click(int x, int y)
{
    if (x >= 20 && x <= 20 + 25 * BOARD_SIZE && y >= 130 && y <= 130 + 25 * BOARD_SIZE)
    {
        int column = (x - 20) / 25;
        int row = (y - 130) / 25;
        return row * BOARD_SIZE + column;
    }
    return -1;
}

// Vérifie si le clique est dans le Board 2
int checkBoard2Click(int x, int y)
{
    if (y >= 130 && y <= 130 + 25 * BOARD_SIZE && x >= 375 && x <= 375 + 25 * BOARD_SIZE)
    {
        int column = (y - 130) / 25;
        int row = (x - 375) / 25;
        return row * BOARD_SIZE + column;
    }
    return -1;
}

// Vérifie si il y à un gagnant
int checkWinner(char board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == 'e')
                return 1;
        }
    }
    return -1;
}