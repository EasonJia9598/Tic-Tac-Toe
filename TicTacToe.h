//
//  TicTacToe.hpp
//  Tic-Tac-Toe
//
//  Created by WillJia on 02/02/2018.
//  Copyright © 2018 Zesheng Jia A00416452. All rights reserved.
//

#ifndef TicTacToe_hpp
#define TicTacToe_hpp

#include <stdio.h>
#include <math.h>
#include <ctime>
#include <random>

class TicTacToe
{
private :
    /*Private paraments*/
    char user1Name = 'X';
    char user2Name = 'O';
    int user1Num = 1;
    int User2Num = -1;
    
    int position = 1;
    /*Creating display chess board for presenting*/
    char chessBoard[5][5] = {
        ' ' , '|' , ' ' , '|' , ' ' ,
        '-' , '+' , '-' , '+' , '-' ,
        ' ' , '|' , ' ' , '|' , ' ' ,
        '-' , '+' , '-' , '+' , '-' ,
        ' ' , '|' , ' ' , '|' , ' ' ,
    };
    
    /*Mathematical check board for finding winner*/
    int checkBoard[3][3] = {0};
    
    /*cordinates for locating*/
    int x1 = 0 , y1 = 0;
    
    /*Count Number for quit*/
    int pieceCount = 0;
    
    /*Private funciton for initializing chess board and check board*/
    void initializeArray();
    
public :
    /*Default constructor*/
    TicTacToe();
    /*Constructor with 2 paraments
      char user1Name and char user2Name*/
    TicTacToe(char user1Name , char user2Name);
    
    /** Place a piece in chess board and add value in check board.
     @post  If successful, a piece will be placed in chess board.
     @param user , the user's value of X or O */
    void placePiece(int user);
    
    /** Find a position for one user, check is there any empty place.
     @post  If successful, it will find a position
     @param user  the user's value of X or O */
    void findPosition(int user);
    
    /** check user win or not.
     @post  If successful, it will return and show who is winner
    @param user  the user's value of X or O
     @return  True if removal was successful, or false if not. */
    bool checkWin(int user);
    
    /** Display chess board
     @post  If successful, print the char array chess board 1*/
    void DispalyChessBoard();
    
    /** Union function of whole process
     @post  If successful, it will run the simulation*/
    void BattleStart();
    
    /** Give back random value
     @post  If successful, anEntry has been removed from the bag
     and the count of items in the bag has decreased by 1.
     @param min the minimum scale of random number
     @param max  the maximum scale of random number
     @param seed  seed of random number
     @return int  the random number  */
    int random_unint(unsigned int min, unsigned int max, unsigned int seed = 0);
    
};


#endif /* TicTacToe_hpp */
