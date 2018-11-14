/*
Filename:transaction.h
Description:header file for the transaction class
Author: Necati Murat Yesil
DoC:11/10/18
*/
#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>

class Transaction
{
    public:
        Transaction();
        void read();
        int get_day();
        double get_amount();
        std::string get_description();
        void print();

    private:
        int m_day;
        double m_amount;
        std::string m_description;
};

#endif 
