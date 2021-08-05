/**
 * @file experiment.cpp
 * @author Hikaze (wgyaaa123@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<iostream>
#include<stdlib.h>

#include "SinglyLinkedList.h"

int main(int argc, char** argv){
    int a[10] = {12,23,45,21,22,44,87,54,12,111};
    SinglyLinkedList<int> test = {a,10};
    std::cout<<"Helloworld\n"<<test<<std::endl;
    system("pause");
    exit(0);
}