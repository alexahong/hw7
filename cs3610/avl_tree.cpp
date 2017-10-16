//****************************************************
// Program: Project 1 - AVL_TREE
//
// Author: Alexa Hong
//
// Email: ah455013@ohio.edu
//
// Description: source code file
//
// Date: 10 October 2017
//****************************************************
#include <iostream>
#include <cmath>
#include "avl_tree.h"
using namespace std;



// INSERT

void AVLTree::insert(const int key) 
{
  this->root = insert(key, this->root);
}

void AVLTree::remove(const int key)
{
  this->root = remove(key, this->root);
}

 BinaryNode* AVLTree::insert(const int key, BinaryNode* node) 
 {
  if (node == NULL) {
    return new BinaryNode(key);
  }

// if the key is less than the node at the key then it will go to the left
  if(key < node->key) {

// if the left side of the tree is null it will make a spot for the value
    if(node->left == NULL) {
      node->left = new BinaryNode(key); 
    } 
    else {
      
      node->left = insert(key, node->left);
    }
  }
  else if(key == node -> key)
  {
    // if user inputted duplicate numbers warn them
    cout << "duplicate key"<<endl;
  }
  else {
    // if the mode on the right is NULL it will add another spot for the key value
    if(node->right == NULL) {
      node->right = new BinaryNode(key); 
    } 
    else {
      // or it will add a value to the right
      node->right = insert(key, node->right);
    }
  }

  return node;
}


int AVLTree::height(BinaryNode* node)const
{
  
  int depth = 0;
  if(node != NULL)
  {
    // if there are key values it will take the hight of the left and right
    int left = height(node -> left);
    int right =  height(node -> right);
    // find the mac of the left and right, plus one counting the root to find the depth
    depth = 1 + max(left, right);
  }
  return depth;
}


//REMOVE

BinaryNode* AVLTree::remove(int key, BinaryNode* node)
{

  if(node == NULL)
  {
    cout << "no node"<<endl;
    return node;
  }

  if(key < node -> key)
  {
    // checks if key is in left node, if true, removes
    node -> left = remove(key, node -> left);

    // calls balance
    node = balance(node);
  }
  else if( key > node -> key)
  {
    // checks if key is in right node, if true, remove
    node -> right = remove(key, node -> right);

    // balances tree
    node = balance(node);
  }
  else {
    BinaryNode* remove_node = node;
    if( remove_node -> left && remove_node -> right)
    {
      remove_node = remove_node -> left;
      while(remove_node -> right)
      {
        remove_node = remove_node -> right;
      }
      node -> key = remove_node -> key;
      node -> left = remove(node -> key, node -> left);
      node = balance(node);
    }
    else
    {

      // if the node at the left and the load on the right at the node doesnt equal NULL
      if (remove_node -> left && !remove_node -> right)
        node = remove_node -> left;
      else if(!remove_node -> left && remove_node -> right)
      {
        node = remove_node -> right;
      }
      else
         {
          node = NULL;
         }
         delete remove_node;
    }
  }
  return node;

}


//ROTATIONS
  
 BinaryNode* AVLTree::rotate_left(BinaryNode* node)
{
  BinaryNode *temp1, *temp2;

  // points to the right node
  temp1 = node -> right;
  // points to the left node
  temp2 = temp1 -> left;
// node equals the pointer to the left
  temp1 -> left = node;
// node that was to the left goes to the right and pointer points to that
  node -> right = temp2;
  return temp1;

}

 BinaryNode* AVLTree::rotate_right(BinaryNode* node)
{
  BinaryNode *temp1, *temp2;
// node at left will equal temp1
  temp1 = node -> left;
  //node at right will equal temp2
  temp2 = temp1 -> right;
// temp 1 at right will equal the node
  temp1 -> right = node;
// the node at left will equal what was temp 2
  node -> left = temp2;
  // returns temp1
  return temp1;

}
 
 BinaryNode* AVLTree::right_left_rotation(BinaryNode* node)
{

// while node steps to left it will go a right rotation with node left
  node -> left = rotate_right(node -> left);
  return rotate_left(node);

}

 BinaryNode* AVLTree::left_right_rotation(BinaryNode* node)
{
  // node at right will equal the node at right with rotation
  node -> right = rotate_left(node -> right);

  //return rotated tree
  return rotate_right(node);
}

// BALANCE
 BinaryNode* AVLTree::balance(BinaryNode* node)
{
  // b will equal the difference of the left and right side
  int b = balance_diff(node);

// if the difference is 1
  if(b > 1)
  {
    // if the left node is greater than 0, it will make and left right rotation
    if(balance_diff(node -> left) > 0)
    {
      node = left_right_rotation(node);
    }
    else{

      // it will just make a right rotation
      node = rotate_right(node);
    }
  } 
  else if( b < -1)
  {
    if (balance_diff(node -> right) > 0)
    {
      node = right_left_rotation(node);
    }
    else{
      node = rotate_left(node);

    }
  }

  return node;
}

int AVLTree::balance_diff(BinaryNode* node)
{
  // find the differnce of the left and right
  int b = height(node -> left) - height(node -> right);
  return b;

}


// PRINT
void AVLTree::print_height(BinaryNode* node)
{
  if (node == NULL)
  {

    return;
  }

  // in inorder tarversal it will print the left node, root, and then right.
  print_height(node -> left);
  cout << height(node) << " ";;
  print_height(node -> right);
}

void AVLTree::print_key(BinaryNode* node)
{
// if no value is given nothing will be printed
    if (node == NULL)
  {
    return;
  }
  // reads value to the left, then to the root, then to the right.
  print_key(node -> left);
  cout << node -> key << " ";
  print_key(node -> right);
}

void AVLTree::print(const char option)
{
  if(this -> root == NULL)
  {
    cout<< " Empty!"<<endl;
    return;
  }
  
    switch(option) {
      case 'h':
          print_height(root);
          cout <<endl;
        break;
      case 'p':
          print_key(root);
          cout<< endl;
        break;
      default:
      cout<< " not valid";
        break;
      }
  
  
}

