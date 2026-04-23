#include "cCandidate.h"
#include <iostream>
#include <iomanip>

using namespace std;

cCandidate::cCandidate() : ma(""), ten(""), diemToan(0), diemVan(0), diemAnh(0) {}

cCandidate::cCandidate(string ma, string ten, Date ngaySinh, double diemToan, double diemVan, double diemAnh)
	: ma(ma), ten(ten), ngaySinh(ngaySinh), diemToan(diemToan), diemVan(diemVan), diemAnh(diemAnh) {
}

void cCandidate::Nhap() {
	cout << "Nhap ma thi sinh: ";
	getline(cin, ma);
	cout << "Nhap ten thi sinh: ";
	getline(cin, ten);
	cout << "Nhap ngay sinh (dd/mm/yyyy): ";
	// Nhập ngày sinh và kiểm tra tính hợp lệ, nếu không hợp lệ thì yêu cầu nhập lại
	do {
		cin >> ngaySinh.ngay >> ngaySinh.thang >> ngaySinh.nam;
		if (ngaySinh.NgayHopLe()) {
			break;
		} else {
			cout << "Ngay sinh khong hop le. Vui long nhap lai (dd/mm/yyyy): ";
		}
	} while (!ngaySinh.NgayHopLe());

	// Nhập điểm thi và kiểm tra tính hợp lệ, nếu không hợp lệ thì yêu cầu nhập lại
	do {
		cout << "Nhap diem Toan: ";
		cin >> diemToan;
		if (diemToan < 0 || diemToan > 10) {
			cout << "Diem Toan phai trong khoang 0-10. Vui long nhap lai." << endl;
		}
	} while (diemToan < 0 || diemToan > 10);

	do {
		cout << "Nhap diem Van: ";
		cin >> diemVan;
		if (diemVan < 0 || diemVan > 10) {
			cout << "Diem Van phai trong khoang 0-10. Vui long nhap lai." << endl;
		}
	} while (diemVan < 0 || diemVan > 10);

	do {
		cout << "Nhap diem Anh: ";
		cin >> diemAnh;
		if (diemAnh < 0 || diemAnh > 10) {
			cout << "Diem Anh phai trong khoang 0-10. Vui long nhap lai." << endl;
		}
	} while (diemAnh < 0 || diemAnh > 10);

	cin.ignore(); // Để loại bỏ ký tự newline sau khi nhập điểm
}

void cCandidate::Xuat() {
	cout << left << setw(10) << ma
		<< setw(20) << ten
		<< setw(15) << (to_string(ngaySinh.ngay) + "/" + to_string(ngaySinh.thang) + "/" + to_string(ngaySinh.nam))
		<< setw(8) << diemToan
		<< setw(8) << diemVan
		<< setw(8) << diemAnh
		<< setw(8) << tinhTongDiem() << endl;
}

double cCandidate::tinhTongDiem() const {
	return (diemToan + diemVan + diemAnh);
}

bool cCandidate::operator>(const cCandidate& other) {
	return this->tinhTongDiem() > other.tinhTongDiem();
}