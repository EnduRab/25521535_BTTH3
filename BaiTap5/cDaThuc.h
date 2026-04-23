#ifndef CDATHUC_H
#define CDATHUC_H

#include <iostream>

class cDaThuc {
private:
    int n;          
    double* heSo;   

public:
    
    // Constructor
    cDaThuc(int bac = 0);

    // Copy constructor
    cDaThuc(const cDaThuc& other);

    // Destructor (Hàm hủy)
    ~cDaThuc();

    // Toan tu gan
    cDaThuc& operator=(const cDaThuc& other);

	// Tinh gia tri cua da thuc khi biet x
    double TinhGiaTri(double x) const;

	// Cong va tru 2 da thuc
    cDaThuc operator+(const cDaThuc& other) const;
    cDaThuc operator-(const cDaThuc& other) const;

	// Friend function de nhap bac da thuc va cap phat bo nho cho mang he so
    friend void NhapBacDaThuc(cDaThuc&);

	// Nhap va xuat da thuc
    friend std::istream& operator>>(std::istream& in, cDaThuc& dt);
    friend std::ostream& operator<<(std::ostream& out, const cDaThuc& dt);

    friend void NhapBacDaThuc(cDaThuc&);
};

#endif