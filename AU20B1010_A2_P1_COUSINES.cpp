#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *current = NULL;

struct node *add_data(int dat)
{
    /*
    Function to add new nodes in existing tree
    */
    current = new node;
    current->data = dat;
    current->left = NULL;
    current->right = NULL;
    return current;
}

int getLevel(node *root, node *node, int level)
{
    /*
    A function to get the level of an existing tree
    */
    if (root == NULL)
        return 0;
    if (root == node)
        return level;

    // If node is present in left subtree
    int downlevel = getLevel(root->left,
                             node, level + 1);
    if (downlevel != 0)
        return downlevel;

    // If node is not present in left subtree
    return getLevel(root->right, node, level + 1);
}

void printGivenLevel(node *root, node *node, int level)
{
    /*
    A function to print the current level of tree
    */
    if (root == NULL || level < 3)
        return;

    // If current node is parent of a node
    // with given level
    if (level == 3)
    {
        if (root->left == node || root->right == node)
            return;
        if (root->left)
            cout << root->left->data << " ";
        if (root->right)
            cout << root->right->data;
    }

    // Recursion operation for left and right subtrees
    else if (level > 3)
    {
        printGivenLevel(root->left, node, level - 1);
        printGivenLevel(root->right, node, level - 1);
    }
    cout << "  ";
}

void printCousins(node *root, node *node)
{
    /*
    A function to print the cousins of tree or elements of same level
    */

    // storing the level of given node
    int level = getLevel(root, node, 3);

    // Print nodes of given level.
    printGivenLevel(root, node, level);
}

int main()
{
    struct node *head = NULL;

    // initializing the root or parent node of the tree.
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 1;
    head->left = NULL;
    head->right = NULL;

    struct node *traverse = head;

    // Adding new nodes to form a tree
    head->left = add_data(2);
    head->right = add_data(3);

    head->left->left = add_data(4);
    head->left->right = add_data(5);
    head->right->left = add_data(6);
    head->right->right = add_data(7);

    head->left->left->left = add_data(8);
    head->left->left->right = add_data(9);
    head->left->right->left = add_data(10);
    head->left->right->right = add_data(11);
    head->right->left->left = add_data(12);
    head->right->left->right = add_data(13);

    cout << "cousins of level 2 are -> ";
    printCousins(head, head->left);

    return 0;
}
