#ifndef LOGIN_H
#define LOGIN_H
#include"file.h"
#include"personFunction.h"
#include"kalaFunction.h"
#include<time.h>
#include<random>



void chooseKala(string& username,vector<Kala>&kalaList , vector<Factor>& cart
                ,vector<Comment>&comments)
{
    int idKala, index;
    cout<<"\nwhat you want ?\nEnter id : ";
    cin>>idKala;
    cin.get();

    index = searchIdKala(kalaList,idKala);
    while (index==-1)
    {
        cout<<"\n       !! invalid id !!\n";
        cout<<"\nwhat you want ?\nEnter id : ";
        cin>>idKala;
        cin.get();
        index = searchIdKala(kalaList,idKala);
    }

    cout<<endl<<endl;
    kalaList[index].print();

    int choice=0;
    cout<<"\nare you want leave a comment ?\n";
    cout<<"1-yes , 2-no\nenter choice : ";
    cin>>choice;
    cin.get();

    if(choice==1)
    {
        Comment c;
        c._idKala = idKala;
        c._username = username;
        c._show=false;
        cout<<"\nwrite your comment : ";
        getline(cin,c._text,'\n');
        cout<<"\nenter star 1-5 : ";
        cin>>c._star;
        cin.get();

        kalaList[index].comments.push_back(c);
        comments.push_back(c);

        writeCommentTXT(comments);

    }


    cout<<"\n\nare you want add this ware in your cart ?\n";
    cout<<"1-yes , 2-no\nenter choice : ";
    cin>>choice;
    cin.get();

    if(choice==1)
    {
        int num;
        cout<<"\nenter number of this ware who you want : ";
        cin>>num;
        cin.get();

        while (num > kalaList[index]._amount)
        {
            cout<<"\n       !! invalid number !!\n";
            cout<<"enter number of this ware who you want : ";
            cin>>num;
            cin.get();
        }

        Factor c;
        bool flag=true;
        c._kala=kalaList[index];
        c._count = num;

        for(int i=0 ; i<(int)cart.size() ; i++)
        {
            if(c._kala._id==cart[i]._kala._id)
            {
                cart[i]._count+=num;
                flag=false;
            }
        }

        if(flag)
            cart.push_back(c);

        cout<<"\nadded successfully";
        cin.get();

    }



}

void filters(string& username,vector<Kala>&kalaList , vector<Factor>& cart
             ,vector<Comment>&comments )
{
    int choice=0;
    vector<Kala> AfterFilter;
    AfterFilter = kalaList;

    string city,category;
    int beginPrice=-1,endPrice=-1;

    while (choice!=5)
    {
        system("cls");
        cout<<"1)Limitations city\n2)Limitations price\n3)Limitations category\n4)See product\n5)Back\n\n";
        cout<<"enter choice :";
        cin>>choice;
        cin.get();

        if(choice==1)
        {
            cout<<"enter city :";
            cin>>city;
            cin.get();

            for (int i = 0; i < (int)AfterFilter.size(); i++)
            {
                if(AfterFilter[i]._city != city)
                {
                    vector<Kala>::iterator it = AfterFilter.begin() + i;
                    AfterFilter.erase(it);
                    i=-1;
                }
            }
            cout<<"\n\nFilter applied successfully";
            cin.get();
        }
        else if(choice==2)
        {
            cout<<"enter beginPrice :";
            cin>>beginPrice;
            cin.get();
            cout<<"enter endPrice :";
            cin>>endPrice;
            cin.get();

            for (int i = 0; i < (int)AfterFilter.size(); i++)
            {
                if(AfterFilter[i]._price < beginPrice || AfterFilter[i]._price > endPrice)
                {
                    vector<Kala>::iterator it = AfterFilter.begin() + i;
                    AfterFilter.erase(it);
                    i=-1;
                }
            }
            cout<<"\n\nFilter applied successfully";
            cin.get();
        }
        else if(choice==3)
        {
            cout<<"enter category :";
            cin>>category;
            cin.get();

            for (int i = 0; i < (int)AfterFilter.size(); i++)
            {
                if(AfterFilter[i]._category != category)
                {
                    vector<Kala>::iterator it = AfterFilter.begin() + i;
                    AfterFilter.erase(it);
                    i=-1;
                }
            }
            cout<<"\n\nFilter applied successfully";
            cin.get();
        }
        else if(choice==4)
        {
            if(AfterFilter.size()==0)
                cout<<"\n\n     !According to the applied filters there is no product to display!\n";
            else
            {
                seeProduct(AfterFilter);
                int c;
                cout<<"\nare you want choose ware ?\n1-yes , 2-no\nenter choice :";
                cin>>c;
                cin.get();
                if(c==1)
                    chooseKala(username,kalaList,cart,comments);
                cin.get();
            }
        }
        else if(choice==5)
        {
            choice=5;
        }
    }

}

