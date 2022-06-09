#include "../src/account.cpp"
#include<iostream>
void controller(account user)
{
    bool loopBreak=false;
    do{
        cout<<"Select an option:"<<endl;
        cout<<"1. Credit"<<endl;
        cout<<"2. Debit"<<endl;
        cout<<"3. Check Balance"<<endl;
        cout<<"4. Exit"<<endl;
        string type;
        getline(cin,type);
        int choice=stoi(type);
        switch(choice)
        {
        case 1:{
            string input;
            cout<<"Enter Amount: "<<endl;
            getline(cin,input);
            bool completed=user.depositMoney(input);
            if(completed)
                cout<<"Successful!"<<endl;
            break;
            }
        case 2:{
            string input;
            cout<<"Enter Amount: "<<endl;
            getline(cin,input);
            user.withdrawMoney(input);
            cout<<"Done!"<<endl;
            break;
        }
        case 3:{
            string bal=user.accountBalance();
            cout<<"Current Balance is "<<bal<<endl;
            break;
        }
        case 4:{
            loopBreak=true;
            break;
        }
        default:{
            cout<<"Invalid option!"<<endl;
        }
        }
    }
    while(!loopBreak);
}
