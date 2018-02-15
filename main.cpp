/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: b1
 *
 * Created on February 14, 2018, 12:38 PM
 */

#include <cstdlib>
#include <iostream>
#include "performance.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Performance P;
    P.run(2,20);
    //first parameter is the number of standard deviations for bands. 
    //Second parameter is the number of periods in the moving average.
    cout<<"Sharpe Ratio:" << P.sharpe_ratio() <<endl;
    system("pause");
    return 0;
}

