#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>


#define HUYNA NULL
#define RED "\033[31m"
#define DEFUALT "\033[0m"

#ifndef Elem_t
    #define Elem_t double
#endif
#ifndef FMT
    #define FMT "%lg"
#endif
#ifndef PZ
    #define PZ NAN
#endif

#ifdef DEBUG
    #define $(...) __VA_ARGS__
    #define START_FUNC printf("%s started\n", __FUNCTION__);
    #define END_FUNC printf("%s ended\n", __FUNCTION__);
    #define CHECK(tree)  do {\
                                if (tree_verificator((tree))) tree_dump((tree)); \
                                assert(!((tree)->error));\
                            } while(0)
#else
    #define $(...) ;
    #define START_FUNC ;
    #define END_FUNC ;
    #define CHECK(tree) do {tree_verificator((tree)); assert(!((tree)->error));} while(0)
#endif


typedef enum 
{
    HUYNA_PTR_TREE = -1,
    HUYNA_PTR_ROOT = -2,
    PARENT_NULL_PTR = -3,
    WRONG_LINK_SIDE = -4,

    COUNT_ERRORS,
} Tree_err;


typedef enum
{
    PREORDER = 0,
    INORDER,
    POSTORDER,
    CLASSIC,
    COUNT_MODES,
} TREE_IO_MODE;

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
  //struct _node_t* parent;

} Node_t;

typedef struct 
{
    Node_t* root;
    Tree_err error;
    int height;
} Tree_t;

Tree_t* tree_create();
int tree_init(Tree_t* tree, Elem_t val);
void tree_destroy(Tree_t* tree);

int tree_insert(Tree_t* tree, Elem_t val);
void fprint_tree(FILE* stream, Tree_t* tree, TREE_IO_MODE mode);

int tree_verificator(Tree_t* tree);
void tree_dump(Tree_t* tree);
void graph_script_geenrate(Tree_t* tree, int* dump_num);

Tree_t* fread_tree(const char* file_name, TREE_IO_MODE mode);


Node_t* _node_create();
int _node_init(Node_t* node, Elem_t val);
Node_t* _node_insert(Node_t* cur_node, Elem_t val);
int _node_link(Node_t* parent, Node_t* child, LINK_SIDE side);


#endif