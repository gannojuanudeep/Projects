/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "minheap.h"

// Write your code below this line
HeapNode *replace(HeapNode *node, HeapNode *rep_node)
{
    int l = 0, r = 0;
    if (node->right != NULL)
    {
        if (node->right != rep_node)
        {
            l = 1;
        }
        else
        {
            r = 1;
        }
    }
    else
    {
        l = 1;
    }
    if (node->par != NULL)
    {
        rep_node->par = node->par;
    }
    else
    {
        rep_node->par = NULL;
    }
    node->par = rep_node;

    if (r)
    {
        HeapNode *temp = node->left;
        node->right = rep_node->right;
        if (rep_node->right != NULL)
        {
            rep_node->right->par = node;
        }
        node->left = rep_node->left;
        if (rep_node->left != NULL)
        {
            rep_node->left->par = node;
        }
        rep_node->left = temp;
        if (temp != NULL)
        {
            temp->par = rep_node;
        }
        rep_node->right = node;
    }
    else
    {
        HeapNode *temp1 = node->right;
        node->right = rep_node->right;
        if (rep_node->right != NULL)
        {
            rep_node->right->par = node;
        }
        node->left = rep_node->left;
        if (rep_node->left != NULL)
        {
            rep_node->left->par = node;
        }
        rep_node->right = temp1;
        if (temp1 != NULL)
        {
            temp1->par = rep_node;
        }
        rep_node->left = node;
    }
    return rep_node;
}
void Heapup(HeapNode *root, HeapNode *node)
{
    if (node == root)
    {
        return;
    }
    else
    {
        while (node->par != NULL)
        {
            if (node->val >= node->par->val)
            {
                return;
            }
            else
            {
                replace(node->par, node);
            }
        }
        return;
    }
}
void Heapdown(HeapNode *root, HeapNode *node)
{
    if (node->left == NULL && node->right == NULL)
    {
        return;
    }
    else if (node->left != NULL && node->right != NULL)
    {
        if (node->left->val > node->val)
        {
            HeapNode *t;
            t = replace(node, node->left);
            Heapdown(root, t->left);
        }
        else
        {
            HeapNode *t;
            t = replace(node, node->right);
            Heapdown(root, t->right);
        }
    }
    else
    {
        if (node->left == NULL)
        {
            if (node->right->val > node->val)
            {
                HeapNode *t;
                t = replace(node, node->right);
                Heapdown(root, t->right);
            }
        }
        else
        {
            if(node->left->val>node->val){
            HeapNode *t;
             t = replace(node, node->left);
            Heapdown(root, t->left);
            }
        }
    }
}
MinHeap::MinHeap()
{
    
}

void MinHeap::push_heap(int num)
{
    if (size == 0)
    {
        root = new HeapNode(num);
        size++;
        return;
    }
    else
    {
    }
}

int MinHeap::get_min()
{
    return root->val;
}

void MinHeap::pop()
{
}

MinHeap::~MinHeap()
{
    if (root)
    {
        delete root;
    }
}