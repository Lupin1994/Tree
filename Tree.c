#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Tree.h"

Ttree* tree_create(Ttree *root, int value){

    Ttree *root = malloc(sizeof(Ttree));
    root->value = value;
    root->parent_node = NULL;
    root->left_node = NULL;
    root->right_node = NULL;
}

Ttree* tree_addNode(Ttree *root, int value){
    Ttree *current_root = root, *current_parent;
    Ttree *new_node = malloc(sizeof(Ttree));
    new_node->value = value;

    while (current_root != NULL)
    {
        current_parent = current_root;
        if (value < current_root->value)
        {
            current_root = current_root->left_node;
        }
        else
        {
            current_root = current_root->right_node;
        }   
    }
    new_node->parent_node = current_parent;    
    new_node->left_node = NULL;
    new_node->right_node = NULL;
    if (value < current_parent->value)
    {
        current_parent->left_node = new_node;
    }
    else
    {
        current_parent->right_node = new_node;
    }
    return root;
}

Ttree* tree_searchValue(Ttree *root, int value){
    Ttree *current_root = root;

    while (current_root->value != value && current_root != NULL)
    {
        if (value < current_root->value )
        {
            current_root = current_root->left_node;
        }
        else
        {
            current_root = current_root->right_node;
        }   
    }
    return current_root;
}

Ttree* tree_minValue(Ttree *root){
    Ttree *min_value = root;
    while(min_value->left_node != NULL){
        min_value = min_value->left_node;
    }
    return min_value;
}

Ttree* tree_maxValue(Ttree *root){
    Ttree *max_value = root;
    while(max_value->right_node != NULL){
        max_value = max_value->right_node;
    }
    return max_value;
}

Ttree* function_return_node_toReplace_delete_value(Ttree *root){
    Ttree *current_node = root, *search_value = NULL;
    if (current_node->right_node != NULL)
    {
        return tree_minValue(current_node->right_node);
    }

    search_value = current_node->parent_node;

    while ((search_value != NULL) && (current_node == search_value->right_node))
    {
        current_node = search_value;
        search_value = search_value->parent_node;
    }
    return search_value;
}

Ttree* tree_removeValue(Ttree *root, int value){

    Ttree *current_node = root, *remove_value = NULL, *node_before_remove_value = NULL;

    if (tree_searchValue(root, value) == NULL)
    {
        printf("The value to be deleted was not found");
    }

    remove_value = tree_searchValue(root, value);

    // У удаляемого узла нет поддеревьев
    if (remove_value->left_node == NULL && remove_value->right_node == NULL)
    {
        node_before_remove_value = remove_value->parent_node;
        if (remove_value == node_before_remove_value->right_node)
        {
            node_before_remove_value->right_node = NULL;
        }
        else
        {
            node_before_remove_value->left_node = NULL;
        }
        free(remove_value);
    }

    // У удаляемого узла одно поддерево
    // Первый случай - поддерево справа

    if ((remove_value->left_node == NULL) && (remove_value->right_node != NULL))
    {
        node_before_remove_value = remove_value->parent_node;

        if(remove_value == node_before_remove_value->right_node){
            node_before_remove_value->right_node = remove_value->right_node;
        }
        else{
            node_before_remove_value->left_node = remove_value->right_node;
        }
        free(remove_value);
    }

    // У удаляемого узла одно поддерево
    // Второй случай - поддерево слева

    if ((remove_value->right_node == NULL) && (remove_value->left_node != NULL))
    {
        node_before_remove_value = remove_value->parent_node;

        if (remove_value == node_before_remove_value->right_node)
        {
            node_before_remove_value->right_node = remove_value->left_node;
        }
        else
        {
            node_before_remove_value->left_node = remove_value->left_node;
        }
        free(remove_value);
    }
    
    // У удаляемого узла два поддерева
    Ttree *node_instead_remove_value, node_before_instead_value;
    if ((remove_value->left_node != NULL) && (remove_value->right_node != NULL))
    {
        node_instead_remove_value = function_return_node_toReplace_delete_value(remove_value);
        remove_value->value = node_instead_remove_value->value;
        if (node_instead_remove_value->right_node == NULL)
        {
            node_before_instead_value = node_instead_remove_value->parent_node;
        }
        else{
            node_before_instead_value->parent_node->left_node = node_before_remove_value->right_node;
        }
        free(remove_value)
    }
    

}
    
