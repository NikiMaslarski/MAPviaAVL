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
    value(value_)
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
    if(root == NULL){
        root = new Node<K, V>(key_, value_);
    }
    else{
        Node<K, V>* temp = root;
        while(temp != NULL){
            if(temp->key < key_){
                ++temp->height;
                temp = temp->right;
            }
            else if(temp->key > key_){
                temp = temp->left;
                ++temp->height;
            }
            else if(temp->key == key_)
                return false;
        }
        temp = new Node<K, V>(key_, value_);
    }

    return true;
}


//template<typename K, typename V>
//bool Map<K, V>::contains(K key_) const{
//}


#endif // AVL_TREE_H
