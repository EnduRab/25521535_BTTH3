#include "cPhanSo.h"
#include <cmath>
#include <iostream>

using namespace std;

// Hàm tính ước chung lớn nhất (UCLN) sử dụng thuật toán Euclid
int ucln(int a, int b)
{
    if (b == 0) return a;
    return ucln(b, a % b);
}

// Constructor có tham số, tự động rút gọn phân số
cPhanSo::cPhanSo(int t, int m): Tu(t), Mau(m) {
    RutGon();
}

// Constructor mặc định tạo phân số 0/1
cPhanSo::cPhanSo() {
    Tu = 0;
    Mau = 1;
}

void cPhanSo::RutGon() {
    int UCLN = ucln(abs(Tu), abs(Mau));
    Tu /= UCLN;
    Mau /= UCLN;

	// Đảm bảo mẫu dương
    if (Mau < 0) {
        Tu = -Tu;
        Mau = -Mau;
    }

}

void cPhanSo::Xuat() {
    cout << Tu << "/" << Mau;
}

double cPhanSo::GetGiaTri() const {
    return (double)Tu / Mau;
}

cPhanSo cPhanSo::operator+(const cPhanSo& other) {
	// a/b + c/d = (ad + bc) / bd
    return cPhanSo(Tu * other.Mau + Mau * other.Tu, Mau * other.Mau);
}
bool cPhanSo::operator>(const cPhanSo& other) {
    return GetGiaTri() > other.GetGiaTri();
}