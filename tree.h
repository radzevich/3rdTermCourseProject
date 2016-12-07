#ifndef TREE_H
#define TREE_H
#include "cexpression.h"

struct Tree
{
    Tree () : _value(42), _left(NULL), _right(NULL), _parent(NULL)
    {}
    Tree (TExpression value) : _value(value), _left(NULL), _right(NULL), _parent(NULL)
    {}
    Tree (TExpression value, Tree *left, Tree *right) : _value(value), _left(left), _right(right), _parent(NULL)
    {}
    Tree (TExpression value, Tree *left, Tree *right, Tree *parent) : _value(value), _left(left), _right(right), _parent(parent)
    {}

    void treeDelete(Tree& node);
    void transplant(Tree& node1, Tree& node2);
    bool empty;
    Tree& treeMinimum(Tree& node);
private:
    TExpression _value;
    Tree *_left;
    Tree *_right;
    Tree *_parent;
};

void Tree::treeDelete(Tree &node)
{
    if (NULL == node._left)
        transplant(node, node._right);
    else if (NULL == node._right)
        transplant(node, node._left);
    else
    {
        Tree pnt = treeMinimum(node._right);
        if (pnt._parent != node)
        {
            transplant(pnt, pnt._right);
            pnt._right = node._right;
            pnt._right->_parent = pnt;
        }
        transplant(node, pnt);
        pnt._left = node._left;
        pnt._left->_parent = pnt;
    }

}

void Tree::transplant(Tree &node1, Tree &node2)
{
    if (NULL == node1._parent)
        node1 = node2;
    else if (&node1 == node1._parent->_left)
        node1._parent->_left = &node2;
    else
        node1._parent->_right = &node2;
    if (NULL != &node2)
        node2._parent = node1._parent;
}

Tree& treeMinimum(Tree &node)
{
    Tree pnt = &node;
    while (NULL != pnt._left)
        pnt = pnt._left;
    return &pnt;
}


