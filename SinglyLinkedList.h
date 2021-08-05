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

enum ConstructFlag {HEAD_INSERT, FOOT_INSERT};

template<typename T>
class SinglyLinkedList{
    public:
    SinglyLinkedList();
    SinglyLinkedList(T* data, int number, ConstructFlag flag);//
    ~SinglyLinkedList();
    /**
     * @brief Get list length, representing total counts of valid nodes.
     * 
     * @return int 
     */
    int getLength();
    T getValue(int index);
    /**
     * @brief Locate a data and return its index
     * 
     * @param data Data to be located
     * @return int 
     */
    int locateData(T data);
    void insertData(int index, T data);
    T deleteData(int index);
    bool isEmpty();
    template<typename DT>
    friend std::ostream& operator<<(std::ostream& os, SinglyLinkedList<DT>&);
private:
    Node<T>* pInit;
    int listLength;
};

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList(){
    pInit = new Node<T>;
    pInit->data = -2147483648;
    pInit->next = nullptr;
    listLength = 0;
}

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList(T* data, int number, ConstructFlag flag){
    pInit = new Node<T>;
    pInit->data = -2147483648;
    Node<T>* p;
    switch (flag){
    case HEAD_INSERT:
        p = new Node<T>;
        p->data = data[0];
        p->next = nullptr;
        pInit->next = p;
        for(int i = 1; i < number; i++){
            p = new Node<T>;
            p->data = data[i];
            p->next = pInit->next;
            pInit->next = p;
        }
        listLength = number;
        break;
    case FOOT_INSERT:
        p = pInit;
        for(int i = 0; i<number; i++){
            p->next = new Node<T>;
            p = p->next;
            p->data = data[i];
        }
        p->next = nullptr;
        listLength = number;
        break;
    default:
        throw("Invalid flag");
        break;
    }
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

template<typename T>
int SinglyLinkedList<T>::getLength(){
    return listLength;
}

template<typename T>
T SinglyLinkedList<T>::getValue(int index){
    if(index<0 || index>listLength-1) throw("Invalid index");
    Node<T>* p = pInit->next;
    for(int i = 0; i<index; i++){
        p = p->next;
    }
    return p->data;
}

template<typename T>
int SinglyLinkedList<T>::locateData(T data){
    Node<T>* p = pInit->next;
    for(int i = 0; i<listLength; i++){
        if(p->data == data) return i;
        p = p->next;
    }
    throw("Data not found");
}

template<typename T>
void SinglyLinkedList<T>::insertData(int index, T data){
    if(index<0 || index>listLength) throw("Invalid index");
    Node<T>* p = pInit,* d;
    for(int i = 0; i<listLength+1; i++){
        if(index == i){
            d = new Node<T>;
            d->data = data;
            d->next = p->next;
            p->next = d;
        }
        p = p->next;
    }
    listLength++;
}

template<typename T>
T SinglyLinkedList<T>::deleteData(int index){
    if(index<0 || index>listLength-1) throw("Invalid index");
    Node<T>* p = pInit,* d;
    for(int i = 0; i<index; i++){
        p = p->next;
    }
    T data = p->next->data;
    d = p->next;
    if(p->next->next != nullptr) p->next = p->next->next;
    else p->next = nullptr;
    delete d;
    listLength--;
    return data;
}

template<typename T>
bool SinglyLinkedList<T>::isEmpty(){
    if(listLength == 0) return true;
    else return false;
}

template<typename DT>
std::ostream& operator<<(std::ostream& os, SinglyLinkedList<DT>& list){
    Node<DT>* p = list.pInit;
    os<<"Length:\t"<<list.getLength()<<std::endl;
    while(p != nullptr){
        os<<p;
        p = p->next;
    }
    return os;
}
    