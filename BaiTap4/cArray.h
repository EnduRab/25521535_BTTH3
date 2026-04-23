#ifndef CARRAY_H
#define CARRAY_H

class cArray {
private:
    int* arr;
    int size;

	// Hàm kiểm tra số nguyên tố
    bool LaSoNguyenTo(int n) const;

public:
    cArray(int s = 0);
    ~cArray();

    void Nhap();
    void Xuat() const;
    void TaoNgauNhien();

    int DemX(int x) const;
    bool KiemTraTangDan() const;
	int TimLeMin() const; // Trả về số lẻ nhỏ nhất, nếu không có số lẻ nào thì trả về 0
	int TimNguyenToMax() const; // trả về số nguyên tố lớn nhất, nếu không có số nguyên tố nào thì trả về -1

    // Các phương thức sắp xếp (Sử dụng Insertion Sort)
    void SapXepTangDan();
    void SapXepGiamDan(); 

    // Hàm bạn để thay đổi kích thước mảng
    friend void NhapSize(cArray&);
};

#endif