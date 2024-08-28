#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition of a binary tree node
typedef struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to create a new tree node
TreeNode* createNode(int value) {
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to search for a specific value in the binary tree
bool searchTree(TreeNode *root, int target) {
    if (root == NULL) {
        return false; // Base case: the tree is empty or reached a leaf node
    }
    if (root->value == target) {
        return true;  // Node with the target value found
    }
    // Recursively search in the left and right subtrees
    return searchTree(root->left, target) || searchTree(root->right, target);
}

int main() {
    // Creating a binary tree manually
    TreeNode *root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(5);
    root->right->right = createNode(7);

    // Searching for a specific value
    int target = 5;
    if (searchTree(root, target)) {
        printf("Value %d found in the binary tree.\n", target);
    } else {
        printf("Value %d not found in the binary tree.\n", target);
    }

    // Free allocated memory (not shown here for simplicity)
    return 0;
}
