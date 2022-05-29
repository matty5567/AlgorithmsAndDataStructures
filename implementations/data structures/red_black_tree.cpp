#include <iostream>
#include <cassert>

struct Node{
    Node(int key, int val, bool colour): key(key), val(val), leftChild(nullptr), rightChild(nullptr), colour(colour){}
    int key;
    int val;
    Node* leftChild;
    Node* rightChild;
    bool colour;
};


class RedBlackTree{

    private:

        Node* rootNode;
        static const bool RED   = true;
        static const bool BLACK = false;

        bool isRed(Node* x){
            if (x==NULL){return false;}
            return (x->colour == RED);
        }

        Node* rotateLeft(Node* h){
            assert(isRed(h->rightChild));
            Node* x = h->rightChild;
            h->rightChild = x->leftChild;
            x->leftChild = h;
            x->colour = h->colour;
            h->colour = RED;
            return x;
        }

        Node* rotateRight(Node* h){
            assert(isRed(h->leftChild));
            Node* x = h->leftChild;
            h->leftChild = x->rightChild;
            x->rightChild = h;
            x->colour = h->colour;
            h->colour = RED;
            return x;
        }

        void flipColours(Node* h){
            assert(!isRed(h));
            assert(isRed(h->leftChild));
            assert(isRed(h->rightChild));
            h->colour = RED;
            h->leftChild->colour = BLACK;
            h->rightChild->colour = BLACK;

        }

        Node* put(Node* h, int key, int val){
            if (h == NULL){return new Node(key, val, RED);}
            
            if      (key < h->key){h->leftChild  = put(h->leftChild, key, val);}
            else if (key > h->key){h->rightChild = put(h->rightChild, key, val);}
            else if (key == h->key){h->val = val;}

            if (isRed(h->rightChild) && !isRed(h->leftChild)){            h = rotateLeft(h);}
            if (isRed(h->leftChild)  &&  isRed(h->leftChild->leftChild)){ h = rotateRight(h);}
            if (isRed(h->leftChild)  &&  isRed(h->rightChild)){               flipColours(h);}

            return h;
        }


    public:
    
        int get(int key){
            Node* x = rootNode;
            while (x != NULL){
                if      (x->key > key){x = x->rightChild;}
                else if (x->key < key){x = x->leftChild;}
                else if (x->key == key){return x->val;}
            }
            return -1;
        }

        void insert(int key, int val){
            this->rootNode = put(this->rootNode, key, val);
        }

        
};



