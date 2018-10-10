#ifndef MOBILE_H
#define MOBILE_H

/*
Store class is the parent class containing number of phones
*/
class Store{
    int n;
public:
    Store() : n(0){}
    void set_n(int n_){n=n_;}
};
/*
Mobile Class inherits from Store  class and contains some of the functionality of the project
*/
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

#endif // MOBILE_H
