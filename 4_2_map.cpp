#include<iostream>
#include<map>
using namespace std;

class person
{
    protected:
    int age;
    string name;

    public:
    person()
    {}
    person(string n , int a)
    {
        name = n;
        age = a;
    }
};

class employee : public person
{
    protected:
    int empid;

    public:
    employee()
    {}
    employee(string n, int a, int id) : person(n,a)
    {
        empid = id;
        
    }
};

class manager : public employee
{
    protected:
    string dep;

    public:
    manager()
    {}
    manager(string n, int a, int id,string d) : employee(n,a,id)
    {
        dep = d;
        
    }
    void display()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
        cout<<"ID : "<<empid<<endl;
        cout<<"Department : "<<dep<<endl;
    }
};
int main()
{
    string n,d;
    int a,id,t;
    map <int,manager> m;

    cout<<"Enter total number : ";
    cin>>t;

    for (int i=0;i<t;i++)
    {
    cout<<"Enter name : ";
    cin>>n;
    cout<<"Enter age : ";
    cin>>a;
    cout<<"Enter id : ";
    cin>>id;
    cout<<"Enter department : ";
    cin>>d;

    m[id] = manager(n,a,id,d);
    }
   
    
    

    cout<<"\n\n\n";
    for(auto &i : m)
    {
        i.second.display();
    }

    cout<<endl<<"24CE129 _ DIKSH Trambadia";
    return 0;
}