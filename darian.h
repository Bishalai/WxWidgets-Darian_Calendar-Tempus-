
#include "wx/wx.h"
#include "wx/setup.h"
#include "darianMain.h"


class darian :public wxApp
{
public:
	darian();
	~darian();

public:
	virtual bool OnInit();
private:
	darianMain* m_frame1 = nullptr;
};


