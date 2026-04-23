
#include "cDSPhanSo.h"
#include <iostream>

using namespace std;

int main() {
	cDSPhanSo a;
	a.Nhap();
	vector<cPhanSo> ds = a.getDS();
	cout << "Danh sach phan so da nhap la: "; a.Xuat(); cout << endl;
	cout << "Tong cua cac phan so trong danh sach la: "; a.Tong().Xuat(); cout << endl;

	int maxIdx = a.TimMax();
	int minIdx = a.TimMin();
	if (maxIdx == -1 || minIdx == -1) {
		cout << "Danh sach trong, khong co phan so lon nhat hay nho nhat" << endl;
	}
	else {
		cout << "Phan so lon nhat trong danh sach la: "; ds[maxIdx].Xuat(); cout << endl;
		cout << "Phan so nho nhat trong danh sach la: "; ds[minIdx].Xuat(); cout << endl;
	}
	if (a.TuPrimeLonNhat() == -1) cout << "Khong co phan so nao trong danh sach co tu so la so nguyen to" << endl;
	else {
		cout << "Phan so co tu la so nguyen to lon nhat trong mang la: "; ds[a.TuPrimeLonNhat()].Xuat(); cout << endl;
	}

	a.SapXepTangDan();
	cout << "Danh sach phan so sap xep tang dan:  "; a.Xuat(); cout << endl;
	a.SapXepGiamDan();
	cout << "Danh sach phan so sap xep giam dan:  "; a.Xuat(); cout << endl;
}