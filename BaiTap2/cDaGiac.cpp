#include "cDaGiac.h"
#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.141592653589793;

// constructor mac dinh
cDaGiac::cDaGiac() {
    soDinh = 0;
    arrDinh = nullptr;
}

// constructor co tham so
cDaGiac::cDaGiac(int n) {
    if (n >= 3) {
        soDinh = n;
        arrDinh = new Diem[soDinh];
    }
    else {
        soDinh = 0;
        arrDinh = nullptr;
    }
}

// copy constructor tranh loi vung nho
cDaGiac::cDaGiac(const cDaGiac& other) {
    soDinh = other.soDinh;
    if (soDinh > 0) {
        arrDinh = new Diem[soDinh];
        for (int i = 0; i < soDinh; i++) {
            arrDinh[i] = other.arrDinh[i];
        }
    }
    else {
        arrDinh = nullptr;
    }
}

// destructor
cDaGiac::~cDaGiac() {
    delete[] arrDinh;
}

// toan tu gan
cDaGiac& cDaGiac::operator=(const cDaGiac& other) {
    if (this != &other) {
        delete[] arrDinh;
        soDinh = other.soDinh;
        if (soDinh > 0) {
            arrDinh = new Diem[soDinh];
            for (int i = 0; i < soDinh; i++) {
                arrDinh[i] = other.arrDinh[i];
            }
        }
        else {
            arrDinh = nullptr;
        }
    }
    return *this;
}

// nhap da giac
void cDaGiac::Nhap() {
    do {
        cout << "Nhap so luong dinh cua da giac (n >= 3): ";
        cin >> soDinh;
        if (soDinh < 3) {
            cout << "Da giac phai co it nhat 3 dinh. Vui long nhap lai!\n";
        }
    } while (soDinh < 3);

    // cap phat lai bo nho
    delete[] arrDinh;
    arrDinh = new Diem[soDinh];

    cout << "--- NHAP TOA DO CAC DINH CUA DA GIAC ---\n";
    for (int i = 0; i < soDinh; i++) {
        cout << "Dinh thu " << i + 1 << ":\n";
        arrDinh[i].NhapDiem();
    }
}

// xuat da giac
void cDaGiac::Xuat() const {
    if (soDinh == 0 || arrDinh == nullptr) {
        cout << "Da giac rong!\n";
        return;
    }

    for (int i = 0; i < soDinh; i++) {
        cout << "Dinh " << i + 1 << ": ";
        arrDinh[i].XuatDiem();
        cout << endl;
    }
    cout << "CHU VI: " << TinhChuVi() << endl;
    cout << "DIEN TICH: " << TinhDienTich() << endl;
}

// tinh chu vi 
double cDaGiac::TinhChuVi() const {
    if (soDinh < 3) return 0;

    double chuVi = 0;
    for (int i = 0; i < soDinh; i++) {
        // (i + 1) % soDinh giup noi dinh cuoi cung voi dinh dau tien
        int nextDinh = (i + 1) % soDinh;
        chuVi += arrDinh[i].KhoangCach(arrDinh[nextDinh]);
    }
    return chuVi;
}

// tinh dien tich su dung cong thuc Shoelace 
// dien tich dung khi nhap cac dinh theo thu tu chieu kim dong ho (hoac nguoc chieu kim dong ho)
// de dam bao da giac khong bi lap lai cac canh
double cDaGiac::TinhDienTich() const {
    if (soDinh < 3) return 0;
    double area = 0;
    for (int i = 0; i < soDinh; i++) {
        int nextDinh = (i + 1) % soDinh;
        // Cong thuc Shoelace
        area += (arrDinh[i].x * arrDinh[nextDinh].y) - (arrDinh[nextDinh].x * arrDinh[i].y);
    }
    return abs(area) / 2.0;
}

// tinh tien theo do doi dx, dy
void cDaGiac::TinhTien(double dx, double dy) {
    for (int i = 0; i < soDinh; i++) {
        arrDinh[i].x += dx;
        arrDinh[i].y += dy;
    }
}

// tinh tien theo vector v
void cDaGiac::TinhTien(Diem v) {
    TinhTien(v.x, v.y);
}

// quay da giac quanh goc toa do (0,0)
void cDaGiac::Quay(double GocQuay) {
    // doi don vi Do ve Radian
    double GocQuayRadian = GocQuay * (PI / 180.0);

    double cosQ = cos(GocQuayRadian);
    double sinQ = sin(GocQuayRadian);

    // quay tung diem
    for (int i = 0; i < soDinh; i++) {
        double oldX = arrDinh[i].x;
        arrDinh[i].x = oldX * cosQ - arrDinh[i].y * sinQ;
        arrDinh[i].y = oldX * sinQ + arrDinh[i].y * cosQ;
    }
}

// phong to thu nho (nhan he so k)
void cDaGiac::PhongToThuNho(double k) {
    if (k <= 0) return; // he so phai > 0

    for (int i = 0; i < soDinh; i++) {
        arrDinh[i].x *= k;
        arrDinh[i].y *= k;
    }
}