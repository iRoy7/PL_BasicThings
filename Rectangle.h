#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include <iostream>
#include "DrawObj.h"
using namespace std;

class Rectangle : public DrawObj
{
protected:
	int m_width;
	int m_height;

public:
	Rectangle()
		: m_width(0), m_height(0)
	{}

	Rectangle(int x, int y, int width, int height)
		: DrawObj(x, y), m_width(width), m_height(height)
	{}
	
	virtual void Input()
	{
		DrawObj::Input();
		cout << "[Rectangle]: Size? ";
		cin >> m_width >> m_height;
	}

	virtual void Draw() const
	{
		cout << "Position of Rectangle = ( " <<
			m_pt.getx() << ", " << m_pt.gety() << "), Size = ( " <<
			m_width << ", " << m_height << ")" << endl;
	}

	void setSize(const int width, const int height)
	{
		m_width = width;
		m_height = height;
	}
};

#endif // __RECTANGLE_H__
