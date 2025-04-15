#include<iostream>
#include<queue>
using namespace std;

class Fuel

{
    protected:
    string fueltype;

    public:

    Fuel(string f)
    {
        fueltype = f;
    }

    void display_fuel()
    {
        cout<<"Fuel name is : "<<fueltype<<endl;
    }
};

class Brand
{
    protected:
    string brandname;

    public:

    Brand(string b)
    {
        brandname = b;
    }

    void display_brand()
    {
        cout<<"Brand name is : "<<brandname<<endl;
    }
};

class Car : public Fuel , public Brand
{
     private:
     string model;

     public:

     Car(string f, string b, string m) : Fuel(f) , Brand(b)
     {
        model = m;
     }

     void display()
     {
         display_fuel();
         display_brand();
         cout<<"Model name is : "<<model<<endl;
     }
};

int main()
{
    int t,i;
    string f,b,m;
     queue<Car> c;

     cout<<"Enter total number of cars : ";
     cin>>t;

     for (i=0 ; i<t ; i++)
     {
        cout<<"Enter fuel of car : ";
        cin>>f;
        cout<<"Enter brand name of fuel : ";
        cin>>b;
        cout<<"Enter model of car : ";
        cin>>m;

        c.push(Car(f,b,m));
     }

     while(!c.empty())
     {
        Car bmw = c.front();
        bmw.display();
        c.pop();
        cout<<endl;
     }

     cout<<endl<<"24CE129 _ DIKSH Trambadia";
     return 0;
}