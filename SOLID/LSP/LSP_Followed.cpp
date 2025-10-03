#include <iostream>
#include <vector>
using namespace std;

class Account{

public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
};


class DepositOnlyAccount{
    public:
        virtual void deposit(double amount) = 0;
};

class WithdrawableAccount : public DepositOnlyAccount{
    public:
        virtual void withdraw(double amount) = 0;
};

class SavingAccount : public WithdrawableAccount {

    private:
        double balance;

    public:
        SavingAccount(){
            balance = 0;
        }

        void deposit(double amount){
            balance = balance + amount;
            cout<<"Deposited: "<< amount<<" in Savings account. New Balance: "<<balance<<endl;
        }

        void withdraw(double amount){
            if(balance >= amount){
                balance = balance - amount;
                cout<<"Withdrawn: " << amount<<" in Savings account. New Balance: "<<balance<<endl;
            }
            else{
                cout<<"Insufficients funds in savings account!\n";
            }
        }
};

class CurrentAccount : public WithdrawableAccount {

    private:
        double balance;

    public:
        CurrentAccount(){
            balance = 0;
        }

        void deposit(double amount){
            balance = balance + amount;
            cout<<"Deposited: "<< amount<<" in Current account. New Balance: "<<balance<<endl;
        }

        void withdraw(double amount){
            if(balance >= amount){
                balance = balance - amount;
                cout<<"Withdrawn: " << amount<<" in Current account. New Balance: "<<balance<<endl;
            }
            else{
                cout<<"Insufficients funds in Current account!\n";
            }
        }
};

class FixedTermAccount : public DepositOnlyAccount {

    private:
        double balance;

    public:
        FixedTermAccount(){
            balance = 0;
        }

        void deposit(double amount){
            balance = balance + amount;
            cout<<"Deposited: "<< amount<<" in Fixed Term account. New Balance: "<<balance<<endl;
        }
};


class BankClient{
    private:
        vector<WithdrawableAccount*> withdrawableAccounts;
        vector<DepositOnlyAccount*> depositOnlyAccounts;

    public:
        BankClient(vector<WithdrawableAccount*> withdrawableAccounts,vector<DepositOnlyAccount*> depositOnlyAccounts){
            this -> withdrawableAccounts = withdrawableAccounts;
            this -> depositOnlyAccounts = depositOnlyAccounts;
        }

        void processTransactions(){
            for(WithdrawableAccount* acc : withdrawableAccounts){
                acc -> deposit(1500);
                acc -> withdraw(500);
            }
            for(DepositOnlyAccount* acc : depositOnlyAccounts){
                acc -> deposit(5000);
            }
        }

};


int main(){

    //*********Withdrawable Accounts****************
    vector<WithdrawableAccount*> withdrawableAccounts;

    withdrawableAccounts.push_back(new SavingAccount());
    withdrawableAccounts.push_back(new CurrentAccount());

    //*********Deposit Only Accounts****************
    vector<DepositOnlyAccount*> depositOnlyAccounts;
    depositOnlyAccounts.push_back(new FixedTermAccount());


    BankClient* client = new BankClient(withdrawableAccounts , depositOnlyAccounts);

    client -> processTransactions();

    return 0;
}