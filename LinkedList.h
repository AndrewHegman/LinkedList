#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdio.h>

template<typename T>
class LinkedList{

    public:
        template<typename NodeT>
        struct Node{
            NodeT data;
            Node<NodeT> *next;
        };
        LinkedList();
        ~LinkedList();

        /**
         * \brief Add a new node to the list
         * \param node The node to be added
         * \index Position node should be added
         *        in. If index is greater than 
         *        the current size, it is added to
         *        the end. If not provided, node 
         *        will be added to the end.
        **/
        void add(T data, int index = -1);
        int size();
        T pop(int index = -1);
        T get(int index);
        void remove(int index);
        void clear();
        void sort();

    private:
        Node<T>* root;
        Node<T>* last;
        
        Node<T>* getNode(int index) const;

        int _size;
};

#include "LinkedList.h"
#include <stdlib.h>

template<typename T>
LinkedList<T>::LinkedList(){
    root = NULL;
    last = NULL;
    _size = 0;
}

template<typename T>
LinkedList<T>::~LinkedList(){
    
}

template<typename T>
void LinkedList<T>::add(T data, int index){
    Node<T>* newNode = new Node<T>;
    newNode->data = data;

    
    if(index == -1){

        // Add node to end of list
        if(root){

            // Root node has already been created
            newNode->next = getNode(index);
            last->next = newNode;
            last = newNode;
            _size++;

        }else{

            // Root node hasn't been created yet
            newNode->next = NULL;
            root = newNode;
            last = newNode;
            _size++;

        }
    }else{

        // Add node at specified index
        if(index == 0){

            // Add node at beginning of list, replacing root
            newNode->next = root;
            root = newNode;
            _size++;

        }else{

            // Add node at specified index
            // printf("\n\nSize: %d\nIndex: %d\nData: %d\n\tBefore: %d\n\tAfter: %d\n\n", _size, index, data, getNode(index-1)->data, getNode(index)->data);
            newNode->next = getNode(index);
            getNode(index-1)->next = newNode;
            _size++;

        }
        getNode(index);
    }
}

template<typename T>
int LinkedList<T>::size(){
    return _size;
}

template<typename T>
T LinkedList<T>::pop(int index){
    T tmp;
    if(index < 0){

        // Pop the last index
        tmp = last->data;
        remove(_size);

    }else{

        // Pop node at index
        tmp = getNode(index)->data;
        remove(index);

    }

    return tmp;
}

template<typename T>
T LinkedList<T>::get(int index){
    return getNode(index)->data;
}

template<typename T>
LinkedList<T>::Node<T>* LinkedList<T>::getNode(int index) const {
    // Take care of a few low-hanging fruit
    if(index == 0) return root;
    if(index >= _size) return last;
    if(index < 0) return NULL;

    int currentIndex = 0;
    Node<T>* currentNode = root;

    while(currentIndex < index && currentNode){
        currentNode = currentNode->next;
        currentIndex++;
    }
    return currentNode;
}

template<typename T>
void LinkedList<T>::remove(int index){
    if(index >= _size){

        // Remove last node
        getNode(_size - 1)->next = NULL;
        delete(last);
        _size--;

    }else if(index <= 0){
        
        // Remove root node
        delete(root);
        _size--;

    }else{

        // Remove node at index
        Node<T>* tmp = getNode(index-1);
        tmp->next = getNode(index+1);
        delete(getNode(index));
        _size--;

    }
}

template<typename T>
void LinkedList<T>::clear(){
    int idx = 0;
    while(_size > 0){
        remove(idx);
    }
    root = NULL;
    last = NULL;
}

template<typename T>
void LinkedList<T>::sort(){
    
}


#endif