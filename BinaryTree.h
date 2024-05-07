//
// Created by Kareem Nabulsi on 5/3/24.
//

#ifndef BINARYTREEMENU_BINARYTREE_H
#define BINARYTREEMENU_BINARYTREE_H
#include "TreeNode.h"
#include <iostream>
using namespace std;


class BinaryTree {
private:
    TreeNode* root;

public:
    BinaryTree();
    void insertNode(int num);
    void insert(TreeNode *&nodePtr, TreeNode *&newNode);
    void displayTree(TreeNode* nodePtr) const;
    int leafCounter(TreeNode *nodePtr, int count);
    void displayNumberOfLeafs();
    void display();
    int treeHeight(TreeNode *nodePtr, int leftCtr, int rightCtr);
    void displayHeight();
    void displayWidth();
    void populateList(TreeNode* nodePtr, vector<int>& list, int level);
    int getMaxWidth();
//    void displayLevel();

};


#endif //BINARYTREEMENU_BINARYTREE_H
