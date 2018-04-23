#pragma once
#include <iostream>

using namespace std;

template <class T>
class TLink {
public:
	T value;
	TLink<T> *pNext;

	TLink<T>() { pNext = nullptr; }
};

template <class T>
class TList {
protected:
	TLink<T> *pFirst;
	TLink<T> *pPrev;
	TLink<T> *pCurr;
	TLink<T> *pLast;
	TLink<T> *pStop;
	int size;
public:
	TList() {
		size = 0;
		pFirst = pPrev = pCurr = pLast = pStop = nullptr;
	}
	~TList();

	int GetSize() { return size; }
	TLink<T> *GetFirst() { return pFirst; }
	TLink<T> *GetPrev() { return pPrev; }
	TLink<T> *GetCurr() { return pCurr; }
	TLink<T> *GetLast() { return pLast; }
	TLink<T> *GetStop() { return pStop; }

	void Reset() { pCurr = pFirst; pPrev = pStop; }
	bool IsEnd() { return pCurr == pStop; }
	void GoNext() { pPrev = pCurr; pCurr = pCurr->pNext; }

	virtual void InsFirst(const T &elem);
	virtual void InsCurr(const T &elem);
	virtual void InsLast(const T &elem);

	virtual void DelFirst();
	virtual void DelCurr();
	virtual void DelLast();
};



template <class T>
TList<T>::~TList() {
	while (size) {
		DelFirst();
	}
}

template <class T>
void TList<T>::InsFirst(const T &elem) {
	TLink<T> *tmp = new TLink<T>();
	tmp->value = elem;

	if (!size) {
		pFirst = pLast = pCurr = tmp;
		pFirst->pNext = pStop;
		pPrev->pNext = pFirst;
	}
	else {
		tmp->pNext = pFirst;
		pFirst = tmp;
	}

	size++;
}

template <class T>
void TList<T>::InsLast(const T &elem) {
	if (!size) {
		InsFirst(elem);
	}
	else {
		TLink<T> *tmp = new TLink<T>();
		tmp->value = elem;
		tmp->pNext = pStop;

		pLast->pNext = tmp;
		pLast = tmp;

		size++;
	}
}

template <class T>
void TList<T>::InsCurr(const T &elem) {
	if (!size) {
		InsFirst(elem);
	}
	else if (pCurr == pStop) {
		InsLast(elem);
	}
	else {
		TLink<T> *tmp = new TLink<T>();
		tmp->value = elem;
		tmp->pNext = pCurr;

		pPrev->pNext = tmp;
		pCurr = tmp;

		size++;
	}
}

template <class T>
void TList<T>::DelFirst() {
	if (size) {
		if (size == 1) {
			delete pFirst;
			pFirst = pLast = pPrev = pCurr = nullptr;
		}
		else {
			TLink<T> *tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
			pCurr = pFirst;
			pPrev->pNext = pFirst;
			pPrev = nullptr;
		}
		size--;
	}
}

template <class T>
void TList<T>::DelLast() {
	if (size) {
		if (size == 1) {
			DelFirst();
		}
		else {
			for (Reset(); pCurr->pNext != pStop; GoNext()) {}
			delete pLast;
			pCurr->pNext = pStop;
			pLast = pCurr;
			size--;
		}
	}
}

template <class T>
void TList<T>::DelCurr() {
	if (size) {
		if (size == 1) {
			DelFirst();
		}
		else if (pCurr == pLast) {
			DelCurr();
		}
		else {
			TLink<T> *tmp = pCurr;
			pPrev->pNext = pCurr->pNext;
			delete tmp;
			pCurr = pPrev->pNext;
			size--;
		}
	}
}
