#ifndef COMMENT_H
#define COMMENT_H
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;

class Comment
{
    friend ostream& operator<<(ostream& out ,const Comment& c );
public:
    Comment(){};
    void print();


public:
    int _idKala;
    string _username;
    string _text;
    int _star;
    bool _show;
};





#endif // COMMENT_H
