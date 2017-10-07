#ifndef __DRAWOBJ_H__
#define __DRAWOBJ_H__

#include <iostream>
#include "Point.h"

class DrawObj 
{
protected:
	Point m_pt;

public:
	DrawObj()
		: m_pt(0, 0)
	{}

	DrawObj(int x, int y)
		: m_pt(x, y)
	{}

	virtual void Input()
	{
		cout << "[DrawObj]: Position info. ? ";
		int x, y;
		cin >> x >> y;
		m_pt.setx(x);
		m_pt.sety(y);
	}

	// 어짜피 하위 클래스에서 재정의하기 때문에
	// 순수 가상항수 선언
	virtual void Draw() const = 0;
	/*
	virtual void Draw() const
	{
		cout << "Position of DrawObj = (" <<
				m_pt.getx() << ", " << m_pt.gety() << ")" << endl;
	}
	*/

	void Offset(const Point& ptOffset)
	{
		m_pt.setx(m_pt.getx() + ptOffset.getx());
		m_pt.sety(m_pt.gety() + ptOffset.gety());
	}

	void Offset(const int xOffset, const int yOffset)
	{
		m_pt.setx(m_pt.getx() + xOffset);
		m_pt.sety(m_pt.gety() + yOffset);
	}
};

#endif //__DRAWOBJ_H__

