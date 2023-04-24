/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

#include <fstream>
using namespace std;
#include <vector>

#include "Account.h"
#include "Transaction.h"


void Read(const string filename, vector<Account> & accounts)
{
   string firstname;
   string lastname;
   string PIN;
   string accountnumber;
   ifstream din;
   din.open(filename);
   while (din >> firstname >> lastname >> PIN >> accountnumber)
   {
       Account temp(firstname, lastname, PIN, accountnumber);
       accounts.push_back(temp);
       
       
   }
}


void ReadTransaction(const string TransactionFilename, vector<Transaction> & transactions)
{
    string fromAccountNumber;
    string toAccountNumber;
    string amount;
    ifstream din;
    din.open(TransactionFilename);
     while (din >> fromAccountNumber >> toAccountNumber >> amount)
   {
       Transaction temp(fromAccountNumber, toAccountNumber, amount);
       transactions.push_back(temp);
       
   }
}
void WriteTransaction(const string TransactionFilename, vector<Transaction> VectorTransaction)
{
    string fromAccountNumber;
    string toAccountNumber;
    string amount;
    ofstream dout;
    dout.open("results.txt");
    for(int i = 0; i < VectorTransaction.size(); i++)
    {
        dout << VectorTransaction[i].getFromAccountNumber() << " " << VectorTransaction[i].getToAccountNumber() << " " << VectorTransaction[i].getAmount() << "\n";
    }
    
    
}




int main()
{
    string TransactionFilename = "encryptedTransactions.txt";
    
    string filename = "accounts.txt";
    
    
    
    vector<Transaction> VectorTransaction;
    
    vector<Account> VectorAccount;
    
    ReadTransaction(TransactionFilename, VectorTransaction);
    
    Read(filename, VectorAccount);
    
   
    
 
    
   
    
    string DonnaAccountnum;
    
    string DonnaPINnum;
    
    for(int i = 0; i < VectorAccount.size(); i++)
    {
        
       if (VectorAccount[i].getFirstName() == "Donna")
       {
           DonnaAccountnum = VectorAccount[i].getAccountNumber();
           DonnaPINnum = VectorAccount[i].getPIN();
       }
    }  
    for(int i = 0; i < VectorTransaction.size(); i++)   
    {
        if(VectorTransaction[i].decrypt(DonnaAccountnum, DonnaPINnum))
        {
            cout << "Donnas inocent \n";
            break;
        }
        
    }
   for(int i = 0; i < VectorAccount.size(); i++)
  {
      bool found = false;
        for(int j = 0; j < VectorTransaction.size(); j++)  
        {
        
            if(VectorTransaction[j].decrypt(VectorAccount[i].getAccountNumber(),VectorAccount[i].getPIN()))
           {
            found = true;
            break;
           }
        }
       if(found == false) 
       {
       VectorAccount[i].print();
       cout << " is a hacker " << endl;
       }
   }
    for(int i = 0; i < VectorTransaction.size(); i++)
  {
        for(int j = 0; j < VectorAccount.size(); j++)
        {
            if(VectorTransaction[i].decrypt(VectorAccount[j].getAccountNumber(),VectorAccount[j].getPIN()))
            break;
        }

     }
       
    WriteTransaction(TransactionFilename, VectorTransaction);   
    ReadTransaction(TransactionFilename, VectorTransaction);   
    
  
  
    
    

    return 0;
}