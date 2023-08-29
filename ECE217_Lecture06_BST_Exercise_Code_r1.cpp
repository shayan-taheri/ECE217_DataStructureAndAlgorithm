// Binary Search Tree (BST) Operations in C++ Language
// Instructor: Dr. Shayan (Sean) Taheri

#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Create a Tree Node
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Inorder Traversal Operation
void inorder(struct node *root) {
  if (root != NULL) {
    // Traverse left side of root
    inorder(root->left);

    // Traverse root
    cout << root->key << " -> ";

    // Traverse right side of root
    inorder(root->right);
  }
}

// Insertion Operation
struct node *insert(struct node *node, int key) {
  // Return a new node if the tree is empty
  if (node == NULL) return newNode(key);

  // Traverse to the correct location and insert the node
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

// Operation of Finding the Inorder Successor
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  // Find the leftmost leaf (or child)
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// Deletion Operation
struct node *deleteNode(struct node *root, int key) {
  // Return if the tree is empty
  if (root == NULL) return root;

  // Find the node to be deleted
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    // If the node is with only one child or no child
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    // If the node has two children
    struct node *temp = minValueNode(root->right);

    // Place the inorder successor in position of the node to be deleted
    root->key = temp->key;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

// Driver Code
int main() {
    
  // Task 1: Create a Tree Node
	struct node *root = NULL;
	root = insert(root, 2);
	root = insert(root, 9);
	root = insert(root, 5);
	root = insert(root, 4);
	root = insert(root, 3);

	cout << "BST Inorder Traversal: ";
	inorder(root);

  // Task 2: Execute BST Operations on the Created Tree

}