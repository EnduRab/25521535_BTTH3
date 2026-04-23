#ifndef CLISTNHANVIEN_H
#define CLISTNHANVIEN_H

#include "cNhanVienVP.h"
#include <vector>

class cListNhanVienVP {
private:
	int size;
	std::vector<cNhanVienVP> listNV;
public:

	cListNhanVienVP();
	cListNhanVienVP(int);

	void Nhap();
	void Xuat();

	void ThemNhanVien(cNhanVienVP&);
	cListNhanVienVP NhanVienLuongCaoNhat();
	double TongLuong();
	cListNhanVienVP NhanVienTuoiCaoNhat();
	void SapXepTangDanTheoLuong();

};

#endif 


