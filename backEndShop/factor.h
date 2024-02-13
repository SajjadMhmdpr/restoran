#ifndef FACTOR_H
#define FACTOR_H
#include<string>
#include"kala.h"
using namespace std;


class stFactor
{
public:
    stFactor()
    {
        for(int i=0 ; i<30 ; i++)
            id[i]=-1;
        for(int i=0 ; i<30 ; i++)
            price[i]=-1;
        for(int i=0 ; i<30 ; i++)
            count[i]=-1;
    }

    int id[30];
    int price[30];
    int count[30];
    string username;
};


class Factor
{
public:
    Factor() : _kala(){};
    void print();
    //Factor operator=(const stFactor& stf);

public:
    Kala _kala;
    int _count;
};




#endif // FACTOR_H
