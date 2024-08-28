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

// Post-order traversal function
void postorderTraversal(TreeNode *root) {
    if (root != NULL) {
        postorderTraversal(root->left);   // Traverse the left subtree
        postorderTraversal(root->right);  // Traverse the right subtree
        printf("%d ", root->value);       // Visit the current node
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

    // Perform post-order traversal
    printf("Post-order Traversal: ");
    postorderTraversal(root);
    printf("\n");

    // Free allocated memory (not shown here for simplicity)
    return 0;
}
