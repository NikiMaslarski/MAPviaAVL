#include <iostream>
#include "avl_tree.h"


template<typename K, typename V>
Node<K, V>::Node():
    left(NULL),
    right(NULL),
    height(0)
    {
    }

template<typename K, typename V>
Node<K, V>::Node(K key_, V value_):
    height(1),
    key(key_),
    value(value_)
    {
    }

template<typename K, typename V>
Map<K, V>::Map():
    root(NULL)
{

}
