#include "Tree.h"

void _node_fread_preorder()
{
    
}

void _node_fread_inorder()
{

}

void _node_fread_postorder()
{

}


static void (*node_fread_funcs[])(Node_t*, FILE*, int) = 
{
    _node_fread_preorder, 
    _node_fread_inorder, 
    _node_fread_postorder
};

Tree_t* fread_tree(FILE* stream, TREE_READ_MODE mode)
{
    if (mode <= 0 || mode >= COUNT_READ_MODES)
    {
        fprintf(stderr, RED"WRONG PRINT mode, try again later one of this variants:\n"
                                          "\t0 - CLASSIC;\n"
                                          "\t1 - PREORDER;\n"
                                          "\t2 - INORDER;\n"
                                          "\t3 - POSTOORDER;\n");
    }

    
    
}