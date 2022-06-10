#include<string>

using namespace std;

// Extracts Dollars and cents from the input string and returns currency object
currency extractDollarsAndCents(string input)
{
    string curr = "";
    int inputDollars = 0,inputCents = 0;
    int n = input.size();
    bool negative = false;
    for(int i = 0;i < n;i++)
    {
        if(curr == "" && input[i] == '-')
        {
            negative = true;
        }
        if(input[i] == 'D' && curr.size() != 0)
        {
            inputDollars = stoi(curr);
            inputDollars = negative? -inputDollars : inputDollars;
            negative = false;
        }
        else if(input[i] == 'C' && curr.size() != 0)
        {
            inputCents = stoi(curr);
            inputCents = negative? -inputCents : inputCents;
            negative = false;
        }
        else if(input[i] == ' ')
        {
            curr = "";
        }
        else if(input[i] >= '0' && input[i] <= '9'){
            curr.push_back(input[i]);
        }

    }
    currency amount;
    amount.dollars = inputDollars;
    amount.cents = inputCents;
    return amount;
}


// it balances the cents to dollar , if greater than 100 and also converts when positive cents to negative dollars
void convertCentsToDollars(currency& balance)
{

    balance.dollars += (balance.cents)/100;
    balance.cents = (balance.cents)%100;
    if(balance.dollars < 0 && balance.cents > 0)
    {
        balance.dollars += 1;
        balance.cents = balance.cents - 100;
    }
}
