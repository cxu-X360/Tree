#include <stdio.h>
#define DEBUG
#include "Tree.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define READ_ERROR(message) do {fprintf(stderr, RED message DEFUALT);\
                                return -1;} while(0)


static int _node_fread_preorder(Node_t* root, char** source $(, int level))
{
    START_FUNC

    $(printf("before reading a node cur_char = '%c'\n", **source));
    $(printf("cur_level = %d\n", level));
    if (**source == '{')
    {
        int offset = 0;
        Elem_t val = PZ;

        if (sscanf(*source, "{"FMT"%n[{}]", &val, &offset) != 1) 
        {   
            char temp = 0;
            if (sscanf(*source, "{nil}%n%c", &offset, &temp) == 1)
            {
                (*source) = (*source) + offset;
                if (_node_fread_preorder(root, source, level)) READ_ERROR("Can`t continue a recurs\n");
                return 0;
            }        
        
            READ_ERROR("Not val in node\n");
        }
        
        *source = (*source) + offset;

        Node_t* new_node = _node_create();
        _node_init(new_node, val);

        $(printf("after reading a node cur_char = '%c' val = <"FMT">\n", **source, val));
        
        if (_node_fread_preorder(new_node, source, level+1)) READ_ERROR("Can`t continue a recurs\n");

        if (_node_link(root, new_node)) READ_ERROR("Can`t link a node\n");

        (*source)++;

        if (_node_fread_preorder(root, source, level)) READ_ERROR("Can`t continue a recurs\n");
        return 0;
    }

    if (**source == '}' || **source == '\0') return 0;

    fprintf(stderr, RED"WRONG char['%c'] to read\n"DEFUALT, **source);
    return -1;
}

static int _node_fread_inorder(Node_t* root, char** source $(, int level))
{
    START_FUNC



    $(printf("before reading a node cur_char = '%c'\n", **source));
    $(printf("cur_level = %d\n", level));
    if (**source == '{')
    {
        Node_t* new_node = _node_create();
        
        if (_node_fread_preorder(new_node, source $(, level+1))) READ_ERROR("Can`t continue a recurs\n");
        (*source)++;

        int offset = 0;
        Elem_t val = PZ;

        if (sscanf(*source, FMT"%n", &val, &offset) != 1) 
        {   
            char temp = 0;
            if (sscanf(*source, "{nil}%n%c", &offset, &temp) == 1)
            {
                (*source) = (*source) + offset;
                if (_node_fread_preorder(root, source, level)) READ_ERROR("Can`t continue a recurs\n");
                return 0;
            }        
        
            READ_ERROR("Not val in node\n");
        }
        
        *source = (*source) + offset;

        $(printf("after reading a node cur_char = '%c' val = <"FMT">\n", **source, val));
        
        
        if (_node_link(root, new_node)) READ_ERROR("Can`t link a node\n");

        

        if (_node_fread_preorder(root, source $(, level))) READ_ERROR("Can`t continue a recurs\n");
        return 0;
    }

    if (**source == '}' || **source == '\0') return 0;

    fprintf(stderr, RED"WRONG char['%c'] to read\n"DEFUALT, **source);
    return -1;
}

// static int _node_fread_postorder(Node_t* root, char** source)
// {
//     return 0;
// }


static int (*_node_fread_funcs[])(Node_t* root, char** source $(, int level)) = 
{
    _node_fread_preorder, 
    _node_fread_inorder, 
    // _node_fread_postorder
};

static size_t get_file_size(const char* filename)
{
    struct stat file_info = {};

    if (stat(filename, &file_info)) return -fprintf(stderr, RED"cant get stat of file\n"DEFUALT);

    return (size_t) file_info.st_size;
}

Tree_t* fread_tree(const char* filename, TREE_IO_MODE mode)
{
    START_FUNC

    if (mode < 0 || mode > COUNT_MODES - 1)
    {
        fprintf(stderr, RED"WRONG READ mode <%d>, try again later one of this variants:\n"
                                          "\t0 - PREORDER;\n"
                                          "\t1 - INORDER;\n"
                                          "\t2 - POSTOORDER;\n"DEFUALT, mode);
        return NULL;
    }

    FILE* file = fopen(filename, "r");
    size_t file_size = get_file_size(filename);
    char* buffer = calloc(file_size, sizeof(char));
    

    fread(buffer, sizeof(char),file_size , file); 
    fclose(file);
    char* source = buffer;

    Tree_t* tree = tree_create();
    tree_init(tree, PZ);
    if (_node_fread_funcs[mode](tree->root, &source, 0)) 
    {
        fprintf(stderr, RED"ERROR while reading a tree\n"DEFUALT);
        return HUYNA;
    }

    CHECK(tree);

    free(buffer);
    END_FUNC
    return tree;
}