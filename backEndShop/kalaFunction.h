#ifndef KALAFUNCTION_H
#define KALAFUNCTION_H
#include<iostream>
#include<iomanip>
#include"comment.h"
#include"factor.h"
#include"user.h"
#include"kala.h"
using namespace std;

void setCommentForKala(vector<Kala>& KalaList , vector<Comment>& commentList)
{
    Comment c;

    for(int i=0 ; i<(int)KalaList.size() ; i++)
    {
        for(int j=0 ; j<(int)commentList.size() ; j++)
        {
            if(commentList[j]._idKala == KalaList[i]._id)
            {
                c=commentList[j];
                KalaList[i].comments.push_back(c);
            }
        }
    }
}

void seeProduct(vector<Kala>&kalaList)
{
    cout << setiosflags(ios::left) << setw(10) << "id" << setw(20) << "Name"
         << setw(10) << "Price" << setw(50) << "Description"<< setw(10) << "Amount"<< setw(20) << "Category"
         << setw(20) << "City"<< setiosflags(ios::fixed | ios::showpoint)<<endl;
    for(int i=0 ; i<(int)kalaList.size() ; i++)
        kalaList[i].print2();
}

int searchIdKala(vector<Kala>&kalaList, int id)
{
    for(int i=0 ; i<(int)kalaList.size() ; i++)
    {
        if(kalaList[i]._id == id)
        {
            return i;
        }
    }
    return -1;
}

void seeFactor(vector<Factor>& cart)
{
    cout << setiosflags(ios::left) << setw(10) << "id" << setw(20) << "Name"
         << setw(10) << "Price" << setw(50) << "Description"<< setw(20) << "Category"
         << setw(20) << "City"<<setw(20) << "Number"<< setiosflags(ios::fixed | ios::showpoint)<<endl;
    for(int i=0 ; i<(int)cart.size() ; i++)
        cart[i].print();
}

void updateStfactor(string& username,vector<stFactor>& factors,vector<Factor>& cart)
{
    /*int fi;
    bool f=true;
    for(int i=0 ; i<(int)factors.size() && f ; i++)
    {
        if(factors[i].username == username)
        {
            fi = i;
            f=false;
        }
    }

    f=true;
    int j=0;
    int addIndex;
    while (f)
    {
        if(factors[fi].id[j] == -1)
        {
            addIndex=j;
            f=false;
        }
        j++;
    }


    for(int i=0 ; i<(int)cart.size() ; i++)
    {
        factors[fi].id[addIndex] = cart[i]._kala._id;

        factors[fi].price[addIndex] = cart[i]._kala._price;

        factors[fi].count[addIndex] = cart[i]._count;

        addIndex++;
    }*/


    stFactor factor;
    int addIndex = 0;

    factor.username = username;

    for(int i=0 ; i<(int)cart.size() ; i++)
    {
        factor.id[addIndex] = cart[i]._kala._id;

        factor.price[addIndex] = cart[i]._kala._price;

        factor.count[addIndex] = cart[i]._count;

        addIndex++;
    }

    factors.push_back(factor);



}

void seeCommentAndConfirm(vector<Kala>&kalaList)
{

    for (int i = 0; i < (int)kalaList.size(); i++)
    {
        for (int j = 0; j < (int)kalaList[i].comments.size(); j++)
        {
            if(!kalaList[i].comments[j]._show)
            {
                cout << kalaList[i].comments[j] <<endl;
            }
        }

    }
}

int searchProductId(int id, vector<Kala>&kalaList)
{
    for (int i = 0; i < (int)kalaList.size(); i++)
    {
        if(kalaList[i]._id==id)
            return i;
    }

    return -1;
}

void setCountBuyingOfEachProduct(vector<User>& userList , vector<Kala>&kalaList)
{
    int count=0;

    for (int i = 0; i < (int)kalaList.size(); i++)
    {
        for (int j = 0; j < (int)userList.size(); j++)
        {
            for (int k = 0; k < (int)userList[j]._factor.size(); k++)
            {
                if(userList[j]._factor[k]._kala._id == kalaList[i]._id)
                    count += userList[j]._factor[k]._count;
            }

        }


        kalaList[i].countBuy = count;
        count = 0;
    }


}
























#endif // KALAFUNCTION_H
