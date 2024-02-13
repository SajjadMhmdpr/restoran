#include "person.h"


ostream& operator<<(ostream& out ,const Person& p )
{
    out<<"id = "<<p._id<<" , name = "<<p._name<<" , city = "<<p._city
            <<" , address = "<<p._address<<"\n"<<"email = "<<p._email
            <<" , username = "<<p._username<<" , pass = "<<p._pass
           <<" , type = "<<p._type;
    return  out;
}
