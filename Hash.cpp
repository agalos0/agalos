#include "Hash.h"
#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

Hash::Hash(int counter)
{
    for(int i=0 ; i < counter+1 ; i++)
        pinakas[i] = new char[25];
}

Hash::~Hash()
{
    //dctor
}

int Hash::convertToASCII(char *word)
{
    int hash_code = 0;
    for (unsigned int i = 0; i < strlen(word); i++)
    {
        hash_code += pow(2 , i) * int(word[i]);
    }
    return hash_code % 255000;
}



void Hash::Insert(char *word)
{
    //int pinakas_size = 260000;
    //strcpy(arxiko , word);
    int hash_code = convertToASCII(word);

    for(int i = hash_code ; i < 255000 ; i++)
    {
        if(pinakas[i] != NULL)
        {
            strcpy(pinakas[i] , word);
            //*pinakas[i] = *word;
            break;
        }
        if(i == 255000)
            i = 0;
    }
}




bool Hash::Search(char *word)
{
    strcpy(arxiko , word);
    int hash_search = convertToASCII(arxiko);
    if(strcmp(pinakas[hash_search] , word) == 0)
        return 1;
    else
        return 0;

}
