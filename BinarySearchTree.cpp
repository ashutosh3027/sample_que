#include <bits/stdc++.h>
#include "NodeTypes.h";
#include "BinaryTree.cpp";
using namespace std;
BTNode *recTreeSearch(BTNode *root, string key) // performs a recursive search for key in the BST
{
  if(root==NULL) return NULL;
  if(root->data<key){
    return recTreeSearch(root->right, key);
  }   
  else if(root->data>key){
    return recTreeSearch(root->left, key);
  }
  else{
    return root;
  }
}
BTNode *treeMinimum(BTNode *root) // finds the smallest node in the BST
{
    BTNode* current = root;
    while (current->left != NULL)
        current = current->left;
     
    return current;
}
BTNode *treeMaximum(BTNode *root) // finds the largest node in the BST
{
    BTNode* current = root;
    while (current->right != NULL)
        current = current->right;
     
    return current;
}
BTNode *inOrderSuccessor(BTNode *node) // finds the inorder successor of a node in the BST
{
    if (node == NULL)
        return NULL;
    // If node has a Right Child
    if (node->right != NULL)
    {
        // Move to Right Node
        node = node->right;
        // Move to the extreme left
        while (node->left != NULL)
            node = node->left;
        return node;
    }
    while (node)
    {
        BTNode *temp = node->parent;
        if (temp == NULL)
            break;
        if (temp->left == node)
            return temp;
        else
            node = temp;
    }
    return NULL;
}
BTNode *ceiling(BTNode *root, string key)
{
    if (root == NULL)
        return NULL;
    if (root->data < key)
    {
        return ceiling(root->right, key);
    }
    else
    {
        if (root->left == NULL)
            return root;
        return ceiling(root->left, key);
    }
}
BTNode *deleteNode(BTNode *root, string key)
{
    if (root == NULL)
        return root;
    if (root->data > key)
    {
        root->left = deleteNode(root->left, key);
        return root;
    }
    else if (root->data < key)
    {
        root->right = deleteNode(root->right, key);
        return root;
    }
    if (root->left == NULL)
    {
        BTNode *temp = root->right;
        return temp;
    }
    else if (root->right == NULL)
    {
        BTNode *temp = root->left;
        return temp;
    }
    else
    {
        BTNode *succParent = root;
        BTNode *succ = root->right;
        while (succ->left != NULL)
        {
            succParent = succ;
            succ = succ->left;
        }
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
        root->data = succ->data;
        root->count = succ->count;

        return root;
    }
}
BTNode *floor(BTNode *root, string key)
{
    // Base cases
    if (root == NULL)
        return NULL;
    if (root->data == key)
        return root;
    else if (root->data < key)
    {
        BTNode *temp = floor(root->right, key);
        if (temp == NULL)
            return root;
        else
            return temp;
    }
    else if (root->data > key)
        return floor(root->left, key);
    return NULL;
}
BTNode *inOrderPredecessor(BTNode *node)
{
    if (node == NULL)
        return NULL;
    if (node->left)
    {
        BTNode *pred = node->left;
        while (pred->right)
            pred = pred->right;
        return pred;

    }
    return node->parent;
   
}
bool insert(BTNode *root, string key)
{
    if(root==NULL){
        root = createBTNode(NULL, key);
        return true;
    }
    if (key < root->data)
    {
        if (root->left == NULL)
        {
            root->left = createBTNode(root, key);
            return true;
        }
        return insert(root->left, key);
    }
    else if (key > root->data)
    {
        if (root->right == NULL)
        {
            root->right = createBTNode(root, key);
            return true;
        }
        return insert(root->right, key);
    }
    else
    {
        root->count++;
        return false;
    }
}
