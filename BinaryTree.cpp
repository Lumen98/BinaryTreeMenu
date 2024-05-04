//
// Created by Kareem Nabulsi on 5/3/24.
//

#include "BinaryTree.h"
#include <iostream>
using namespace std;


BinaryTree::BinaryTree() {
    root = nullptr;
}

BinaryTree::~BinaryTree() {


}

void BinaryTree::insertNode(int num) {
    TreeNode *newNode = nullptr;

    newNode = new TreeNode;
    newNode->value = num;
    newNode->left = newNode->right = nullptr;
    insert(root, newNode);

}

void BinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode) {
    if(nodePtr == nullptr) {
        nodePtr = newNode;
    }
    else if(newNode->value < nodePtr->value) {
        insert(nodePtr->left, newNode);
    }
    else {
        insert(nodePtr->right, newNode);
    }
}

void BinaryTree::displayTree(TreeNode* nodePtr) const {
    if(nodePtr) {
        displayTree(nodePtr->left);
        cout << nodePtr->value << endl;
        displayTree(nodePtr->right);
    }

}

int BinaryTree::leafCounter(TreeNode *nodePtr, int count) {
    if(nodePtr == nullptr) {
        return 0;
    }
    else if(nodePtr->left == nullptr && nodePtr->right == nullptr){
        count++;
        return count;
    }
    else {
        count = count + leafCounter(nodePtr->left,0);
        cout << count << endl;
        count = count + leafCounter(nodePtr->right,0);
        return count;
    }
}

void BinaryTree::displayNumberOfLeafs() {
    int count = leafCounter(root,0);
    cout << "Number of leaf nodes in the tree is: " << count << endl;
}

void BinaryTree::display() {
    displayTree(root);
}



