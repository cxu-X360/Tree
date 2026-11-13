#ifndef NODE_H
#define NODE_H

#ifndef Elem_t
    #define Elem_t double
#endif
#ifndef FMT
    #define FMT "%lg"
#endif
#ifndef PZ
    #define PZ NAN
#endif

typedef enum
{
    LEFT = 0,
    RIGHT = -1,
} LINK_SIDE;

typedef struct _node_t
{
    Elem_t val;
    struct _node_t* left;
    struct _node_t* right;
} Node_t;

Node_t* _node_create();
int _node_init(Node_t* node, Elem_t val);
Node_t* _node_insert(Node_t* cur_node, Elem_t val, int (*cmp)(void* a, void* b));
int _node_link(Node_t* parent, Node_t* child, LINK_SIDE side);      

#endif