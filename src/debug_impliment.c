#define DEBUG
#include "Tree.h"

static int _is_wrong_values(Node_t* node)
{
    if (!node) return 0;

    if ((node->left && (node->left->val > node->val)) 
        || (_is_wrong_values(node->left))) return WRONG_VALUES;
    
    if ((node->right && (node->right->val < node->val))
        || (_is_wrong_values(node->right))) return WRONG_VALUES;

    return 0;
}  

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
        fprintf(stderr, RED"\033[31m HUYNA ptr on root\n \033[0mdefault"DEFUALT);
        tree->error = HUYNA_PTR_ROOT;
        return tree->error;
    }  
    
    if (_is_wrong_values(tree->root))
    {
        fprintf(stderr, RED"\033[31m Wrong values in tree\n \033[0m"DEFUALT);
        tree->error = WRONG_VALUES;
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
    if (tree) fprintf(log_file, "error = <%d> and root[%p].val = <"FMT">\n",tree->error, tree->root, tree->root->val);
    fprint_tree(log_file, tree, CLASSIC);

    fclose(log_file);
    END_FUNC
}



