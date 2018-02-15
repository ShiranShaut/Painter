#pragma once
#include "myshape.h"
class MyEllipse :
	public MyShape
{
public:
	DECLARE_SERIAL(MyEllipse)
	MyEllipse(void);
	~MyEllipse(void);
	void innerDraw(CDC *dc);
	bool InShape(CPoint p);
};

