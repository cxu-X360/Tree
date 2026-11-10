#define Elem_t double
#define FMT "%lg"
#define PZ NAN

#include "src/Tree.h"

void create_preorder_file(Tree_t* tree)
{
    FILE* preorder_log_file = fopen("logs/text_logs/preorder_log.txt", "a");
    fprint_tree(preorder_log_file, tree, PREORDER);
    fclose(preorder_log_file);
}

void create_inorder_file(Tree_t* tree)
{
    FILE* inorder_log_file = fopen("logs/text_logs/inorder_log.txt", "a");
    fprint_tree(inorder_log_file, tree, INORDER);
    fclose(inorder_log_file);
}

void create_postorder_file(Tree_t* tree)
{
    FILE* postorder_log_file = fopen("logs/text_logs/postorder_log.txt", "a");
    fprint_tree(postorder_log_file, tree, POSTORDER);
    fclose(postorder_log_file);
}


int main()
{
    Elem_t start_val = (Elem_t) 56;

    Tree_t* main_tree = tree_create(start_val);

    for (int i = 0; i < 100; i+=10)
    {
        printf("i = %d) ", i);
        printf("tree_root = [%p]\n", main_tree->root);

        tree_insert(main_tree, (Elem_t) i);
        tree_dump(main_tree);
    }
    tree_insert(main_tree, 77);
    tree_insert(main_tree, 32);
    tree_insert(main_tree, 44);
    tree_insert(main_tree, 67);
    tree_insert(main_tree, 119);
    tree_insert(main_tree, -5);
    tree_insert(main_tree, -1.8);
    tree_insert(main_tree, -0.87);

    tree_dump(main_tree);

    
    create_preorder_file(main_tree);
    create_inorder_file(main_tree);
    create_postorder_file(main_tree);

    int dump_file_num = 0;
    graph_script_geenrate(main_tree, &dump_file_num);

    tree_destroy(main_tree);
    return 0;
}