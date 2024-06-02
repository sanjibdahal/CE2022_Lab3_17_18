#include "bst.h"

#define ArrayBST_h
#define MAX_NUM_NODES 128

// ArrayNode structure
struct ArrayNode
{
    int value;
    bool isOccupied;

    ArrayNode() : value(0), isOccupied(false) {}
    ArrayNode(int value) : value(value), isOccupied(true) {}
};

// ArrayBinarySearchTree class definition
class ArrayBST : public BST
{
public:
    ArrayBST();
    ~ArrayBST();
    virtual bool isEmpty();
    virtual void addBST(int data);
    virtual bool removeBST(int keyToDelete);
    virtual bool searchBST(int targetKey);

private:
    ArrayNode *nodes[MAX_NUM_NODES];
};