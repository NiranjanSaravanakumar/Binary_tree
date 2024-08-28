#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary tree
typedef struct Node {
    int data;              // Data to be stored in the node
    struct Node* left;     // Pointer to the left child
    struct Node* right;    // Pointer to the right child
} Node;

// Function to create a new node with the given data
Node* createNode(int data) {
    // Allocate memory for the new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    // Check if memory allocation was successful
    if (newNode == NULL) {
        printf("Error allocating memory!\n");
        exit(1);
    }

    // Initialize the node's data and pointers
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Function to print the tree in-order (for demonstration purposes)
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);         // Visit left subtree
        printf("%d ", root->data);            // Print node data
        inorderTraversal(root->right);        // Visit right subtree
    }
}

// Main function to demonstrate the usage of the node structure
int main() {
    // Create nodes for the binary tree
    Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(2);
    root->left->right = createNode(7);
    root->right->left = createNode(12);
    root->right->right = createNode(18);

    // Print the tree in-order
    printf("In-order traversal of the binary tree:\n");
    inorderTraversal(root);
    printf("\n");

    // Free allocated memory (not shown in this example for brevity)
    // Free the tree nodes here

    return 0;
}
