#include "cDSPhanSo.h"
#include <iostream>
using namespace std;

bool la_SoNguyenTo(int n) {
	// Số nguyên dương nhỏ hơn 2 không phải là số nguyên tố
    if (n < 2) return false;
    if (n == 2) return true;
	// Số chẵn lớn hơn 2 không phải là số nguyên tố
    if (n % 2 == 0) return false;
	// Kiểm tra các ước số lẻ từ 3 đến căn bậc hai của n
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

cDSPhanSo::cDSPhanSo(int n): size(n) {
    if (n < 0) size = 0;
    ds_PhanSo.resize(size);
}

void cDSPhanSo::Nhap() {
    if (size <= 0) {
        do {
            cout << "Nhap so luong phan so (>= 0): ";
            cin >> size;
            if (size < 0) cout << "So luong khong hop le!\n";
        } while (size < 0);
        ds_PhanSo.resize(size);
    }


    for (int i = 0; i < size; i++) {
        cout << "Nhap phan so thu: " << i + 1 << endl;
        cout << "Nhap tu so: ";
        cin >> ds_PhanSo[i].Tu;
		// Đảm bảo mẫu số khác 0
        do {
            cout << "Nhap mau so (khac 0): ";
            cin >> ds_PhanSo[i].Mau;
            if (ds_PhanSo[i].Mau == 0) {
                cout << "Loi: Mau so khong duoc bang 0. Vui long nhap lai!" << endl;
            }
        } while (ds_PhanSo[i].Mau == 0);
        ds_PhanSo[i].RutGon();
    }
}

void cDSPhanSo::Xuat() {
    for (int i = 0; i < size; i++) {
        cout << ds_PhanSo[i].Tu << "/" << ds_PhanSo[i].Mau << " ";
    }
}

cPhanSo cDSPhanSo::Tong() {
    
    cPhanSo sum(0, 1);
    for (int i = 0; i < size; i++) {
        sum = sum + ds_PhanSo[i];
    }
    return sum;
}

int cDSPhanSo::TimMax() {
    
    int index = 0;
    if (size <= 0) return -1;
    else if (size == 1) return 0;
    cPhanSo max = ds_PhanSo[0];
    // Tìm phần tử lớn nhất bằng cách so sánh từng phần tử với phần tử hiện tại lớn nhất
    for (int i = 1; i < size; i++) {
        if (ds_PhanSo[i] > max)
        {
            max = ds_PhanSo[i];
            index = i;
        }
    }
    return index;
}

int cDSPhanSo::TimMin() {
    int index = 0;
    if (size <= 0) return -1;
    else if (size == 1) return 0;
    cPhanSo min = ds_PhanSo[0];
	// Tìm phần tử nhỏ nhất bằng cách so sánh từng phần tử với phần tử hiện tại nhỏ nhất
    for (int i = 1; i < size; i++) {
        if (min > ds_PhanSo[i])
        {
            min = ds_PhanSo[i];
            index = i;
        }
    }
    return index;
}

int cDSPhanSo::TuPrimeLonNhat() {
    int index = -1; 
    int maxTu = -1; 
    for (int i = 0; i < size; i++) {
		// Kiểm tra nếu tử số là số nguyên dương và là số nguyên tố
        if (la_SoNguyenTo(ds_PhanSo[i].Tu)) {
            if (ds_PhanSo[i].Tu > maxTu) {
				// Cập nhật maxTu và index nếu tìm thấy tử số nguyên dương lớn hơn
                maxTu = ds_PhanSo[i].Tu;
                index = i;
            }
        }
    }
    return index;
}

void cDSPhanSo::SapXepTangDan() {
    if (size <= 1) return;
    // Insertion sort
    for (int i = 1; i < size; i++) {
        cPhanSo toInsert = ds_PhanSo[i];
        int scanPos = i - 1;
        for (; scanPos >= 0 && ds_PhanSo[scanPos] > toInsert; scanPos--);
        int insertPos = scanPos + 1;

        for (int j = i; j > insertPos; j--)
            ds_PhanSo[j] = ds_PhanSo[j - 1];
        ds_PhanSo[insertPos] = toInsert;
    }
}

void cDSPhanSo::SapXepGiamDan() {
    if (size <= 1) return;
    // Insertion sort
    for (int i = 1; i < size; i++) {
        cPhanSo toInsert = ds_PhanSo[i];
        int scanPos = i - 1;
        for (; scanPos >= 0 && toInsert > ds_PhanSo[scanPos]; scanPos--);
        int insertPos = scanPos + 1;

        for (int j = i; j > insertPos; j--)
            ds_PhanSo[j] = ds_PhanSo[j - 1];
        ds_PhanSo[insertPos] = toInsert;
    }
}

