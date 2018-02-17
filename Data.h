/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   data.h
 * Author: b1
 *
 * Created on February 14, 2018, 12:41 PM
 */

#ifndef DATA_H
#define DATA_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
class Data{
public:
    vector<float> read_csv(string filename); 
    // here we only consider the csv files....
                                           
    // maybe in the future we will establish it...
};


#endif /* DATA_H */

