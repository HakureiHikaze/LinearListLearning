/**
 * @file SeqList.h
 * @author Hikaze (wgyaaa123@qq.com)
 * @brief Sequence list data structure expriment
 * @version 0.1
 * @date 2021-08-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<iostream>
const int MAXSIZE = 100;
template<typename DT>
class SeqList{
public:
/**
 * @brief Construct a new Seq List object
 * 
 */
    SeqList();
/**
 * @brief Construct a new SeqList<DT>:: SeqList object
 * 
 * @param a Passing data
 * @param n Data length
 */
    SeqList(DT a[], int n);
/**
 * @brief Destroy the Seq List object
 * 
 */
    ~SeqList();
/**
 * @brief Return length of SeqList
 * 
 * @return int - Length of SeqList
 */
    int Length();
/**
 * @brief Get a data from SeqList using index
 * 
 * @param i Index
 * @return DT - Data-type name
 */
    DT Get(int i);
/**
 * @brief Locate data index by data value
 * 
 * @param x data
 * @return int - Index returned
 */
    int Locate(DT x);
/**
 * @brief Insert a data by index, the data after this will be moved backwards
 * 
 * @param i Index
 * @param x Data
 */
    void Insert(int i, DT x);
/**
 * @brief Delete a data and return deleted data, the data after this will be moved forwards
 * 
 * @param i Index
 * @return DT Data-type returned
 */
    DT Delete(int i);
/**
 * @brief Detemine whether this SeqList is empty
 * 
 * @return true The SeqList is empty
 * @return false The SeqList isn't empty
 */
    bool isEmpty();
/**
 * @brief Override operator "<<" for ostream
 * 
 * @tparam T 
 * @return std::ostream& 
 */
    template<typename T>
    friend std::ostream& operator<<(std::ostream&, SeqList<T>&);

private:
    DT data[MAXSIZE];
    int listLength;
};

template<typename DT>
SeqList<DT>::SeqList(DT a[], int n){
    if (n >MAXSIZE) throw "Invalid lenth.";
    for (int i = 0; i < n; i++){
        data[i] = a[i];
    }
    listLength = n;
}
template<typename DT>
SeqList<DT>::~SeqList(){

}

template<typename DT>
int SeqList<DT>::Length(){
    return listLength;
}
template<typename DT>
DT SeqList<DT>::Get(int i){
    if (i < 0 || i > listLength) throw "Invalid index.";
    else return data[i];
}
template<typename DT>
int SeqList<DT>::Locate(DT x){
    for (int i = 0; i < listLength; i++){
        if (data[i] == x) return i;
    }
    return -1;
}
template<typename DT>
void SeqList<DT>::Insert(int i, DT x){
    if(listLength == MAXSIZE) throw "Overflow.";
    if(i<0 || i>=listLength) throw "Invalid index.";
    for(int j = listLength; j>i; j--){
        data[j] = data[j-1];
    }
    data[i] = x;
    listLength++;
}
template<typename DT>
DT SeqList<DT>::Delete(int i){
    if(listLength == 0) throw "Downside overflow.";
    if(i<0 || i>=listLength) throw "Invalid index.";
    DT buffer = data[i];
    for(int j=i+1; j<listLength; j++){
        data[j-1] = data[j];
    }
    listLength--;
    return buffer;
}
template<typename DT>
bool SeqList<DT>::isEmpty(){
    if (listLength == 0) return true;
}

template<typename DT>
std::ostream& operator<<(std::ostream& os, SeqList<DT>& seqList){
    for (int i = 0; i<seqList.Length(); i++){
        os<<"["<<i<<"]: "<<seqList.Get(i);
        if ((i+1)%4 == 0) os<<"\n";
        else os<<"\t";
    }
    os<<"\n"<<"List Length:"<<seqList.Length();
    return os;
}
