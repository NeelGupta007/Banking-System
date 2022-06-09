#include "currency.cpp"
#include "../util/utility.cpp"
#include<string>
#include<iostream>
using namespace std;
class account{
    currency balance;

    public:
        account()
        {
            balance.dollars=0;
            balance.cents=0;
        }
        bool depositMoney(string input);
        void withdrawMoney(string input);
        string accountBalance();

};


 bool account::depositMoney(string input)
{

    currency amount = extractDollarsAndCents(input);
    balance.dollars += (amount.dollars) ;
    balance.cents += (amount.cents);
    convertCentsToDollars(balance);
    if(balance.dollars>1e9 || balance.cents>1e9)
    {
        return false;
    }
    return true;
}

void account::withdrawMoney(string input)
{
    currency amount = extractDollarsAndCents(input);
    balance.dollars -= (amount.dollars) ;

    if(balance.cents < amount.cents)
    {
        balance.cents += 100;
        balance.dollars -= 1;
    }
    balance.cents -= (amount.cents);
    convertCentsToDollars(balance);

}
string account::accountBalance()
{

    string bal;
    if(balance.dollars != 0){
        bal= to_string(balance.dollars)+ "D";
    }
    if( balance.cents!=0)
    {
        if(bal.size()){
            bal.push_back(' ');
        }
        bal+=to_string(balance.cents)+"C";
    }
    if(!bal.size())
    {
        bal="0D 0C";
    }

    return bal;
}


