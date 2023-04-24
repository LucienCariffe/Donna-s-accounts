#include "Account.h"
#include <iostream>

//constructor
Account::Account()
{
    firstName = "";
    lastName = "";
    PIN = "";
    accountNumber = "";
}

Account::Account(const string firstNameIn, const string lastNameIn, const string PINIn, const string accountNumberIn)
{
    firstName = firstNameIn;
    lastName =lastNameIn;
    PIN = PINIn;
    accountNumber = accountNumberIn;
}
//copy constructor
Account::Account(const Account & copy)
{
    firstName = copy.firstName;
    lastName = copy.lastName;
    PIN = copy.PIN;
    accountNumber = copy.accountNumber;
}
//destructor
Account::~Account()
{
    firstName = "";
    lastName = "";
    PIN = "";
    accountNumber = "";
}

//print      
void Account::print() 
{
    cout << firstName << lastName << PIN << accountNumber;
}
      

      // Getters
string Account::getFirstName() const
{
    return firstName;
}
string Account::getLastName() const
{
    return lastName;
}
string Account::getPIN() const
{
    return PIN;
}
string Account::getAccountNumber() const
{
    return accountNumber;
}

      // Setters
void Account::setFirstName(const string firstNameIn)
{
    firstName = firstNameIn;
}
void Account::setLastName(const string lastNameIn)
{
    lastName = lastNameIn;
}
void Account::setPIN(const string PINIn)
{
    PIN = PINIn;
}
void Account::setAccountNumber(const string accountNumberIn)
{
    accountNumber = accountNumberIn;
}

      