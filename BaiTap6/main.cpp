#include "cListCandidate.h"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
	int n;
	do {
		cout << "Nhap so luong thi sinh: ";
		cin >> n;
		if (n <= 0) cout << "So luong phai lon hon 0. Vui long nhap lai.\n";
	} while (n <= 0);

	cin.ignore(); // Xóa bỏ ký tự newline còn lại trong bộ đệm sau khi nhập số)

	cListCandidate danhSach(n);
	danhSach.Nhap();
	danhSach.XuatTongDiemTren15();

	cout << "\n--- Danh sach thi sinh co tong diem cao nhat---" << 
		endl;
	cListCandidate maxCandidates = danhSach.ThiSinhTongDiemCaoNhat();
	maxCandidates.XuatTatCa();

	
	cout << "\n--- Danh sach thi sinh sau khi sap xep giam dan theo tong diem ---" << endl;
	// Sắp xếp thí sinh theo tổng điểm giảm dần và xuất danh sách
	danhSach.SapXepTheoDiemTongGiamDan();
	danhSach.XuatTatCa();

	return 0;
}