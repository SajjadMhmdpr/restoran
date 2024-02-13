#include "admin.h"


void Admin::print()
{
    cout << setiosflags(ios::left) << setw(10) << "id" << setw(20) << "Name"
         << setw(20) << "City" << setw(30) << "Address"<< setw(30) << "Email"<< setw(20) << "Username"
         << setw(20) << "password"<< setw(20) << "type"<< setiosflags(ios::fixed | ios::showpoint)<<endl;


    cout << fixed<<left << setw(10) << _id << setw(20) << _name
         << setw(20) << _city << setw(30) << _address
         << setw(30) << _email<< setw(20) << _username
         << setw(20) << _pass<< setw(20) << _type<<endl;


    cout<<endl;
}

Admin Admin::operator=(const Person &p)
{
    _id = p._id;
    _name = p._name;
    _city = p._city;
    _address = p._address;
    _email = p._email;
    _username = p._username;
    _pass = p._pass;
    _type = p._type;

    return  *this;
}
