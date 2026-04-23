#include "cListNhanVienSX.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

cListNhanVienSX::cListNhanVienSX() {
	size = 0;
}

cListNhanVienSX::cListNhanVienSX(int n) {
	size = n;
	listNV.resize(n);
}

void cListNhanVienSX::Nhap() {
	if (size == 0) {
		std::cout << "Nhap so luong nhan vien san xuat:  ";
		std::cin >> size;
		while (size <= 0) {
			std::cout << "So luong phai lon hon 0. Nhap lai!" << std::endl;
			std::cin >> size;
		}
		listNV.resize(size);
	}
	for (int i = 0; i < size; i++) {
		cout << "Nhap thong tin nhan vien thu " << i + 1 << ":" << endl;
		listNV[i].Nhap();
	}
}

void cListNhanVienSX::Xuat() {
	for (int i = 0; i < size; i++) {
		cout << "======THONG TIN NHAN VIEN THU " << i + 1 << "======" << endl;
		listNV[i].Xuat();
	}
}

void cListNhanVienSX::ThemNhanVien(cNhanVienSX& nv) {
	// Thêm nhân viên mới vào danh sách
	listNV.push_back(nv);
	// Cập nhật kích thước của danh sách sau khi thêm nhân viên mới
	size++;
}

cListNhanVienSX cListNhanVienSX::getNhanVienLuongThapNhat() {
	cListNhanVienSX result;
	double minLuong = std::numeric_limits<double>::max();
	// Duyệt qua danh sách nhân viên để tìm lương thấp nhất
	for (auto& nv : listNV) {
		if (nv.getLuong() < minLuong) {
			// Nếu lương của nhân viên hiện tại nhỏ hơn lương thấp nhất đã tìm được,
			// cập nhật lương thấp nhất và làm mới danh sách kết quả
			minLuong = nv.getLuong();
			result.listNV.clear();
			result.listNV.push_back(nv);
		}
		else if (nv.getLuong() == minLuong) {
			// Nếu lương của nhân viên hiện tại bằng lương thấp nhất đã tìm được, 
			// thêm nhân viên vào danh sách kết quả
			result.listNV.push_back(nv);
		}
	}
	result.size = result.listNV.size();
	return result;
}

cListNhanVienSX cListNhanVienSX::getNhanVienTuoiCaoNhat() {
	cListNhanVienSX result;
	if (listNV.empty()) return result;
	// Giả sử nhân viên đầu tiên có ngày sinh nhỏ nhất (tuổi cao nhất)
	Date minNgaySinh = listNV[0].getNgaySinh();
	for (auto& nv : listNV) {
		if (nv.getNgaySinh() < minNgaySinh) {
			// Nếu ngày sinh của nhân viên hiện tại nhỏ hơn ngày sinh nhỏ nhất đã tìm được,
			// cập nhật ngày sinh nhỏ nhất và làm mới danh sách kết quả
			minNgaySinh = nv.getNgaySinh();
			result.listNV.clear();
			result.listNV.push_back(nv);
		}
		else if (nv.getNgaySinh() == minNgaySinh) {
			// Nếu ngày sinh của nhân viên hiện tại bằng ngày sinh nhỏ nhất đã tìm được,
			// thêm nhân viên vào danh sách kết quả
			result.listNV.push_back(nv);
		}
	}
	result.size = result.listNV.size();
	return result;
}

void cListNhanVienSX::SapXepTangDanTheoLuong() {
	// Sắp xếp danh sách nhân viên văn phòng tăng dần theo lương
	// Sử dụng hàm sort với lambda để so sánh lương của nhân viên
	sort(listNV.begin(), listNV.end(), [](cNhanVienSX& a, cNhanVienSX& b) {
		return a.getLuong() < b.getLuong();
		});
}

double cListNhanVienSX::tinhTongLuong() {
	double tong = 0;
	// Duyệt qua danh sách nhân viên và cộng dồn lương của từng nhân viên
	for (auto& nv : listNV) {
		tong += nv.getLuong();
	}
	return tong;
}