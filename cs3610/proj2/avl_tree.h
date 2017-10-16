
//****************************************************
// Program: Project 1 - AVL_TREE
//
// Author: Alexa Hong
//
// Email: ah455013@ohio.edu
//
// Description: header file
//
// Date: 10 October 2017
//****************************************************
#ifndef AVL_TREE_H
#define AVL_TREE_H

struct BinaryNode {
  BinaryNode(const int key) : key(key), left(NULL), right(NULL) {}

  ~BinaryNode() {
    delete left;
    delete right;
    left = right = NULL;
  }

  int key;
  BinaryNode *left, *right;
};




class AVLTree {

public:


  AVLTree() : root(NULL) {}

  ~AVLTree() {  delete root;}

//*****************************************************
//
// Function: insert(const int key)
//
// Purpose: inserts values
// Parameters: key
//
//*****************************************************
  void insert(const int key);

//*****************************************************
//
// Function: remove(const int key)
//
// Purpose: removes value
// Parameters: key
//
//***************************************************** 
  void remove(const int key);


//*****************************************************
//
// Function: rotate_left(BinaryNode* node)
//
// Purpose: rotates tree left
// Parameters: node
//
//*****************************************************
  BinaryNode* rotate_left(BinaryNode* node);

//*****************************************************
//
// Function: rotate_right(BinaryNode* node)
//
// Purpose: rotates right
// Parameters: node
//
//*****************************************************
  BinaryNode* rotate_right(BinaryNode* node);


//*****************************************************
//
// Function: right_left_rotation(BinaryNode* node)
//
// Purpose: right to left rotation
// Parameters: node
//
//*****************************************************
  BinaryNode* right_left_rotation(BinaryNode* node);

//*****************************************************
//
// Function: left_right_rotation(BinaryNode* node)
//
// Purpose: left to right rotation
//
// Parameters: node
//
//*****************************************************
  BinaryNode* left_right_rotation(BinaryNode* node);

//*****************************************************
//
// Function: balance(BinaryNode* node)
//
// Purpose:  balances tree to be a legal AVL tree, and
// determine which rotation to make to keep it balanced
// Parameters: node
//
//
//*****************************************************
  BinaryNode* balance(BinaryNode* node);

//*****************************************************
//
// Function: balance_diff(BinaryNode* node)
//
// Purpose: difference of left and right
// Parameters: node
//
//*****************************************************
  int balance_diff(BinaryNode* node);

//*****************************************************
//
// Function: height(BinaryNode* node)
//
// Purpose: determines height of node
// Parameters: node
//
//*****************************************************
  int height(BinaryNode* node)const;

  //*****************************************************
//
// Function:   void print(const char option)
//
// Purpose: prints out height and key if it has values or not
// Parameters: option
//
//*****************************************************
  void print(const char option);




private:

   //*****************************************************
//
// Function: print_height(BinaryNode* node)
//
// Purpose: prints height of node
// Parameters: node
//
//*****************************************************
  void print_height(BinaryNode* node);

//*****************************************************
//
// Function: print_key(BinaryNode* node)
//
// Purpose: prints the values that were inputted to make
// tree
// Parameters: node
//
//*****************************************************

  void print_key(BinaryNode* node);

  //*****************************************************
//
// Function: insert(const int key, BinaryNode* node)
//
// Purpose: insert values that were inputted into keyboard
// Parameters: key, node
//
// Pre-Conditions: gets value
//
// Post-Conditions: inserts into tree
//
//*****************************************************
  BinaryNode* insert(const int key, BinaryNode* node);

//*****************************************************
//
// Function: remove(const int key, BinaryNode* node)
//
// Purpose: removes a value from tree 
// Parameters: key, node
//
// Pre-Conditions: recieve value that is to be removed
//
// Post-Conditions: removes from tree
//
//*****************************************************
  BinaryNode* remove(const int key, BinaryNode* node);

  BinaryNode* root;
};

#endif