void cartMeno(int id ,vector<User>& userList
              ,vector<Factor>& cart,vector<Kala>& kalaList,vector<stFactor>& factors)
{
    int userIndex = searchIdU(id,userList);
    /*for(int i=0 ; i<(int)userList.size() ; i++)
    {
        if(userList[i]._id==id)
            userIndex = i;
    }*/


    if(cart.size()!=0)
    {
        int choice=0;
        while (choice!=3)
        {
            system("cls");
            seeFactor(cart);
            cout<<"\n\n1)Delete a product from cart\n2)Buying\n3)Back\n\n";
            cout<<"enter choice :";
            cin>>choice;
            cin.get();

            if(choice==1)
            {
                cout<<"\n\nenter id kala for delete : ";
                int c;
                cin>>c;
                cin.get();

                for(int i=0 ; i<(int)cart.size() ; i++)
                {
                    if(c==cart[i]._kala._id)
                    {
                        vector<Factor>::iterator it = cart.begin() + i;
                        cart.erase(it);
                    }
                }

                cout<<"\n\ndeleted successfully";
                cin.get();
            }
            else if(choice==2)
            {

                userList[userIndex].addFactor(cart);

                updateStfactor(userList[userIndex]._username,factors,cart);

                for(int i=0 ; i<(int)cart.size() ; i++)
                {
                    bool f=true;
                    for(int j=0 ; j<(int)kalaList.size() && f ; j++)
                    {
                        if(cart[i]._kala._id==kalaList[j]._id)
                        {
                            kalaList[j].decreaseCount(cart[i]._count);
                            f=false;
                        }
                    }
                }

                writeKalaTXT(kalaList);
                writeFactorTXT(factors);

                system("cls");
                cout<<"this buying factor : \n\n\n";
                seeFactor(cart);
                cin.get();

                cart.clear();

                cout<<"\nbuying successfully";
                cin.get();
            }
            else if(choice==3)
            {
                choice=3;
            }
        }
    }
    else
    {
        cout<<"\n\n       !! your cart is empty !!\n\n";
        cin.get();
    }





}

void changeInformation(int Id,vector<Person>& personList,vector<User>& userList)
{
    bool f=true;

    int u = searchIdU(Id,userList);
    int p = searchIdP(Id,personList);

    int choice=0;
    enum {id=1,username,pass,name,city,address,email,back};
    while (choice!=8)
    {
        system("cls");
        cout<<"1)Change id\n2)Change username\n3)Change password\n4)Change name"
              "\n5)Change city\n6)Change address\n7)Change email\n8)Back\n\n";
        cout<<"enter choice :";
        cin>>choice;
        cin.get();

        if(choice== id)
        {
            cout<<"id :";
            int iidd=0;
            cin>>iidd;
            cin.get();

            while (f)
            {
                if(searchId(iidd,personList) || iidd>99)
                {
                    cout<<"this id is repetitive";
                    cout<<"\nid :";
                    cin>>iidd;
                    cin.get();
                }
                else
                    f=false;
            }
            personList[p]._id = iidd;

            f=true;
        }
        else if(choice== username)
        {
            string s;
            cout<<"username :";
            getline(cin,s,'\n');
            while (f)
            {
                if(searchUsername(s,personList))
                {
                    cout<<"this username is repetitive";
                    cout<<"\nusername :";
                    getline(cin,s,'\n');
                }
                else
                    f=false;
            }
            personList[p]._username = s;

            f=true;
        }
        else if(choice== pass)
        {
            string s;
            cout<<"password :";
            getline(cin,s,'\n');
            f=true;
            while (f)
            {
                f=false;
                if(!chekPasswordCharacter(s))
                {
                    cout<<"! use number and letter and character in your password !";
                    cout<<"\npassword :";
                    getline(cin,s,'\n');
                    f=true;
                }
                if(searchPass(s,personList))
                {
                    cout<<"this password is repetitive";
                    cout<<"\npassword :";
                    getline(cin,s,'\n');
                    f=true;
                }
            }
            personList[p]._pass = s;

            f=true;
        }
        else if(choice== name)
        {
            cout<<"name :";
            getline(cin,personList[p]._name,'\n');
        }
        else if(choice== city)
        {
            cout<<"city :";
            getline(cin,personList[p]._city,'\n');
        }
        else if(choice== address)
        {
            cout<<"address :";
            getline(cin,personList[p]._address,'\n');

        }
        else if(choice== email)
        {
            cout<<"email :";
            getline(cin,personList[p]._email,'\n');

        }
        else if(choice== back)
        {
            userList[u]=personList[p];
            choice=8;
        }
    }
}


