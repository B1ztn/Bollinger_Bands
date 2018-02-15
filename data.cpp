/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   data.cpp
 * Author: b1
 *
 * Created on February 14, 2018, 12:46 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include "data.h"
using namespace std;

/*
 * 
 */
// one class and then we can use the protected function inside it...
vector<float> Data::read_csv(string filename) // read the .csv file and returns it as a vector
{
    vector<float> PricesTemp;
    vector<float> data;
    ifstream inFile;
    inFile.open(filename.c_str());
    //Because the constructor for an ifstream takes a const char*, not a string pre-C++11.
    // not filename...
    if(!inFile){
        cout<<"cannot open the file";
        exit(1);
    }
    int count =0;
    float x;

    while(inFile >> x)
    {
        count++;
        data.push_back(x);
    }
    return data;
}

