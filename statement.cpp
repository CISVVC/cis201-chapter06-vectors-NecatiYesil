/*
Filename: statement.cpp
Description: this is the implementation file for the header statement.h
Author: Necati Murat Yesil
DoC: 11/10/18
*/
#include "statement.h"
#include "transaction.h"
#include <iostream>
#include <vector>
#include <string>

Statement::Statement() //constructor 
{
}

void Statement::read() // read function for transaction class object's
{
    Transaction t;
    bool more = true;
    while(more)
    {
        t.read();
        transactions.push_back(t);
        
        char answer;
        std::cout << "More transactions? (y/n) " << std::endl;
        std::cin >> answer;
        
        if( answer == 'N' || answer == 'n')
            more = false;
    }

    compute_balances();
}

void Statement::compute_balances() //Computes the dailey balances
{
    double balance = 0.0;
    for(int i = 0; i < transactions.size(); i++)
    {
        balance += transactions[i].get_amount();
        dailey_balances.push_back(balance);
    }
    
}

void Statement::print() //prints the dailey balance, average and minimum interest.
{
    for(int i = 0; i < transactions.size(); i++)
    {
        transactions[i].print();
        std::cout << "Balance: " << dailey_balances[i] << std::endl;
    }
    std::cout << "-------------------" << std::endl;
    std::cout << "Average dailey interest charges: " << get_average_dailey_balance() << std::endl;
    std::cout << "Minimum dailey interest charges: " << get_minimum_dailey_balance(dailey_balances)
              << std::endl << "------------------"<< std::endl;
}

double Statement::get_average_dailey_balance() //computes the average dailey balance
{
    double sum = 0.0;
    for(int i = 0; i < MAX_DAY; i++)
    {
        sum += transactions[i].get_amount();
    }
    return (sum / MAX_DAY)*INTEREST_RATE;
}

double Statement::get_minimum_dailey_balance(const std::vector<double> &v) //computes the min
//dailey balance
{
    double min_balance = v[0];
    for(int i = 0; i < transactions.size(); i++)
    {
        if(v[i] < min_balance)
            min_balance = v[i];
    }
    return min_balance * INTEREST_RATE;
}















