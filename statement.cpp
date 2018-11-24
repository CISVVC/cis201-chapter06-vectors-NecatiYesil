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

    get_balances();
}

void Statement::get_balances() //Computes the dailey balances
{
    double balance = 0.0;
    for(int i = 0; i < transactions.size(); i++)
    {
        balance += transactions[i].get_amount();
        dailey_balances.push_back(balance);
    }
    
}


double Statement::total_balances() //Computes the dailey balances
{
    double total = 0.0;
    for(int i = 0; i < MAX_DAY; i++)
    {
        total += get_transactions_total(i + 1);
    }
    return total;
}

double Statement::get_transactions_total(int day)
{
   double total = 0.0;
   for(int i = 0; i < transactions.size(); i++)
   {
        if(day != transactions[i].get_day())
        {
            total += transactions[i].get_amount();
        }
   }

   return total;
}

void Statement::print() //prints the dailey balance, average and minimum interest.
{
    for(int i = 0; i < transactions.size(); i++)
    {
        transactions[i].print();
        std::cout << "Balance: " << dailey_balances[i] << std::endl;
    }
    std::cout << "\n###################################" << std::endl;
    std::cout << "Average daily balance: " << get_average_dailey_balance() 
              << "  Interest: " << get_average_dailey_rate() << std::endl;
    std::cout << "Minimum daily balance: " << get_minimum_dailey_balance(dailey_balances)
              << "  Interest: " << get_minimum_dailey_rate(dailey_balances)
              << std::endl << "###################################" << std::endl;
}

double Statement::get_average_dailey_rate() //computes the average dailey interest
{
    return (total_balances() / (2*MAX_DAY))*INTEREST_RATE;
}

double Statement::get_average_dailey_balance() //computes the average dailey balance
{
    return total_balances() / (2*MAX_DAY);
}

double Statement::get_minimum_dailey_rate(const std::vector<double> &v) //computes the min
//dailey interest
{
    double min_balance = v[0];
    for(int i = 0; i < transactions.size(); i++)
    {
        if(v[i] < min_balance)
            min_balance = v[i];
    }
    return min_balance * INTEREST_RATE;
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
    return min_balance;
}
