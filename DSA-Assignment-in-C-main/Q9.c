#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};


struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


int treeHeight(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    else {

        int leftHeight = treeHeight(root->left);
        int rightHeight = treeHeight(root->right);

        return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
    }
}

int main() {

    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);


    int height = treeHeight(root);
    printf("Height of the binary tree is: %d\n", height);

    free(root->left->right);
    free(root->left->left);
    free(root->right);
    free(root->left);
    free(root);

    return 0;
}
