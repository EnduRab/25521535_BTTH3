#include <iostream>
#include "cTamGiac.h"
#include <cmath>
using namespace std;

#define mu2(x) ((x) * (x))
const double EPSILON = 1e-9;
const double PI = 3.141592653589793;
const double HALF_PI = PI / 2.0;

cTamGiac::cTamGiac() : A{0,0}, B{0,0}, C{0,0},ThongSoTamGiac{0} {}

cTamGiac::cTamGiac(Diem A1, Diem A2, Diem A3): A(A1), B(A2), C(A3), ThongSoTamGiac{0} {
	setThongSo();
}

void cTamGiac::setThongSo() {
	// Tinh do dai cac canh
	ThongSoTamGiac.canh_A = B.KhoangCach(C);
	ThongSoTamGiac.canh_B = A.KhoangCach(C);
	ThongSoTamGiac.canh_C = A.KhoangCach(B);

	// Tinh goc cua tam giac su dung dinh ly cos
	ThongSoTamGiac.goc_A = acos((mu2(ThongSoTamGiac.canh_B) + mu2(ThongSoTamGiac.canh_C) - mu2(ThongSoTamGiac.canh_A)) / (2 * ThongSoTamGiac.canh_B * ThongSoTamGiac.canh_C));
	ThongSoTamGiac.goc_B = acos((mu2(ThongSoTamGiac.canh_A) + mu2(ThongSoTamGiac.canh_C) - mu2(ThongSoTamGiac.canh_B)) / (2 * ThongSoTamGiac.canh_A * ThongSoTamGiac.canh_C));
	ThongSoTamGiac.goc_C = acos((mu2(ThongSoTamGiac.canh_A) + mu2(ThongSoTamGiac.canh_B) - mu2(ThongSoTamGiac.canh_C)) / (2 * ThongSoTamGiac.canh_A * ThongSoTamGiac.canh_B));
}

void cTamGiac::Nhap() {
	do {
		cout << "---NHAP TOA DO CAC DIEM CUA TAM GIAC---\n";
		cout << "DIEM A\n";
		A.NhapDiem();
		cout << "DIEM B\n";
		B.NhapDiem();
		cout << "DIEM C\n";
		C.NhapDiem();
		setThongSo();
		// Kiem tra xem 3 diem co tao thanh tam giac hay khong, neu khong thi yeu cau nhap lai
		if (KiemTraLoai_TamGiac() == -1) cout << "! BA DIEM TREN KHONG TAO THANH TAM GIAC, VUI LONG NHAP LAI !\n";

	} while (KiemTraLoai_TamGiac() == -1);
}

void cTamGiac::Xuat() {
	cout << "A"; A.XuatDiem(); cout << endl;
	cout << "B"; B.XuatDiem(); cout << endl;
	cout << "C"; C.XuatDiem(); cout << endl;
	cout << "CHU VI: " << TinhChuVi() << endl;
	cout << "DIEN TICH: " << TinhDienTich() << endl;
	cout << "LOAI TAM GIAC: ";
	int type = KiemTraLoai_TamGiac();
	if (type == 0) cout << "TAM GIAC THUONG";
	else if (type == 1) cout << "TAM GIAC DEU";
	else if (type == 2) cout << "TAM GIAC CAN";
	else if (type == 3) cout << "TAM GIAC VUONG";
	else cout << "TAM GIAC VUONG CAN";
	cout << endl;
	
}

int cTamGiac::KiemTraLoai_TamGiac() {

	// ---  + EPSILON de tranh sai so khi so sanh voi double/double ---


	// Kiem tra co phai tam giac, return -1 neu ko phai tam giac
	if (ThongSoTamGiac.canh_A < 0 || ThongSoTamGiac.canh_B < 0 || ThongSoTamGiac.canh_C < 0) return -1;
	if ((ThongSoTamGiac.canh_A + ThongSoTamGiac.canh_B <= ThongSoTamGiac.canh_C + EPSILON) ||
		(ThongSoTamGiac.canh_A + ThongSoTamGiac.canh_C <= ThongSoTamGiac.canh_B + EPSILON) ||
		(ThongSoTamGiac.canh_B + ThongSoTamGiac.canh_C <= ThongSoTamGiac.canh_A + EPSILON)) return -1; // Neu tong 2 canh < canh con lai thi khong phai tam giac

	// Kiem tra tam giac deu, return 1 neu la tam giac deu
	if ((abs(ThongSoTamGiac.canh_A - ThongSoTamGiac.canh_B) < EPSILON) &&
		(abs(ThongSoTamGiac.canh_B - ThongSoTamGiac.canh_C) < EPSILON)) return 1;

	
	bool laVuong = (abs(ThongSoTamGiac.goc_A - HALF_PI) < EPSILON) ||
				   (abs(ThongSoTamGiac.goc_B - HALF_PI) < EPSILON) ||
				   (abs(ThongSoTamGiac.goc_C - HALF_PI) < EPSILON);

	bool laCan = ((abs(ThongSoTamGiac.canh_A - ThongSoTamGiac.canh_B) < EPSILON) ||
				  (abs(ThongSoTamGiac.canh_A - ThongSoTamGiac.canh_C) < EPSILON) ||
				  (abs(ThongSoTamGiac.canh_B - ThongSoTamGiac.canh_C) < EPSILON));

	if (laVuong && laCan) return 4;
	if (laVuong) return 3;
	if (laCan) return 2;

	// Neu khong roi vao truong hop nao o tren thi la tam giac thuong, return 0
	return 0;
}

double cTamGiac::TinhChuVi() {
	return ThongSoTamGiac.canh_A + ThongSoTamGiac.canh_B + ThongSoTamGiac.canh_C;
}

double cTamGiac::TinhDienTich() {
	// Su dung cong thuc Heron de tinh dien tich
	double p = TinhChuVi() / 2.0;
	return sqrt(p * (p - ThongSoTamGiac.canh_A) * (p - ThongSoTamGiac.canh_B) * (p - ThongSoTamGiac.canh_C));
}

void cTamGiac::TinhTien(double dx, double dy) {
	// Di chuyen tam giac theo vector (dx, dy)
	A.x += dx; A.y += dy;
	B.x += dx; B.y += dy;
	C.x += dx; C.y += dy;
}

void cTamGiac::TinhTien(Diem v) {
	TinhTien(v.x, v.y);
}

void cTamGiac::Quay(double GocQuay) {
	// Doi don vi Do ve Radian
	double GocQuayRadian = GocQuay * (PI / 180.0);

	double cosQ = cos(GocQuayRadian);
	double sinQ = sin(GocQuayRadian);

	// Quay tung diem quanh goc toa do (0,0)
	double oldX_A = A.x;
	A.x = oldX_A * cosQ - A.y * sinQ;
	A.y = oldX_A * sinQ + A.y * cosQ;

	double oldX_B = B.x;
	B.x = oldX_B * cosQ - B.y * sinQ;
	B.y = oldX_B * sinQ + B.y * cosQ;

	double oldX_C = C.x;
	C.x = oldX_C * cosQ - C.y * sinQ;
	C.y = oldX_C * sinQ + C.y * cosQ;
}

void cTamGiac::PhongToThuNho(double k) {
	if (k <= 0) return; // He so phai > 0

	// Phong to tam giac theo he so k, neu k > 1 thi phong to, neu 0 < k < 1 thi thu nho
	A.x *= k; A.y *= k;
	B.x *= k; B.y *= k;
	C.x *= k; C.y *= k;
	setThongSo();
}