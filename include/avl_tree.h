#ifndef AVL_TREE_H
#define AVL_TREE_H

template<typename K, typename V>
struct Node{
     // STRUCTUR
    /*
    Node();
    Node(K, V);

    K key;
    V value;
    Node<K, V>* left;
    Node<K, V>* right;
    int height;
    */


public:
    // Default CTOR
    Node():
     left(NULL),
     right(NULL),
     height(0)
    {
    }

    //Ctor
    Node(K key_, V value_):
     height(1),
     key(key_),
     value(value_),
     left(NULL),
     right(NULL)
    {
    }

// DATA MEMBERS
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
    // STRUCTURE

    public:
        Map();
        ~Map();
        Map(const Map&);
        Map& operator=(const Map&);



        bool isEmpty() const;
        bool put(K, V);
        bool remove(K);
        bool contains(K) const;
        bool containsValue(V) const;

    private:
        Node<K, V>* root;

        void free(Node<K, V>*);
        bool find(Node<K, V>*, K) const;

        bool putR(Node<K, V>*&, K, V);
};


template<typename K, typename V>
Map<K, V>::Map():
    root(NULL)
{
}


template<typename K, typename V>
void Map<K, V>::free(Node<K, V>* n){

    if(n == NULL)
        return;

    if(n->left != NULL)
        free(n->left);
    if(n->right != NULL)
        free(n->right);

    delete n;
}


template<typename K, typename V>
bool Map<K, V>::putR(Node<K, V>*& n, K key_, V value_){
    if( n == NULL){
        n = new Node<K, V>(key_, value_);
        return true;
    }
    else if( n->key < key_){
        return putR(n->right, key_, value_);
    }
    else if( n->key > key_){
        return putR(n->left, key_, value_);
    }
    else if(n->key == key_)
        return false;
}


template<typename K, typename V>
Map<K, V>::~Map(){
    free(root);
}


template<typename K, typename V>
bool Map<K, V>::isEmpty() const{
    return root == NULL;
}


template<typename K, typename V>
bool Map<K, V>::find(Node<K, V>* n, K key_) const{
    if( n == NULL)
        return false;
    if(n->key < key_)
        return find(n->right);
    if(n->key > key_)
        return find(n->left);
    else
        return true;
}


template<typename K, typename V>
bool Map<K, V>::put(K key_, V value_)
{
    return putR(root, key_, value_);
}


//template<typename K, typename V>
//bool Map<K, V>::contains(K key_) const{
//}


#endif // AVL_TREE_H