void userMeno(User& user,vector<User>& userList
              ,vector<Person>& personList,vector<Kala>&kalaList
              ,vector<Comment>&comments , vector<stFactor>& factors)
{
    int choice=0;
    vector<Factor> cart;
    while (choice!=5)
    {
        system("cls");
        cout<<"1)See product\n2)Cart\n3)Change information\n4)View all purchase history\n5)Back\n\n";
        cout<<"enter choice :";
        cin>>choice;
        cin.get();

        if(choice==1)
        {
            filters(user._username,kalaList , cart,comments);
        }
        else if(choice==2)
        {
            cartMeno(user._id , userList,cart,kalaList,factors);
        }
        else if(choice==3)
        {
            int userIndexU = searchIdU(user._id,userList);

            changeInformation(user._id,personList,userList);


            updateCommentAndFactorUsername(user._username ,userList[userIndexU]._username
                                           ,comments,factors);

            user = userList[userIndexU];

            writePersonTXT(personList);
            writeFactorTXT(factors);
            writeCommentTXT(comments);
        }
        else if(choice==4)
        {
            int userIndex = searchIdU(user._id,userList);

            seeFactor(userList[userIndex]._factor);

            cin.get();
        }
        else if(choice==5)
        {
            choice=5;
        }
    }
}


void changeProductInformation(int Id,vector<Kala>&kalaList)
{
    bool f=true;

    int choice=0;
    enum {id=1,name,price,category,description,city,amount,back};
    while (choice!=8)
    {
        system("cls");
        cout<<"1)Change id\n2)Change name\n3)Change price\n4)Change category"
              "\n5)Change description\n6)Change city\n7)Change amount\n8)Back\n\n";
        cout<<"enter choice :";
        cin>>choice;
        cin.get();

        if(choice== id)
        {
            cout<<"id :";
            int iidd;
            cin>>iidd;
            cin.get();

            while (f)
            {
                if(searchProductId(iidd,kalaList)>-1)
                {
                    cout<<"this id is repetitive";
                    cout<<"\nid :";
                    cin>>iidd;
                    cin.get();
                }
                else
                    f=false;
            }
        }
        else if(choice== name)
        {
            cout<<"name :";
            getline(cin,kalaList[Id]._name,'\n');

        }
        else if(choice== price)
        {
            cout<<"price :";
            cin>>kalaList[Id]._price;
            cin.get();
        }
        else if(choice== category)
        {
            cout<<"category :";
            getline(cin,kalaList[Id]._category,'\n');
        }
        else if(choice== description)
        {
            cout<<"description :";
            getline(cin,kalaList[Id]._description,'\n');
        }
        else if(choice== city)
        {
            cout<<"city :";
            getline(cin,kalaList[Id]._city,'\n');

        }
        else if(choice== amount)
        {
            cout<<"amount :";
            cin>>kalaList[Id]._amount;
            cin.get();

        }
        else if(choice== back)
        {
            choice=8;
        }
    }
}


void takhfif(vector<User>& userList ,vector<Kala>&kalaList , int darsad)
{
    setCountBuyingOfEachProduct(userList,kalaList);

    int max=0;

    for (int i = 0; i < (int)kalaList.size(); i++)
    {
        if(kalaList[i].countBuy > max)
            max = kalaList[i].countBuy;
    }

    max *= 0.6 ;
    darsad = 100 - darsad;

    for (int i = 0; i < (int)kalaList.size(); i++)
    {
        if(kalaList[i].countBuy < max)
        {
            kalaList[i]._price = ((kalaList[i]._price*darsad)/100);
        }

    }
}


