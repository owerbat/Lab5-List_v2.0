#include "List.h"

int main() {
	TList<int> l;
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

	l.Print();

	return 0;
}