#include <iostream>
#include<iomanip>

#include"file.h"
#include"login.h"

using namespace std;

int main()
{
    srand(time(0));

    vector<Person>persons;
    readPersonTextFileAndSetVector(persons);

    vector<Kala>kalas;
    readKalaTextFileAndSetVector(kalas);

    vector<Comment>comments;
    readCommentTextFileAndSetVector(comments);

    vector<stFactor>factors;
    readFactorTextFileAndSetVector(factors);

    vector<User>users;
    vector<Admin>admins;

    setUserAndAdmin(users,admins,persons);
    setCommentForKala(kalas,comments);
    setFactorForUsers(users,factors,kalas);



    firstMeno(persons,users,admins,kalas,comments,factors);









    return 0;
}
