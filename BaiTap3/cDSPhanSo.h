#ifndef CDSPHANSO_H
#define CDSPHANSO_H
#include <vector>
#include "cPhanSo.h"

class cDSPhanSo {
private:
	int size;
	std::vector<cPhanSo> ds_PhanSo;
public:

	cDSPhanSo(int = 0);

	void Nhap();
	void Xuat();
	std::vector<cPhanSo> getDS() {
		return ds_PhanSo;
	}

	cPhanSo Tong();
	int TimMax();
	int TimMin();
	int TuPrimeLonNhat();
	void SapXepTangDan();
	void SapXepGiamDan();
};


#endif // !CDSPHANSO_H
