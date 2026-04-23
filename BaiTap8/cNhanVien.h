#ifndef CNHANVIEN_H
#define CNHANVIEN_H

#include "Date.h"
#include <string>

class cNhanVien {
protected:
	std::string maNV;
	std::string hoTen;
	Date ngaySinh;
	double luong;
public:

	cNhanVien();
	cNhanVien(std::string, std::string, Date, double);

	virtual void Nhap();
	virtual void Xuat();

	std::string getMaNV();
	std::string getHoTen();
	Date getNgaySinh();
	double getLuong();

	void setMaNV(std::string);
	void setHoTen(std::string);
	void setNgaySinh(Date);
	void setLuong(double);
};

#endif 
