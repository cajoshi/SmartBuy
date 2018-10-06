#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Mobile{
    string name;
    float price;
    int memory;
public:
    void accept();
    void display();
};

void Mobile::accept()
{
    cout<<"\nEnter mobile details : ";
    cout<<"\nName : ";
    getline(cin,name);

    cout<<"\nPrice : ";
    cin>>price;
    cout<<"Memory storage : ";
    cin>>memory;
}
//----------------------------------------------
void Mobile::display()
{
    cout<<"\nName : "<<name<<endl;
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
    fout.open("Data.txt",ios::out);

    Mobile M;

    for(int i=0;i<n;i++)
    {
        M.accept();
        fout.write( (char*)&M , sizeof(M));
    }

    fout.close();
}
//-----------------------------------------------

void displayFile()
{
    ifstream fin;
    Mobile M1;

    fin.open("Data.txt",ios::in);

    while(fin)
    {
        fin.read((char*)&M1, sizeof(M1));

        if(fin.eof()!=0)
            break;

        M1.display();
    }

    fin.close();
}
//-----------------------------------------------

int main()
{

    int ch;

    do{
        cout<<"\n========MENU========="<<endl;
        cout<<"1. Create directory."<<endl;
        cout<<"2. Display details."<<endl;
        cout<<"6. Exit"<<endl;

        cout<<"Enter your choice : ";
        cin>>ch;

        switch(ch)
        {
            case 1 :    createFile();
                        break;

            case 2 :    displayFile();
                        break;
        }

    }while(ch!=6);


    return 0;
}



