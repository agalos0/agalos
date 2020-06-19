#include "node.h"
#include "binary.h"
#include "AVL.h"
#include "Hash.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>
#include <math.h>
#include <cctype>
#include <sstream>
#define W 255000
#define S 1000
#include <bits/stdc++.h>
#define counte 100000

using namespace std;

int main()
{
    //char *pinakas_full = new char[W];   //για ολες τις λεξεις
    //char s;

    char **sorted = new char*[W]; //δισδιαστατος πινακας που θα αποθηκευονται μονο οι λεξεις του κειμενου.
    for(int j=0 ; j<W ; j++)
        sorted[j] = new char[30];


//--------------------------------------------------------------------------------Διαβασμα_αρχειου/Τροποποιησεις--------------------------------------------------------------------
    string word , filename;
    fstream file;
    filename = "small-file.txt";
    file.open(filename.c_str());   //ανοιγμα αρχειου

    unsigned int counter = 0;
    unsigned int i=0 , f , k;
    while(file >> word)       //διαβαζω μονο τις λεξεις(χωρις χαρακτηρες κενου).
    {
        k = 0;
        for(f=0 ; f<word.length() ; f++)  //περναω γραμμα προς γραμμα την λεξη απο το string στον βασικο πινακα.
        {
            if((word[f] >='a' && word[f] <= 'z') || (word[f] >='A' && word[f] <= 'Z'))   //εξαιρουνται χαρακτηρες που δεν ειναι γραμματα της αλφαβητου.
            {
                sorted[i][k] = word[f];
                k++;   //μετρητης γραμμων.
            }
        }
        sorted[i][k] = '\0';  //διαμορφωνεται το μηκος καθε γραμμης.
        counter++;
        i++;
    }
    file.close();


    clock_t time;
//---------------------------------------------BINARY_SEARCH_TREE------------------------------------------------------------------------------------------------------------------
    binary a;

    //INSERT_BINARY_TREE
    time = clock();
    for(i = 0 ; i < counter ; i++)  //γινεται εισαγωγη των λεξεων μεσω της συναρτησης Insert στο δυαδικο δενδρο αναζητησης.
    {
        a.Insert(sorted[i]);
    }
    time = clock() - time;
    cout<<"->time_for_Insert_binary_tree: "<<(float)time/CLOCKS_PER_SEC<<" seconds"<<endl;  //εμφανιση χρονου.

    //SEARCH_BINARY_TREE
    time = clock();
    for(i = 0 ; i < S ; i++)   //γινεται αναζητηση των λεξεων απο την συναρτηση Search(1000 λεξεις).
    {
        a.Search(a.root , sorted[i]);
        //cout<<"1"<<endl;
    }
    time = clock() - time;
    cout<<"->time_for_search_binary_tree: "<<(float)time/CLOCKS_PER_SEC<<" seconds"<<endl;  //εμφανιση χρονου.

    //INORDER_BINRAY_TREE
    time = clock();
    a.inorder(a.root);
    time = clock() - time;
    cout<<"->time_for_inorder_binary_tree: "<<(float)time/CLOCKS_PER_SEC<<" seconds"<<endl;

    //PREORDER_BINARY_TREE
    time = clock();
    a.preorder(a.root);
    time = clock() - time;
    cout<<"->time_for_preorder_binary_tree: "<<(float)time/CLOCKS_PER_SEC<<" seconds"<<endl;

    //POSTORDER_BINARY_TREE
    time = clock();
    a.postorder(a.root);
    time = clock() - time;
    cout<<"->time_for_postorder_binary_tree: "<<(float)time/CLOCKS_PER_SEC<<" seconds"<<endl;

    //DELETE_BINARY_TREE
    time = clock();
    for(i = 0 ; i < S ; i++)
    {
        a.Delete(a.root , sorted[i]);
    }
    time = clock() - time;
    cout<<"->time_for_Delete_binary_tree: "<<(float)time/CLOCKS_PER_SEC<<" seconds"<<endl;  //εμφανιση χρονου.



//-----------------------------------------------------------AVL--------------------------------------------------------------------------------------------------------------------
    AVL b;

    //INSERT_AVL
    time = clock();
    for(i = 0 ; i < counter ; i++)
    {
        b.Insert(sorted[i]);
        //cout<<"1"<<endl;
    }
    time = clock() - time;
    cout<<"->time_for_Insert_AVL_tree: "<<(float)time/CLOCKS_PER_SEC<<" seconds"<<endl;

    //SEARCH_AVL
    time = clock();
    for(i = 0 ; i < S ; i++)
    {
        b.Search(b.root , sorted[i]);
    }
    time = clock() - time;
    cout<<"->time_for_Search_AVL_tree: "<<(float)time/CLOCKS_PER_SEC<<" seconds"<<endl;

    //INORDER_AVL
    time = clock();
    b.inorder(b.root);
    time = clock() - time;
    cout<<"->time_for_inorder_AVL_tree: "<<(float)time/CLOCKS_PER_SEC<<" seconds"<<endl;

    //PREORDER_AVL
    time = clock();
    b.preorder(b.root);
    time = clock() - time;
    cout<<"->time_for_preorder_AVL_tree: "<<(float)time/CLOCKS_PER_SEC<<" seconds"<<endl;

    //POSTORDER_AVL
    time = clock();
    b.postorder(b.root);
    time = clock() - time;
    cout<<"->time_for_postorder_AVL_tree: "<<(float)time/CLOCKS_PER_SEC<<" seconds"<<endl;

    //DELETE_AVL
    time = clock();
    for(i = 0 ; i < S ; i++)
    {
        b.Delete(b.root , sorted[i]);
    }
    time = clock() - time;
    cout<<"->time_for_Delete_AVL: "<<(float)time/CLOCKS_PER_SEC<<" seconds"<<endl;  //εμφανιση χρονου.


//----------------------------------------------------------------------------Hash_Table---------------------------------------------------------------------------------------

    Hash c(counter);

    //INSERT_HASH_TABLE
    time = clock();
    for(i = 0 ; i < counte ; i++)
    {
        c.Insert(sorted[i]);
    }
    time = clock() - time;
    cout<<"->time_for_Insert_Hash_Table: "<<(float)time/CLOCKS_PER_SEC<<" seconds"<<endl;

    //SEARCH_SEARCH_HASH_TABLE
    time = clock();
    for(i = 0 ; i < S ; i++)
    {
        c.Search(sorted[i]);
    }
    time = clock() - time;
    cout<<"->time_for_Search_Hash_Table: "<<(float)time/CLOCKS_PER_SEC<<" seconds"<<endl;

}
