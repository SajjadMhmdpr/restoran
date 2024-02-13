#ifndef USER_H
#define USER_H
#include<vector>
#include"person.h"
#include"factor.h"
using namespace std;


class User : public Person
{
public:
    User(){}
    void print();
    User operator=(const Person& p);
    void addFactor(vector<Factor>& cart);

public:
    vector<Factor> _factor;
};

#endif // USER_H
