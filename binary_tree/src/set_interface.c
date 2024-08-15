#include <stdio.h>
#include <stdlib.h>
#include "../include/set_interface.h"
#include "../include/static_operations.h"
#include "../include/dynamic_operations.h"

node *subtree_find(node *root, char key)
{
    if (root == NULL)
        return NULL;
    if (root->item > key)
        return subtree_find(root->left, key);
    if (root->item < key)
        return subtree_find(root->right, key);
    return root;
}

node *subtree_find_next(node *root, char key)
{
    if (root == NULL)
        return NULL;
    if (root->item <= key)
    {
        if (root->right != NULL)
            return subtree_find_next(root->right, key);
        else
            return NULL;
    }
    if (root->left != NULL)
    {
        node *next = subtree_find_next(root->left, key);
        if (next != NULL)
            return next;
    }
    return root;
}

node *subtree_find_previous(node *root, char key)
{
    if (root == NULL)
        return NULL;
    if (root->item >= key)
    {
        if (root->left != NULL)
            return subtree_find_previous(root->left, key);
        else
            return NULL;
    }
    if (root->right != NULL)
    {
        node *previous = subtree_find_previous(root->right, key);
        if (previous != NULL)
            return previous;
    }
    return root;
}

void subtree_insert(node *root, node *newNode)
{
    if (newNode->item < root->item)
    {
        if (root->left != NULL)
            subtree_insert(root->left, newNode);
        else
            subtree_insert_before(root, newNode);
    }
    else if (newNode->item > root->item)
    {
        if (root->right != NULL)
            subtree_insert(root->right, newNode);
        else
            subtree_insert_after(root, newNode);     
    }
}