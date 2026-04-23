#include <iostream>
#include <cmath>
#include "Diem.h"
using namespace std;

Diem::Diem() {
	x = 0;
	y = 0;
}
Diem::Diem(double a, double b): x(a), y(b) {}

void Diem::NhapDiem() {
		cout << "Nhap toa do x: ";
		cin >> x;
		cout << "Nhap toa do y: ";
		cin >> y;
	}

void Diem::XuatDiem() {
		cout << "(" << x << " ; " << y << ")";
}

double Diem::KhoangCach(Diem other) {
		return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
}
