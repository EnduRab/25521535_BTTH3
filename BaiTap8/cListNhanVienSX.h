#ifndef CLISTNHANVIENSX_H
#define CLISTNHANVIENSX_H
#include "cNhanVienSX.h"
#include <vector>

class cListNhanVienSX {
private:
	int size;
	   std::vector<cNhanVienSX> listNV;
public:
	cListNhanVienSX();
	cListNhanVienSX(int);
	void Nhap();
	void Xuat();
	void ThemNhanVien(cNhanVienSX&);
	cListNhanVienSX getNhanVienLuongThapNhat();
	double tinhTongLuong();
	cListNhanVienSX getNhanVienTuoiCaoNhat();
	void SapXepTangDanTheoLuong();
};


#endif 