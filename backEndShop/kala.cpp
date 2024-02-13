#include "kala.h"

Kala::Kala()
{

}

void Kala::print()
{
    cout << "id = " << _id  <<"\nName = "<< _name
         << "\nPrice = " << _price<<"$" << "\nDescription = " << _description<< "\nAmount = " <<_amount
         << "\nCategory = " << _category << "\nCity = " << _city<< endl;

    cout<<"\ncomments of customers :\n\n";

    int j=1;
    for(int i=0 ; i<(int)comments.size() ; i++)
    {
        if(comments[i]._show)
        {
            cout<<j<<") ";
            if(comments[i]._show)
                comments[i].print();
            cout<<endl;
            j++;
        }

    }

}

void Kala::print2()
{
    cout << fixed<<left << setw(10) << _id << setw(20) << _name
         << setw(10) << _price << setw(50) << _description<< setw(10) << _amount
         << setw(20) << _category << setw(20) << _city<<endl;
}

void Kala::decreaseCount(int c)
{
    _amount -=c;
}

ostream& operator<<(ostream& out ,const Kala& k )
{
    out<<"id = " << k._id << " , name = " <<k._name
            << " , price = " << k._price << " , description = " << k._description<< endl
            <<"amount = "<<k._amount
            << " , category = " << k._category << " , city = " << k._city;

    return out;
}














