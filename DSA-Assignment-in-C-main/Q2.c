//Delete function for a binary tree

#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new binary tree node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to find the minimum value node in a binary tree
struct TreeNode* minValueNode(struct TreeNode* node) {
    struct TreeNode* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete a node from a binary tree
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    // Base case: if the tree is empty
    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the root's key, 
    // then it lies in the left subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key, 
    // then it lies in the right subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    // If the key is same as root's key, then this is the node
    // to be deleted
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest 
        // in the right subtree)
        struct TreeNode* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to inorder traversal of the binary tree
void inorder(struct TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main function
int main() {
    // Creating a binary search tree
    struct TreeNode* root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);
    root->left->left = createNode(20);
    root->left->right = createNode(40);
    root->right->left = createNode(60);
    root->right->right = createNode(80);

    printf("Inorder traversal of the original tree: ");
    inorder(root);
    printf("\n");

    // Deleting a node (e.g., 30) from the binary search tree
    int key = 30;
    root = deleteNode(root, key);
    printf("Inorder traversal after deletion of %d: ", key);
    inorder(root);
    printf("\n");

    return 0;
}
