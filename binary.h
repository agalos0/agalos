#ifndef BINARY_H
#define BINARY_H
#include "node.h"


class binary : public node
{
    public:
    node *root;
    binary();
    void Insert(char *);
    void inorder(node *);
    void preorder(node *);
    void postorder(node *);
    bool Search(node * , char *);
    node *Delete(node * , char *);
    virtual ~binary();

    protected:

    private:

};
#endif // BINARY_H
