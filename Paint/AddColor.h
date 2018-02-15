#pragma once
#include "command.h"
#include "PaintDlg.h"

class AddColor : public command
{
public:
	AddColor(MyShape *s, COLORREF color);
	~AddColor(void);
	void perform();
	void rollback();
private:
	MyShape *s;
	COLORREF oldColor, oldPen, newColor;
	int oldSize, oldType;
};