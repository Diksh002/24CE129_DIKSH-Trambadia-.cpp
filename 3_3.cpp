#include<iostream>
#include<map>
using namespace std;

class bank
{
   int acccountnumber,balance;
   string name;

   static int totalacc;

   public:
   bank()
   {
      acccountnumber =0;
      balance = 0;
      name ="NA";
   }

   bank(int num,string n,int b)
   {
      acccountnumber = num;
      name = n;
      balance = b;
   }

   void details()
   {
      cout<<"\n\n\nAccount name : "<<name<<"\tAccount number : "<<acccountnumber<<"\tAccount balance : "<<balance;
   }

   void deposite(int amount)
   {
      balance += amount;
      cout<<"\nDeposite done successfully";
   }

   void withdraw(int amount)
   {
      if (balance >= amount)
      {
        balance -=amount;
        cout<<"\nWithdrawal done successfully";
      }

      else
        cout<<"Not sufficient balance";
   }

   int getaccnum()
   {
      return acccountnumber;
   }

   int getbalance()
   {
      return balance;
   }

   friend void transfer(map <int,bank> &account , int fromacc, int toacc, int amount);

};

void transfer(map <int,bank> &account , int fromacc, int toacc, int amount)
{
    if(account.find(fromacc) != account.end() && account.find(toacc) != account.end())
    {
        if(account[fromacc].getbalance()>= amount)
        {
           account[fromacc].withdraw(amount);
           account[toacc].deposite(amount);
           cout<<"Transfer successful";
        }

        else 
          cout<<"Not sufficient balance : ";
    }

    else 
       cout<<"Invalid account number ";
}

int main()
{
    int t,i,accnum,accbal,fromacc,toacc,amount,c;
    string accname;

    cout<<"Enter total number of accounts : ";
    cin>>t;

    map <int,bank> account;

    for (i=0;i<t;i++)
    {
        cout<<"Enter account number : ";
        cin>>accnum;
        cout<<"Enter accounnt holder name : ";
        cin>>accname;
        cout<<"Enter balance : ";
        cin>>accbal;

        account[accnum] = bank(accnum,accname,accbal);
    }

    do
    {
        cout<<"\n\nEnter 1 for deposite"<<endl<<"Enter 2 for withdraw"<<endl<<"Enter 3 to see details"<<endl<<"Enter 4 for Transfer money"<<endl<<"Enter 5 for exit";
        cout<<"\nEnter your number : ";
        cin>>c;
        
        switch(c)
        {
            case 1:
            cout<<"\n\nEnter account number : ";
            cin>>accnum;
            cout<<"Enter the amount you want to deposite : ";
            cin>>amount;
            account[accnum].deposite(amount);
            break;

            case 2:
            cout<<"\n\nEnter account number : ";
            cin>>accnum;
            cout<<"Enter the amount you want to withdraw : ";
            cin>>amount;
            account[accnum].withdraw(amount);
            break;

            case 3:
            cout<<"\n\nEnter account number : ";
            cin>>accnum;
            account[accnum].details();
            break;

            case 4:
            cout<<"\n\nEnter account you want to transfer money from : ";
            cin>>fromacc;
            cout<<"Enter account you want to receive money to : ";
            cin>>toacc;
            cout<<"Enter the amount you have to transfer : ";
            cin>>amount;
        
        
            transfer(account,fromacc,toacc,amount);
            break;

            case 5:
            cout<<"\n\nExited";
            break;

            default :
            cout<<"Invalid choice ";
        }
          
    } while (c!=5);
    
    for (auto &i : account)
    {
        i.second.details();
    }

    cout<<endl<<"24CE129 _ DIKSH Trambadia";
    return 0;

}