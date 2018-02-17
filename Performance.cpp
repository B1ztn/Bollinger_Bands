/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Performance.cpp
 * Author: b1
 *
 * Created on February 14, 2018, 3:35 PM
 */

#include <cstdlib>
#include "performance.h"
#include <ostream>
using namespace std;

/*
 * 
 */
Performance::Performance()
{
    
}

void Performance::write_file(vector< vector<float> > input_vec, string filename)
{
    //writes a vector of floats into a .txt file. Values separated by \n
    ofstream outputFile;
    outputFile.open(filename.c_str());
    for(int i=0; i<input_vec.size();i++)
    {
        for(int j =0; j<input_vec[j].size(); j++)
        {
            outputFile<<input_vec[i][j];
            outputFile<<'\n';
        }
    }
}

float Performance::sharpe_ratio()
{
    //calculate the sharpe ratio for the simulation...
    vector<float> risk_free_data = read_csv("/home/b1/Bollinger_Bands-master/CSV/RiskFree.csv");
    for(int i =0; i<risk_free_data.size(); i++)
    {
        if(risk_free_data[i] >1)
        {
            cout<<risk_free_data[i] <<endl;
        }
    }
    risk_free = avg(risk_free_data);
    return (avg(returns) - risk_free)/std_dev(returns);
}


void Performance::matrix()
{
    //creates a matrix of sharpe ratios in order to test optimality...
    float dev = 0.25;
    float movavg = 5;
    vector<float> temp_vec;
    for(int i=0; i<24; i++)
    {
        for(int j=0; j<25; j++)
        {
            run(dev, movavg);
            temp_vec.push_back(sharpe_ratio());
            movavg += 1;
            returns.clear();
            buy_prices.clear();
            sell_prices.clear();
            
        }
        sharpe_matrix.push_back(temp_vec);
        temp_vec.clear();
        dev+= 0.25;
        movavg =5 ;
    }
    write_file(sharpe_matrix,"vector.txt");
}