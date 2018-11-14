/*
Filename: main.cpp
Description: this code will prompt bank statements with day, amount and description to user. and then
i will compute balances for each day, interest on average and min  dailey balance.  
Author: Necati Murat Yesil
DoC: 11/10/18
*/
#include "statement.h"
#include "transaction.h"
#include <iostream>
#include <vector>

int main()
{
    Statement stat; //object from statement class
    stat.read(); //prompts for  data
    stat.print(); //prints the results
    
return 0;
}


