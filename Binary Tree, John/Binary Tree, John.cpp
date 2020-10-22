// Mario. This program builds a binary tree of letters.
// It does not use "struc" whichis used in the example programs you have seen.

// If you declare class where everything is public and it does not have any
// functions (methods) it is the same (almost) as a struct.

// struc is a key word from C on which C++ is based,

// You can delete the class Node and public: (lines 15 and 17) and replace them with
// struc Node { if you want to use that instead

#include <iostream>
using namespace std;

// struct Node {

class Node {

public:

    char letter;
    Node* left;
    Node* right;

};

class Tree {

public:

    Tree() {

        root = NULL;

    };

    Node* root;

    //private:

    void AddNode(char letter, Node* newLeaf) {

        cout << "Parent letter = " << newLeaf->letter << endl;

        if (letter < newLeaf->letter) {
            if (newLeaf->left != NULL) {
                cout << "Add leaf for letter " << letter << " to parent " << newLeaf->letter << endl;
                AddNode(letter, newLeaf->left);
            }
            else {
                cout << "create left leaf for letter " << letter << " parent " << newLeaf->letter << endl;
                newLeaf->left = new Node;
                newLeaf->left->letter = letter;
                newLeaf->left->left = NULL;
                newLeaf->left->right = NULL;
            }
        }
        else {
            if (letter >= newLeaf->letter) {
                if (newLeaf->right != NULL) {
                    cout << "letter " << letter << " greater than " << newLeaf->letter << endl;
                    AddNode(letter, newLeaf->right);
                }
                else {
                    cout << "create right leaf for letter " << letter << " parent " << newLeaf->letter << endl;
                    newLeaf->right = new Node;
                    newLeaf->right->letter = letter;
                    newLeaf->right->right = NULL;
                    newLeaf->right->left = NULL;
                }
            }
        }


    };


    void AddNode(char letter) {

        if (root != NULL) {

            AddNode(letter, root);
        }
        else {
            cout << "Set root node for first letter " << letter << endl;

            // The variable root will be changed only once, when the letter (Node) is added
            // to the tree. Once done it will never be NULL again.

            root = new Node;
            root->letter = letter;
            root->left = NULL;
            root->right = NULL;
        }

    };

    void Print() {
        Print(root);
    }

    void Print(Node* node) {
        if (node != NULL) {
            Print(node->left);
            cout << node->letter << endl;
            Print(node->right);
        }
    }
};
int main()
{
    Tree* letterTree = new Tree();

    cout << "Add node A to tree" << endl;
    letterTree->AddNode('A');
    cout << "Add node C to tree" << endl;
    letterTree->AddNode('C');
    cout << "Add node B to tree" << endl;
    letterTree->AddNode('B');
    cout << "Add node Z to tree" << endl;
    letterTree->AddNode('Z');
    cout << "Add node k to tree" << endl;
    letterTree->AddNode('k');

    letterTree->Print();

};