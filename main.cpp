//
//  main.cpp
//  Tic-Tac-Toe
//
//  Created by WillJia on 02/02/2018.
//  Copyright © 2018 Zesheng Jia A00416452. All rights reserved.
//! github upload

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <ctime>
#include <random>
#include "TicTacToe.h"
using namespace std;


int main(int argc, const char * argv[]) {
    // insert code here...
    
    cout << "This program simulates a TicTacToe game\n";
    TicTacToe test;
    test.BattleStart();
    cout << "******************************************\n";
    cout << "*************Second round*****************\n";
    cout << "******************************************\n\n";
    test.BattleStart();
    
    return 0;
}
