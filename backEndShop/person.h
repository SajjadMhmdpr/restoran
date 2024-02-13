#ifndef PERSON_H
#define PERSON_H
#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Person
{
    friend ostream& operator<<(ostream& out ,const Person& p );
public:
    Person(){};


public:
    int _id;
    string _name;
    string _city;
    string _address;
    string _email;
    string _username;
    string _pass;
    string _type;
};







#endif // PERSON_H
