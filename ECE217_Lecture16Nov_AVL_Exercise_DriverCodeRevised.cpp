// Binary Search Tree (BST) Operations in C++ Language
// Instructor: Dr. Shayan (Sean) Taheri

// Driver Code
int main() {
    
  // Task 1: Create an AVL Tree Node
  
  // Task 2: Execute AVL Tree Operations on the Created Tree
  
  Node *root = NULL;
  root = insertNode(root, 33);
  root = insertNode(root, 13);
  root = insertNode(root, 53);
  root = insertNode(root, 9);
  root = insertNode(root, 21);
  root = insertNode(root, 61);
  root = insertNode(root, 8);
  root = insertNode(root, 11);
  cout << "Current AVL Tree: " << endl;
  printTree(root, "", true);
  root = deleteNode(root, 13);
  cout << "AVL Tree After Deletion of 13: " << endl;
  printTree(root, "", true);
  
  // Task 3.A (Exercise): Create an AVL Tree with 18 Random Numbers.
  // Task 3.B (Exercise): Show the AVL Tree During the Insertion Process.
  
  // Task 4.A (Exercise): Delete 4 Numbers from Your Tree Randomly.
  // Task 4.B (Exercise): Show the AVL Tree During the Deletion Process.
  
  // Task 5 (Exercise): Get the Tree Left-Height, the Right-Height, and Total-Height.
  
  // Task 6 (Exercise): Get the Balance Factor Value for Three Different Nodes.
  
  // Task 7 (Exercise): Perform Either Rotation-Left or Rotation-Right on a Tree Node
  // and Only Show the Resulting Node and Its Child(s) after the Process

}