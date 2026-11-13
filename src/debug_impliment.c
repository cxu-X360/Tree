#include <stdio.h>
#define DEBUG
#include "Tree.h"


int tree_verificator(Tree_t* tree)
{
    if (tree == HUYNA)
    {
        fprintf(stderr, RED"HUYNA ptr tree\n"DEFUALT);
        tree->error = HUYNA_PTR_TREE;
        return tree->error;
    }

    
    printf("tree_root = [%p]\n", tree->root);
    if (tree->root == HUYNA)
    {
        fprintf(stderr, RED"\033[31m HUYNA ptr on root\n \033[0m"DEFUALT);
        tree->error = HUYNA_PTR_ROOT;
        return tree->error;
    }  

    return 0;
}

void tree_dump(Tree_t* tree)
{
    START_FUNC
    FILE* log_file = fopen("logs/text_logs/log.txt", "a");
    assert(log_file);

    fprintf(log_file, "cur_tree[%p] ", tree);

    if (tree) 
    {
        if (tree->error) fprintf(log_file, "error = <%d>\n", tree->error);
        if (tree->root) fprintf(log_file, "root[%p].val = <"FMT">\n", tree->root, tree->root->val);
    }
    fprint_tree(log_file, tree, CLASSIC);

    fclose(log_file);
    END_FUNC
}



