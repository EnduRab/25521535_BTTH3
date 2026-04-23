#include "cNhanVienVP.h"
#include <iostream>

cNhanVienVP::cNhanVienVP() : cNhanVien() {
}

cNhanVienVP::cNhanVienVP(std::string ma, std::string ten, Date ns, double l) : cNhanVien(ma, ten, ns, l) {
}

void cNhanVienVP::Nhap() {
	cNhanVien::Nhap();
}

void cNhanVienVP::Xuat() {
	cNhanVien::Xuat();
}
