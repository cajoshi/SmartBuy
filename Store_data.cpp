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
    void display(int);
    char* getName(){return name;}
    float getPrice(){return price;}
    int getMemory(){return memory;}
};


void cartAdd(int);
void cartDisplay();


void cartAdd(int num){
    fstream file;
    file.open("Data.txt", ios::in | ios::binary);
    Mobile m1;
    if(num == 1){
        file.read((char *)&m1, sizeof(m1));

    }else{
        for(int i = 0 ; i < num ; i++){
            file.read((char *)&m1, sizeof(m1));
        }
    }
    m1.display();
    file.close();
    file.open("Cart", ios::out | ios::binary | ios::app);
    file.write((char *)&m1, sizeof(m1));
    file.close();
}

void cartDisplay(){
    Mobile m1;
    fstream file;
    file.open("Cart", ios::in | ios::binary);
    int cnt = 1;
    while(file)
    {
        file.read((char*)&m1, sizeof(m1));

        if(file.eof() != 0)
            break;

        m1.display(cnt);
        cnt++;
        cout<<endl;
    }
    file.close();
}
//------------------------------------------------
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
void Mobile::display()
{
    cout << "-------------------------" << endl;
    cout<<"Name : "<<name<<endl;
    cout<<"Price : "<<price<<endl;
    cout<<"Memory : "<<memory<<endl;
}
//-----------------------------------------------
void Mobile::display(int cnt)
{
    cout << "-------------------------" << endl;
    cout<< cnt << ".Name : "<<name<<endl;
    cout<<"  Price : "<<price<<endl;
    cout<<"  Memory : "<<memory<<endl;
}
//----------------------------------------------
void createFile()
{
    int n;
    cout << "-------------------------" << endl;
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

        //cout<<cnt<<".";
        M1.display(cnt);
        cnt++;
        cout<<endl;
    }

    fin.close();


    return cnt;
}
//----------------------------------------------------

void buyPhone(int cnt)
{
    cout<<cnt << endl;
    displayFile();
    int buy_num;
    cout << "-------------------------" << endl;
   cout<<"\n Which phone do you want to buy?(Enter the number)";
   cin>>buy_num;                //As per the number before the phone (cnt)

    if(buy_num < cnt){
        cartAdd(buy_num);
        cout << "-------------------------" << endl;
        cout<<"Success! Added to cart.";
    }
    else{
        cout << "-------------------------" << endl;
        cout<<"Phone not in store.";
    }
}
//---------------------------------------------------------------------
void search_ph()
{
    void Sname();
    void Sprice();
    void Smemory();

    int param;
    cout << "-------------------------" << endl;
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
    cout << "-------------------------" << endl;
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
            cout << "-------------------------" << endl;
            cout<<"\nPhone record found."<<endl;
            M1.display();
            flag=1;
            break;
        }
    }
    fin.close();

    if(flag==0){
        cout << "-------------------------" << endl;
        cout<<"Record not found."<<endl;
    }

}
//---------------------------------------------------------
void Sprice()
{
    float price;
    int flag;
    ifstream fin;
    Mobile M1;
    flag=0;
    cout << "-------------------------" << endl;
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
            cout << "-------------------------" << endl;
            cout<<"\nPhone record found."<<endl;
            M1.display();
            flag=1;
            break;
        }
    }
    fin.close();

    if(flag==0){
        cout << "-------------------------" << endl;
        cout<<"Record not found."<<endl;
    }

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
    cout << "-------------------------" << endl;
    cout<<"Enter memory of phone to be searched : ";
    cin>>memory;

    fin.open("Data", ios::in | ios::binary);

    while(fin)
    {
        fin.read((char*) &M1, sizeof(M1));

        if(fin.eof()!=0)
            break;



        if(M1.getMemory() == memory)
        {
            cout << "-------------------------" << endl;
            cout<<"\nPhone record found."<<endl;
            M1.display();
            flag=1;
            break;
        }
    }
    fin.close();

    if(flag==0){
        cout << "-------------------------" << endl;
        cout<<"Record not found."<<endl;
    }

}

void exitDeleteDatabase(){
    remove("Data.txt");
    remove("Cart");
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
            case 5:     cartDisplay();
                        break;
            case 6:    exitDeleteDatabase();
                        break;
            default:
                        cout << "-------------------------" << endl;
                        cout << "Please Enter correct Choice" << endl;

        }

    }while(ch!=6);


    return 0;
}
