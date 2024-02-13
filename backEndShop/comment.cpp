#include"comment.h"



void Comment::print()
{
    /*cout << setiosflags(ios::left) << setw(20) << "id" << setw(20) << "Username"
         << setw(50) << "Text" << setw(20) << "star"<< setw(20) << "show"<<
            setiosflags(ios::fixed | ios::showpoint)<<endl;*/

    cout <<_username <<" : "<<_text <<" ("<< _star<<" star)";

}

ostream& operator<<(ostream& out ,const Comment& c )
{
    out<<"id = "<<c._idKala  <<" , username = "<<c._username
            <<" , comment = "<<c._text<<" , star = "<<c._star <<" , show = "<<c._show;
    return  out;
}
