#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char board [3][3];

void sign ()
{
    printf ( "  __        _            \n" );
    printf ( "  \\ \\  ___ | |__  _ __   " );
    printf ( "     __ _  __ _ _ __ ___   ___  ___  \n" );
    printf ( "   \\ \\/ _ \\| '_ \\| '_ \\   " );
    printf ( "   / _` |/ _` | '_ ` _ \\ / _ \\/ __| \n" );
    printf ( "/\\_/ / (_) | | | | | | \\   " );
    printf ( " | (_| | (_| | | | | | |  __/\\__ \\ \n" );
    printf ( "\\___/ \\___/|_| |_|_| |_|   " );
    printf ( "  \\__, |\\__,_|_| |_| |_|\\___||___/ \n" );
    printf ( "                             |___/ \n" );
}

void ResetBoard ( )
{
    int i ;
    int j ;
    for( i = 0 ; i < 3 ; i ++ )
    {
        for( j = 0 ; j < 3 ;j ++ )
        {
            board[i][j] = ' ';
        }
    }
}

void PrintBoard ( )
{

    printf ( " %c | %c | %c " , board[0][0] , board[0][1] , board[0][2] );
    printf ( "\n---|---|---\n" );
    printf ( " %c | %c | %c " , board[1][0] , board[1][1] , board[1][2] );
    printf ( "\n---|---|---\n" );
    printf ( " %c | %c | %c " , board[2][0] , board[2][1] , board[2][2] );
    printf ( "\n" );
}

int CheckFreeSpaces ( )
{
    int FreeSpaces = 9 ;
    int i ;
    int j ;
    for( i = 0 ; i < 3 ; i ++ )
    {
        for( j = 0 ; j < 3 ;j ++ )
        {
            if( board[i][j] != ' ')
            {
                FreeSpaces -- ;
            }
        }
    }
    return FreeSpaces ;
}

void PlayerMove ( char PLAYER )
{
    int x ;
    int y ;
    do
    {
        printf ( "Scrie linia #( 1-3 ) :\n" );
        scanf ( "%d" , &x );
        x--;
        printf ( "Scrie coloana #( 1-3 ) :\n" );
        scanf ( "%d" , &y );
        y--;
        if( board[x][y] != ' ' )
        {
            printf( "Patratica este deja ocupata\n" );
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }
    }
    while( board[x][y] != ' ' );
}

void PlayerMove2 ( char COMPUTER )
{
    int x ;
    int y ;
    do
    {
        printf ( "Scrie linia #( 1-3 ) :\n" );
        scanf ( "%d" , &x );
        x--;
        printf ( "Scrie coloana #( 1-3 ) :\n" );
        scanf ( "%d" , &y );
        y--;
        if( board[x][y] != ' ' )
        {
            printf( "Patratica este deja ocupata\n" );
        }
        else
        {
            board[x][y] = COMPUTER;
            break;
        }
    }
    while( board[x][y] != ' ' );
}

char CheckWinner ( )
{
    int i ;
    ///Linii
    for( i=0 ; i < 3 ; i++ )
    {
        if( board[i][0] == board[i][1] && board[i][1] == board[i][2] )
        {
            return board[i][2] ;
        }
    }
    ///Coloane
    for( i=0 ; i < 3 ; i++ )
    {
        if( board[0][i] == board[1][i] && board[1][i] == board[2][i] )
        {
            return board[2][i] ;
        }
    }
    ///Diagonala Principala
    if( board[0][0] == board[1][1] && board[1][1] == board[2][2] )
    {
        return board[2][2] ;
    }
    ///Diagonala Secundara
    if( board[0][2] == board[1][1] && board[1][1] == board[2][0] )
    {
        return board[2][0] ;
    }
    return ' ';
}

void PrintWinnerPVC ( char *winner , char PLAYER , char COMPUTER )
{
    if ( *winner == PLAYER )
    {
        printf ("Ai castigat\n" );
    }
    else if ( *winner == COMPUTER )
    {
        printf ( "Ai pierdut\n" );
    }
    else
    {
        printf ( "Egalitate\n" );
    }
}

