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

void menu(){
    int cnt;
    int ch;

    do{
        cout<<"\n========MENU========="<<endl;
        cout<<"1. Create directory."<<endl;
        cout<<"2. Display details."<<endl;
        cout<<"3. Buy a phone."<<endl;
        cout<<"4. Search for a phone"<<endl;
        cout<<"5. View cart"<<endl;
        cout<<"6. Edit cart"<<endl;
        cout<<"7. Exit"<<endl;

        cout<<"Enter your choice : ";
        cin>>ch;

        switch(ch)
        {
            case 1 :    createFile();
                        break;


            case 2 :    cnt=displayFile();
                        break;

            case 3 :    buyPhone(cnt);
                        break;

            case 4 :    search_ph();
                        break;
            case 5:     cartDisplay();
                        break;
            case 6:		modifyCart();
            			break;
            case 7:    exitDeleteDatabase();
                        break;
            default:
                        cout << "-------------------------" << endl;
                        cout << "Please Enter correct Choice" << endl;

        }

    }while(ch!=7);

}
