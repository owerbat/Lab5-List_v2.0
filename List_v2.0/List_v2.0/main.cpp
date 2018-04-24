#include "Polynom.h"

int main() {
	/*THeadList<int> l;
	for (int i = 0; i < 10; i++) {
		l.InsFirst(i * 10);
	}
	l.InsCurr(100);
	l.Reset();
	for (int i = 0; i < 5; i++) {
		l.GoNext();
	}
	l.InsCurr(101);
	l.InsLast(102);
	l.Reset();
	l.InsCurr(103);

	l.DelFirst();
	l.DelCurr();
	l.GoNext(); l.GoNext();
	l.DelCurr();
	l.DelLast();

	l.Print();*/


	/*try {
		TMonom l(8, 1, 2, 3), m(2, 1, 2, 3), n(4, 4, 5, 6);
		l.Print(); cout << endl; m.Print(); cout << endl; n.Print(); cout << endl;
		cout << "l + m = "; (l + m).Print();
		cout << endl << "l - m = "; (l - m).Print();
		cout << endl << "n * m = "; (n * m).Print();
		cout << endl << "n / m = "; (n / m).Print();
	}
	catch (char * str) {
		cout << endl << str << endl;
	}*/



	/*TMonom l(8, 1, 2, 3), m(2, 1, 2, 3), n(4, 4, 5, 6);
	if (n < m) {
		cout << "OK\n";
	}
	else {
		cout << "NOT OK\n";
	}*/



	TMonom *m = new TMonom[1], *n = new TMonom[1];

	m[0].coeff = 2.0;
	m[0].x = 1;
	m[0].y = m[0].z = 2;

	n[0].coeff = 4.0;
	n[0].x = 3;
	n[0].y = n[0].z = 4;

	cout << "m = "; m[0].Print(); cout << "\nn = "; n[0].Print(); cout << endl;

	TPolynom p(m, 1), q(n, 1);
	p.DelFirst();
	TPolynom res = q * p;
	res.Print();
	cout << endl;

	return 0;
}