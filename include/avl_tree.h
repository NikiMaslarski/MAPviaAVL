#ifndef AVL_TREE_H
#define AVL_TREE_H

template<typename K, typename V>
struct Node{
    Node();
    Node(K, V);

    K key;
    V value;
    Node<K, V>* left;
    Node<K, V>* right;
    int height;
};

template<typename K, typename V>
class Map
{
    public:
        Map();
        ~Map();
        Map(const Map&);
        Map& operator=(const Map&);


        bool isEmpty() const;
        bool put(K, V);
        bool remove(K);
        bool contains(K);
        bool containsValue(V);


    private:
        Node<K, V>* root;


};

#endif // AVL_TREE_H
