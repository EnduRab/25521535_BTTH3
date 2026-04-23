#include "Date.h"

Date::Date() : ngay(1), thang(1), nam(1900) {}
Date::Date(int n, int t, int y) : ngay(n), thang(t), nam(y) {}

bool Date::NgayHopLe() {
	// Kiểm tra năm, tháng, ngày có hợp lệ không
	if (nam < 0 || thang < 1 || thang > 12 || ngay < 1 || ngay > 31) {
		return false;
	}
	if (thang == 2) {
		// Năm nhuận: chia hết cho 4 nhưng không chia hết cho 100, hoặc chia hết cho 400
		if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0) {
			return ngay <= 29;
		}
		else {
			return ngay <= 28;
		}
	}
	if (thang == 4 || thang == 6 || thang == 9 || thang == 11) {
		return ngay <= 30;
	}
	return true;
}

bool Date::operator<(const Date& other) const {
	if (nam != other.nam) return nam < other.nam;
	if (thang != other.thang) return thang < other.thang;
	return ngay < other.ngay;
}

bool Date::operator==(const Date& other) const {
	return ngay == other.ngay && thang == other.thang && nam == other.nam;
}