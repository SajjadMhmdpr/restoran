#include "user.h"

void User::print()
{
    /*cout << setiosflags(ios::left) << setw(10) << "id" << setw(15) << "Name"
         << setw(15) << "City" << setw(20) << "Address"<< setw(25) << "Email"<< setw(15) << "Username"
         << setw(15) << "password"<< setw(10) << "type"<< setiosflags(ios::fixed | ios::showpoint)<<endl;*/
    cout << fixed<<left << setw(10) << _id << setw(15) << _name
         << setw(15) << _city << setw(30) << _address
         << setw(30) << _email<< setw(15) << _username
         << setw(15) << _pass<< setw(10) << _type<<endl;
}

User User::operator=(const Person &p)
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

void User::addFactor(vector<Factor> &cart)
{
    for(int i=0 ; i<(int)cart.size() ; i++)
    {
        _factor.push_back(cart[i]);
    }
}
