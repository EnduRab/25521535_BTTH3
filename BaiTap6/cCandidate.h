
#ifndef CCANDIDATE_H
#define CCANDIDATE_H

#include "Date.h"
#include <string>

class cCandidate {
private:
	std::string ma;
	std::string ten;
	Date ngaySinh;
	double diemToan, diemVan, diemAnh;
public:
	// Constructor mặc định và constructor có tham số
	cCandidate();
	cCandidate(std::string,std::string, Date, double, double, double);
	
	void Nhap();
	void Xuat();

	double tinhTongDiem() const;

	// So sánh điểm trung bình của hai thí sinh
	bool operator>(const cCandidate&);
};

#endif 
