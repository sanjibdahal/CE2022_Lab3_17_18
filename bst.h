class Node{
    public:
        Node(int key) : key(key), leftChild(nullptr), rightChild(nullptr) {}
        int key;
        Node* leftChild;
        Node* rightChild;
};

class BST{
    public:
        virtual bool isEmpty() = 0;
        virtual void addBST(Node* newNode) = 0;
        virtual void removeBST(int keyToDelete) = 0;
        virtual bool searchBST(int targetKey) = 0;
};



