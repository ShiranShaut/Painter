#pragma once
#include "myshape.h"
class MyLine :
	public MyShape
{
public:
	DECLARE_SERIAL(MyLine)
	MyLine(void);
	~MyLine(void);
	void innerDraw(CDC *dc);
	bool InShape(CPoint p);
};