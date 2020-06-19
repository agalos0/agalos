#ifndef NODE_H
#define NODE_H

class node
{
    public:
        char str[25];
        node *leftchild;
        node * rightchild;
        char *d;
        int Height;

        node();
        node(char *);
        virtual ~node();

    protected:

    private:

};

#endif // NODE_H
