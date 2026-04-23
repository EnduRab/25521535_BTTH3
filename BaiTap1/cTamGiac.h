
#ifndef CTAMGIAC_H
#define CTAMGIAC_H
#include "Diem.h"

struct ThongSo {
	double canh_A, canh_B, canh_C;
	double goc_A, goc_B, goc_C;
};

class cTamGiac{
private:
	Diem A, B, C;
	ThongSo ThongSoTamGiac;
public:
	cTamGiac();
	cTamGiac(Diem A1, Diem A2, Diem A3);
	void setThongSo();
	void Nhap();
	void Xuat();
	int KiemTraLoai_TamGiac(); // -1: Khong phai tam giac, 0: Tam giac thuong, 1: Tam giac deu, 2: Tam giac can, 3: Tam giac vuong, 4: Tam giac vuong can
	double TinhChuVi();
	double TinhDienTich();
	void TinhTien(double,double);
	void TinhTien(Diem);
	void Quay(double);
	void PhongToThuNho(double);
};

#endif 

