#include "cListNhanVienVP.h"
#include <iostream>
#include <iomanip> 

using namespace std;

int main() {
	int n;
	do {
		cout << "Nhap so luong nhan vien van phong: ";
		cin >> n;
		if (n <= 0) cout << "So luong phai lon hon 0. Nhap lai!" << endl;
	} while (n <= 0);

	cListNhanVienVP congTy(n);

	cout << "\n--- NHAP THONG TIN NHAN VIEN ---" << endl;
	congTy.Nhap();


	cout << "\n--- DANH SACH NHAN VIEN VAN PHONG ---" << endl;
	congTy.Xuat();


	cout << "\n--- NHAN VIEN CO LUONG CAO NHAT ---" << endl;
	cListNhanVienVP dsMaxLuong = congTy.NhanVienLuongCaoNhat();
	dsMaxLuong.Xuat();

	cout << "\n=> TONG LUONG CONG TY PHAI TRA: " << fixed << setprecision(0) << congTy.TongLuong() << " VND" << endl;

	cout << "\n--- NHAN VIEN CO TUOI CAO NHAT ---" << endl;
	cListNhanVienVP dsMaxTuoi = congTy.NhanVienTuoiCaoNhat();
	dsMaxTuoi.Xuat();

	cout << "\n--- DANH SACH SAU KHI SAP XEP LUONG TANG DAN ---" << endl;
	congTy.SapXepTangDanTheoLuong();
	congTy.Xuat();

	return 0;
}