#pragma once
#include "List.h"

template <class T>
class THeadList : public TList<T> {
protected:
	TLink<T> *pHead;
public:
	THeadList();
	~THeadList();

	virtual void InsFirst(const T &elem);
	virtual void DelFirst();
};



template <class T>
THeadList<T>::THeadList() : TList() {
	pHead = new TLink<T>;
	pHead->pNext = pHead;
	pStop = pHead;
}

template <class T>
THeadList<T>::~THeadList() {
	TList<T>::~TList();
	delete[] pHead;
}

template <class T>
void THeadList<T>::InsFirst(const T &elem) {
	TList::InsFirst(elem);
	pHead->pNext = pFirst;
}

template <class T>
void THeadList<T>::DelFirst() {
	TList::DelFirst();
	pHead->pNext = pFirst;
}
