#include<iostream>
using namespace std;

class Grading{ //abstract base class
    protected:
    float m1, m2, m3, Percent;
    char Grade;
    virtual void CalculateGrade() = 0; //with pure virtual function
};


class UgGrading : private Grading{
    char Grade1, Grade2, Grade3; //derived classs

    void CalculateGrade() override{//each out of 50, total 3 sub, each sub pass or fail
        Percent = (m1+m2+m3)/1.5;
        Grade1 = m1>45?'O':m1>40?'I':m1>35?'A':m1>30?'B':m1>25?'C':m1>17?'D':'F';
        Grade2 = m2>45?'O':m2>40?'I':m2>35?'A':m2>30?'B':m2>25?'C':m2>17?'D':'F'; //different grading system
        Grade3 = m3>45?'O':m3>40?'I':m3>35?'A':m3>30?'B':m3>25?'C':m3>17?'D':'F';
    }

public:
    void InputMarks(int l, int m, int n){
        m1=l;
        m2=m;
        m3=n;
        CalculateGrade();
    }

    void DisplayData(){
        cout<<"\nMarks 1: "<<m1
            <<"\nGrade1: "<<Grade1
            <<"\nMarks 2: "<<m2
            <<"\nGrade2: "<<Grade2
            <<"\nMarks 3: "<<m3
            <<"\nGrade3: "<<Grade3
            <<"\nPercentage: "<<Percent;
    }
};

class PgGrading : private Grading{
    void CalculateGrade() override{//each out of 100, total 2 sub, average pass or fail
        Percent = (m1+m2)/2;
        Grade = Percent>95?'O':Percent>90?'A':Percent>80?'B':Percent>70?'C':Percent>60?'D':Percent>50?'E':'F';
    }//different grading system

public:
    void InputMarks(int l, int m){
        m1=l;
        m2=m;
        CalculateGrade();
    }

    void DisplayData(){
        cout<<"\nMarks 1: "<<m1
            <<"\nMarks 2: "<<m2
            <<"\nPercentage: "<<Percent
            <<"\nGrade: "<<Grade;
    }
};


int main()
{
    int nUG, nPG;
    float m1, m2, m3;
    cout<<"\nEnter number of UG students: ";
    cin>>nUG;
    cout<<"\nEnter number of PG students: ";
    cin>>nPG;

    UgGrading UgStudent[nUG];
    PgGrading PgStudent[nPG];

    cout<<"\n\nEnter marks (out of 50) of all UG students:\n";
    for(int i=0; i<nUG; i++){
        cout<<"\nStudent "<<i+1;
        cout<<"\nMarks 1: ";
        cin>>m1;
        cout<<"Marks 2: ";
        cin>>m2;
        cout<<"Marks 3: ";
        cin>>m3;
        UgStudent[i].InputMarks(m1, m2, m3);
    }

    cout<<"\nEnter marks (out of 100) of all PG students:\n";
    for(int i=0; i<nPG; i++){
        cout<<"\nStudent "<<i+1;
        cout<<"\nMarks 1: ";
        cin>>m1;
        cout<<"Marks 2: ";
        cin>>m2;
        PgStudent[i].InputMarks(m1, m2);
    }

    cout<<"\nDisplaying Details of all UG students:";
    for(int i=0; i<nUG; i++){
        cout<<"\n\nStudent "<<i+1;
        UgStudent[i].DisplayData();
    }

    cout<<"\n\nDisplaying Details of all PG students:";
    for(int i=0; i<nPG; i++){
        cout<<"\n\nStudent "<<i+1;
        PgStudent[i].DisplayData();
    }

    cout<<"\n\n"<<"24CE129_DIKSH Trambadia";

    return 0;
}