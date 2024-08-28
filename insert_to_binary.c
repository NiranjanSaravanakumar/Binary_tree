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

// Function to insert a new node into the binary search tree
Node* insertNode(Node* root, int data) {
    // If the tree is empty, create and return a new node
    if (root == NULL) {
        return createNode(data);
    }

    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    // Return the (unchanged) node pointer
    return root;
}

// Function to print the tree in-order (for demonstration purposes)
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);         // Visit left subtree
        printf("%d ", root->data);            // Print node data
        inorderTraversal(root->right);        // Visit right subtree
    }
}

// Main function to demonstrate the insertion of nodes
int main() {
    // Create an empty tree
    Node* root = NULL;

    // Insert nodes into the binary search tree
    root = insertNode(root, 10);
    insertNode(root, 5);
    insertNode(root, 15);
    insertNode(root, 2);
    insertNode(root, 7);
    insertNode(root, 12);
    insertNode(root, 18);

    // Print the tree in-order
    printf("In-order traversal of the binary search tree:\n");
    inorderTraversal(root);
    printf("\n");

    // Free allocated memory (not shown in this example for brevity)
    // Free the tree nodes here

    return 0;
}
