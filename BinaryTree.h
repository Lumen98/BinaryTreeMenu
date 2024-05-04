//
// Created by Kareem Nabulsi on 5/3/24.
//

#ifndef BINARYTREEMENU_BINARYTREE_H
#define BINARYTREEMENU_BINARYTREE_H
#include "TreeNode.h"
using namespace std;


class BinaryTree {
private:
    TreeNode* root;

public:
    BinaryTree();
    ~BinaryTree();
    void insertNode(int num);
    void insert(TreeNode *&nodePtr, TreeNode *&newNode);
    void displayTree(TreeNode* nodePtr) const;
    int leafCounter(TreeNode *nodePtr, int count);
    void displayNumberOfLeafs();
    void display();

};


#endif //BINARYTREEMENU_BINARYTREE_H
