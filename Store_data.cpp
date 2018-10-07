#include<iostream>
#include<fstream>
#include<cstring>
#include <cstdio>
using namespace std;


class Store{
    int n;
public:
    Store() : n(0){}
    void set_n(int n_){n=n_;}
};

class Mobile : public Store{
    char name[50];
    float price;
    int memory;
public:
    void accept();
    void display();
    char* getName(){return name;}
    float getPrice(){return price;}
    int getMemory(){return memory;}
};


//------------------------------------------------
void Mobile::accept()
{
    cout<<"\nEnter mobile details : ";
    cout<<"\nName : ";
    cin >> name;
    cout<<"Price : ";
    cin>>price;
    cout<<"Memory storage : ";
    cin>>memory;

}
//----------------------------------------------
void Mobile::display()
{
    cout<<"Name : "<<name<<endl;
    cout<<"Price : "<<price<<endl;
    cout<<"Memory : "<<memory<<endl;
}
//-----------------------------------------------

//----------------------------------------------
void createFile()
{
    int n;

    cout<<"\nEnter number of phones : ";
    cin>>n;

    ofstream fout;
    fout.open("Data.txt",ios::out | ios::binary);

    Mobile M;
    M.set_n(n);

    for(int i=0;i<n;i++)
    {
        M.accept();
        fout.write( (char*)&M , sizeof(M));

    }

    fout.close();
}
//-----------------------------------------------

int displayFile()
{
    ifstream fin;
    Mobile M1;
    int cnt=1;

    fin.open("Data.txt",ios::in | ios::binary);

    while(fin)
    {
        fin.read((char*)&M1, sizeof(M1));

        if(fin.eof()!=0)
            break;

        cout<<cnt<<" ";
        M1.display();
        cnt++;
        cout<<endl;
    }

    fin.close();


    return cnt;
}
//----------------------------------------------------

void buyPhone(int cnt)
{
    cout<<cnt;
    displayFile();
    int buy_num;

   cout<<"\n Which phone do you want to buy?(Enter the number)";
   cin>>buy_num;                //As per the number before the phone (cnt)

    if(buy_num < cnt)
        cout<<"Success! Added to cart.";
    else
        cout<<"Phone not in store.";
}
//---------------------------------------------------------------------
void search_ph()
{
    void Sname();
    void Sprice();
    void Smemory();

    int param;

    cout<<"\nSearch by - "<<endl;
    cout<<"1. Name"<<endl;
    cout<<"2. Price"<<endl;
    cout<<"3. Memory"<<endl;
    cout<<"Enter parameter by which to search : ";
    cin>>param;

    switch(param)
    {
        case 1 :    Sname();
                    break;
        case 2 :    Sprice();
                    break;
        case 3 :    Smemory();
                    break;
    }

}
//---------------------------------------------------
void Sname()
{
    char name[50];
    int flag;
    ifstream fin;
    Mobile M1;
    flag=0;

    cout<<"Enter name to be searched : ";
    cin>>name;

    fin.open("Data.txt", ios::in);

    while(fin)
    {
        fin.read((char*) &M1, sizeof(M1));

        if(fin.eof()!=0)
            break;

        if(!strcmp(M1.getName(),name))
        {
            cout<<"\nPhone record found."<<endl;
            M1.display();
            flag=1;
            break;
        }
    }
    fin.close();

    if(flag==0)
        cout<<"Record not found."<<endl;

}
//---------------------------------------------------------
void Sprice()
{
    float price;
    int flag;
    ifstream fin;
    Mobile M1;
    flag=0;

    cout<<"Enter price of phone to be searched : ";
    cin>>price;

    fin.open("Data.txt", ios::in);

    while(fin)
    {
        fin.read((char*) &M1, sizeof(M1));

        if(fin.eof()!=0)
            break;


        if(M1.getPrice() == price)
        {
            cout<<"\nPhone record found."<<endl;
            M1.display();
            flag=1;
            break;
        }
    }
    fin.close();

    if(flag==0)
        cout<<"Record not found."<<endl;

}
//----------------------------------------------------------------------
//---------------------------------------------------------
void Smemory()
{
    int memory;
    int flag;
    ifstream fin;
    Mobile M1;
    flag=0;

    cout<<"Enter memory of phone to be searched : ";
    cin>>memory;

    fin.open("Data.txt", ios::in);

    while(fin)
    {
        fin.read((char*) &M1, sizeof(M1));

        if(fin.eof()!=0)
            break;



        if(M1.getMemory() == memory)
        {
            cout<<"\nPhone record found."<<endl;
            M1.display();
            flag=1;
            break;
        }
    }
    fin.close();

    if(flag==0)
        cout<<"Record not found."<<endl;

}




//----------------------------------------------------------------------
int main()
{


    int cnt;
    int ch;

    do{
        cout<<"\n========MENU========="<<endl;
        cout<<"1. Create directory."<<endl;
        cout<<"2. Display details."<<endl;
        cout<<"3. Buy a phone."<<endl;
        cout<<"4. Search for a phone"<<endl;
        cout<<"5. View cart"<<endl;
        cout<<"6. Exit"<<endl;

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

        }

    }while(ch!=6);


    return 0;
}



