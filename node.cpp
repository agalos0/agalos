#include "node.h"
#include <cstring>

node::node()
{

}

node::~node()
{

}

node::node(char *o)
{
    strcpy(str , o);
}
