#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <list>
#include <math.h>
#include <cstdio>
#include <algorithm>
#include "Mobile.h"
using namespace std;

//------------------------------------------------
/*
Accept Data
*/
void Mobile::accept()
{
    cout << "-------------------------" << endl;
    cout<<"Enter mobile details : " << endl;
    cout << "-------------------------" << endl;
    cout<<"\nName : ";
    cin >> name;
    cout<<"Price : ";
    cin>>price;
    cout<<"Memory storage : ";
    cin>>memory;

}
//----------------------------------------------
/*
Display Data
*/
void Mobile::display()
{
    cout << "-------------------------" << endl;
    cout<<"Name : "<<name<<endl;
    cout<<"Price : "<<price<<endl;
    cout<<"Memory : "<<memory<<endl;
}
//-----------------------------------------------
/*
Overloaded Display data
*/
void Mobile::display(int cnt)
{
    cout << "-------------------------" << endl;
    cout<< cnt << ".Name : "<<name<<endl;
    cout<<"  Price : "<<price<<endl;
    cout<<"  Memory : "<<memory<<endl;
}
