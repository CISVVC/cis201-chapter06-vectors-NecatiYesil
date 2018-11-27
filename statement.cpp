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

    balance(transactions);
}

std::vector<double> Statement::balance(std::vector<Transaction> &v) //Computes the dailey balances
{
    double balance = 0.0;
    for(int i = 0; i < MAX_DAY; i++)
        {
            balance += get_transactions_total(i +1);
            dailey_balances.push_back(balance);
        }
    return dailey_balances;
}

double Statement::get_transactions_total(int day)
{
   double total = 0.0;
   for(int i = 0; i < transactions.size(); i++)
   {
        if(day == transactions[i].get_day())
        {
            total += transactions[i].get_amount();
        }
   }

   return total;
}

void Statement::print() //prints the dailey balance, average and minimum interest.
{
    int x = 0;
    for(int i = 0; i < MAX_DAY; i++)
    {
        while(i+1 == transactions[x].get_day()) 
        {
            transactions[x].print();
            x++;
        }
        std::cout << "Balance on day " << i+1 << ": "<< dailey_balances[i] << std::endl;
    }
    std::cout << "\n###################################" << std::endl;
    std::cout << "Average daily balance: " << get_average_dailey_balance(dailey_balances) 
              << "  Interest: " << get_average_dailey_rate(dailey_balances) << std::endl;
    std::cout << "Minimum daily balance: " << get_minimum_dailey_balance(dailey_balances)
              << "  Interest: " << get_minimum_dailey_rate(dailey_balances)
              << std::endl << "###################################" << std::endl;
}

double Statement::get_average_dailey_rate(const std::vector<double> &v) //computes the average dailey interest
{
    double sum = 0.0;
    for( int i = 0; i < MAX_DAY; i++)
        sum += v[i];

    return (sum / MAX_DAY)*INTEREST_RATE;
}

double Statement::get_average_dailey_balance(const std::vector<double> &v) //computes the average dailey balance
{
    double sum = 0.0;
    for( int i = 0; i < MAX_DAY; i++)
        sum += v[i];

    return sum / MAX_DAY;
}

double Statement::get_minimum_dailey_rate(const std::vector<double> &v) //computes the min
//dailey interest
{
    double min_balance = v[0];
    for(int i = 0; i < MAX_DAY; i++)
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
    for(int i = 0; i < MAX_DAY; i++)
    {
        if(v[i] < min_balance)
            min_balance = v[i];
    }
    return min_balance;
}
