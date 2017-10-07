#ifndef __POINT_H__
#define __POINT_H__

#include <iostream>
using namespace std;

// 접근자(Set/Get) Interface
// 클래스 외부와 멤버변수를 주고받기 위한 함수
// 접근자를 통한 값(범위) 검증

class Point
{
private:
	int m_x, m_y;
	enum {MIN_X = 0, MAX_X = 100, MIN_Y = 0, MAX_Y = 100};

public:
	// 클래스 생성자가 존재하지 않는 경우, 컴파일러가 제공해주는 생성자:
	// 인자를 가지지 않는  Default Constructor:
	Point() {
		cout << " Call default constructor: " << endl;
		m_x = 0;	// , or setx(0);
		m_y = 0;	// , or sety(0);
	}
	// (1) 인자가 하나 있는 생성자:
	Point(int xy) {
		setx(xy);
		sety(xy);
	}
	// (2) 인자가 2개 있는 생성자:
	Point(int x, int y) {
		cout << " Call constructor with two arguments " << endl;
		setx(x);
		sety(y);
	}
	
	// 클래스 내부에 멤버함수의 선언과 구현을 함께하는 것
	// 인라인 방식
	// 인라인 키워드로 분리한 함수는 헤더가 참조하기 좋은 위치인 
	// 클래스 헤더에 함께 두어야함
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

	// 상수형 멤버함수: 함수내에서 멤버변수 값을 변경할일이 없다. const!!!
	int getx() const { return m_x; }
	int gety() const { return m_y; }
	void print() const {
		cout << "Point = ( " << getx() << ", " << gety() << ")" << endl;
	}

	// 연산자 중복정의
	// 멤버함수로 연산자 중복정의를 구현하는 것이 일반적이기는 하지만,
	// 연산자의 좌측항이 클래스 객체가 아닐 때는 멤버함수가 아니라,
	// 반드시 전역함수로 구현해야함!
	// 다음의 연산자는 전역함수로 연산자 중복정의를 할 수 없음
	// 할당 연산자 '='
	// 클래스 멤버 액세스 '->'
	// 배열첨자 '[]'
	// 함수호출 '()'
	// 이 연산자들은 반드시 멤버함수로만 연산자 중복정의를 구현해야함
	// 연산자 중복정의 함수의 인자는 const 참조형!!!
	// MyString 클래스의 경우 복제 생성자를 구현해야하기 때문에 
	// 연산자 중복정의 함수를 구현할 때,
	// 인자를 const 참조형을 하지 않으면 오버헤드가 발생!

	/*
	연산자 중복정의를 멤버함수로 ...
	class className: 접근지정자 상위클래스이름
	{
	public:
		className operator연산자(const className& 우측피연산자);
	};

	className className::operator연산자(const className& 우측피연산자)
	{
	}
	*/

	/*
	연산자 중복정의를 전역함수로 ...
	class className: 접근지정자 상위클래스이름
	{
	public:
		friend className operator연산자(const className& 좌측피연산자, 
							const className& 우측피연산자);
	};

	className operator연산자(const className& 좌측피연산자,
						const className& 우측피연산자)
	{
	}
	*/

	Point operator+ (const Point& op2)
	{
		Point ret(m_x + op2.m_x, m_y + op2.m_y);
		return ret;
	}

	// * 반환값이 연산자를 중복정의한 클래스 객체가 아니어야하는 경우
	// 비교 연산자나 관계 연산자를 중복정의한 경우
	// 비교 연산자 중복정의를 멤버함수로 ...
	bool operator== (const Point& op2)
	{
		return(m_x == op2.m_x && m_y == op2.m_y);
	}
	// 비교 연산자 중복정의를 전역함수로 ...
	// friend bool operator== (const Point& op1, const Point& op2);

	// * 단항 연산자 중복정의
	// 단항 연산자를 멤버함수로 중복정의한다면,
	// 연산자의 우측(이항 연산자인 경우에는 좌측)에 있는 피연산자의 멤버가 호출
	// 그래서 단항 연산자를 멤버함수로 구현하면 인자가 존재하지 않는다.
	// 만약, 단항 연산자를 전역함수로 구현한다면,
	// 연산자의 피연산자 하나가 인자로 전달되므로 하나의 인자를 갖는다.
	// 단항 연산자 중복정의를 멤버함수로 ...
	Point operator-()
	{
		Point ret(-m_x, -m_y);
		return ret;
	}
	// 단항 연산자 중복정의를 전역함수로 ...
	// friend Point operator-(const Ponit& op1);

	// * 증감 단항 연산자 중복정의
	// 전위형(Prefix)과 후위형(Postfix)
	// 피연산자 자신이 변경

	// & 전위형
	// 전위 증감 단항 연산자 중복정의를 멤버함수로 ...
	// className operator++[--]();
	Point operator++()
	{
		++m_x;
		++m_y;
		return *this;
	}
	// 전위 증감 단항 연산자 중복정의를 전역함수로 ...
	// friend className operator++[--](className& 단항피연산자);
	// friend Point operator++(Point& op1);
	// 일반적으로 객체 자신의 값이 변경되지 않지만, 
	// 증감 연산자는 객체 자신의 값이 변경되기 때문에
	// 인자로 전달될 피연산자에 const가 없음!!!

	// & 후위형
	// : 구분을 위한 dummy int 사용
	// 후위 증감 단항 연산자 중복정의를 멤버함수로 ...
	// className operator++[--](int);
	Point operator++(int)
	{
		//m_x++;
		//m_y++;
		// 임시 객체 생성 문법
		// className([생성자인자1], [생성자인자2]);
		return Point(m_x++, m_y++);
	}

	// 후위 증감 단항 연산자 중복정의를 전역함수로 ...
	// friend className operator++[--](className& 단항피연산자, int);
	// friend Point operator++(Point& op1, int);

	// * 복합 연산자도 연산자 '하나' 이다.
	// 복합 단항 연산자 중복정의를 멤버함수로 ...
	Point operator+=(const Point& op2)
	{
		m_x += op2.m_x;
		m_y += op2.m_y;
		return *this;
	}
	// 복합 단항 연산자 중복정의를 전역함수로 ...
	// friend Point operator+=(Point& op1, const Point& op2);

};

#endif //__POINT_H__

