char QwertyToAzerty(char lettre)
{
    switch (lettre)
    {
    case 'q':
        return 'A';
        break;
    case 'b':
        return 'B';
        break;
    case 'c':
        return 'C';
        break;
    case 'd':
        return 'D';
        break;
    case 'e':
        return 'E';
        break;
    case 'f':
        return 'F';
        break;
    case 'g':
        return 'G';
        break;
    case 'h':
        return 'H';
        break;
    case 'i':
        return 'I';
        break;
    case 'j':
        return 'J';
        break;
    default:
        return lettre;
        break;
    }
}

void replace_element(int array[][BOARD_SIZE], int i, int j)
{
    if (i < BOARD_SIZE && j < BOARD_SIZE && array[i][j] == 'e')
    {
        array[i][j] = 'X';
    }
    if (i < BOARD_SIZE && j < BOARD_SIZE && array[i][j] == 'o')
    {
        array[i][j] = 'm';
    }
}
