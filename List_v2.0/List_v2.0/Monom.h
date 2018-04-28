#pragma once
#include "HeadList.h"

class TMonom {
public:
	double coeff;
	int x;
	int y;
	int z;

	TMonom(double c = 0.0, int _x = 0, int _y = 0, int _z = 0);
	TMonom(const TMonom &m);

	TMonom &operator=(const TMonom &m);

	bool operator<(const TMonom &m); //{ return (x * 100 + y * 10 + z) < (m.x * 100 + m.y * 10 + m.z); }
	bool operator>(const TMonom &m); //{ return (x * 100 + y * 10 + z) > (m.x * 100 + m.y * 10 + m.z); }
	bool operator==(const TMonom &m); //{ return (x * 100 + y * 10 + z) == (m.x * 100 + m.y * 10 + m.z); }
	bool operator!=(const TMonom &m); //{ return (x * 100 + y * 10 + z) != (m.x * 100 + m.y * 10 + m.z); }
	bool operator<=(const TMonom &m); //{ return (x * 100 + y * 10 + z) <= (m.x * 100 + m.y * 10 + m.z); }
	bool operator>=(const TMonom &m); //{ return (x * 100 + y * 10 + z) >= (m.x * 100 + m.y * 10 + m.z); }

	TMonom operator*(double a);

	TMonom operator+(const TMonom &m);
	TMonom operator-(const TMonom &m);
	TMonom operator*(const TMonom &m);
	TMonom operator/(const TMonom &m);

	void Print();

	friend TMonom operator*(const TMonom &m, double a);
};


TMonom::TMonom(double c, int _x, int _y, int _z) {
	coeff = c;
	x = _x;
	y = _y;
	z = _z;
}

TMonom::TMonom(const TMonom &m) {
	coeff = m.coeff;
	x = m.x;
	y = m.y;
	z = m.z;
}

TMonom &TMonom::operator=(const TMonom &m) {
	coeff = m.coeff;
	x = m.x;
	y = m.y;
	z = m.z;

	return *this;
}

bool TMonom::operator<(const TMonom &m) {
	if (x < m.x) {
		return true;
	}
	else if (x == m.x) {
		if (y < m.y) {
			return true;
		}
		else if (y == m.y) {
			if (z < m.z) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool TMonom::operator>(const TMonom &m) {
	if (x > m.x) {
		return true;
	}
	else if (x == m.x) {
		if (y > m.y) {
			return true;
		}
		else if (y == m.y) {
			if (z > m.z) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool TMonom::operator==(const TMonom &m) {
	if ((x == m.x) && (y == m.y) && (z == m.z)) {
		return true;
	}
	else {
		return false;
	}
}

bool TMonom::operator>=(const TMonom &m) {
	return !(*this < m);
}

bool TMonom::operator<=(const TMonom &m) {
	return !(*this > m);
}

bool TMonom::operator!=(const TMonom &m) {
	return !(*this == m);
}

TMonom TMonom::operator*(double a) {
	TMonom res = *this;
	res.coeff *= a;
	return res;
}

TMonom TMonom::operator+(const TMonom &m) {
	if ((x != m.x) || (y != m.y) || (z != m.z)) {
		throw "Addition error";
	}

	TMonom res;

	res.coeff = coeff + m.coeff;
	res.x = x;
	res.y = y;
	res.z = z;

	return res;
}

TMonom TMonom::operator-(const TMonom &m) {
	if ((x != m.x) || (y != m.y) || (z != m.z)) {
		throw "Substraction error";
	}

	TMonom res;

	res.coeff = coeff - m.coeff;
	res.x = x;
	res.y = y;
	res.z = z;

	return res;
}

TMonom TMonom::operator*(const TMonom &m) {
	TMonom res;

	res.coeff = coeff * m.coeff;
	res.x = x + m.x;
	res.y = y + m.y;
	res.z = z + m.z;

	return res;
}

TMonom TMonom::operator/(const TMonom &m) {
	if ((m.coeff == 0) || (x < m.x) || (y < m.y) || (z < m.z)) {
		throw "Devision error";
	}

	TMonom res;

	res.coeff = coeff / m.coeff;
	res.x = x - m.x;
	res.y = y - m.y;
	res.z = z - m.z;

	return res;
}

void TMonom::Print() {
	if (coeff) {
		cout << "(" << coeff << ")x^" << x << "y^" << y << "z^" << z;
	}
	else {
		cout << "0";
	}
}

TMonom operator*(const TMonom &m, double a) {
	TMonom res = m;
	res.coeff *= a;
	return res;
}
