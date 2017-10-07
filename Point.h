#ifndef __POINT_H__
#define __POINT_H__

#include <iostream>
using namespace std;

// ������(Set/Get) Interface
// Ŭ���� �ܺο� ��������� �ְ�ޱ� ���� �Լ�
// �����ڸ� ���� ��(����) ����

class Point
{
private:
	int m_x, m_y;
	enum {MIN_X = 0, MAX_X = 100, MIN_Y = 0, MAX_Y = 100};

public:
	// Ŭ���� �����ڰ� �������� �ʴ� ���, �����Ϸ��� �������ִ� ������:
	// ���ڸ� ������ �ʴ�  Default Constructor:
	Point() {
		cout << " Call default constructor: " << endl;
		m_x = 0;	// , or setx(0);
		m_y = 0;	// , or sety(0);
	}
	// (1) ���ڰ� �ϳ� �ִ� ������:
	Point(int xy) {
		setx(xy);
		sety(xy);
	}
	// (2) ���ڰ� 2�� �ִ� ������:
	Point(int x, int y) {
		cout << " Call constructor with two arguments " << endl;
		setx(x);
		sety(y);
	}
	
	// Ŭ���� ���ο� ����Լ��� ����� ������ �Բ��ϴ� ��
	// �ζ��� ���
	// �ζ��� Ű����� �и��� �Լ��� ����� �����ϱ� ���� ��ġ�� 
	// Ŭ���� ����� �Բ� �ξ����
	void setx(int x) {
		if (MAX_X < x) m_x = MAX_X;
		if (x < MIN_X) m_x = MIN_X;
		m_x = x;
	}
	void sety(int y) {
		if (MAX_Y < y) m_y = MAX_Y;
		if (y < MIN_Y) m_y = MIN_Y;
		m_y = y;
	}

	// ����� ����Լ�: �Լ������� ������� ���� ���������� ����. const!!!
	int getx() const { return m_x; }
	int gety() const { return m_y; }
	void print() const {
		cout << "Point = ( " << getx() << ", " << gety() << ")" << endl;
	}

	// ������ �ߺ�����
	// ����Լ��� ������ �ߺ����Ǹ� �����ϴ� ���� �Ϲ����̱�� ������,
	// �������� �������� Ŭ���� ��ü�� �ƴ� ���� ����Լ��� �ƴ϶�,
	// �ݵ�� �����Լ��� �����ؾ���!
	// ������ �����ڴ� �����Լ��� ������ �ߺ����Ǹ� �� �� ����
	// �Ҵ� ������ '='
	// Ŭ���� ��� �׼��� '->'
	// �迭÷�� '[]'
	// �Լ�ȣ�� '()'
	// �� �����ڵ��� �ݵ�� ����Լ��θ� ������ �ߺ����Ǹ� �����ؾ���
	// ������ �ߺ����� �Լ��� ���ڴ� const ������!!!
	// MyString Ŭ������ ��� ���� �����ڸ� �����ؾ��ϱ� ������ 
	// ������ �ߺ����� �Լ��� ������ ��,
	// ���ڸ� const �������� ���� ������ ������尡 �߻�!

	/*
	������ �ߺ����Ǹ� ����Լ��� ...
	class className: ���������� ����Ŭ�����̸�
	{
	public:
		className operator������(const className& �����ǿ�����);
	};

	className className::operator������(const className& �����ǿ�����)
	{
	}
	*/

	/*
	������ �ߺ����Ǹ� �����Լ��� ...
	class className: ���������� ����Ŭ�����̸�
	{
	public:
		friend className operator������(const className& �����ǿ�����, 
							const className& �����ǿ�����);
	};

	className operator������(const className& �����ǿ�����,
						const className& �����ǿ�����)
	{
	}
	*/

	Point operator+ (const Point& op2)
	{
		Point ret(m_x + op2.m_x, m_y + op2.m_y);
		return ret;
	}

	// * ��ȯ���� �����ڸ� �ߺ������� Ŭ���� ��ü�� �ƴϾ���ϴ� ���
	// �� �����ڳ� ���� �����ڸ� �ߺ������� ���
	// �� ������ �ߺ����Ǹ� ����Լ��� ...
	bool operator== (const Point& op2)
	{
		return(m_x == op2.m_x && m_y == op2.m_y);
	}
	// �� ������ �ߺ����Ǹ� �����Լ��� ...
	// friend bool operator== (const Point& op1, const Point& op2);

	// * ���� ������ �ߺ�����
	// ���� �����ڸ� ����Լ��� �ߺ������Ѵٸ�,
	// �������� ����(���� �������� ��쿡�� ����)�� �ִ� �ǿ������� ����� ȣ��
	// �׷��� ���� �����ڸ� ����Լ��� �����ϸ� ���ڰ� �������� �ʴ´�.
	// ����, ���� �����ڸ� �����Լ��� �����Ѵٸ�,
	// �������� �ǿ����� �ϳ��� ���ڷ� ���޵ǹǷ� �ϳ��� ���ڸ� ���´�.
	// ���� ������ �ߺ����Ǹ� ����Լ��� ...
	Point operator-()
	{
		Point ret(-m_x, -m_y);
		return ret;
	}
	// ���� ������ �ߺ����Ǹ� �����Լ��� ...
	// friend Point operator-(const Ponit& op1);

	// * ���� ���� ������ �ߺ�����
	// ������(Prefix)�� ������(Postfix)
	// �ǿ����� �ڽ��� ����

	// & ������
	// ���� ���� ���� ������ �ߺ����Ǹ� ����Լ��� ...
	// className operator++[--]();
	Point operator++()
	{
		++m_x;
		++m_y;
		return *this;
	}
	// ���� ���� ���� ������ �ߺ����Ǹ� �����Լ��� ...
	// friend className operator++[--](className& �����ǿ�����);
	// friend Point operator++(Point& op1);
	// �Ϲ������� ��ü �ڽ��� ���� ������� ������, 
	// ���� �����ڴ� ��ü �ڽ��� ���� ����Ǳ� ������
	// ���ڷ� ���޵� �ǿ����ڿ� const�� ����!!!

	// & ������
	// : ������ ���� dummy int ���
	// ���� ���� ���� ������ �ߺ����Ǹ� ����Լ��� ...
	// className operator++[--](int);
	Point operator++(int)
	{
		//m_x++;
		//m_y++;
		// �ӽ� ��ü ���� ����
		// className([����������1], [����������2]);
		return Point(m_x++, m_y++);
	}

	// ���� ���� ���� ������ �ߺ����Ǹ� �����Լ��� ...
	// friend className operator++[--](className& �����ǿ�����, int);
	// friend Point operator++(Point& op1, int);

	// * ���� �����ڵ� ������ '�ϳ�' �̴�.
	// ���� ���� ������ �ߺ����Ǹ� ����Լ��� ...
	Point operator+=(const Point& op2)
	{
		m_x += op2.m_x;
		m_y += op2.m_y;
		return *this;
	}
	// ���� ���� ������ �ߺ����Ǹ� �����Լ��� ...
	// friend Point operator+=(Point& op1, const Point& op2);

};

#endif //__POINT_H__

