#include <bits/stdc++.h>
using namespace std;
#include "NodeTypes.h";
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
    BTNode *root = NULL;
    while (1)
    {
        char menuOption = menu();
        if (menuOption == '1')
        {
            cout << "Please enter the name of the file or M (Menu): \n";
            string fileName;
            ifstream inputFile;
            cin >> fileName;
            if (fileName == "M")
            {
                continue;
            }
            inputFile.open(fileName);
            string word;
            while (inputFile >> word)
            { // take word and print
                insert(root, word);
            }
            cout << "BST is created.\n";
        }
        else if (menuOption == '2')
        {
            cout << "Please enter the word to insert in the BST or M (Menu): \n";
            string word;
            cin >> word;
            if (word == "M")
            {
                continue;
            }
            insert(root, word);
            cout << "Word is inserted.\n";
        }
        else if (menuOption == '3')
        {
            cout << "Please enter the word to delete from the BST or M (Menu): \n";
            string word;
            cin >> word;
            if (word == "M")
            {
                continue;
            }
            if (!recTreeSearch(root, word))
            {
                cout << "Node is not present in tree.\n";
            }
            else
            {
                deleteNode(root, word);
                cout << "Successfully deleted the node.\n";
            }
        }
        else if (menuOption == '4')
        {
            cout << "Please enter a word to search for or M (Menu): \n";
            string word;
            cin >> word;
            if (word == "M")
            {
                continue;
            }
            BTNode *temp = recTreeSearch(root, word);
            if (!temp)
            {
                cout << "Node is not present in tree.\n";
            }
            else
            {
                cout << temp->count << " " << temp->data << endl;
            }
        }
        else if (menuOption == '5')
        {

            inOrder(root);
            preOrder(root);
        }
        else if (menuOption == '6')
        {
            cout << "Please enter a word: \n";
            string word;
            cin >> word;
            BTNode *temp = floor(root, word);
            if (!temp)
            {
                cout << "No word is present before the " << word << " in BST.\n";
            }
            else
            {
                cout << temp->data << endl;
            }
        }
        else if (menuOption == '7')
        {
            cout << "Please enter a word: \n";
            string word;
            cin >> word;
            BTNode *temp = ceiling(root, word);
            if (!temp)
            {
                cout << "No word is present after the " << word << " in BST.\n";
            }
            else
            {
                cout << temp->data << endl;
            }
        }
        else if (menuOption == '8')
        {

            string fileName;
            ifstream inputFile;
            cout << "Please enter the name of the file to create the BST or M (Menu): \n";
            cin >> fileName;
            if (fileName == "M")
            {
                continue;
            }
            inputFile.open(fileName);
            string word;
            BTNode *temp;
            while (inputFile >> word)
            { // take word and print
                insert(temp, word);
            }
            if (isEqual(root, temp))
            {
                cout << " Both BST are equal.\n";
            }
            else
            {
                cout << " BST's are not equal. \n";
            }
        }
        else if (menuOption == '9')
        {

            int numOfNodes = 0;
            countNodes(root, numOfNodes);
            int htOfTree = height(root);
            int wdOfTree = width(root);
            int wtOfTree = weight(root);
            auto smallest = treeMinimum(root)->data;
            auto biggest = treeMaximum(root)->data;
            cout << "(1) The number of nodes in the tree : " << numOfNodes << "\n(2) The height of the tree: " << htOfTree << "\n(3) The width of the tree: " << wdOfTree << "\n(4) The weight of the tree: "<<wtOfTree<<"\n(5) The smallest word and the biggest word (in alphabetical order) stored in the tree: "<<smallest<<", " <<biggest<<"\n";
        }
        else if (menuOption == 'Q')
            break;
    }

    return 0;
}