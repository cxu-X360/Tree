#include <stddef.h>
#define DEBUG
#include "Tree.h"


Node_t* _node_create()
{
    START_FUNC

    Node_t* node_ptr = (Node_t*) calloc(1, sizeof(Node_t));
    if (!node_ptr)
    {
        fprintf(stderr, RED"HUYNA PTR of node\n"DEFUALT);
        return HUYNA;
    }

    *node_ptr = (Node_t) {.val = PZ, .left = HUYNA, .right = HUYNA};

    END_FUNC
    return node_ptr;
}

Tree_t* tree_create()
{
    START_FUNC

    Tree_t* tree = (Tree_t*) calloc(1, sizeof(Tree_t));

    if (tree == HUYNA)
    {
        fprintf(stderr, RED"HUYNA ptr tree\n"DEFUALT);
        tree->error = HUYNA_PTR_TREE;
        return HUYNA;
    }
    
    tree->root = NULL;

    END_FUNC
    return tree;
}

int _node_init(Node_t* node, Elem_t val)
{
    START_FUNC

    if(!node)
    {
        fprintf(stderr, RED"Cannot inti node cause of NULL ptr in it\n"DEFUALT); 
        return -1;
    }

    node->val = val;

    return 0;

    END_FUNC
}

int tree_init(Tree_t* tree, Elem_t val)
{
    START_FUNC

    if (!tree)
    {
        fprintf(stderr, RED"Cannot init tree cause of NULL ptr on it\n"DEFUALT); 
        return HUYNA_PTR_TREE;
    }

    Node_t* root = _node_create();
    if (_node_init(root, val))
    {
        fprintf(stderr, RED"Cannot create a root of tree(\n"DEFUALT);
        return HUYNA_PTR_ROOT;
    }

    tree->root = root; 
    tree->height = 1;
    
    END_FUNC

    return 0;
}

int _node_destroy(Node_t* node)
{
    START_FUNC
    

    if (!node) {$(printf("node_destroy ended with HUYNA arg\n");) return 0;}

    _node_destroy(node->left);
    _node_destroy(node->right);

    $(printf("node to destroy: [ptr = [%p], val = <"FMT">, left = [%p], right = [%p]\n", 
        node, (node) ? node->val : PZ, (node) ? node->left : HUYNA, (node) ? node->right : HUYNA); )
    
    free(node);

    return 0;
    END_FUNC    
}

void tree_destroy(Tree_t* tree)
{
    START_FUNC

    CHECK(tree);
    
    if (!tree) return;
    _node_destroy(tree->root);
    $(printf("all node_destroy ended\n");)
    free(tree);

    END_FUNC
}

Node_t* _node_insert(Node_t* cur_node, Elem_t val, int (*cmp)(void* a, void* b))
{
    START_FUNC
    $(printf("set_val = "FMT", cur node = [ptr = [%p], val = <"FMT">, left = [%p], right = [%p]\n", 
        val, cur_node, (cur_node) ? cur_node->val : PZ, (cur_node) ? cur_node->left : HUYNA, (cur_node) ? cur_node->right : HUYNA);)

    if (!cur_node)
    {
        $(printf("create node\n");)
        cur_node = _node_create();
        _node_init(cur_node, val);
        return cur_node;
    }

    if (cmp(&val, &cur_node->val) > 0)
    {
        $(printf("right insert\n");)
        cur_node->right = _node_insert(cur_node->right, val, cmp);
        return cur_node;
    }

    $(printf("left insert\n");)
    cur_node->left = _node_insert(cur_node->left, val, cmp);
    return cur_node;
}

int _node_link(Node_t* parent, Node_t* child, LINK_SIDE side)
{
    if (!parent)
    {
        fprintf(stderr, RED"Can`t link a node cause null ptr parent\n"DEFUALT);
        return PARENT_NULL_PTR;  
    }

    if (side == LEFT) parent->left = child;
    else if (side == RIGHT) parent->right = child;
    else
    {
        fprintf(stderr, RED"Wrong side\n"DEFUALT);
        return WRONG_LINK_SIDE;
    }
    
    return 0;
}

int tree_insert(Tree_t* tree, Elem_t val, int (*cmp)(void* a, void* b))
{
    START_FUNC
    CHECK(tree);

    tree->root = _node_insert(tree->root, val, cmp);

    END_FUNC
    return 0;
}





















