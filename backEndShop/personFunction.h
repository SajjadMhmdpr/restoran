#ifndef PERSONFUNCTION_H
#define PERSONFUNCTION_H
#include<string>
#include<vector>
#include"person.h"
#include"user.h"
#include"admin.h"
using namespace std;

void setUserAndAdmin(vector<User>& userList,vector<Admin>& adminList , vector<Person>& personList)
{
    User u;
    Admin a;

    for(int i=0 ; i<(int)personList.size() ; i++)
    {
        if(personList[i]._type == "user")
        {
            u=personList[i];
            userList.push_back(u);
        }
        else if(personList[i]._type == "admin")
        {
            a=personList[i];
            adminList.push_back(a);
        }
    }
}


Kala searchKala(vector<Kala>& KalaLis , int id)
{
    for(int i=0 ; i<(int)KalaLis.size() ; i++)
    {
        if(KalaLis[i]._id==id)
            return KalaLis[i];
    }

    Kala k;
    k._name="deleted";
    k._id = -1;
    k._price=0;

    return  k;
}
void convert_stFactor_to_Factor(User& user , stFactor& stFactor , vector<Kala>& KalaList)
{
    int i=0;
    Factor f;

    while (stFactor.id[i] > -1)
    {
        f._kala = searchKala(KalaList,stFactor.id[i]);
        f._count = stFactor.count[i];
        user._factor.push_back(f);
        i++;
    }

}
void setFactorForUsers(vector<User>& userList , vector<stFactor>& stFactorList , vector<Kala>& KalaList)
{
    for(int i=0 ; i<(int)userList.size() ; i++)
    {
        for(int j=0 ; j<(int)stFactorList.size() ; j++)
        {
            if(userList[i]._username == stFactorList[j].username)
            {
                convert_stFactor_to_Factor(userList[i],stFactorList[j],KalaList);
            }
        }
    }
}


bool searchUsername(string& u,vector<Person>& personList)
{
    bool f=false;
    for(int i=0 ; i<(int)personList.size() ; i++)
    {
        if(personList[i]._username == u)
            f=true;
    }
    return  f;
}
bool searchPass(string& p,vector<Person>& personList)
{
    bool f=false;
    for(int i=0 ; i<(int)personList.size() ; i++)
    {
        if(personList[i]._pass == p)
            f=true;
    }
    return  f;
}
bool searchId(int id,vector<Person>& personList)
{
    bool f=false;
    for(int i=0 ; i<(int)personList.size() ; i++)
    {
        if(personList[i]._id == id)
            f=true;
    }
    return  f;
}
bool chekPasswordCharacter(string& p)
{
    bool num=0,w=0,ch=0;
    for(int i=0 ; i<(int)p.size() ; i++)
    {
        int x;
        x=p[i];
        if((x>=99 && x<=122) || (x>=65&&x<=90))
            w=true;
        if(x>=48&&x<=57)
            num=true;
        if((x>=33&&x<=47)||(x>=58&&x<=64) || (x>=91&&x<=96) || (x>=123&&x<=126))
            ch=true;
    }

    if(num && w && ch)
        return true;
    else
        return false;
}
int productId(vector<Person>& personList)
{
    int id=4;
    while (searchId(id,personList))
    {
        id = (rand()%100)+1;
    }

    return  id;
}


int searchIdU(int id,vector<User>& userList)
{
    for(int i=0 ; i<(int)userList.size() ; i++)
    {
        if(userList[i]._id == id)
            return i;
    }
    return -1;
}
int searchIdP(int id,vector<Person>& personList)
{
    for(int i=0 ; i<(int)personList.size() ; i++)
    {
        if(personList[i]._id == id)
            return i;
    }
    return -1;
}


void updateCommentAndFactorUsername(string s1 , string s2
                                    ,vector<Comment>&comments , vector<stFactor>& factors )
{
    for(int i=0 ; i<(int)comments.size() ; i++)
    {
        if(comments[i]._username==s1)
            comments[i]._username = s2;
    }

    for(int i=0 ; i<(int)factors.size() ; i++)
    {
        if(factors[i].username==s1)
            factors[i].username = s2;
    }
}




























#endif // PERSONFUNCTION_H
