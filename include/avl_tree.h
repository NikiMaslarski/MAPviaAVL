#ifndef AVL_TREE_H
#define AVL_TREE_H

template<typename K, typename V>
struct Node{
    /*
    Node();
    Node(K, V, Node<K, V> l = NULL, Node<K, V> r = NULL);

    K key;
    V value;
    Node<K, V>* left;
    Node<K, V>* right;
    int height;
    */
public:
    // Default CTOR
    Node():
    key(K()),
    value(V()),
    left(NULL),
    right(NULL),
    height(0)
    {
    }

    //Ctor
    Node(K key_, V value_, Node<K, V> l, Node<K, V> r):
    height(1),
    key(key_),
    value(value_),
    left(l),
    right(r)
    {
    }


public:
    K key;
    V value;
    Node<K, V>* left;
    Node<K, V>* right;
    int height;

};

template<typename K, typename V>
class Map
{
//    public:
//        Map();
//        ~Map();
//        Map(const Map&);
//        Map& operator=(const Map&);
//
//
//        bool isEmpty() const;
//
//        bool put(K, V);
//        bool remove(K);
//        bool contains(K);
//        bool containsValue(V);
//
//
//    private:
//        Node<K, V>* root;

    public:
        Map():
        root(NULL)
        {
        }

    bool isEmpty() const{
        return !root;
    }


    private:
        Node<K, V>* root;

};

#endif // AVL_TREE_H
