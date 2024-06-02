#include<iostream>
#include"array_bst.h"

// Constructor
ArrayBST::ArrayBST() {
    for (int i = 0; i < MAX_NUM_NODES; ++i) {
        nodes[i] = nullptr;
    }
}

// Destructor
ArrayBST::~ArrayBST() {
    for (int i = 0; i < MAX_NUM_NODES; ++i) {
        if (nodes[i] != nullptr) {
            delete nodes[i];
        }
    }
}

// Check if the tree is empty
bool ArrayBST::isEmpty() {
    return nodes[0] == nullptr;
}

// Add a node to the BST
void ArrayBST::addBST(int data) {
    if (isEmpty()) {
        nodes[0] = new ArrayNode(data);
    } else {
        int index = 0;
        while (index < MAX_NUM_NODES && nodes[index] != nullptr && nodes[index]->isOccupied) {
            if (data < nodes[index]->value) {
                index = 2 * index + 1;  // Left child index
            } else if (data > nodes[index]->value) {
                index = 2 * index + 2;  // Right child index
            } else {
                // Duplicate value, not adding
                return;
            }
        }
        if (index < MAX_NUM_NODES) {
            nodes[index] = new ArrayNode(data);
        } else {
            std::cout << "Tree is full, cannot add more nodes." << std::endl;
        }
    }
}

// Remove a node from the BST
bool ArrayBST::removeBST(int keyToDelete) {
    if (isEmpty())
    {
        return false;
    }
    
    int index = 0;
    while (index < MAX_NUM_NODES && nodes[index] != nullptr && nodes[index]->isOccupied) {
        if (nodes[index]->value == keyToDelete) {
            nodes[index]->isOccupied = false;
            return true;
        } else if (nodes[index]->value > keyToDelete) {
            index = 2 * index + 1;
        } else {
            index = 2 * index + 2;
        }
    }
    return false;
}

// Search for a node in the BST
bool ArrayBST::searchBST(int targetKey) {
    int index = 0;
    while (index < MAX_NUM_NODES && nodes[index] != nullptr && nodes[index]->isOccupied) {
        if (targetKey == nodes[index]->value) {
            return true;
        } else if (targetKey < nodes[index]->value) {
            index = 2 * index + 1;  // Left child index
        } else {
            index = 2 * index + 2;  // Right child index
        }
    }
    return false;
}