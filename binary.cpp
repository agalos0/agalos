#include "node.h"
#include "binary.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

binary::binary()
{
    root = NULL;
}

void binary::Insert(char *new_string)   //δεχεται μια συμβολοσειρα κατα την κληση της
{
    node *newnode = new node;           //για καθε στοιχειο που εισαγεται δημιουργειται ενας δεικτης κομβου
    node *parent;
    strcpy(newnode->str , new_string);  //γινεται αντιγραφη του δεικτη του νεου στοιχειου στο δεικτη κομβου
    newnode->leftchild = NULL;          //ο αριστερος
    newnode->rightchild = NULL;         //και ο δεξιος κομβος παιρνουν την τιμη NULL
    if(root == NULL)
        root = newnode;
    else
    {
        node *parent_node = root;
        while(parent_node!=NULL)
        {
            parent = parent_node;
            if(strcmp(new_string , parent_node->str) > 0)
                parent_node = parent_node->rightchild;
            else
                parent_node = parent_node->leftchild;
        }
        if(strcmp(new_string , parent->str) < 0)
            parent->leftchild = newnode;
        else
            parent->rightchild = newnode;
    }

}

void binary::inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->leftchild);
        cout<<root->str<<endl;
        inorder(root->rightchild);
    }
    return;

}

void binary::preorder(node *root)
{
    if(root!=NULL)
    {
        cout<<root->str<<endl;
        preorder(root->leftchild);
        preorder(root->rightchild);
    }
}

void binary::postorder(node * root)
{
    if(root!=NULL)
    {
        postorder(root->leftchild);
        postorder(root->rightchild);
        cout<<root->str<<endl;
    }
}

bool binary::Search(node *temp, char *key)
{
    if(temp == NULL)
        return false;
    if(strcmp(temp->str , key) == 0)
        return true;
    if(strcmp(temp->str , key) > 0)
        return Search(temp->leftchild , key);
    if(strcmp(temp->str , key) < 0)
        return Search(temp->rightchild , key);
}

node *binary::Delete(node *root , char *off)
{
    if(root == NULL)
        return root;
    if(strcmp(root->str , off) > 0)
        root->leftchild = Delete(root->leftchild , off);
    else if(strcmp(root->str , off) < 0)
        root->rightchild = Delete(root->rightchild , off);
    else
    {
        if(root->leftchild == NULL)
        {
            node *temp1 = root->rightchild;
            //delete(root);
            return temp1;
        }
        else if(root->rightchild == NULL)
        {
            node * temp2 = root->leftchild;
            //delete(root);
            return temp2;
        }
        else
        {
            node *temp = root->rightchild;
            while(temp->leftchild != NULL)
                temp = temp->leftchild;
            strcpy(root->str , temp->str);
            root->rightchild = Delete(root->rightchild , temp->str);
        }
    }
    return root;
}

binary::~binary()
{
    //dctor
}
