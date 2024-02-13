#ifndef ADMIN_H
#define ADMIN_H
#include"person.h"
#include<iostream>
#include<iomanip>
using namespace std;

class Admin : public Person
{
public:
    Admin(){};
    void print();
    Admin operator=(const Person& p);

};

#endif // ADMIN_H
