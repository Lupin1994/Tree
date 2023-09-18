#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Tree.h"

int main()
{
    int value_for_root, value;
    char stop_char;
    printf("Write value for root: ");
    scanf("%d", &value_for_root);
    Ttree *root = tree_create(root, value_for_root);
    do
    {
        printf("\nWrite value: ");
        scanf("%d", &value);
        tree_addNode(root, value);
        getchar();
        printf("Next (y/n)? ");
        stop_char = getchar();
    } while (stop_char == 'y');
    //root = tree_minValue(root);
    //root = tree_searchValue(root, 5);
    tree_printIn_forwardOrder(root);
    root = tree_removeValue(root, 6);
    printf("\n");
    tree_printIn_forwardOrder(root);
}
