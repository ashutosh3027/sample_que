#include <bits/stdc++.h>
#include "NodeTypes.h"
using namespace std;
int moment(BTNode *root);  // finds the moment of the tree
void countNodes(BTNode* root, int& count){
    if(root==NULL) return;
    count++;
    countNodes(root->left, count);
    countNodes(root->right, count);
}
void inOrder(BTNode *root) // performs non-recursive in-order traversal
{
   stack<BTNode*> st;
   cout<<"In order traversal of tree is: \n";
   while(root||!st.empty()){
       while(root){
        st.push(root);
        root= root->left;
       }
       root = st.top();
       st.pop();
        cout << " ( " << root->data << " --> " << root->count << " ), ";
   }
   cout<<endl;
}
void levelOrder(BTNode *root) // performs level-order traversal
{
    queue<BTNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            BTNode *temp = q.front();
            if(temp!=NULL){
                cout << " ( " << temp->data << " --> " << temp->count << " ), ";
            }
            q.pop();
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
BTNode *createBTNode(BTNode *parent, string data)
{
    BTNode *newNode = new BTNode();
    newNode->data = data;
    newNode->count = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = parent;
    return newNode;
}
int height(BTNode *root)
{
    stack<pair<BTNode *, int>> st;
    st.push({root, 0});
    int ht = 0;
    while (!st.empty())
    {
        pair<BTNode *, int> it = st.top();
        st.pop();
        if (it.first == NULL)
            continue;
        if (it.first->left != NULL)
        {
            ht = max(ht, it.second + 1);
            st.push({it.first->left, it.second + 1});
        }
        if (it.first->right != NULL)
        {
            ht = max(ht, it.second + 1);
            st.push({it.first->right, it.second + 1});
        }
    }
    return ht;
}
bool isEmptyTree(BTNode *root)
{
    return root == NULL;
}
bool isEqual(BTNode *root1, BTNode *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL && root2 != NULL)
        return false;
    if (root1 != NULL && root2 == NULL)
        return false;
    if (root1->data != root2->data)
        return false;
    bool f = true;
    f = isEqual(root1->left, root2->left);
    if (!f)
        return f;
    f = isEqual(root1->right, root2->right);
    return f;
}
void preOrder(BTNode *root)
{
    stack<BTNode *> st;
    cout<<"PreOrder travsersal of tree is.\n ";
    while (root || !st.empty())
    {
        while (root)
        {
            cout << " ( " << root->data << " --> " << root->count << " ), ";
            st.push(root);
            root = root->left;
        }
        root = st.top()->right;
        st.pop();
    }
    cout << endl;
}
int weight(BTNode *root)
{
    int count = 0;
    stack<BTNode *> st;

    while (root || !st.empty())
    {
        while (root)
        {
            if (root->left == NULL && root->right == NULL)
                count++;
            st.push(root);
            root = root->left;
        }
        root = st.top()->right;
        st.pop();
    }
    return count;
}
int width(BTNode *root)
{
    queue<BTNode *> q;
    q.push(root);
    int mx = 0;
    while (!q.empty())
    {
        int n = q.size();
        mx = max(mx, n);
        for (int i = 0; i < n; i++)
        {
            BTNode *temp = q.front();
            q.pop();
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    return mx;
}