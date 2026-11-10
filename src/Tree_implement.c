#define DEBUG
#include "Tree.h"


static Node_t* _node_create(Elem_t val)
{
    START_FUNC

    Node_t* node_ptr = (Node_t*) calloc(1, sizeof(Node_t));
    if (!node_ptr)
    {
        fprintf(stderr, "HUYNA PTR of node\n");
        return HUYNA;
    }

    *node_ptr = (Node_t) {.val = val, .left = HUYNA, .right = HUYNA};

    END_FUNC
    return node_ptr;
}

Tree_t* tree_create(Elem_t val)
{
    START_FUNC

    Tree_t* tree = (Tree_t*) calloc(1, sizeof(Tree_t));

    if (tree == HUYNA)
    {
        fprintf(stderr, "HUYNA ptr tree\n");
        tree->error = HUYNA_PTR_TREE;
        return HUYNA;
    }
    
    tree->root = _node_create(val);

    CHECK(tree);

    END_FUNC
    return tree;
}

static int _node_destroy(Node_t* node)
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

static Node_t* _node_insert(Node_t* cur_node, Elem_t val)
{
    START_FUNC
    $(printf("set_val = "FMT", cur node = [ptr = [%p], val = <"FMT">, left = [%p], right = [%p]\n", 
        val, cur_node, (cur_node) ? cur_node->val : PZ, (cur_node) ? cur_node->left : HUYNA, (cur_node) ? cur_node->right : HUYNA);)

    if (!cur_node)
    {
        $(printf("create node\n");)
        return _node_create(val);
    }

    if (val > cur_node->val)
    {
        $(printf("right insert\n");)
        cur_node->right = _node_insert(cur_node->right, val);
        return cur_node;
    }

    $(printf("left insert\n");)
    cur_node->left = _node_insert(cur_node->left, val);
    return cur_node;
}

int tree_insert(Tree_t* tree, Elem_t val)
{
    START_FUNC
    CHECK(tree);

    tree->root = _node_insert(tree->root, val);

    END_FUNC
    return 0;
}





















