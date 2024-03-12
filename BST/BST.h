#ifndef BST_H
#define BST_H

class BST {
	
private:

  class BSTNode {

    public:
  
      int element = 0;
      BSTNode * left = nullptr;
      BSTNode * right = nullptr;

      // Constructors
      BSTNode() {}
      BSTNode(int element) { this->element = element; }

      BSTNode(int element, BSTNode * left, BSTNode * right) {
        this->element = element;
        this->left = left;
        this->right = right;
      }

      // Boolean helper functions
      bool isLeaf() const { return (left == nullptr && right == nullptr); }
      bool hasLeft() const { return (left != nullptr); }
      bool hasRight() const { return (right != nullptr); }

  };

  BSTNode * root = nullptr; 
  unsigned int elementCount = 0;          

	
  // Description: Recursive insertion into a binary search tree.
  void insertR(BSTNode * newElement, BSTNode * current);

  // Description: Recursively traverse the a binary search tree
  //              printing its elements in order.   
  void printInOrderR(BSTNode * current) const;
	
  // Description: Recursive preorder traversal of a binary search tree in order to build its copy.
  void copyR(BSTNode * current);

  // Description: Recursive postorder traversal of a BST in order to release heap memory allocated to BSTNode.
  void destroyR(BSTNode * current);

  unsigned int rNodes(BSTNode * current) const;

  unsigned int rPath(BSTNode * node) const;

  unsigned int heightOfNode(BSTNode * root, BSTNode * node) const;

  BSTNode* max(BSTNode * a, BSTNode * b) const;

  unsigned int getBalance(BSTNode * node) const;

  void printPreOrderR(BSTNode * current) const;

  void printPostOrderR(BSTNode * current) const;

public:

  // Default constructor: Constructs an empty tree.
  BST();            

  // Parameterized constructor
  BST(int element);        

  // Copy constructor
  BST(const BST & aBST);

  // Destructor 
  ~BST();
   
  // Description: Returns the number of elements currently stored in the binary search tree.  
  unsigned int getElementCount() const;

  // Description: Inserts an element into the binary search tree.
  //              This is a wrapper method which calls the recursive insertR( ).
  void insert(int newElement);

  // Description: Returns the height of this binary search tree.
  //              Feel free to implement this method as an iterative method or
  //              as a wrapper method calling a recursive method.
  unsigned int height() const;

  // Description: Returns the number of nodes in this binary search tree.
  //              You cannot return "elementCount".
  //              Feel free to implement this method as an iterative method or
  //              as a wrapper method calling a recursive method.		
  unsigned int numberOfNodes(BSTNode * node) const;
  
  // Description: Prints the content of the binary search tree in order.
  //              This is a wrapper method which calls the recursive printsInOrderR( ).
  void printInOrder() const;

  BSTNode* insertAVLR(BSTNode * newNode, int newElement) const;

  BSTNode* rotateRight(BSTNode * node) const;

  BSTNode* rotateLeft(BSTNode * node) const;

  void printPreOrder() const;

  void printPostOrder() const;

};

#endif