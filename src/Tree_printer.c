#define DEBUG
#include "Tree.h"

#define FPRINT_SEP(stream) fprintf((stream),"__________________________________________________________________\n");


static void _node_viz_print(Node_t* node, FILE* stream, int level)
{
    START_FUNC

    if (!node) return;

    _node_viz_print(node->right, stream, level+1);

    if(level > 0) fputc('|', stream);
    for (int i = 0; i < 4*level; i++) fputc(' ', stream);
    fprintf(stream, "----"FMT"\n", node->val);
    
    _node_viz_print(node->left, stream, level+1);

    END_FUNC
}

static void _node_fprint_preorder(Node_t* node, FILE* stream, int level)
{
    START_FUNC
    if (!node) return;

    fputc('{', stream);

        fprintf(stream,FMT" ", node->val);
        _node_fprint_preorder(node->left, stream, level);
        _node_fprint_preorder(node->right, stream, level);

    fputc('}', stream);

    END_FUNC
}

static void _node_fprint_inorder(Node_t* node, FILE* stream, int level)
{
    START_FUNC
    if (!node) return;

    fputc('{', stream);

        _node_fprint_preorder(node->left, stream, level);
        fprintf(stream,FMT" ", node->val);
        _node_fprint_preorder(node->right, stream, level);

    fputc('}', stream);

    END_FUNC
}
static void _node_fprint_postorder(Node_t* node, FILE* stream, int level)
{
    START_FUNC
    if (!node) return;

    fputc('{', stream);

        _node_fprint_preorder(node->left, stream, level);
        _node_fprint_preorder(node->right, stream, level);
        fprintf(stream,FMT" ", node->val);

    fputc('}', stream);

    END_FUNC
}

static void (*node_fprint_funcs[])(Node_t*, FILE*, int) = 
{
    _node_viz_print,
    _node_fprint_preorder, 
    _node_fprint_inorder, 
    _node_fprint_postorder
};

void fprint_tree(FILE* stream, Tree_t* tree, TREE_PRINT_MODE mode)
{
    START_FUNC
    CHECK(tree);

    if (mode < 0 || mode >= COUNT_PRINT_MODES)
    {
        fprintf(stderr, RED"WRONG PRINT mode, try again later one of this variants:\n"
                                          "\t0 - CLASSIC;\n"
                                          "\t1 - PREORDER;\n"
                                          "\t2 - INORDER;\n"
                                          "\t3 - POSTOORDER;\n");
    }

    FPRINT_SEP(stream);

    int start_level = 0;
    node_fprint_funcs[mode](tree->root, stream, start_level);
    fputc('\n', stream);

    FPRINT_SEP(stream);

    END_FUNC
    return;
}
