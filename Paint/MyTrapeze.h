#pragma once
#include "MyShape.h"
class MyTrapeze :
	public MyShape
{
public:
	DECLARE_SERIAL(MyTrapeze)
	MyTrapeze(void);
	~MyTrapeze(void);
	void innerDraw(CDC *dc);
	bool InShape(CPoint p);
};

