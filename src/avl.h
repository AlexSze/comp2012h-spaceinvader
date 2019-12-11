#include <iostream>

#include "player_record.h"

using namespace std;

// numerically comparible type T is required
// Required operators: > < >= <= == != +=
// Required operators: conversion converter to one line of csv formatted QString with newline
template <typename T>
class AVL{
    private:
        // AVL Node for storage of data
        struct AVLnode{
            // data to be stored
            T value;
            int height;
            AVL left;
            AVL right;
            AVLnode(const T& x):value(x), height(0), left(), right(){}
        };

        // Data storage of this branch
        AVLnode* root = nullptr;
        // Accessors
        AVL& right_subtree() { return root->right; }
        AVL& left_subtree() { return root->left; }
        const AVL& right_subtree() const { return root->right; }
        const AVL& left_subtree() const { return root->left; }

        int height() const;
        int bfactor() const;
        void fix_height() const;

        void rotate_left();
        void rotate_right();
        void balance();

    public:
        //AVL()=default;
        ~AVL(){delete root;}	//delete AVL
        bool is_empty() const { return root == nullptr; }
        const T& find_min() const; // Find the minimum value in an AVL
        const T& find_max() const;
        bool contains(T & x) const; // Search an item
        void insert(player_record x); // Insert an item in sorted order
        void remove(player_record& x); // Remove an item
        QString dump_csv() const; // Print by rotating 90 degrees
};

// accessor for height with -1 to indicate empty
template <typename T>
int AVL<T>::height() const{
    return is_empty() ? -1 : root->height;
};

// accessor for bfactor
template <typename T>
int AVL<T>::bfactor() const{
    return is_empty() ? 0: right_subtree().height() - left_subtree().height();
}

// set height to be max of subtrees +1
template <typename T>
void AVL<T>::fix_height() const{
    if (!is_empty()){
        int left_avl_height = left_subtree().height();
        int right_avl_height = right_subtree().height();
        root->height = 1 + max(left_avl_height, right_avl_height);
    }
}

// tree rotation
template <typename T>
void AVL<T>::rotate_left(){
    // swap nodes
    AVLnode* b = right_subtree().root;
    right_subtree()=b->left;
    b->left=*this;
    // fix height for old node
    fix_height();
    this->root=b;
    // fix height for new node
    fix_height();
}

// tree rotation
template <typename T>
void AVL<T>::
rotate_right(){
    // swap nodes
    AVLnode* b = left_subtree().root;
    left_subtree() = b->right;
    b->right = *this;
    // fix height for old node
    fix_height();
    this->root = b;
    // fix height for new node
    fix_height();
}


// balance out the binary search tree
template <typename T>
void AVL<T>::balance(){
    if (is_empty())
        return;
    fix_height();
    int balance_factor = bfactor();
    if (balance_factor == 2){
        if (right_subtree().bfactor() < 0)
            right_subtree().rotate_right();
        return rotate_left();
    }
    else if (balance_factor == -2){
        if (left_subtree().bfactor() > 0)
            left_subtree().rotate_left();
        return rotate_right();
    }
}

// get the left most tree
template <typename T>
const T& AVL<T>::find_min() const{
    const AVL& left_avl = left_subtree();
    if (left_avl.is_empty())
        return root->value;
    return left_avl.find_min();
}

// get the right most tree
template<typename T>
const T& AVL<T>::find_max() const
{
    const AVL& right_avl = right_subtree();
    if (right_avl.is_empty())
        return root->value;
    return right_avl.find_max();
}

// look for element in the tree
template <typename T>
bool AVL<T>::contains(T & x) const{
    if (is_empty())
        return false;
    else if (x == root->value)
        return true;
    else if (x < root->value)
        return left_subtree().contains(x);
    else
        return right_subtree().contains(x);
}

// insert element to the tree
template <typename T>
void AVL<T>::insert(player_record x){
    if (is_empty())
        root = new AVLnode(x);
    else if (x > root->value)
        right_subtree().insert(x);
    else if (x < root->value)
        left_subtree().insert(x);
    else /* x == root->value */ {
        // add/append element to the existing one
        root->value += x;
        return;
    }
    // balance out the tree
    balance();
}

// remove element from the tree
template <typename T>
void AVL<T>::remove(player_record& x){
    if (is_empty())
        return;

    if (x < root->value)
        left_subtree().remove(x);
    else if (x > root->value)
        right_subtree().remove(x);
    else /* x == root->value */ {
        AVL& left_avl = left_subtree();
        AVL& right_avl = right_subtree();

        if (!left_avl.is_empty() && !right_avl.is_empty()){
            // both are not empty
            root->value = right_avl.find_min();
            right_avl.remove(root->value);
        }
        else {
            AVLnode* node_to_remove = root;
            *this = left_avl.is_empty() ? right_avl : left_avl;

            right_avl.root = left_avl.root = nullptr;
            delete node_to_remove;
        }
    }

    balance();
}

// output the entire tree from right to left 
template <typename T>
QString AVL<T>::dump_csv() const {
    if (is_empty())
        // return empty QString
        return QString();
    QString output;
    // add the larger values
    output.append(right_subtree().dump_csv());
    // add this data
    output.append(root->value);
    // add the lower values
    output.append(left_subtree().dump_csv());
    return output;
}
