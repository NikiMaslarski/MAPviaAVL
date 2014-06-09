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
     balance(0)
    {
    }

    //Ctor
    Node(K key_, V value_):
     balance(0),
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
    int balance;
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
        bool contains(K) const;
        bool containsValue(V) const;

    private:
        Node<K, V>* root;

        bool find(Node<K, V>*, K) const;

        void freeR(Node<K, V>*);
        bool putR(Node<K, V>*&, K, V);
        void assistRemoveR(Node<K, V>*&, K);
        void removeR(Node<K, V>*&);

        //Single Left Rotation
        void SLR(Node<K, V>*&);
        //Single Right Rotation
        void SRR(Node<K, V>*&);
};


template<typename K, typename V>
Map<K, V>::Map():
    root(NULL)
{
}


template<typename K, typename V>
void Map<K, V>::freeR(Node<K, V>* n){

    if(n == NULL)
        return;

    if(n->left != NULL)
        freeR(n->left);
    if(n->right != NULL)
        freeR(n->right);

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
    freeR(root);
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
        return find(n->right, key_);
    if(n->key > key_)
        return find(n->left, key_);
    else
        return true;
}


template<typename K, typename V>
bool Map<K, V>::put(K key_, V value_)
{
    return putR(root, key_, value_);
}


template<typename K, typename V>
bool Map<K, V>::contains(K key_) const{
    return find(root, key_);
}


//Single Left Rotation
template<typename K, typename V>
void Map<K, V>::SLR(Node<K, V>*& n){

    Node<K, V>& temp = n->right->left;
    n->right->left = n;
    n = n->right;
    n->left->right = temp;
}


//Single Right Rotation
template<typename K, typename V>
void Map<K, V>::SRR(Node<K, V>*& n){

    Node<K, V>& temp = n->left->right;
    n->left->right = n;
    n = n->left;
    n->right->left = temp;
}

//Remove element by given key
template<typename K, typename V>
bool Map<K, V>::remove(K key_){
    if(!contains(key_))
        return false;

    assistRemoveR(root, key_);
    return true;
}


//Finds the element for Remove
template<typename K, typename V>
void Map<K, V>::assistRemoveR(Node<K, V>*& n, K key_){
    if(n->key == key_){
        removeR(n);
    }

    if( n!=NULL && n->key < key_)
        assistRemoveR(n->right, key_);
    if( n!=NULL && n->key > key_)
        assistRemoveR(n->left, key_);
}


//Removes Root Element
template<typename K, typename V>
void Map<K, V>::removeR(Node<K, V>*& n){

    if(n->left == NULL){
        Node<K, V>* temp = n;
        n = n->right;
        delete temp;
    }
    else{
        Node<K, V>*& prev = n->left;
        while(prev->right != NULL){
            prev = prev->right;
        }

        Node<K, V>* temp = prev;
        prev = prev->left;
        temp->left = n->left;
        temp->right = n->right;

        delete n;
        n = temp;
    }
}


#endif // AVL_TREE_H
