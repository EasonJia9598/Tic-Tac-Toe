//
//  TicTacToe.cpp
//  Tic-Tac-Toe
//
//  Created by WillJia on 02/02/2018.
//  Copyright © 2018 Zesheng Jia A00416452. All rights reserved.
//

#include "TicTacToe.h"
#include <iostream>


TicTacToe :: TicTacToe()
{
    
}// end default constructor

TicTacToe :: TicTacToe(char user1N , char User2N)
{
    user1Name = user1N;
    user2Name = User2N;
} // end constructor



void TicTacToe:: BattleStart()
{
    int i = 0;
    // start round in 9 times max
    while(i < 9)
    {
        /* placePiece function contains
            findPosition()
            and
            Displaychessboard()
         */
        
        // place user1 piece first
        placePiece(user1Num);
        i++;
        
        // std::cout <<"i == "<< i << std::endl;
        /* ********check wining********
            if user1 win then print wining info 
            and break loop
         */
        
        if (checkWin(user1Num))
        {
            // Dispaly wining info
           std::cout << user1Name << " wins!!" << std::endl;
            initializeArray();
            return ;
        } // end if
        
        //Time to stop
        
        if (i == 9) {
            break;
        }
        // place user2 piece second
        placePiece(User2Num);
        i++;
        
        // std::cout <<"i == "<< i << std::endl;
        // check Win
        if (checkWin(User2Num))
        {
            // Dispaly wining info
            std::cout << user2Name << " wins!!" << std::endl;
             initializeArray();
            return ;
        }// end if
        
        
    }// end for
    
    // can't find any winner in 9 times
    // Then there is a tie
    std::cout << "\nThere is a tie, No winner!!\n" << std::endl;
    initializeArray();
    
}

void TicTacToe::initializeArray()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0 ; j < 3 ; j++){
            checkBoard[i][j] = 0;
        }
    }
    char chessBoardInit[5][5] = {
        ' ' , '|' , ' ' , '|' , ' ' ,
        '-' , '+' , '-' , '+' , '-' ,
        ' ' , '|' , ' ' , '|' , ' ' ,
        '-' , '+' , '-' , '+' , '-' ,
        ' ' , '|' , ' ' , '|' , ' ' ,
    };
    pieceCount = 0;
    memcpy(chessBoard, chessBoardInit, sizeof(chessBoard));
}

void TicTacToe::placePiece(int userNum)
{
    // find position to locate user's piece
    findPosition(userNum);
    
    // Display chess board every time
    DispalyChessBoard();
}
void TicTacToe:: findPosition(int user)
{
    
    while (true)
    {
        // create a random location
        /* None strategy model*/
        position = random_unint(1, 10, (unsigned int)time(NULL));
        
        
        /* Put piece into right location*/
        
        /* Calculate random number into array position*/
        if (position < 4) {
            x1 = 0;
            y1 = position - 1;
        }
        else if (position < 7)
        {
            x1 = 1;
            y1 = position - 4;
        }
        else
        {
            x1 = 2;
            y1 = position - 7;
        }
        
        /* Check empty position to locate*/
        if (checkBoard[x1][y1] == 0)
        {
            // add checkBoard to user
            checkBoard[x1][y1] = user;
            pieceCount++;
            
            // print starting info
            if (pieceCount == 1) {
                std::cout << "Player " <<user1Name << " starting at position " << x1 <<" " << y1 << " \n";
            }
            
            // Add user Name into ChessBodar
            if (user == user1Num)
            {
                chessBoard[x1*2][y1*2] = user1Name;
            }
            else if(user == User2Num)
            {
                chessBoard[x1*2][y1*2] = user2Name;
            }
            // end function
            return ;
        }
    }
}// end findPosition

void TicTacToe::DispalyChessBoard()
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << chessBoard[i][j];
        } // end j for
        std::cout << std::endl;
    }
    std::cout << std::endl;
}// end DispalyChessBoard

bool TicTacToe::checkWin(int userNum)
{
    userNum *= 3;
    int checkRow = 0 , checkColumn = 0;
    int leftDiagonal = checkBoard[0][0] + checkBoard[1][1] + checkBoard[2][2];
    int rightDiagonal =checkBoard[0][2] + checkBoard[1][1] + checkBoard[2][0];
    
    if (leftDiagonal == userNum || rightDiagonal == userNum) {
        return true;
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            checkRow += checkBoard[i][j];
            checkColumn += checkBoard[j][i];
        }
        // if find winner then return true
        if (checkRow == userNum || checkColumn == userNum) {
            return true;
        }
         // else reset check value
        else
        {
           
            checkRow = 0;
            checkColumn = 0;
        }
    }
    
    return false;
}
int TicTacToe :: random_unint(unsigned int min, unsigned int max, unsigned int seed )
{
    static std::default_random_engine e(seed);
    static std::uniform_real_distribution<double> u(min, max);
    return (int)u(e);
} // end random_unint





















