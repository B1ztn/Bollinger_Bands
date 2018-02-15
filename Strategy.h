/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Strategy.h
 * Author: b1
 *
 * Created on February 14, 2018, 1:25 PM
 */

#ifndef STRATEGY_H
#define STRATEGY_H
#include <iostream>
#include <vector>
#include "data.h"
using namespace std;
class Strategy: public Data
{
public:
    void run(float std_devs, int num_prices); // runs the traing strategies..
protected:
    float avg(vector<float> prices); // find the average of the vector of the prices...
    float std_dev(vector<float> prices); // finds the standard deviation of a vector of prices...
    vector<float> returns;
    vector<float> sell_prices;
    vector<float> buy_prices;
private:
    vector<float> bottom_band_vec;
    vector<float> top_band_vec;
    vector<float> signal_vec;
    int num_prices; // number of prices for the moving average....
    float std_devs;//float std_devs... 
    float top_band;  // top bollinger band
    float bottom_band; // bottom bollinger band;
    
    int signal;//1==buy and 0 is neutral ... -1 is sell
    float sum(vector<float> vec); // Sums the contents of a vector...
    vector<float> subset(int first, int last, vector<float> vec);
    // create a subset of vector the first and last parameter is the indices of vec that function
    // returns between....
    void sell(int num_shares, float price);
    void buy(int num_shares, float price);
    void bands(vector<float> prices, float standard_devs);// define the bands from a vector of price..
    
    
};


#endif /* STRATEGY_H */

