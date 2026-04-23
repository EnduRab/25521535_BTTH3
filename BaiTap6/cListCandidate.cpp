#include "cListCandidate.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

void XuatHeader() {
	cout << left << setw(10) << "Ma TS"
		<< setw(20) << "Ho Ten"
		<< setw(15) << "Ngay Sinh"
		<< setw(8) << "Toan"
		<< setw(8) << "Van"
		<< setw(8) << "Anh"
		<< setw(8) << "Tong" << endl;
	cout << string(77, '-') << endl;
}

cListCandidate::cListCandidate() : size(0) {}

cListCandidate::cListCandidate(int size) : size(size) {
	candidates.resize(size);
}

void cListCandidate::Nhap() {
	for (int i = 0; i < size; i++) {
		cout << "Nhap thong tin thi sinh thu " << i + 1 << ":" << endl;
		candidates[i].Nhap();
	}
}

void cListCandidate::XuatTatCa() {
	if (size == 0) return;
	XuatHeader();
	for (int i = 0; i < size; i++) {
		candidates[i].Xuat();
	}
}

void cListCandidate::XuatTongDiemTren15() {
	bool found = false;

	for (int i = 0; i < size; i++) {
		if (candidates[i].tinhTongDiem() > 15) {
			found = true;
			break;
		}
	}
	if (!found) {
		cout << "Khong co thi sinh nao co tong diem > 15." << endl;
	}
	else {
		cout << "\n--- Danh sach thi sinh co tong diem > 15 ---" << endl;
		cout << left << setw(10) << "Ma TS"
			<< setw(20) << "Ho Ten"
			<< setw(15) << "Ngay Sinh"
			<< setw(8) << "Toan"
			<< setw(8) << "Van"
			<< setw(8) << "Anh"
			<< setw(8) << "Tong" << endl;

		cout << string(77, '-') << endl; // Kẻ một đường ngang cho đẹp

		for (int i = 0; i < size; i++) {
			if (candidates[i].tinhTongDiem() > 15) {
				candidates[i].Xuat();
			}
		}
	}
}

void cListCandidate::ThemThiSinh(cCandidate& ts) {
	candidates.push_back(ts);
	size = candidates.size(); 
}

cListCandidate cListCandidate::ThiSinhTongDiemCaoNhat() {
	cListCandidate result; // Khởi tạo cListCandidate rỗng
	if (size == 0) return result;
	double maxScore = candidates[0].tinhTongDiem();
	for (int i = 1; i < size; i++) {
		// Cập nhật maxScore nếu thí sinh hiện tại có tổng điểm cao hơn
		if (candidates[i].tinhTongDiem() > maxScore) {
			maxScore = candidates[i].tinhTongDiem();
		}
	}

	// Duyệt lại danh sách thí sinh để tìm những thí sinh có tổng điểm bằng maxScore
	for (int i = 0; i < size; i++) {
		if (candidates[i].tinhTongDiem() == maxScore) {
			// Thêm thí sinh có tổng điểm cao nhất vào danh sách kết quả
			result.ThemThiSinh(candidates[i]);
		}
	}
	return result; 
}

void cListCandidate::SapXepTheoDiemTongGiamDan() {
	// Bubble sort để sắp xếp thí sinh theo tổng điểm giảm dần
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (candidates[j].tinhTongDiem() < candidates[j + 1].tinhTongDiem()) {
				swap(candidates[j], candidates[j + 1]);
			}
		}
	}
}