#include "cNhanVienSX.h"
#include <iostream>

cNhanVienSX::cNhanVienSX() : soSP(0), donGia(0.0) {}

cNhanVienSX::cNhanVienSX(std::string maNV, std::string hoTen, Date ngaySinh, int soSP, double donGia)
    : cNhanVien(maNV, hoTen, ngaySinh, 0), soSP(soSP), donGia(donGia) {}

void cNhanVienSX::Nhap() {
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

    std::cout << "Nhap so san pham: ";
    std::cin >> soSP;
    std::cout << "Nhap don gia: ";
    std::cin >> donGia;
	luong = tinhLuong();
}

void cNhanVienSX::Xuat() {
    cNhanVien::Xuat();
    std::cout << "So san pham: " << soSP << std::endl;
    std::cout << "Don gia: " << donGia << std::endl;
}

int cNhanVienSX::getSoSP() {
    return soSP;
}

double cNhanVienSX::getDonGia() {
    return donGia;
}

void cNhanVienSX::setSoSP(int soSP) {
    this->soSP = soSP;
}

void cNhanVienSX::setDonGia(double donGia) {
    this->donGia = donGia;
}

double cNhanVienSX::tinhLuong() {
    return soSP * donGia;
}