void adminMeno(vector<User>& userList ,vector<Kala>&kalaList
               ,vector<Comment>&comments )
{
    int choice=0;
    while (choice!=7)
    {
        system("cls");
        cout<<"1)Confirm comments\n2)Add product\n3)Edit product\n4)Delete product"
              "\n5)View all purchase history\n6)Discount\n7)Back\n\n";
        cout<<"enter choice :";
        cin>>choice;
        cin.get();

        if(choice==1)
        {
            system("cls");
            for (int i = 0; i < (int)comments.size(); i++)
            {
                if(!comments[i]._show)
                {
                    cout <<i<<") ";
                    comments[i].print();
                    cout <<endl;
                }
            }

            cout<<"enter comment id for confirm : ";
            int c;
            cin>>c;
            cin.get();

            if(c<(int)comments.size())
            {
                comments[c]._show = true;
                writeCommentTXT(comments);

                for (int i = 0; i < (int)kalaList.size(); i++)
                {
                    for (int j = 0; j < (int)kalaList[i].comments.size(); j++)
                    {
                        if(kalaList[i].comments[j]._username == comments[c]._username &&
                                kalaList[i].comments[j]._text == comments[c]._text)
                        {
                            kalaList[i].comments[j]._show = true;
                        }
                    }

                }
            }

            cout<<"\n\n      Done";
            cin.get();
        }
        else if(choice==2)
        {
            system("cls");
            seeProduct(kalaList);
            cout<<"\n\n";

            cout<<"are you want to add product ?";
            cout<<"\n1)yes  2)no";
            cout<<"\nenter your choice : ";
            int c;
            cin>>c;
            cin.get();

            if(c==1)
            {
                Kala k;
                bool f=true;

                cout<<"id :";
                cin>>k._id;
                cin.get();

                while (f)
                {
                    if(searchProductId(k._id,kalaList)>-1)
                    {
                        cout<<"this id is repetitive";
                        cout<<"\nid :";
                        cin>>k._id;
                        cin.get();
                    }
                    else
                        f=false;
                }

                cout<<"name :";
                getline(cin,k._name,'\n');

                cout<<"price :";
                cin>>k._price;
                cin.get();

                cout<<"category :";
                getline(cin,k._category,'\n');

                cout<<"description :";
                getline(cin,k._description,'\n');

                cout<<"city :";
                getline(cin,k._city,'\n');

                cout<<"amount :";
                cin>>k._amount;
                cin.get();

                kalaList.push_back(k);
                writeKalaTXT(kalaList);

                cout<<"\n\n        Done";
                cin.get();

            }

        }
        else if(choice==3)
        {
            system("cls");
            seeProduct(kalaList);
            cout<<"\n\n";

            cout<<"\nenter product id : ";
            int c;
            cin>>c;
            cin.get();

            int cc = searchProductId(c,kalaList);

            if(cc>-1)
            {
                changeProductInformation(cc,kalaList);

                writeKalaTXT(kalaList);

                cout<<"\n\n          Done";
                cin.get();
            }
            else
            {
                cout<<"\n\n          !! invalid id !!";
                cin.get();
            }
        }
        else if(choice==4)
        {
            system("cls");
            seeProduct(kalaList);
            cout<<"\n\n";

            cout<<"\nenter product id for delete : ";
            int c;
            cin>>c;
            cin.get();

            int cc = searchProductId(c,kalaList);

            if(cc>-1)
            {
                for(int i=0 ; i<(int)kalaList.size() ; i++)
                {
                    if(i==cc)
                    {
                        vector<Kala>::iterator it = kalaList.begin() + i;
                        kalaList.erase(it);
                    }
                }

                writeKalaTXT(kalaList);

                cout<<"\n\n          Done";
                cin.get();
            }
            else
            {
                cout<<"\n\n          !! invalid id !!";
                cin.get();
            }
        }
        else if(choice==5)
        {
            system("cls");
            cout << setiosflags(ios::left) << setw(10) << "id" << setw(15) << "Name"
                     << setw(15) << "City" << setw(30) << "Address"<< setw(30) << "Email"<< setw(15) << "Username"
                     << setw(15) << "password"<< setw(10) << "type"<< setiosflags(ios::fixed | ios::showpoint)<<endl;
            for (int i = 0; i < (int)userList.size(); i++)
            {
                userList[i].print();
            }

            cout<<"\n\n";

            cout<<"\nenter user id : ";
            int c;
            cin>>c;
            cin.get();

            int cc = searchIdU(c,userList);

            if(cc>-1)
            {
                system("cls");
                seeFactor(userList[cc]._factor);
                cin.get();
            }
            else
            {
                cout<<"\n\n          !! invalid id !!";
                cin.get();
            }
        }
        else if(choice==6)
        {
            cout<<"\n\n";
            cout<<"\nenter a number for discount : ";
            int c;
            cin>>c;
            cin.get();

            if(c>0 && c<100)
            {
                takhfif(userList,kalaList,c);
                writeKalaTXT(kalaList);

                cout<<"\n\n          The discount was successfully applied";
                cin.get();
            }
            else
            {
                cout<<"\n\n          !! invalid discount number !!";
                cin.get();
            }
        }
        else if(choice==7)
        {
            choice=7;
        }
    }
}


