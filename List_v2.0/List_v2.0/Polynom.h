#pragma once
#include "Monom.h"

class TPolynom : public THeadList<TMonom> {
public:
	TPolynom();
	TPolynom(TMonom *arr, int size);
	TPolynom(TPolynom &p);

	TPolynom &operator=(TPolynom &p);

	void InsByOrder(const TMonom &m);

	TPolynom operator+(const TMonom &m);
	TPolynom operator-(const TMonom &m);
	TPolynom operator*(const TMonom &m);

	TPolynom operator+(TPolynom &p);
	TPolynom operator-(TPolynom &p);
	TPolynom operator*(TPolynom &p);

	double GetCurrCoeff() { return pCurr->value.coeff; }
	int GetCurrX() { return pCurr->value.x; }
	int GetCurrY() { return pCurr->value.y; }
	int GetCurrZ() { return pCurr->value.z; }

	void Print();
};



TPolynom::TPolynom() : THeadList<TMonom>() {
	pHead->value.coeff = 0.0;
	pHead->value.z = -1;
}

TPolynom::TPolynom(TMonom *arr, int _size) : THeadList<TMonom>() {
	pHead->value.coeff = 0.0;
	pHead->value.z = -1;

	for (int i = 0; i < _size; i++) {
		InsByOrder(arr[i]);
	}
}

TPolynom::TPolynom(TPolynom &p) : THeadList<TMonom>() {
	pHead->value.coeff = 0.0;
	pHead->value.z = -1;

	for (p.Reset(); !p.IsEnd(); p.GoNext()) {
		InsByOrder(p.pCurr->value);
	}
}

TPolynom &TPolynom::operator=(TPolynom &p) {
	while (size) {
		DelFirst();
	}

	for (p.Reset(); !p.IsEnd(); p.GoNext()) {
		InsByOrder(p.pCurr->value);
	}

	return *this;
}

void TPolynom::InsByOrder(const TMonom &m) {
	if (m.coeff == 0.0) {
		return;
	}
	if (!size) {
		InsFirst(m);
		return;
	}

	for (Reset(); !IsEnd(); GoNext()) {
		if (pCurr->value == m) {
			pCurr->value = pCurr->value + m;
			if (pCurr->value.coeff == 0) {
				DelCurr();
			}
			return;
		}
		if (pCurr->value < m) {
			InsCurr(m);
			return;
		}
	}

	InsLast(m);
}
