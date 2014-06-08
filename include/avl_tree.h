#ifndef AVL_TREE_H
#define AVL_TREE_H

template<typename K, typename V>
struct Node{
     // STRUCTUR
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
    left(NULL),
    right(NULL),
    height(0)
    {
    }

    //Ctor
    Node(K key_, V value_, Node<K, V> l = NULL, Node<K, V> r = NULL):
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
    // STRUCTURE

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
        void free(Node<K, V>*);
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
Map<K, V>::~Map(){
    free(root);
}

template<typename K, typename V>
bool Map<K, V>::isEmpty() const{
    return !root;
}


template<typename K, typename V>
bool Map<K, V>::put(K key_, V value_)
{
    Node<K, V>* temp = new Node<K, V>;
    Node<K, V>* iterTemp = root;


    while(iterTemp != NULL){
        if(iterTemp->key < key_)
            iterTemp = iterTemp->right;

        else if(iterTemp->key > key_)
            iterTemp = iterTemp->left;

        else if(iterTemp->key == key_)
            return false;
    }

    iterTemp = temp;

    return true;
}


#endif // AVL_TREE_H
