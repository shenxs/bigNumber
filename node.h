#ifndef NODE_H
#define NODE_H
class node
{
public:
    node();
    ~node();

    //int->node
    //用n来初始化一个节点
    //默认pre,next指针都为空
    node(int n);
    //节点值
    int value;
    node *pre;
    node *next;
};

#endif
