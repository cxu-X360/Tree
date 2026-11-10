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
    WRONG_VALUES = -3,

    COUNT_ERRORS,
} Tree_err;


typedef enum
{
    CLASSIC = 0,
    PREORDER = 1,
    INORDER = 2,
    POSTORDER = 3,
    COUNT_PRINT_MODES,
} TREE_PRINT_MODE;
#define TREE_READ_MODE TREE_PRINT_MODE
#define COUNT_READ_MODES COUNT_PRINT_MODES

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

Tree_t* tree_create(Elem_t val);
void tree_destroy(Tree_t* tree);

int tree_insert(Tree_t* tree, Elem_t val);

void fprint_tree(FILE* stream, Tree_t* tree, TREE_PRINT_MODE mode);

int tree_verificator(Tree_t* tree);
void tree_dump(Tree_t* tree);
void graph_script_geenrate(Tree_t* tree, int* dump_num);

Tree_t* fread_tree(FILE* stream, TREE_READ_MODE mode);


#define Elem_t double
#define FMT "%lg"
#define PZ NAN


#endif