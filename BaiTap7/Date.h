#ifndef DATE_H
#define DATE_H

struct Date {
	int ngay, thang, nam;

	Date();
	Date(int, int, int);
	bool NgayHopLe();
	bool operator<(const Date&) const;
	bool operator==(const Date&) const;

};

#endif 
