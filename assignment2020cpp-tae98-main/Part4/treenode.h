#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

#include <memory>
using std::unique_ptr;

#include <utility>
using std::pair;

// TODO your code for the TreeNode class goes here:

template <typename T>
class TreeNode {
public:
    T data;
    unique_ptr<TreeNode> leftChild;
    unique_ptr<TreeNode> rightChild;
    TreeNode* parent;

    TreeNode(T item) {
        data = item;
        parent = nullptr;
    }


    void setLeftChild(TreeNode* child) {

        leftChild = unique_ptr<TreeNode>(child);
        leftChild->parent = this;
    }

    void setRightChild(TreeNode* child) {
        rightChild = unique_ptr<TreeNode>(child);
        rightChild->parent = this;
    }


    void write(ostream& o) {
        o << " ";
        o << this->leftChild->leftChild->data << "  ";
        o << this->leftChild->data << "  ";
        o << this->data << "  ";
        o << this->rightChild->data << " ";
    }


private:
};



// do not edit below this line

#endif
