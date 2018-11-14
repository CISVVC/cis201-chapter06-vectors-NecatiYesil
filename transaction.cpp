/**
File: transaction.cpp
Description this is the implementation file for the header transaction.h
author: Necati Murat Yesil
DoC:11/10/18
**/
#include <iostream>
#include <string>
#include "transaction.h"


Transaction::Transaction()
{
    m_day = 0;
    m_amount = 0;
}

void Transaction::read()  // Prompts day, amount and description of the statement.
{
    std::cout << "Day of the transaction: " << std::endl;
    std::cin >> m_day;
    std::cout << "Amount of the transaction: " << std::endl;
    std::cin >> m_amount;
    std::cin.ignore();
    std::cout << "Description of the transacton: " << std::endl;
    std::getline(std::cin, m_description);
}   

int Transaction::get_day() // Accesor function for m_day
{ 
    return m_day;
}

double Transaction::get_amount() // Accessor function for m_amount
{ 
    return m_amount;
}

std::string Transaction::get_description() // Accessor function for m_description
{
    return m_description;
}

void Transaction::print() // prints out the collected data from user
{
    std::cout << "---------------------" << std::endl;
    std::cout << "DAY" << "  " << "AMOUNT" << "  " << "DESCRIPTION" << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout <<" " << m_day << "     " << m_amount << "     " << m_description << std::endl;
} 

