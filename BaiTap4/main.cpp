#include "cArray.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	// Khởi tạo bộ sinh số ngẫu nhiên
    srand(static_cast<unsigned int>(time(0)));

    cArray a;
    NhapSize(a);

	// Lựa chọn cách nhập dữ liệu
    int choice;
    cout << "Chon cach nhap (1: Thu cong, 2: Ngau nhien): ";
    cin >> choice;
    if (choice == 1) {
        a.Nhap();
    }
    else {
        a.TaoNgauNhien();
    }

    cout << "\n--- DANH SACH PHAN TU TRONG MANG ---" << endl;
    a.Xuat();

    int MinOddNumber = a.TimLeMin();
    if (MinOddNumber != 0) {
        cout << "So le nho nhat trong mang la: " << MinOddNumber << endl;
    }
    else {
        cout << "Khong co so le nao trong mang!" << endl;
    }

    int MaxPrimeNumber = a.TimNguyenToMax();
    if (MaxPrimeNumber != -1) {
        cout << "So nguyen to lon nhat trong mang la: " << MaxPrimeNumber << endl;
    }
    else {
        cout << "Khong co so nguyen to nao trong mang!" << endl;
    }


    int x;
    cout << "\nNhap so X de dem so lan X xuat hien trong mang: ";
    cin >> x;
    cout << "So lan " << x << " xuat hien trong mang la: " << a.DemX(x) << endl;


    cout << "\n--- KIEM TRA MANG TANG DAN ---" << endl;
    if (!a.KiemTraTangDan()) {
        cout << "Mang chua duoc sap xep tang dan." << endl;
    }
    else {
        cout << "Mang da duoc sap xep tang dan tu truoc." << endl;
    }

    cout << "\n--- THUC HIEN SAP XEP (INSERTION SORT) ---" << endl;
    a.SapXepTangDan();
    cout << "Mang sau khi duoc sap xep TANG DAN la: " << endl;
    a.Xuat();

    a.SapXepGiamDan();
    cout << "Mang sau khi duoc sap xep GIAM DAN la: " << endl;
    a.Xuat();

    return 0;
}