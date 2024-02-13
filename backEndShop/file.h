#ifndef FILE_H
#define FILE_H
#include"person.h"
#include"kala.h"
#include"comment.h"
#include<factor.h>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cstring>
using namespace std;


Person extractPerson(string& s1 , string& s2)
{

    int start = 0;
    int end = 0;
    Person p;

    end = s1.find(" , name = ");
    p._id = stoi(s1.substr(5,end-5));

    start = end + 10;
    end = s1.find(" , city = ");
    p._name = s1.substr(start,end-start);

    start = end + 10;
    end = s1.find(" , address = ");
    p._city = s1.substr(start,end-start);

    start = end + 13;
    p._address = s1.substr(start,s1.size()-start);

//----------------

    start = 8;
    end = s2.find(" , username = ");
    p._email = s2.substr(start,end-start);

    start = end + 14;
    end = s2.find(" , pass = ");
    p._username = s2.substr(start,end-start);

    start = end + 10;
    end = s2.find(" , type = ");
    p._pass = s2.substr(start,end-start);

    start = end + 10;
    p._type = s2.substr(start,s2.size()-start);

    return p;
}
void readPersonTextFileAndSetVector(vector<Person>&persons)
{
    ifstream inputTXT("E:\\university\\lessons\\pishrafte\\final Project\\person.txt"
                      , ios::in);
    if(!inputTXT)
        cout<<"cant open TXT file";

    string line1 , line2;
    Person p;

    while(!inputTXT.eof())
    {
        getline(inputTXT,line1,'\n');
        getline(inputTXT,line2,'\n');
        inputTXT.get();
        p=extractPerson(line1,line2);
        persons.push_back(p);
        //persons[p.id] = p;
    }


}


Kala extractKala(string& s1 , string& s2)
{
    int start = 0;
    int end = 0;
    Kala k;

    end = s1.find(" , name = ");
    k._id = stoi(s1.substr(5,end-5));

    start = end + 10;
    end = s1.find(" , price = ");
    k._name = s1.substr(start,end-start);

    start = end + 11;
    end = s1.find(" , description = ");
    k._price = stod(s1.substr(start,end-start));

    start = end + 17;
    end = s1.find(" , amount = ");
    k._description = s1.substr(start,s1.size()-start);

//-------------------

    start = 9;
    end = s2.find(" , category = ");
    k._amount = stoi(s2.substr(start,end-start));

    start = end + 14;
    end = s2.find(" , city = ");
    k._category = s2.substr(start,end-start);


    start = end + 10;
    k._city = s2.substr(start,s2.size()-start);

    return k;
}
void readKalaTextFileAndSetVector( vector<Kala>&kalas)
{
    ifstream inputTXT("E:\\university\\lessons\\pishrafte\\final Project\\kala.txt"
                      , ios::in);
    if(!inputTXT)
        cout<<"cant open TXT file";

    string line1,line2;
    Kala k;
    //int i=0 ;

    while(!inputTXT.eof())
    {
        getline(inputTXT,line1,'\n');
        getline(inputTXT,line2,'\n');
        inputTXT.get();
        k=extractKala(line1,line2);
        kalas.push_back(k);
        //i++;
    }


}


Comment extractComment(string& s)
{
    int start = 0;
    int end = 0;
    Comment c;

    end = s.find(" , username = ");
    c._idKala = stoi(s.substr(5,end-5));

    start = end + 14;
    end = s.find(" , comment = ");
    c._username = s.substr(start,end-start);

    start = end + 13;
    end = s.find(" , star = ");
    c._text = s.substr(start,end-start);


    start = end + 10;
    end = s.find(" , show = ");
    c._star = stoi(s.substr(start,end-start));


    start = end + 10;
    c._show = stoi(s.substr(start,s.size()-start));

    return c;
}
void readCommentTextFileAndSetVector( vector<Comment>&comments)
{
    ifstream inputTXT("E:\\university\\lessons\\pishrafte\\final Project\\comment.txt"
                      , ios::in);
    if(!inputTXT)
        cout<<"cant open TXT file";

    string line;
    Comment c;
    //int i=0;

    while(!inputTXT.eof())
    {
        getline(inputTXT,line,'\n');
        inputTXT.get();
        c=extractComment(line);
        comments.push_back(c);
        //i++;

    }


}


