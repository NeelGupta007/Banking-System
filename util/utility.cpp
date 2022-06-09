#include<string>
using namespace std;
currency extractDollarsAndCents(string input)
{
    string curr="";
    int inputDollars=0,inputCents=0;
    int n=input.size();
    bool negative=false;
    for(int i=0;i< n;i++)
    {
        if(curr=="" && input[i]=='-')
        {
            negative=true;
        }
        if(input[i]=='D' && curr.size()!=0)
        {
            inputDollars=stoi(curr);
            inputDollars= negative? -inputDollars : inputDollars;
            negative=false;
        }
        else if(input[i]=='C' && curr.size()!=0)
        {
            inputCents=stoi(curr);
            inputCents= negative? -inputCents : inputCents;
            negative=false;
        }
        else if(input[i]==' ')
        {
            curr="";
        }
        else if(input[i]>='0' && input[i]<='9'){
            curr.push_back(input[i]);
        }
        else{
            // error
            break;
        }

    }
    currency amount;
    amount.dollars=inputDollars;
    amount.cents=inputCents;
    return amount;
}

void convertCentsToDollars(currency& balance)
{
    balance.dollars += (balance.cents)/100;
    balance.cents = (balance.cents)%100;
}
