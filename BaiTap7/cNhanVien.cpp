#include "cNhanVien.h"
#include <iostream>
#include <iomanip>

void cNhanVien::Nhap() {
	std::cout << "Nhap ma nhan vien: ";
	// Đọc bỏ các ký tự trắng còn lại trong bộ đệm trước khi đọc chuỗi
	std::cin >> std::ws;
	std::getline(std::cin, maNV);
	std::cout << "Nhap ho ten: ";
	std::getline(std::cin, hoTen);
	std::cout << "Nhap ngay sinh (ngay thang nam): ";
	do {
		std::cin >> ngaySinh.ngay >> ngaySinh.thang >> ngaySinh.nam;
		if (ngaySinh.NgayHopLe()) {
			break;
		}
		else {
			std::cout << "Ngay sinh khong hop le. Vui long nhap lai (dd/mm/yyyy): ";
		}
	} while (!ngaySinh.NgayHopLe());

	std::cout << "Nhap luong: ";
	std::cin >> luong;
}

void cNhanVien::Xuat() {
	std::cout << "Ma nhan vien: " << maNV << std::endl;
	std::cout << "Ho ten: " << hoTen << std::endl;
	std::cout << "Ngay sinh: " << ngaySinh.ngay << "/" << ngaySinh.thang << "/" << ngaySinh.nam << std::endl;
	// Hiển thị lương với định dạng không có chữ số thập phân
	std::cout << "Luong: " << std::fixed << std::setprecision(0) << luong << std::endl;
}

cNhanVien::cNhanVien() {
	maNV = "";
	hoTen = "";
	ngaySinh = Date();
	luong = 0;
}

cNhanVien::cNhanVien(std::string ma, std::string ten, Date ns, double l) {
	maNV = ma;
	hoTen = ten;
	ngaySinh = ns;
	luong = l;
}

std::string cNhanVien::getMaNV() {
	return maNV;
}

std::string cNhanVien::getHoTen() {
	return hoTen;
}

Date cNhanVien::getNgaySinh() {
	return ngaySinh;
}

double cNhanVien::getLuong() {
	return luong;
}

void cNhanVien::setMaNV(std::string ma) {
	maNV = ma;
}

void cNhanVien::setHoTen(std::string ten) {
	hoTen = ten;
}

void cNhanVien::setNgaySinh(Date ns) {
	ngaySinh = ns;
}

void cNhanVien::setLuong(double l) {
	luong = l;
}