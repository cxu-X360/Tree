#include "src/Tree.h"

int main()
{
    Tree_t* main_tree = fread_tree("logs/text_logs/inorder_log.txt", INORDER);

    int dump_file_num = 0;
    tree_dump(main_tree);
    graph_script_geenrate(main_tree, &dump_file_num);

    return 0;
}