void PrintWinnerPVP ( char *winner , char numep1[] , char numep2[] , char PLAYER , char COMPUTER )
{
    if ( *winner == PLAYER )
    {
        printf ("A castigat %s \n" , numep1 );
    }
    else if ( *winner == COMPUTER )
    {
        printf ("A castigat %s \n" , numep2 );
    }
    else
    {
        printf ( "Egalitate\n" );
    }
}

void ComputerMove ( char PLAYER ,char COMPUTER )
{
    int x;
    int y;
    int i ;
    int contra = 1 ;
    if( contra == 1 )
    {
        if( board[0][0] == board[1][1] && board[1][1] != ' ' && board[2][2] == ' ' )///Diagonala Principala
        {
            board[2][2] = COMPUTER ;
            contra = 0 ;
        }
        else if( board[0][0] == board[2][2] && board[2][2] != ' ' && board[1][1] == ' ' )
        {
            board[1][1] = COMPUTER ;
            contra = 0 ;
        }
        else if( board[1][1] == board[2][2] && board[1][1] != ' ' && board[0][0] == ' ' )
        {
            board[0][0] = COMPUTER ;
            contra = 0 ;
        }
        else if( board[0][2] == board[1][1] && board[1][1] != ' ' && board[2][0] == ' ' )///Diagonala Secundara
        {
            board[2][0] = COMPUTER;
            contra = 0;
        }
        else if( board[2][0] == board[0][2] && board[2][0] != ' ' && board[1][1] == ' ' )
        {
            board[1][1] = COMPUTER ;
            contra = 0 ;
        }
        else if( board[1][1] == board[2][0] && board[1][1] != ' ' && board[0][2] == ' ' )
        {
            board[0][2] = COMPUTER ;
            contra = 0 ;
        }
        for (i = 0; i < 3 && contra == 1 ; i++ )
        {
            if (board[i][0] == board[i][1] && board[i][0] != ' ' && board[i][2] == ' ' ) ///Linii
            {
                board[i][2] = COMPUTER;
                contra = 0 ;
            }
            else if (board[i][0] == board[i][2] && board[i][0] != ' ' && board[i][1] == ' ' )
            {
                board[i][1] = COMPUTER;
                contra = 0 ;
            }
            else if (board[i][1] == board[i][2] && board[i][1] != ' ' && board[i][0] == ' ' )
            {
                board[i][0] = COMPUTER;
                contra = 0 ;
            }
            else if (board[0][i] == board[1][i] && board[0][i] != ' ' && board[2][i] == ' ' ) ///Coloane
            {
                board[2][i] = COMPUTER;
                contra = 0 ;
            }
            else if (board[0][i] == board[2][i] && board[0][i] != ' ' && board[1][i] == ' ' )
            {
                board[1][i] = COMPUTER;
                contra = 0 ;
            }
            else if (board[1][i] == board[2][i] && board[1][i] != ' ' && board[0][i] == ' ' )
            {
                board[0][i] = COMPUTER;
                contra = 0 ;
            }
        }
    }
    srand(time(0));
    if ( CheckFreeSpaces ( board ) > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        }
        while( board[x][y] != ' ' );
        if( contra == 1)
        {
            board[x][y] = COMPUTER;
        }
    }
    else
    {
        PrintWinnerPVC ( ' ' , PLAYER , COMPUTER );
    }
}

void PXVC0 ( char PLAYER , char COMPUTER )
{
    char winner = ' ' ;
    ResetBoard ( );
    while ( winner == ' ' && CheckFreeSpaces ( ) )
    {
        PrintBoard ( );
        PlayerMove ( PLAYER );
        winner = CheckWinner ( );
        if ( winner != ' ' || CheckFreeSpaces ( ) == 0 )
        {
            break ;
        }
        ComputerMove ( PLAYER , COMPUTER );
        winner = CheckWinner ( );
        if ( winner != ' ' || CheckFreeSpaces ( ) == 0 )
        {
            break ;
        }
    }
    PrintBoard ( board );
    PrintWinnerPVC ( winner , PLAYER , COMPUTER );
}

