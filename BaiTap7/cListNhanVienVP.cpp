#include "cListNhanVienVP.h"
#include <iostream>
#include <algorithm>
using namespace std;

cListNhanVienVP::cListNhanVienVP() {
	size = 0;
}

cListNhanVienVP::cListNhanVienVP(int n) {
	size = n;
	listNV.resize(n);
}


void cListNhanVienVP::Nhap() {
	for (int i = 0; i < size; i++) {
		cout << "Nhap thong tin nhan vien thu " << i + 1 << ":" << endl;
		listNV[i].Nhap();
	}
}

void cListNhanVienVP::Xuat() {
	for (int i = 0; i < size; i++) {
		cout << "Thong tin nhan vien thu " << i + 1 << ":" << endl;
		listNV[i].Xuat();
	}
}

void cListNhanVienVP::ThemNhanVien(cNhanVienVP& nv) {
	// Thêm nhân viên mới vào danh sách
	listNV.push_back(nv);
	// Cập nhật kích thước của danh sách sau khi thêm nhân viên mới
	size++;
}

cListNhanVienVP cListNhanVienVP::NhanVienLuongCaoNhat() {
	cListNhanVienVP result;
	double maxLuong = 0;
	// Duyệt qua danh sách nhân viên để tìm lương cao nhất
	for (auto &nv : listNV) {
		if (nv.getLuong() > maxLuong) {
			// Nếu lương của nhân viên hiện tại lớn hơn lương cao nhất đã tìm được,
			// cập nhật lương cao nhất và làm mới danh sách kết quả
			maxLuong = nv.getLuong();
			result.listNV.clear();
			result.listNV.push_back(nv);
		} else if (nv.getLuong() == maxLuong) {
			// Nếu lương của nhân viên hiện tại bằng lương cao nhất đã tìm được, 
			// thêm nhân viên vào danh sách kết quả
			result.listNV.push_back(nv);
		}
	}
	result.size = result.listNV.size();
	return result;
}

cListNhanVienVP cListNhanVienVP::NhanVienTuoiCaoNhat() {
	cListNhanVienVP result;
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

void cListNhanVienVP::SapXepTangDanTheoLuong() {
	// Sắp xếp danh sách nhân viên văn phòng tăng dần theo lương
	// Sử dụng hàm sort với lambda để so sánh lương của nhân viên
	sort(listNV.begin(), listNV.end(), [](cNhanVienVP &a, cNhanVienVP &b) {
		return a.getLuong() < b.getLuong();
	});
}

double cListNhanVienVP::TongLuong() {
	double tong = 0;
	// Duyệt qua danh sách nhân viên và cộng dồn lương của từng nhân viên
	for (auto &nv : listNV) {
		tong += nv.getLuong();
	}
	return tong;
}

