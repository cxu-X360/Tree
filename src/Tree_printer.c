#define DEBUG
#include "Tree.h"

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
    if (!node) {fprintf(stream, "{nil}"); return;}

    fputc('{', stream);

        fprintf(stream,FMT, node->val);
        _node_fprint_preorder(node->left, stream, level);
        _node_fprint_preorder(node->right, stream, level);

    fputc('}', stream);

    END_FUNC
}

static void _node_fprint_inorder(Node_t* node, FILE* stream, int level)
{
    START_FUNC
    if (!node) {fprintf(stream, "{nil}"); return;}

    fputc('{', stream);

        _node_fprint_preorder(node->left, stream, level);
        fprintf(stream,FMT, node->val);
        _node_fprint_preorder(node->right, stream, level);

    fputc('}', stream);

    END_FUNC
}
static void _node_fprint_postorder(Node_t* node, FILE* stream, int level)
{
    START_FUNC
    if (!node) {fprintf(stream, "{nil}"); return;}

    fputc('{', stream);

        _node_fprint_preorder(node->left, stream, level);
        _node_fprint_preorder(node->right, stream, level);
        fprintf(stream,FMT, node->val);

    fputc('}', stream);

    END_FUNC
}

static void (*_node_fprint_funcs[])(Node_t*, FILE*, int) = 
{
    _node_fprint_preorder, 
    _node_fprint_inorder, 
    _node_fprint_postorder,
    _node_viz_print,
};

void fprint_tree(FILE* stream, Tree_t* tree, TREE_IO_MODE mode)
{
    START_FUNC
    //CHECK(tree);

    if (mode < 0 || mode >= COUNT_MODES)
    {
        fprintf(stderr, RED"WRONG PRINT mode <%d>, try again later one of this variants:\n"
                                          "\t0 - PREORDER;\n"
                                          "\t1 - INORDER;\n"
                                          "\t2 - POSTOORDER;\n"
                                          "\t3 - CLASSIC;\n", mode);
    }

    int start_level = 0;
    if (tree) _node_fprint_funcs[mode](tree->root, stream, start_level);
    else fprintf(stream, "NO tree\n");

    END_FUNC
    return;
}
