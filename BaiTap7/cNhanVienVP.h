#ifndef CNHANVIENVP_H
#define CNHANVIENVP_H

#include "cNhanVien.h"

class cNhanVienVP : public cNhanVien {
public:
    cNhanVienVP();
    cNhanVienVP(std::string, std::string, Date, double);

    void Nhap() override;
	void Xuat() override;
};

#endif // !CNHANVIENVP_H