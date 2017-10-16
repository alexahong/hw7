//****************************************************
// Program: Project 1 - AVL_TREE
//
// Author: Alexa Hong
//
// Email: ah455013@ohio.edu
//
// Description: this progam will allow to have an option
// of inputting values or removing them. The values that they
// input into the keyboard can be printed out and also give the height.
//
//
// Date: 10 October 2017
//****************************************************

#include <iostream>
#include <fstream>
#include "avl_tree.h"
using namespace std;

int main(int argc, char** argv) {

  AVLTree tree;
  char option;
  int key;
  string filename;

  BinaryNode* avl = NULL;


   do {
    cin >> option;
    switch(option) {
      case 'i':
        cin >> key;
         tree.insert(key);
        break;
      case 'r':
        cin >> key;
         tree.remove(key);
        break;
      case 'h':
         tree.print('h');
        break;
      case 'p':
         tree.print('p');
        break;
      default:
        break;
    }
  } while(option != 'q');
 
}
