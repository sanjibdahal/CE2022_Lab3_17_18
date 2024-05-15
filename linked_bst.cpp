#include <iostream>
#include "linked_bst.h"

using namespace std;

LinkedBST::LinkedBST() : root(nullptr) {}
LinkedBST::~LinkedBST() {}

bool LinkedBST::isEmpty()
{
    return root == nullptr;
}

void LinkedBST::addBST(int data)
{
    Node* newNode = new Node(data);
    if (root == nullptr) {
        root = newNode;
        return;
    }

    Node* temp = root;
    Node* parent = nullptr;

    while (temp != nullptr) {
        parent = temp;
        if (data < temp->key) {
            temp = temp->leftChild;
        } else if (data > temp->key) {
            temp = temp->rightChild;
        } else {
            // Duplicate keys not allowed
            delete newNode;
            return;
        }
    }

    // Attach the new node to the appropriate side of the parent
    if (data < parent->key) {
        parent->leftChild = newNode;
    } else {
        parent->rightChild = newNode;
    }
}

bool LinkedBST::removeBST(int keyToDelete)
{
}

bool LinkedBST::searchBST(int targetKey)
{
}