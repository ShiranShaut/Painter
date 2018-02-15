#pragma once
class MyShape : public CObject
{
public:
	DECLARE_SERIAL(MyShape)
	MyShape(void);
	virtual ~MyShape(void);
	void setStart(CPoint p) { start = p; }
	void setEnd(CPoint p) { end = p; }
	CPoint getStart() const { return start; }
	CPoint getEnd() const { return end; }
	COLORREF getBg() const { return bgColor; }
	void setBg(COLORREF c) { bgColor = c; }
	COLORREF getP() const { return pColor; }
	void setP(COLORREF c) { pColor = c; }
	int getShapePenType() const { return ShapePenType; }
	void setShapePenType (int c) { ShapePenType = c; }
	int getShapePenSize() const { return ShapePenSize; }
	void setShapePenSize (int c) { ShapePenSize = c; }
	virtual void draw(CDC *dc);
	virtual void innerDraw(CDC *dc) {}
	void Serialize(CArchive& archive);
	virtual bool InShape(CPoint p) { return 0; }
	CPoint start, end;
	COLORREF bgColor, pColor;
	int ShapePenType, ShapePenSize;
};