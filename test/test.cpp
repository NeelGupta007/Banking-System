#include <iostream>
#include "../src/bank.cpp"
#include "mock-data.cpp"

using namespace std;

// If parameter is not true, test fails
#define IS_TRUE(x) { !(x) ? (std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl) : (std::cout << __FUNCTION__ << " Passed "<< std::endl) ; }

void testDepositMoney(string inputAmount,string expectedAmount)
{
    bank user;
    user.depositMoney(inputAmount);

    IS_TRUE(user.accountBalance() == expectedAmount);
}

void testWithdrawMoney(string inputAmount,string expectedAmount)
{
    bank user;
    user.withdrawMoney(inputAmount);
    IS_TRUE(user.accountBalance() == expectedAmount);
}

void test1()
{
    bank user;
    user.depositMoney(POSITIVE_AMOUNT);
    IS_TRUE(user.accountBalance() == POSITIVE_AMOUNT);
    user.withdrawMoney(POSITIVE_DOLLARS);
    IS_TRUE(user.accountBalance() == "-14D -40C");
}

void test2()
{
    bank user;
    user.depositMoney(POSITIVE_AMOUNT);
    IS_TRUE(user.accountBalance() == POSITIVE_AMOUNT);
    user.withdrawMoney(POSITIVE_CENTS);
    IS_TRUE(user.accountBalance() == "4D 93C");
}

int main(void) {
    // Call all tests. Using a test framework would simplify this.
    testDepositMoney(POSITIVE_AMOUNT,DEPOSIT_POSITIVE_AMOUNT);
    testDepositMoney(NEGATIVE_AMOUNT,DEPOSIT_NEGATIVE_AMOUNT);
    testDepositMoney(POSITIVE_DOLLARS,DEPOSIT_POSITIVE_DOLLARS);
    testDepositMoney(NEGATIVE_DOLLARS,DEPOSIT_NEGATIVE_DOLLARS);
    testDepositMoney(POSITIVE_CENTS,DEPOSIT_POSITIVE_CENTS);
    testDepositMoney(NEGATIVE_CENTS,DEPOSIT_NEGATIVE_CENTS);

    testWithdrawMoney(POSITIVE_AMOUNT,WITHDRAW_POSITIVE_AMOUNT);
    testWithdrawMoney(NEGATIVE_AMOUNT,WITHDRAW_NEGATIVE_AMOUNT);
    testWithdrawMoney(POSITIVE_DOLLARS,WITHDRAW_POSITIVE_DOLLARS);
    testWithdrawMoney(NEGATIVE_DOLLARS,WITHDRAW_NEGATIVE_DOLLARS);
    testWithdrawMoney(POSITIVE_CENTS,WITHDRAW_POSITIVE_CENTS);
    testWithdrawMoney(NEGATIVE_CENTS,WITHDRAW_NEGATIVE_CENTS);

    test1();
    test2();
}
