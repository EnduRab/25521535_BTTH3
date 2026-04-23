#include "cTamGiac.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	cout << fixed << setprecision(2);

	cTamGiac a;
	a.Nhap();
	cout << "\n---TAM GIAC DA NHAP---\n";
	a.Xuat();

	Diem v;
	cout << "--- NHAP VECTOR TINH TIEN ---\n";
	v.NhapDiem();
	a.TinhTien(v);

	cout << "--- TAM GIAC SAU KHI TINH TIEN THEO VECTOR ---\n";
	a.Xuat();

	double gocquay;
	cout << "--- NHAP GOC QUAY (DON VI: DO) ---\n";
	cin >> gocquay;
	a.Quay(gocquay);
	cout << "--- TAM GIAC SAU KHI QUAY THEO GOC " << gocquay << " DO ---\n";
	a.Xuat();

	double k;
	do {
		cout << "--- NHAP HE SO k DE PHONG TO HOAC THU NHO k LAN (k > 0) ---\n";
		cin >> k;
		if (k <= 0) cout << "VUI LONG NHAP HE SO k > 0\n";
	} while (k <= 0);

	a.PhongToThuNho(k);
	cout << "--- TAM GIAC SAU KHI PHONG TO HOAC THU NHO k LAN ---\n";
	a.Xuat();

	return 0;
}