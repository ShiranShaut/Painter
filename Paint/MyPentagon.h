#pragma once
#include "myshape.h"
class MyPentagon : public MyShape
{
public:
	DECLARE_SERIAL(MyPentagon)
	MyPentagon(void);
	~MyPentagon(void);
	void innerDraw(CDC *dc);
	bool InShape(CPoint p);
};