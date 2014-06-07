#ifndef AVL_TREE_H
#define AVL_TREE_H

template<template K, template V>
struct Node{
    K key;
    V value;
    Node<K, V>* left;
    Node<K, V>* right
};

template<typename T>
class avl_tree
{
    public:
        avl_tree();


    private:
        Node<T> root;

};

#endif // AVL_TREE_H
