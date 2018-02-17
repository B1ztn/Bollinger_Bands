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
#include "Data.h"
#include "Strategy.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    string path = "/home/b1/Bollinger_Bands-master/CSV/CAT.csv";
    Data data;
    vector<float> mydata = data.read_csv(path);
    //first parameter is the number of standard deviations for bands. 
    //Second parameter is the number of periods in the moving average.

    cout<<mydata.size()<<endl;
    
    Strategy s;
    s.run(5,20);
    
        
    Performance P;
    P.run(2,20);
    cout<<"sharpe ratio: " << P.sharpe_ratio() <<endl;
    
    return 0;
}

