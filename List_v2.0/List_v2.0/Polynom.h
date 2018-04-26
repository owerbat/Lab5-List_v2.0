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

	if (p.size){
		for (p.Reset(); !p.IsEnd(); p.GoNext()) {
			InsByOrder(p.pCurr->value);
		}
	}
}

TPolynom &TPolynom::operator=(TPolynom &p) {
	while (size) {
		DelFirst();
	}

	if (p.size) {
		for (p.Reset(); !p.IsEnd(); p.GoNext()) {
			InsByOrder(p.pCurr->value);
		}
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

TPolynom TPolynom::operator+(const TMonom &m) {
	if (size) {
		TPolynom res = *this;
		res.InsByOrder(m);
		return res;
	}
	else {
		TMonom arr[1] = { m };
		TPolynom res(arr, 1);
		return res;
	}
}

TPolynom TPolynom::operator-(const TMonom &m) {
	if(size){
		TPolynom res = *this;
		res.InsByOrder(m * (-1.0));
		return res;
	}
	else {
		TMonom arr[1] = { m * (-1.0)};
		TPolynom res(arr, 1);
		return res;
	}
}

TPolynom TPolynom::operator*(const TMonom &m) {
	if (size) {
		TPolynom res = *this;

		for (res.Reset(); !res.IsEnd(); res.GoNext()) {
			res.pCurr->value = res.pCurr->value * m;
		}

		return res;
	}
	else {
		TPolynom res;
		//TMonom m(0, 0, 0, 0);
		//res.InsByOrder(m);
		return res;
	}
}

TPolynom TPolynom::operator+(TPolynom &p) {
	if(size && p.size) {
		TPolynom res = *this;

		for (p.Reset(); !p.IsEnd(); p.GoNext()) {
			res.InsByOrder(p.pCurr->value);
		}

		return res;
	}
	else if(!size && p.size) {
		TPolynom res = p;
		return res;
	}
	else if (size && !p.size) {
		return *this;
	}
	else {
		TPolynom res;
		return res;
	}
}

TPolynom TPolynom::operator-(TPolynom &p) {
	if (size && p.size) {
		TPolynom res = *this;

		for (p.Reset(); !p.IsEnd(); p.GoNext()) {
			res.InsByOrder((p.pCurr->value) * (-1.0));
		}

		return res;
	}
	else if(!size && p.size) {
		TMonom m(-1.0, 0, 0, 0);
		TPolynom res = p * m;
		return res;
	}
	else if (size && !p.size) {
		return *this;
	}
	else {
		TPolynom res;
		return res;
	}
}

TPolynom TPolynom::operator*(TPolynom &p) {
	if (size && p.size) {
		TPolynom tmp, res;

		for (Reset(); !IsEnd(); GoNext()) {
			tmp = tmp + (p * pCurr->value);
		}

		for (tmp.Reset(); !tmp.IsEnd(); tmp.GoNext()) {
			res.InsByOrder(tmp.pCurr->value);
		}

		return res;
	}
	else {
		TPolynom res;
		//TMonom m(0, 0, 0, 0);
		//res.InsByOrder(m);
		return res;
	}
}

void TPolynom::Print() {
	if (size) {
		Reset();
		(pCurr->value).Print();
		GoNext();
		for (; !IsEnd(); GoNext()) {
			cout << " + ";
			(pCurr->value).Print();
		}
	}
	else {
		cout << "0";
	}
}
