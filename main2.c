#include "src/Tree.h"

int main()
{
    Tree_t* main_tree_pre = fread_tree("logs/text_logs/preorder_log.txt", PREORDER);
    Tree_t* main_tree_in = fread_tree("logs/text_logs/inorder_log.txt",  INORDER);
    Tree_t* main_tree_post = fread_tree("logs/text_logs/postorder_log.txt", POSTORDER);

    int dump_file_num = 0;
    tree_dump(main_tree_pre);

    graph_script_geenrate(main_tree_pre, &dump_file_num);
    graph_script_geenrate(main_tree_in, &dump_file_num);
    graph_script_geenrate(main_tree_post, &dump_file_num);

    return 0;
}