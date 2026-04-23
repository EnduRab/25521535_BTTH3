#include "cListNhanVienSX.h"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    cListNhanVienSX dsNhanVien;
    cout << "---- NHAP DANH SACH NHAN VIEN ----\n";
    dsNhanVien.Nhap();

    cout << "\n---- DANH SACH NHAN VIEN DA NHAP ----\n";
    dsNhanVien.Xuat();

    cout << "\n---- NHAN VIEN CO LUONG THAP NHAT ----\n";
    cListNhanVienSX dsLuongThapNhat = dsNhanVien.getNhanVienLuongThapNhat();
    dsLuongThapNhat.Xuat();

    cout << "\n---- TONG LUONG CONG TY PHAI TRA ----\n";
    cout << fixed << "Tong luong: " << dsNhanVien.tinhTongLuong() << "\n";

    cout << "\n---- NHAN VIEN CO TUOI CAO NHAT ----\n";
    cListNhanVienSX dsTuoiCaoNhat = dsNhanVien.getNhanVienTuoiCaoNhat();
    dsTuoiCaoNhat.Xuat();

    cout << "\n---- DANH SACH TANG DAN THEO LUONG ----\n";
    dsNhanVien.SapXepTangDanTheoLuong();
    dsNhanVien.Xuat();

    return 0;
}