#ifndef CLISTCANDIDATE_H
#define CLISTCANDIDATE_H

#include "cCandidate.h"
#include <vector>

class cListCandidate{
private:
	int size;
	std::vector<cCandidate> candidates;
public:

	cListCandidate();
	cListCandidate(int);

	void Nhap();
	void XuatTongDiemTren15();
	void XuatTatCa();
	
	void ThemThiSinh(cCandidate& );
	cListCandidate ThiSinhTongDiemCaoNhat();
	void SapXepTheoDiemTongGiamDan();
};


#endif // !CLISTCANDIDATE_H
