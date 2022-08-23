#ifndef BST_H
#define BST_H

#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <iterator>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
namespace cop4530
{
template <typename T>
class BST{
public:
    using iterator = T*;
    using const_iterator = const T*;

    BST(int th=1);
    BST(const string input, int th=1);
    BST(const BST &rhs);
    BST(BST &&rhs);
    ~BST();
    void buildFromInputString(const string input);
    const BST & operator=(const BST& v);
    const BST & operator=(BST&& v);
    bool empty();

    void printInOrder() const;
    void printLevelOrder() const;
    int numOfNodes() const;
    int height() const;
    void makeEmpty();
    void insert(const T& v);
    void insert(T &&v);
    void remove(const T& v);
    bool contains(const T& v);
    const T& findMin() const;
    const T& findMax() const;

private:
    struct BSTNode{
        T element;
        BSTNode *left;
        BSTNode *right;
        BSTNode(const T &theElement, BSTNode *lt, BSTNode *rt):element{theElement}, left{lt},right{rt}{}
        BSTNode(T &&theElement, BSTNode *lt, BSTNode *rt):element{move(theElement)}, left{lt}, right{rt}{}
    };
    BSTNode* root;

    void printInOrder(BSTNode *t, ostream& os) const;
    void printLevelOrder(BSTNode *t,ostream& os) const;
    void makeEmpty(BSTNode *&t);
    void insert(const T& v, BSTNode *&t);
    void insert(T&& v, BSTNode* &t);
    void remove(const T& v, BSTNode *&t);
    bool contains(const T& v, BSTNode *&t);//may need other params
    int numOfNodes(BSTNode *t) const;
    int height(BSTNode *t) const;
    BSTNode* findMin(BSTNode *t) const;
    BSTNode* findMax(BSTNode *t) const;
    BSTNode* clone(BSTNode *t) const;
    int numNode;
};
#include "bst.hpp"
}
#endif
