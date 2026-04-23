#include "cDaThuc.h"
#include <cmath>
#include <algorithm>

using namespace std;

// khoi tao da thuc
cDaThuc::cDaThuc(int bac) : n(bac) {
    heSo = new double[n + 1];
    for (int i = 0; i <= n; i++) heSo[i] = 0;
}

// Copy constructor tranh loi giai phong bo nho khi gan da thuc A = B
cDaThuc::cDaThuc(const cDaThuc& other) : n(other.n) {
    heSo = new double[n + 1];
    for (int i = 0; i <= n; i++) heSo[i] = other.heSo[i];
}

// Destructor
cDaThuc::~cDaThuc() {
    delete[] heSo;
}

// toan tu gan
cDaThuc& cDaThuc::operator=(const cDaThuc& other) {
    if (this != &other) { // tranh tu gan
        delete[] heSo; // xoa du lieu cu
        n = other.n;
        heSo = new double[n + 1];
        for (int i = 0; i <= n; i++) {
            heSo[i] = other.heSo[i];
        }
    }
    return *this;
}

// tinh gia tri cua da thuc
double cDaThuc::TinhGiaTri(double x) const {
    double sum = 0;
    for (int i = n; i >= 0; i--) {
        sum += heSo[i] * pow(x, i);
    }
    return sum;
}

// toan tu cong 2 da thuc
cDaThuc cDaThuc::operator+(const cDaThuc& other) const {
    int maxBac = max(this->n, other.n);
    cDaThuc sum(maxBac);

    for (int i = 0; i <= maxBac; i++) {
        // kiem tra xem he so i hien tai co vuot qua so bac cua hai da thuc hay ko
        double heso1 = (i <= this->n) ? this->heSo[i] : 0;
        double heso2 = (i <= other.n) ? other.heSo[i] : 0;

        sum.heSo[i] = heso1 + heso2;
    }
    return sum;
}

// toan tu tru 2 da thuc
cDaThuc cDaThuc::operator-(const cDaThuc& other) const {
    int maxBac = max(this->n, other.n);
    cDaThuc result(maxBac);

    for (int i = 0; i <= maxBac; i++) {
        // kiem tra xem he so i hien tai co vuot qua so bac cua hai da thuc hay ko
        double heso1 = (i <= this->n) ? this->heSo[i] : 0;
        double heso2 = (i <= other.n) ? other.heSo[i] : 0;

        result.heSo[i] = heso1 - heso2;
    }
    return result;
}

// nhap da thuc
istream& operator>>(istream& in, cDaThuc& dt) {
    for (int i = dt.n; i >= 0; i--) {
        cout << "Nhap he so cho x^" << i << ": ";
        in >> dt.heSo[i];
    }
    return in;
}

// xuat da thuc
ostream& operator<<(ostream& out, const cDaThuc& dt) {
    bool first = true; // kiem tra xem co phai he so dau tien

    // tim he so khac 0 de kiem tra xem da thuc co bang 0 hoan toan khong
    bool isZero = true;
    for (int i = dt.n; i >= 0; i--) {
        if (dt.heSo[i] != 0) {
            isZero = false;
            break;
        }
    }
    if (isZero) {
        out << "0";
        return out;
    }

    for (int i = dt.n; i >= 0; i--) {
        // he so = 0 thi bo qua
        if (dt.heSo[i] == 0) continue;

        // neu ko phai phan tu dau thi in dau cong hoac tru
        if (!first && dt.heSo[i] > 0) out << " + ";
        if (dt.heSo[i] < 0) {
            if (first) out << "-";
            else out << " - ";
        }

        // chi in he so neu no khac 1 hoac la so hang tu do
        double val = abs(dt.heSo[i]);
        if (val != 1 || i == 0) out << val;

        if (i > 0) out << "x";
        if (i > 1) out << "^" << i;

        first = false;
    }

    return out;
}

// ham nhap bac da thuc
void NhapBacDaThuc(cDaThuc& a) {
    delete[] a.heSo; // giai phong bo nho truoc khi cap phat lai
    cout << "Nhap bac cua da thuc: ";
    cin >> a.n;
    if (a.n >= 0) {
        a.heSo = new double[a.n + 1];
        for (int i = 0; i <= a.n; i++) a.heSo[i] = 0;
    }
    else {
        a.heSo = nullptr;
    }
}