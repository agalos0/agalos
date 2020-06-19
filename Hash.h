#ifndef HASH_H
#define HASH_H
#include <iostream>
#include <string>
#include "node.h"

class Hash : public node
{
public:
    char arxiko[30];
    char **pinakas = new char*[255000];


    Hash(int);  //ctor
    ~Hash(); //dctor
    int convertToASCII(char *word);
    void Insert(char *);
    bool Search(char *);

protected:

private:

};
#endif // HASH_H
