#include<iostream>
#include<vector>

struct Node {
    int key;
    int val;
    Node* leftChild;
    Node* rightChild;

    Node(int key, int val): key(key), val(val), leftChild(nullptr), rightChild(nullptr) {}
};

class BinaryTree{

    private:
         Node* rootNode = nullptr;

         Node* getMinNode(Node* node){
            while (node->leftChild != NULL){
                node = node->leftChild;
            }
            return node;
        }


        Node* deleteMinNode(Node* node){
            if (node->leftChild == NULL){return node->rightChild;}
            
            node->leftChild = deleteMinNode(node->leftChild);
            return node;
        }

         Node* removeNode(Node* node, int key){
            // Hibbard deletion, not ideal though since leads to non-symmetric trees 
            
            if (node == NULL){return NULL;}
            else if (node->key > key){node->leftChild = removeNode(node->leftChild, key);}
            else if (node->key < key){node->rightChild = removeNode(node->rightChild, key);}
            else {
                
                if (node->leftChild == NULL && node->rightChild && NULL){
                    delete node;
                    node = NULL;
                }
                else if (node->rightChild == NULL){
                    Node* tmp = node;
                    node = node->leftChild;
                    delete tmp;
                }
                else if (node->leftChild == NULL){
                    Node* tmp = node;
                    node = node->rightChild;
                    delete tmp;
                } 
                else {
                    
                    Node* tmp = node;
                    node = getMinNode(tmp->rightChild);
                    node->rightChild = deleteMinNode(tmp->rightChild);
                    node->leftChild = tmp->leftChild;

                    }
                }  

                return node;
            }

            

         Node* insertNode(Node* nodeToInsert, Node* rootNode){
            
            if (rootNode == NULL){return nodeToInsert;}
            else if (nodeToInsert->key == rootNode->key){
                rootNode->val = nodeToInsert->val;
                return rootNode;
            }
            else if (nodeToInsert->key > rootNode->key){
                rootNode->rightChild = insertNode(nodeToInsert, rootNode->rightChild);
                return rootNode;
                }
            else {
                rootNode->leftChild = insertNode(nodeToInsert, rootNode->leftChild);
                return rootNode;
                }

        };

    public:

        BinaryTree() {};

        void insert(int key, int val){
            Node* node = new Node(key, val);
            this->rootNode = insertNode(node, this->rootNode);
        }

        int getVal(int lookupKey){
            Node* curNode = this->rootNode;
            while (curNode != NULL){
                int curKey = curNode->key;
                if (curKey == lookupKey){
                    return curNode->val;
                }
                else if (curKey > lookupKey){
                    curNode = curNode->leftChild;
                }
                else {curNode = curNode->rightChild;}

            }

            return - INT_MAX;
        };

        

        void deleteNode(int key){
            this->rootNode = removeNode(this->rootNode, key);
        };

};


int main(){

    BinaryTree* binaryTree = new BinaryTree();

}