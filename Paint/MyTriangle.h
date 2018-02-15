#pragma once
#include "MyShape.h"
class MyTriangle :
	public MyShape
{
public:
	DECLARE_SERIAL(MyTriangle)
	MyTriangle(void);
	~MyTriangle(void);
	void innerDraw(CDC *dc);
	bool InShape(CPoint p);
};