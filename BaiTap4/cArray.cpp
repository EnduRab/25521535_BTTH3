#include "cArray.h"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cmath>

using namespace std;

cArray::cArray(int s) : size(s) {
    if (size > 0) arr = new int[size];
    else arr = nullptr;
}

cArray::~cArray() {
    delete[] arr;
}

void cArray::Nhap() {
    for (int i = 0; i < size; ++i) {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> arr[i];
    }
}

void cArray::Xuat() const {
    if (!arr || size <= 0) {
        cout << "Mang rong!" << endl;
        return;
    }
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void cArray::TaoNgauNhien() {
    for (int i = 0; i < size; i++) {
        // Tạo ngẫu nhiên từ 1 đến 100 để dễ quan sát
        arr[i] = rand() % 100 + 1;
    }
}

int cArray::DemX(int x) const {
    int so_lan_xuat_hien = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) so_lan_xuat_hien++;
    }
    return so_lan_xuat_hien;
}

bool cArray::KiemTraTangDan() const {
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) return false;
    }
    return true;
}

int cArray::TimLeMin() const {
    int SoLe_min = INT_MAX;
    bool Found = false;
    for (int i = 0; i < size; i++) {
        if (arr[i] < SoLe_min && arr[i] % 2 != 0) {
            Found = true;
            SoLe_min = arr[i];
        }
    }
	if (!Found) return 0; // 0 = không tìm thấy số lẻ nào
    return SoLe_min;
}

bool cArray::LaSoNguyenTo(int n) const {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int cArray::TimNguyenToMax() const {
	int max_prime = -1; // -1 = không tìm thấy số nguyên tố nào
    for (int i = 0; i < size; i++) {
        if (LaSoNguyenTo(arr[i])) {
            if (max_prime == -1 || arr[i] > max_prime) {
                max_prime = arr[i];
            }
        }
    }
    return max_prime;
}

// Thuật toán Insertion Sort sắp xếp tăng dần
void cArray::SapXepTangDan() {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

    
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Thuật toán Insertion Sort sắp xếp giảm dần
void cArray::SapXepGiamDan() {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void NhapSize(cArray& a) {
    delete[] a.arr; // Giải phóng bộ nhớ cũ nếu có
    cout << "Nhap so phan tu cua mang: ";
    cin >> a.size;
    if (a.size > 0) a.arr = new int[a.size];
    else a.arr = nullptr;
}