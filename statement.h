/*
Filename:statement.h
Description: header file for statement class
Author: Necati Murat Yesil
DoC:11/10/18
*/
#ifndef STATEMENT_H
#define STATEMENT_H
#include "transaction.h"
#include <vector>
#include <iostream>


class Statement
{
    public:
        Statement();
        void read();// read funtion for transaction object's
        void compute_balances();
        void print() ;
        double get_average_dailey_balance();
        double get_minimum_dailey_balance(const std::vector<double> &v);

    private:
        const int MAX_DAY = 30; //billling cycle
        const double INTEREST_RATE = 0.005; // interest rate on account
        std::vector<Transaction> transactions;
        std::vector<double> dailey_balances;
};
#endif
