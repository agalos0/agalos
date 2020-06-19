#ifndef AVL_H
#define AVL_H
#include "binary.h"
#include "node.h"


class AVL : public binary
{
public:
    node *root;
    AVL();                       //
    ~AVL();                      //distructor
    node *RotateRight(node *);   //right_rotation
    node *RotateLeft(node *);    //left_rotation
    node *Rotate_L_R(node *);    //left_right rotation
    node *Rotate_R_L(node *);    //right_left rotation

    int Height(node *);          //height_of_tree
    int balance(node *);
    int difference(node *);

    void Insert(char *);
    void show(node * , int);
    void inorder(node *);
    void preorder(node *);
    void postorder(node *);
    bool Search(node * , char *);
    node *min_val(node *);
    node *Deletee(node * , char *);

protected:

private:

};
#endif // AVL_H