void P0VCX ( char PLAYER , char COMPUTER )
{
    char winner = ' ' ;
    ResetBoard ( board );
    while ( winner == ' ' && CheckFreeSpaces ( board ) )
    {
        ComputerMove ( PLAYER , COMPUTER );
        winner = CheckWinner ( board );
        if ( winner != ' ' || CheckFreeSpaces ( board ) == 0 )
        {
            break ;
        }
        else
        {
            PrintBoard ( );
        }
        PlayerMove ( PLAYER );
        winner = CheckWinner ( );
        if ( winner != ' ' || CheckFreeSpaces ( ) == 0 )
        {
            break ;
        }
    }
    PrintBoard ( );
    PrintWinnerPVC ( &winner , PLAYER , COMPUTER );
}

void PVC ( char PLAYER , char COMPUTER )
{
    PLAYER = ' ' ;
    while( PLAYER != '0' && PLAYER != 'X' )
    {
        printf ("Cu ce simbol doresti sa joci (X/0) ?");
        scanf ("%c" , &PLAYER);
    }
    if ( PLAYER == '0' )
    {
        PLAYER = '0';
        COMPUTER = 'X';
        P0VCX ( PLAYER , COMPUTER );
    }
    else
    {
        PLAYER = 'X';
        COMPUTER = '0';
        PXVC0 ( PLAYER , COMPUTER );
    }

}

void PVP ( char PLAYER , char COMPUTER )
{
    char winner = ' ' ;
    char numep1[51] ;
    char numep2[51] ;
    printf ( "Nume Player1(X):" );
    scanf ( "%s" , numep1 );
    printf ( "Nume Player2(0):" );
    scanf ( "%s" , numep2 );

    ResetBoard ( );
    while ( winner == ' ' && CheckFreeSpaces ( ) )
    {
        PrintBoard ( );
        printf ( "%s (X) face miscarea\n" , numep1 );
        PlayerMove ( PLAYER );
        winner = CheckWinner ( );
        if ( winner != ' ' || CheckFreeSpaces ( ) == 0 )
        {
            break ;
        }
        else
        {
            PrintBoard ( );
        }
        printf ( "%s (0) face miscarea\n" , numep2);
        PlayerMove2 ( COMPUTER );
        winner = CheckWinner ( );
        if ( winner != ' ' || CheckFreeSpaces ( ) == 0 )
        {
            break ;
        }
    }
    PrintBoard ( );
    PrintWinnerPVP ( winner , numep1 , numep2 , PLAYER , COMPUTER );
}

int playmode( char pm[] )
{
    if( strcmp ( pm , "PVP" ) == 0 )
    {
        return 0;
    }
    else if( strcmp ( pm , "PVC" ) == 0 )
    {
        return 1;
    }
    return -1;
}

int playagain( char pa[] )
{
    if( strcmp ( pa , "NU" ) == 0 )
    {
        return 0;
    }
    else if( strcmp ( pa , "DA" ) == 0 )
    {
        return 1;
    }
    return -1;
}

int main ()
{
    char PLAYER = 'X' ;
    char COMPUTER = '0' ;

    sign ();
    int playag = 1;
    while ( playag == 1 )
    {
        char pm[10] = " ";
        char pa[10];
        while ( playmode ( pm ) == -1)
        {
            printf ( "Modurile disponibile de joc sunt PVP (Player Vs Player) si PVC (Player Vs Computer) \n" );
            printf ( "Selectati modul de joc scriindul mai jos (Folositi majuscule) : \n" );
            scanf ( "%s" , pm );

        }
        if ( playmode ( pm ) == 1  )
        {
            PVC ( PLAYER , COMPUTER );
        }
        else if ( playmode ( pm ) == 0 )
        {
            PVP ( PLAYER , COMPUTER );
        }
        while ( playagain ( pa ) == -1)
        {
            printf ( "\nVreti sa jucati din nou?(DA/NU)\n" );
            scanf ( "%s" ,pa );
        }
        playag = playagain ( pa );

    }


    return 0;
}
