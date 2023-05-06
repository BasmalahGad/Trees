// FCAI - Data Structures - 2023 - Assignment 2
// Program Name: Max Heap
// Last Modification Date:
// Author3 and ID and Group: Basmala Mohamed Sayed Gad            ID: 20210090      Group: S25,26

#include "MaxHeapHeader.h"

template<class  T>
MaxHeap<T> ::MaxHeap()
{
    heapSize = 0;
    heapArr = new T[mxSize];
}

template<class T>
int MaxHeap<T>::parentOf(int idx) {
    return (idx - 1) / 2;
}

template<class T>
int MaxHeap<T>::leftChildOf(int idx) {
    return (2 * idx + 1);
}

template<class T>
int MaxHeap<T>::rightChildOf(int idx) {
    return (2 * idx + 2);
}

template<class T>
void MaxHeap<T>::maxHeapify(int idx) {
    int left = leftChildOf(idx);
    int right = rightChildOf(idx);
    int maxIdx = idx;
    if(heapArr[left] > heapArr[maxIdx]){
        maxIdx = left;
    }
    if(heapArr[right] > heapArr[maxIdx]){
        maxIdx = right;
    }
    if(maxIdx != idx){
        swap(heapArr[idx], heapArr[maxIdx]);
        maxHeapify(maxIdx);
    }
}

template<class T>
void MaxHeap<T>::buildMaxHeap() {
    for (int i = heapSize / 2 - 1; i >= 0; i--) {
        maxHeapify(i);
    }
}

template<class T>
T MaxHeap<T>::getMax() {
    return heapArr[0];
}

template<class T>
int MaxHeap<T>::size() {
    return heapSize;
}