//
// Created by Kareem Nabulsi on 5/3/24.
//

#include "BinaryTree.h"
#include <iostream>
#include <vector>
using namespace std;

BinaryTree::BinaryTree() {
    root = nullptr;
}

void BinaryTree::insertNode(int num) {
    // method to call from main
    // make new node and fill with correct info
    TreeNode *newNode = nullptr;
    newNode = new TreeNode;
    newNode->value = num;
    // set left and right nodes to null
    newNode->left = newNode->right = nullptr;
    // call insert from root since we are starting from the top
    insert(root, newNode);
}

void BinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode) {
    if(nodePtr == nullptr) {
        // if the node is the first in the tree
        nodePtr = newNode;
    }
    else if(newNode->value < nodePtr->value) {
        // if the value is lower than the parent node, insert on the left
        // iterate pointer on each recursive call to move down the tree (left side)
        insert(nodePtr->left, newNode);
    }
    else {
        // if its higher, insert on the right
        insert(nodePtr->right, newNode);
    }
}

void BinaryTree::displayTree(TreeNode* nodePtr) const {
    // display the tree in order
    // if nodeptr is not null (we didnt reach the end of the tree)
    if(nodePtr) {
        // search and print starting by getting all left side nodes
        displayTree(nodePtr->left);
        cout << nodePtr->value << endl;
        // after basecase is hit for above, search right nodes until it reaches the last (null)
        displayTree(nodePtr->right);
    }

}

int BinaryTree::leafCounter(TreeNode *nodePtr, int count) {
    if(nodePtr == nullptr) {
        // if the tree is empty
        return 0;
    }
    else if(nodePtr->left == nullptr && nodePtr->right == nullptr){
        // if we hit the 2nd to last node, iterate count once more and return it
        count++;
        return count;
    }
    else {
        // iterate count on every run, start with left nodes then right
        count += leafCounter(nodePtr->left,0);
        cout << count << endl;
        count += leafCounter(nodePtr->right,0);
        return count;
    }
}

void BinaryTree::displayNumberOfLeafs() {
    // method for main
    int count = leafCounter(root,0);
    cout << "Number of leaf nodes in the tree is: " << count << endl;
}

void BinaryTree::display() {
    // method for main
    displayTree(root);
}


int BinaryTree::treeHeight(TreeNode* nodePtr, int leftCtr, int rightCtr) {
    if(root == nullptr) {
        // return -1 if tree is empty
        return -1;
    }
    if(nodePtr == nullptr) {
        // base case for below functions
        return 0;
    }
    else {
        // iterate leftcounter before each left recursive call
        leftCtr++;
        leftCtr += treeHeight(nodePtr->left,0,0);
        //iterate right counter before each right recursive call
        rightCtr++;
        rightCtr += treeHeight(nodePtr->right,0,0);
        // find the max of the 2 values
        // left counter represents left tree depth
        // right counter represents right tree depth
        if(leftCtr > rightCtr) {
            return leftCtr;
        }
        else {
            return rightCtr;
        }
    }
}

void BinaryTree::displayHeight() {
    // method for main
    int height = treeHeight(root, -1,-1);
    if(height == -1) {
        cout << "The tree is empty. " << endl;
    }
    else {
        cout << "The tree height is: " << height << endl;
    }
}

void BinaryTree::populateList(TreeNode* nodePtr, vector<int>& list, int level) {
    // method to fill in vector with according values
    // the index represents the level and the value at that index represents the # of nodes on that level
    if (nodePtr == nullptr) {
        // base case
        return;
    }

    // make sure vector is big enough to encorporate the depth of the tree
    if (level >= list.size()) {
        list.resize(level + 1);
    }

    // iterate the number of nodes at that level
    list[level]++;
    // call recursive functions start with left then right, increase level everytime since we are moving down 1 everytime its called
    populateList(nodePtr->left, list, level + 1);
    populateList(nodePtr->right, list, level + 1);
}

int BinaryTree::getMaxWidth() {
    // find the max width given the list from above method
    vector<int> list;
    populateList(root, list, 0);
    int max = 0;
    for(int i = 0; i < list.size(); i++) {
        if(list[i] > max) {
            max = list[i];
        }
    }
    return max;
}

//void BinaryTree::displayLevel() {
//    for testing purposes
//    TreeNode* nodePtr = root;
//    nodePtr = nodePtr->right;
//    nodePtr = nodePtr->right;
//    nodePtr = nodePtr->right;
//    nodePtr = nodePtr->left;
//    cout << "THIS IS THE TREE LEVEL: " << level << endl;
//}

void BinaryTree::displayWidth() {
    // display method for main
    if(root == nullptr) {
        cout << "The tree is empty. " << endl;
    }
    else {
        vector<int> list;
        int width = getMaxWidth();
        cout << "The tree width is: " << width << endl;
    }

}

