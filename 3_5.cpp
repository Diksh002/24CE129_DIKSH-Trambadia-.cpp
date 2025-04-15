#include<iostream>
#include<string>
using namespace std;

int SuperDigit(long long Number, int z){//max number = 9223372036854775807, so 19 digits
    if(z==1) //base case for recursive function
    return Number;
    else{
        long long Super =0;
        int y=0;

        while(Number>=1){
            Super+= Number%10; //adding each digit
            Number/=10;
            y++;
        }

        return SuperDigit(Super, y); //recursion
    }
}

int main()
{
    string Number, N;
    int k;

    cout<<"\n\nEnter the Number: ";cin>>N;
    cout<<"Enter the number of concatenations of this number: ";cin>>k;

    for(int i=0; i<k; i++){
        Number+=N;
    }

    cout<<"\nThe Super Digit of "<<Number<<" is "<<SuperDigit(stoll(Number), Number.size()); //string to number function

    cout<<endl<<"24CE129 _ DIKSH Trambadia";
    return 0;
}