stFactor extractFactor(string& s)
{
    int start = 0;
    int end = 0;
    int start2,end2,i=0,k;
    stFactor f;

    end = s.find(" , price = ");
    start2=5;
    end2 = s.find(",");
    if(end2>end)
    {
        f.id[i] = stoi(s.substr(start2,end-start2));
        i++;
    }
    while(end2<=end)
    {
        k=end2-start2;
        f.id[i] = stoi(s.substr(start2,k));
        i++;
        start2 = end2+1;
        end2 = s.find(",",start2);
        if(end2>end)
        {
            f.id[i] = stoi(s.substr(start2,end-start2));
            i++;
        }
    }



    i=0;
    start = end + 11;
    end = s.find(" , count = ");
    start2 = start;
    end2 = s.find(",",start2);
    if(end2>end)
    {
        f.price[i] = stoi(s.substr(start2,end-start2));
        i++;
    }
    while(end2<=end)
    {
        k=end2-start2;
        f.price[i] = stoi(s.substr(start2,k));
        i++;
        start2 = end2+1;
        end2 = s.find(",",start2);
        if(end2>end)
        {
            f.price[i] = stoi(s.substr(start2,end-start2));
            i++;
        }
    }

    i=0;
    start = end + 11;
    end = s.find(" , username = ");
    start2 = start;
    end2 = s.find(",",start2);
    if(end2>end)
    {
        f.count[i] = stoi(s.substr(start2,end-start2));
        i++;
    }
    while(end2<=end)
    {
        k=end2-start2;
        f.count[i] = stoi(s.substr(start2,k));
        i++;
        start2 = end2+1;
        end2=s.find(",",start2);
        if(end2>end)
        {
            f.count[i] = stoi(s.substr(start2,end-start2));
            i++;
        }
    }



    start = end + 14;
    f.username = s.substr(start,s.size()-start);

    return f;
}
void readFactorTextFileAndSetVector( vector<stFactor>&factors)
{
    ifstream inputTXT("E:\\university\\lessons\\pishrafte\\final Project\\factor.txt"
                      , ios::in);
    if(!inputTXT)
        cout<<"cant open TXT file";

    string line;
    stFactor f;
    //int i=0;

    while(!inputTXT.eof())
    {
        getline(inputTXT,line,'\n');
        f =extractFactor(line);
        factors.push_back(f);
        //i++;
    }


}





void writePersonTXT(vector<Person>&persons)
{
    ofstream outputTXT("E:\\university\\lessons\\pishrafte\\final Project\\person.txt"
                       , ios::trunc | ios::out);
    if(!outputTXT)
        cout<<"cant open TXT file";


    for(int i=0 ; i<(int)persons.size() ; i++)
    {
        if(i!=0)
            outputTXT<<"\n";

        outputTXT<<persons[i];

        if(i!=(int)persons.size()-1)
            outputTXT<<"\n";
        /*outputTXT<<"id="<<persons[i]._id<<",name="<<persons[i]._name<<",city="<<persons[i]._city
                <<",address="<<persons[i]._address<<"\n"<<"email="<<persons[i]._email
                <<",username="<<persons[i]._username<<",pass="<<persons[i]._pass
               <<",type="<<persons[i]._type;*/
    }

}

void writeCommentTXT(vector<Comment>&comments)
{
    ofstream outputTXT("E:\\university\\lessons\\pishrafte\\final Project\\comment.txt"
                       , ios::trunc | ios::out);
    if(!outputTXT)
        cout<<"cant open TXT file";


    for(int i=0 ; i<(int)comments.size() ; i++)
    {
        if(i!=0)
            outputTXT<<"\n";

        outputTXT<<comments[i];

        if(i!=(int)comments.size()-1)
            outputTXT<<"\n";

        /*outputTXT<<"id="<<comments[i]._idKala  <<",username="<<comments[i]._username
                <<",comment="<<comments[i]._text<<",star="<<comments[i]._star <<",show="<<comments[i]._show;*/
    }

}

void writeFactorTXT(vector<stFactor>& factors)
{
    ofstream outputTXT("E:\\university\\lessons\\pishrafte\\final Project\\factor.txt"
                       , ios::trunc | ios::out);
    if(!outputTXT)
        cout<<"cant open TXT file";


    for(int i=0 ; i<(int)factors.size() ; i++)
    {
        if(i!=0)
            outputTXT<<"\n";
        int j=0;

        outputTXT<<"id = ";
        while(factors[i].id[j]!=-1)
        {
            outputTXT<<factors[i].id[j];
            j++;
            if(factors[i].id[j]!=-1)
                outputTXT<<",";
        }

        j=0;
        outputTXT<<" , price = ";
        while(factors[i].price[j]!=-1)
        {
            outputTXT<<factors[i].price[j];
            j++;
            if(factors[i].price[j]!=-1)
                outputTXT<<",";
        }

        j=0;
        outputTXT<<" , count = ";
        while(factors[i].count[j]!=-1)
        {
            outputTXT<<factors[i].count[j];
            j++;
            if(factors[i].count[j]!=-1)
                outputTXT<<",";
        }

        outputTXT<<" , username = "<<factors[i].username;

    }



}

void writeKalaTXT(vector<Kala>&kalas)
{
    ofstream outputTXT("E:\\university\\lessons\\pishrafte\\final Project\\kala.txt"
                       , ios::trunc | ios::out);
    if(!outputTXT)
        cout<<"cant open TXT file";

    for(int i=0 ; i<(int)kalas.size() ; i++)
    {
        if(i!=0)
            outputTXT<<"\n";

        outputTXT<<kalas[i];

        if(i!=(int)kalas.size()-1)
            outputTXT<<"\n";
        /*outputTXT<<"id=" << kalas[i]._id << ",name=" << kalas[i]._name
                << ",price=" << kalas[i]._price << ",description=" << kalas[i]._description<< endl
                <<"amount="<< kalas[i]._amount
                << ",category=" << kalas[i]._category << ",city=" << kalas[i]._city;*/
    }

}



#endif // FILE_H
