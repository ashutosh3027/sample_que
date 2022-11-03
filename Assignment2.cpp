#include <bits/stdc++.h>
using namespace std;
#include "NodeTypes.h"
#include "BinaryTree.cpp";
#include "BinarySearchTree.cpp";
char menu()
{
    cout << "\n\n\nBinary Search Tree (BST)\n";
    cout << "-----------------------------------------------------\n\n\n\n";
    cout << "1. Create BST from File\n2. Add Word to BST\n3. Delete Word from BST\n4. Search for Word in BST\n5. Traverse BST\n6. What Comes Before Word in BST?\n7. What Comes After Word in BST?\n8. Compare BSTs\n9. Statistics\nQ. Quit\n\n\n\n";
    cout << "Please enter an option\n";
    char c;
    cin >> c;
    return c;
}
int main()
{
    while (1)
    {
        char menuOption = menu();
        if (menuOption == 'Q')
            break;
    }

    return 0;
}