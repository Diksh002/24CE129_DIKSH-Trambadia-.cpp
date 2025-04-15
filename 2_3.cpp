#include<iostream>
using namespace std;

int AN = 69420;

class BankAccount
{
    int AccountNum;
    float Bal;
    string Name;       //class variables
    static int MinBal, Count;

public:

    int ReturnAccountNum()
    {return AccountNum;}

    int CreateAccount(string N = "Test", float B = 0)
    {
        Count++;
        Name = N;
        Bal = B;
        AccountNum = AN+Count;

        return AccountNum;
    }

    void Deposit(float B)
    {
        Bal+=B;
    }

    int Withdraw(float B)
    {
        if(Bal-B>=MinBal)
        { //check if withdrawal leaves minimum balance
            Bal-=B;
            return 0;
        }
        else
        return 1;
    }

    void AccountSummary()
    {
        cout<<"\nName: "<<Name;
        cout<<"\nAccount Number: "<<AccountNum;
        cout<<"\nCurrent Balance: "<<Bal;
    }
};

int BankAccount :: MinBal = 1000;
int BankAccount :: Count = 0;

int main()
{
    BankAccount Account[10];
    int Choice=0, Count=0, AccountNum=0;
    float Amount=0, Bal=0;
    string Name;

    do{
        int i=0;
        cout<<"\n\nChoices:\n1.Create Account\n2.Deposit Money\n3.Withdraw Money\n4.Accounts List\n0.Exit System";
        cout<<"\n\nPlease Select your Choice: ";
        cin>>Choice;

        switch (Choice)
        {
        case 1:
            cout<<"\nPlease enter your Details to Create New Account:";
            cout<<"\nName: ";
            cin.ignore();
            getline(cin, Name);
            cout<<"Initial Balance to Deposit: ";
            cin>>Bal;                                                          //input from user
            cout<<"\nYour New Account is Created!!\nYour Account Number is: "<<Account[Count].CreateAccount(Name, Bal);
            Count++;
            break;

        case 2:
            cout<<"\nEnter your Account number to Deposit Money: ";
            cin>>AccountNum;
            for(i=0;i<Count;i++)
            {
                if(Account[i].ReturnAccountNum()==AccountNum) //searching all acounts
                {
                    cout<<"\nEnter the Amount of Money you want to Deposit: ";
                    cin>>Amount;
                    Account[i].Deposit(Amount);
                    cout<<endl<<Amount<<" Rs. Deposited in Account Number "<<Account[i].ReturnAccountNum();
                    break;
                }
            }
            if(i>Count)
            cout<<"\nNo such Account found in the system";
            break;

        case 3:
            cout<<"\nEnter your Account number to Withdraw Money: ";
            cin>>AccountNum;
            for(i=0;i<Count;i++)
            {
                if(Account[i].ReturnAccountNum()==AccountNum)
                {
                    cout<<"\nEnter the Amount of Money you want to Withdraw: ";
                    cin>>Amount;
                    if(Account[i].Withdraw(Amount))
                    cout<<"\nInvalid Amount! Please Withdraw such Amount as to leave your Account at Minimum Balance of Rs. 1000";
                    else
                    cout<<endl<<Amount<<" Rs. Withdrawn from Account Number "<<Account[i].ReturnAccountNum();
                    break;
                }
            }
            if(i>Count)
            cout<<"\nNo such Account found in the system";
            break;

            case 4:
            for(i=0;i<Count;i++) //listing all accounts in system
            {
                cout<<"\nAccount Number "<<i+1<<endl;
                Account[i].AccountSummary();
            }
            break;

        default:
            break;
        }

    }while(Choice>=1&&Choice<=4);
    cout<<"\nExiting System....\n\n";

    cout<<"24CE129 _ DIKSH Trambadia";

    return 0;
}