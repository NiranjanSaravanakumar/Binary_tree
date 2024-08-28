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

// Pre-order traversal function
void preorderTraversal(TreeNode *root) {
    if (root != NULL) {
        printf("%d ", root->value);       // Visit the current node
        preorderTraversal(root->left);    // Traverse the left subtree
        preorderTraversal(root->right);   // Traverse the right subtree
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

    // Perform pre-order traversal
    printf("Pre-order Traversal: ");
    preorderTraversal(root);
    printf("\n");

    // Free allocated memory (not shown here for simplicity)
    return 0;
}
