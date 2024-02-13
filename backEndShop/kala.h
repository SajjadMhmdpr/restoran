#ifndef KALA_H
#define KALA_H
#include<string>
#include<vector>
#include<iostream>
#include<iomanip>
#include"comment.h"
using namespace std;


class Kala
{
    friend ostream& operator<<(ostream& out ,const Kala& k );
public:
    Kala();
    void print();
    void print2();
    void decreaseCount(int c);

public:
    int _id;
    string _name;
    int _price;
    string _description;
    int _amount;
    string _category;
    string _city;
    vector<Comment> comments;
    int countBuy;
};






#endif // KALA_H
