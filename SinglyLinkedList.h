/**
 * @file SinglyLinkedList.h
 * @author Hikaze (wgyaaa123@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<iostream>

template<typename T>
struct Node{
    T data;
    Node<T>* next;
};

template<typename T>
std::ostream& operator<<(std::ostream& os, Node<T>* node){
    os<<"\nAddr:\t"<<(void*)node<<"\nData:\t"<<node->data<<"\nNext:\t"<<(void*)node->next<<std::endl;
    return os;
}

template<typename T>
class SinglyLinkedList{
    public:
    SinglyLinkedList();
    SinglyLinkedList(T* data, int number);
    ~SinglyLinkedList();
    int getLength();
    T getValue(int index);
    int locateData(T data);
    void insertData(int index, T data);
    T deleteData(int index);
    bool isEmpty();
    template<typename DT>
    friend std::ostream& operator<<(std::ostream& os, SinglyLinkedList<DT>&);
private:
    Node<T>* pInit;
};

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList(){
    pInit = new Node<T>;
    pInit->data = -2147483648;
    pInit->next = nullptr;
}

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList(T* data, int number){
    pInit = new Node<T>;
    Node<T>* p = pInit;
    for(int i = 0; i<number; i++){
        p->next = new Node<T>;
        p = p->next;
        p->data = data[i];
    }
    p->next = nullptr;
}


template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList(){
    Node<T>* p = pInit;
    while(pInit != nullptr){
        pInit = pInit->next;
        delete p;
        p = pInit;
    }
}

template<typename DT>
std::ostream& operator<<(std::ostream& os, SinglyLinkedList<DT>& list){
    Node<DT>* p = list.pInit;
    while(p != nullptr){
        os<<p;
        p = p->next;
    }
    return os;
}
    