#include <cstring>
#include <iostream>
#include "node.h"
#include "AVL.h"

using namespace std;


AVL::AVL()
{
    root = NULL;
}

AVL::~AVL()
{
    //dist
}

int AVL::Height(node *x)
{
    int h;
    if(x != NULL)
    {
        int l_height = Height(x->leftchild);
        int r_height = Height(x->rightchild);
        int max_height = max(l_height , r_height);
        h = max_height + 1;
    }
    return h;
}

node *AVL::RotateRight(node * parent)
{
    node *t;
    t = parent->rightchild;
    parent->leftchild = t->rightchild;
    t->leftchild = parent;
    return t;
}

node *AVL::RotateLeft(node *parent)
{
    node *t;
    t = parent->leftchild;
    parent->leftchild = t->rightchild;
    t->rightchild = parent;
    return t;
}

int AVL::difference(node *t)
{
    int l_height = Height(t->leftchild);
    int r_height = Height(t->rightchild);
    int b_factor = l_height - r_height;
    return b_factor;
}

int AVL::balance(node *N)
{
    if (N == NULL)
        return 0;
    return Height(N->leftchild) - Height(N->rightchild);
}

void AVL::Insert(char *new_str)
{
    node *newnode = new node;
    node *parent;
    strcpy(newnode->str , new_str);
    newnode->leftchild = NULL;
    newnode->rightchild = NULL;
    if(root == NULL)
        root = newnode;
    else
    {
        node *parent_node = root;
        while(parent_node!=NULL)
        {
            parent = parent_node;
            if(strcmp(new_str , parent_node->str) > 0)
                parent_node = parent_node->rightchild;
            else
                parent_node = parent_node->leftchild;
        }
        if(strcmp(new_str , parent->str) < 0)
            parent->leftchild = newnode;
        else
            parent->rightchild = newnode;
    }

//    int bal = Height()
}

void AVL::show(node *p, int l)
{
    int i;
    if (p != NULL)
    {
       show(p->rightchild, l + 1);
       cout<<" ";
       if (p == rightchild)
          cout << "Root -> ";
       for (i = 0; i < l&& p != rightchild; i++)
       {
           cout << " ";
           cout << p->d;
           show(p->leftchild, l + 1);
       }
    }
}

void AVL::inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->leftchild);
        cout<<root->str<<endl;
        inorder(root->rightchild);
    }
    else
        return;
}

void AVL::preorder(node *root)
{
    if(root!=NULL)
    {
        cout<<root->str<<endl;
        preorder(root->leftchild);
        preorder(root->rightchild);
    }
}

void AVL::postorder(node * root)
{
    if(root!=NULL)
    {
        postorder(root->leftchild);
        postorder(root->rightchild);
        cout<<root->str<<endl;
    }
}

bool AVL::Search(node *temp , char *Find)
{
    if(temp == NULL)
        return false;
    if(strcmp(Find , temp->str) == 0)
        return true;
    if(Find < temp->str)
        return Search(temp->leftchild , Find);
    if(Find > temp->str)
        return Search(temp->rightchild , Find);
}


//node *AVL::min_val(node *root)
//{
//    node *current = root;
//    while(current->leftchild != NULL)
//        current = current->leftchild;
//    return current;
//}

node *AVL::Deletee(node *root , char *d)
{
    if(root == NULL)
        return root;
    if(strcmp(root->str , d) > 0)
        root->leftchild = Deletee(root->leftchild , d);
    else if(strcmp(root->str , d) < 0)
        root->rightchild = Deletee(root->rightchild , d);
    else
    {
        if((root->leftchild == NULL) || (root->rightchild == NULL))
        {
            node *temp = root->leftchild ? root->leftchild : root->rightchild;

            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
        delete(temp);
        }
//        else
//        {
//            node *temp1 = min_val(root->rightchild);
//            root->d = temp1->d;
//            root->rightchild = Deletee(root->rightchild , temp1->d);
//        }
    }
    if(root == NULL)
        return root;

    root->Height = 1 + max(Height(root->leftchild) , Height(root->rightchild));
    int balancee = balance(root);

    if(balancee > 1 && balance(root->leftchild) >= 0)
        return RotateRight(root);
    if(balancee > 1 && balance(root->leftchild) < 0)
    {
        root->leftchild = RotateLeft(root->leftchild);
        return RotateRight(root);
    }

    if(balancee < -1 && balance(root->rightchild) <= 0)
        return RotateLeft(root);
    if(balancee < -1 && balance(root->rightchild) > 0)
    {
        root->rightchild = RotateRight(root->rightchild);
        return RotateLeft(root);
    }
    return root;
}
