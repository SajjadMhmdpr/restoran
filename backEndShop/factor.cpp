#include "factor.h"




void Factor::print()
{
    cout << fixed<<left << setw(10) << _kala._id << setw(20) << _kala._name
         << setw(10) << _kala._price << setw(50) << _kala._description
         << setw(20) << _kala._category << setw(20) << _kala._city<<setw(20) << _count<<endl;
}
