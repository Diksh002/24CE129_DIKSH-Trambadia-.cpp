#include<iostream>
using namespace std;

class shape
{
    float radius;

    public:
    void put_radius()
    {
        cout<<"Enter the radius of shape : ";
        cin>>radius;
    }

    float get_radius()
    {
        return radius*radius;
    }

};

class circle : public shape
{
    float  area;

    public:
    void calculate_area()
    {
        area = 2*3.14*get_radius();
        
    }

    void display()
    {
        cout<<"Area of the circle is : "<<area<<endl;
    }
};

int main()
{
    int t,i;
    circle c[50];
   
    cout<<"Enter total number of shape : ";
    cin>>t;

    for(i=0;i<t;i++)
    {
        c[i].put_radius();
        c[i].calculate_area();
        c[i].display();
    }

    cout<<endl<<"24CE129 _ DIKSH Trambadia";
    return 0;
}