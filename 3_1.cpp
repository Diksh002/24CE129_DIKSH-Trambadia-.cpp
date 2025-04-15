#include<iostream>
#include<vector>
using namespace std;

class EmployeeMaster
{
    string Name;
    int Age;
    float BasicSalary, BonusAmount;

    inline float TotalSalary(){ //utility function
        return (BasicSalary + BonusAmount);
    }

public:

    EmployeeMaster(string N, int A, int Basic, int Bonus = 10000){
     //constructor with Bonus as default arguments
        Name = N;
        Age = A;
        this->BasicSalary = Basic; //this pointer to access class var
        this->BonusAmount = Bonus;
    }


    void DisplayDetails(){
        cout<<"\nName: "<<this->Name;
        cout<<"\nAge: "<<this->Age;
        cout<<"\nBasic Salary: "<<this->BasicSalary;
        cout<<"\nBonus Amount: "<<this->BonusAmount;
        cout<<"\nTotal Salary: "<<TotalSalary();
    }

public:

};

int main()
{
    vector<EmployeeMaster> Emp; //dynamic array to store multiple employees data
    char check='y';
    string Name;
    int Age; //temp variables
    float Basic;

    cout<<"\nEnter Employee details:";
    while(check=='y'||check=='Y'){
        cout<<"\nName: ";
        cin.ignore();
        getline(cin, Name);
        cout<<"Age: ";cin>>Age;
        cout<<"Basic Salary: ";cin>>Basic;
        cout<<"\nDo you want to enter custom Bonus? (Y/N): ";
        cin>>check;
        if(check=='y'||check=='Y'){
            float Bonus;
            cout<<"\nBonus Amount: ";cin>>Bonus;
            Emp.push_back(EmployeeMaster(Name, Age, Basic, Bonus)); //employee with custom Bonus
        }
        else
        Emp.push_back(EmployeeMaster(Name, Age, Basic)); //default bonus

        cout<<"\nDo you want to enter another employee? (Y/N): ";
        cin>>check;
    }

    int i=0;
    cout<<"\nTotal "<<Emp.size()<<" employees added! Displaying Details:";
    for (EmployeeMaster &E : Emp){ //for loop for vectors using reference variable
        cout<<"\n\nEmployee "<<++i;
        E.DisplayDetails();
    }
    cout<<"\n\nEnd Of Program!\n";

    cout<<endl<<"24CE129 _ DIKSH Trambadia";
    return 0;
}