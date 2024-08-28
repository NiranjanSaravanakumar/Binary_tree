#include <stdio.h>
#include <stdlib.h>

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

// In-order traversal function
void inorderTraversal(TreeNode *root) {
    if (root != NULL) {
        inorderTraversal(root->left);       // Visit the left subtree
        printf("%d ", root->value);         // Visit the current node
        inorderTraversal(root->right);      // Visit the right subtree
    }
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

    // Perform in-order traversal
    printf("In-order Traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Free allocated memory (not shown here for simplicity)
    return 0;
}