void login(vector<Person>& personList,vector<User>& userList
           ,vector<Kala>&kalaList
           ,vector<Comment>&comments , vector<stFactor>& factors)
{
    system("cls");
    string userName,pass;
    cout<<"enter username :";
    cin>>userName;
    cin.get();

    cout<<"enter password :";
    cin>>pass;
    cin.get();

    User u;
    //Admin a;

    bool dontFind=false;
    bool f2=true;
    for(int i=0 ; i<(int)personList.size()&&f2 ; i++)
    {
        if(personList[i]._username==userName && personList[i]._pass==pass)
        {
            dontFind=true;
            f2=false;
            if(personList[i]._type == "user")
            {
                u=personList[i];
                userMeno(u,userList,personList,kalaList,comments,factors);
            }
            else
            {
                //a = personList[i];
                adminMeno(userList,kalaList,comments);
            }
        }
    }

    if(!dontFind)
        cout<<"\n"<<"         !! invalid information !!"<<"\n"
           <<"        please try againe or regirter"<<endl;
    cin.get();

}

void registerPerson(vector<Person>& personList)
{
    system("cls");
    Person p;
    bool f=true;

    cout<<"name :";
    getline(cin,p._name,'\n');
    //cin.get();

    cout<<"city :";
    getline(cin,p._city,'\n');
    //cin>>p._city;
    //cin.get();

    cout<<"address :";
    getline(cin,p._address,'\n');
    /*cin>>p._address;
    cin.get();*/

    cout<<"email :";
    getline(cin,p._email,'\n');
    //cin>>p._email;
    //cin.get();

    cout<<"username :";
    getline(cin,p._username,'\n');
    //cin>>p._username;
    //cin.get();
    while (f)
    {
        if(searchUsername(p._username,personList))
        {
            cout<<"this username is repetitive";
            cout<<"\nusername :";
            getline(cin,p._username,'\n');
            //cin>>p._username;
            //cin.get();
        }
        else
            f=false;
    }


    cout<<"password :";
    getline(cin,p._pass,'\n');
    //cin>>p._pass;
    //cin.get();
    f=true;
    while (f)
    {
        f=false;
        if(!chekPasswordCharacter(p._pass))
        {
            cout<<"! use number and letter and character in your password !";
            cout<<"\npassword :";
            getline(cin,p._pass,'\n');
            f=true;
        }

        if(searchPass(p._pass,personList))
        {
            cout<<"this password is repetitive";
            cout<<"\npassword :";
            getline(cin,p._pass,'\n');
            f=true;
        }

    }


    cout<<"choose your type :\n1)user\n2)admin\n?";
    int ch;
    cin>>ch;
    cin.get();

    if(ch==1)
        p._type="user";
    else if(ch==2)
        p._type="admin";


    p._id = productId(personList);
    cout<<"producted id is :"<<p._id;

    personList.push_back(p);

    cin.get();


}


void firstMeno( vector<Person>& personList ,  vector<User>& userList
               , vector<Admin>& adminList ,vector<Kala>&kalaList
               ,vector<Comment>&comments , vector<stFactor>& factors)
{
    int choice=0;
    while (choice!=3)
    {
        system("cls");
        cout<<"1)Login\n2)Register\n3)Exit";

        cout<<"\n\nenter your choice : ";
        cin>>choice;
        cin.get();

        if(choice==1)
        {
            login(personList,userList,kalaList,comments,factors);
        }
        else if(choice==2)
        {
            registerPerson(personList);
            userList.clear();
            adminList.clear();
            setUserAndAdmin(userList,adminList,personList);
            writePersonTXT(personList);
        }
        else if(choice==3)
        {
            choice=3;
        }
    }

}




























#endif // LOGIN_H
