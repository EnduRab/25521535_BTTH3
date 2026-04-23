#ifndef CNHANVIENSX_H
#define CNHANVIENSX_H
#include "cNhanVien.h"

class cNhanVienSX : public cNhanVien {
private:
	int soSP;
	double donGia;
public:
	cNhanVienSX();
	cNhanVienSX(std::string, std::string, Date, int, double);
	void Nhap() override;
	void Xuat() override;
	int getSoSP();
	double getDonGia();
	void setSoSP(int);
	void setDonGia(double);
	double tinhLuong();
};

#endif 