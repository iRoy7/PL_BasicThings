/*
The original source of this contents is '거꾸로 읽는 c++'
*/

#include <iostream>
#include <string>
#include <iomanip>	// Manipulator
using namespace std;

// Strct type
// Low coupling
// It's too difficult to modify and reuse it

struct  STUDENT {
public:
	char name[20];
	int kor, eng, math;
	float tot, avg;
};

STUDENT stdnt[10];

void set_student(STUDENT *ps, char *name, int kor, int eng, int math)
{
	strcpy_s(ps->name, name);
	ps->kor = kor;
	ps->eng = eng;
	ps->math = math;
}

float calc_tot(STUDENT *ps)
{
	ps->tot = (float)(ps->kor + ps->eng + ps->math);
	return ps->tot;
}

float calc_avg(STUDENT *ps)
{
	ps->avg = ps->tot / 3;
	return ps->avg;
}

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

// Class 파생 자료형
class Student {
public:
	char name[20];
	int kor, eng, math;
	float tot, avg;

public:
	void print();
};

// 함수는 일반적으로 선언과 구현을 분리함
// 반환겺 클래스이름::함수이름(인자)
void Student::print()
{
	cout << "Name = " << name << endl;
	cout << "Score\tNational\tEnglish\tMath\tTotal\tAvg." << endl;
	cout << "\t" << kor << "\t\t" << eng << "\t" << math << "\t" << tot << "\t" << avg << endl;
}

// *********************************************************
// 데이터 처리 시작
// 지역변수, 전역변수 그리고 정적변수
int globalVal;

// *********************************************************
// 함수선언
void function();
int function2();


int main()
{
	string str1 = "C++ String Object:";
	char buff[128];
	strcpy_s(buff, str1.c_str());

	cout << str1 << "\n";

	string file;
	cout << "Input file name: ";
	cin >> file;

	int idx = file.find_last_of('.');
	cout << "idx = " << idx << endl;

	if (idx == string::npos)
		cout << "Wrong file extension\n";
	else
		cout << "File extension by file format: " << file.substr(idx) << endl;

	// Reference Type
	// 어떤 변수에 대해 별명을 만들기 위한 자료형을 참조형
	// 새로운 참조를 설정할 수 없다는 사실을 기억
	// 참조형 변수는 반드시 선언과 함께 특정변수를 참조
	int a = 10;
	int& r = a;

	r = 15;

	cout << "a = " << a << endl;
	cout << "r = " << r << endl;

	int b;
	int& r1 = b;
	// 새로운 참조를 설정할 수 없다.
	r1 = r;
	r1 = 20;
	b = 30;

	cout << " a = " << a << endl;
	cout << " r = " << r << endl;
	cout << " b = " << b << endl;
	cout << " r1 = " << r1 << endl;

	// 참조형에 의한 호출(Call by reference)
	int i, j;
	cout << "i, j = ";
	cin >> i >> j;

	swap(i, j);

	cout << "(" << i << ", " << j << ")" << endl;

	double pi = 3.1415;
	int ii = 16;
	cout << "pi = " << pi << endl;
	cout << setw(10) << setfill('0') << pi << endl;
	cout << setprecision(3) << pi << endl;
	cout << "ii = " << ii << endl;
	cout << "dec = " << setbase(10) << ii << endl;
	cout << "hex = " << setbase(16) << ii << endl;
	cout << "oct = " << setbase(8) << ii << endl;

	string str2;
	cout << "INPUT your name: ";
	getline(cin, str2);
	cout << "Thanks, " << str2 << ".\n";

	// 기본 자료형: 논리형, 문자형, 정수형, 실수형
	// 파생 자료형: 배열, 구조체, 공용체, 클래스
	// 구조체 타입 선언 후
	// C++는 C와 달리 변수를 선언할 때 struct 키워드 생략가능

	// 클래스와 객체:
	// 클래스는 새롭게 정의한 자료형이고
	// 실제 메모리상에 생성한 변수가 객체
	// 클래스는 컴파일러가 객체를 생성하기 위해 참조하는 설계도
	// 클래스 = 데이터(멤버변수) + 함수(멤버함수)

	// Convert STUDENT struct type in C to Student class in C++
	// High cohension - Capsulation -> Increase re-usability
	// 캡슐화는 조립을 쉽게 한다.

	// *********************************************************
	/*
	class 클래스이름 [: 접근지정자 상위클래스이름] {
	[접근지정자:]
	멤버함수
	멤버변수
	};
	// 클래스의 접근지정자가 생략될 경우 디폴트 접근지정자는 private 임
	// 구조체(struct)의 디폴트 접근지정자는 public임
	// 디폴트 선언된 struct와 class에서
	// STUDENT stdnt = {"Roy", 100, 80, 90}; // 구조체는 선언 후 중괄호 초기화 가능
	// Student stdnt = {"Roy", 100, 100, 100}; // 클래스는 컴파일 에러 발생
	*/

	// Class - 파생 자료형
	Student stdnt;
	strcpy_s(stdnt.name, "Roy");
	stdnt.kor = 100;
	stdnt.eng = 80;
	stdnt.math = 90;
	stdnt.tot = (float)(stdnt.kor + stdnt.eng + stdnt.math);
	stdnt.avg = (float)stdnt.tot / 3;

	// 디폴트 선언이 아닌, public 접근지정자 선언 후 중괄호 초기화 가능
	Student stdnt2 = { "MJ", 100, 100, 100 };
	stdnt2.tot = (float)(stdnt2.kor + stdnt2.eng + stdnt2.math);
	stdnt2.avg = stdnt2.tot / 3;

	stdnt.print();
	stdnt2.print();

	// *********************************************************
	// 인터페이스
	// pubilc은 클래스 외부에 멤버를 공개할 때 사용하는데,
	// 특히 멤버함수로 public을 사용해 공개한 경우 이를 인터페이스라고 함
	// 모든 멤버가 은폐된 상태에서 클래스 내부에 들어가는 통로 역할을 한다고 해서
	// 이를 인터페이스라고 하는 것이다.
	// 접근자(Set/Get) 인터페이스
	// 클래스 외부와 멤버변수를 주고 받기 위한 함수
	// 접근자를 통한 값(범위 검증)
	// *********************************************************
	class Point {
	private:
		int m_x, m_y;
		enum { MIN_X = 0, MAX_X = 100, MIN_Y = 0, MAX_Y = 100 };

	public:
		// 클래스 생성자가 존재하지 않는 경우, 
		// 컴파일러가 제공해주는
		// (0) Default 생성자:
		// 인자를 가지지 않는 Default 생성자:
		Point() {
			cout << "Call Default Constructor" << endl;
			m_x = 0; // , or setx(0);
			m_y = 0; // , or sety(0);
		}
		// (1) 인자가 1개 있는 생성자:
		Point(int xy) {
			setx(xy);
			sety(xy);
		}
		// (2) 인자가 2개 있는 생성자:
		Point(int x, int y) {
			cout << "Call Constructor with Arguments" << endl;
			setx(x);
			sety(y);
		}
		// 클래스 내부에 멤버함수의 선언과 구현을 함께하는 것
		// 인라인(inline) 방식
		// inline 키워드로 분리한 함수는 헤더가 참조하기 가장 좋은 위치인
		// 클래스 헤더에 함께 두어야함
		void setx(int x) {
			if (MAX_X < x) x = MAX_X;
			if (x < MIN_X) x = MIN_X;
			m_x = x;
		}

		void sety(int y) {
			if (MAX_Y < y) y = MAX_Y;
			if (y < MIN_Y) y = MIN_Y;
			m_y = y;
		}

		// 상수형 멤버함수:
		// 함수내에서 멤버변수 값을 변경할 일이 없다 -> const
		int getx() const { return m_x; }
		int gety() const { return m_y; }
		void print() const {
			cout << "Point = (" << getx() << ", " << gety() << ")" << endl;
		}

		// *********************************************************
		// 연산자 중복정의
		// 멤버함수로 연산자 중복정의를 구현하는 것이 일반적이기는 하지만,
		// 연산자의 좌측항이 클래스 객체가 아닐 때는 멤버함수가 아니라,
		// 반드시 전역함수로 구현해야함.
		// 다음의 연산자는 전역함수로 연산자 중복정의를 할 수 없다.
		// 할당 연산자 '='
		// 클래스 멤버 액세스 '->'
		// 배열첨자 '[]'
		// 함수호출 '()'
		// 이 연산자들은 반드시 멤버함수로만 연산자 중복정의를 구현해야함.
		// 연산자 중복정의 함수의 인자는 const 참조형!
		// MyString 클래스의 경우 복제생성자를 구현해야하기 때문에
		// 연산자 중복정의 함수를 구현할 때
		// 인자를 const 참조형을 하지 않으면 오버헤드가 발생!@
		// *********************************************************

		/*
		// 연산자 중복정의를 멤버함수로 ...
		class className: 접근지정자 상위 클래스이름
		{
		public:
			className operator연산자(const className& 우측 피연산자);
		};

		className className::operator연산자(const className& 우측 피연산자)
		{
		}

		// 연산자 중복정의를 전역함수로 ...
		class className: 접근지정자 상위 클래스이름
		{
		public:
			friend className operator연산자(const className& 좌측 피연산자, 
									const className& 우측 피연산자);
		};

		className operator연산자(const className& 좌측 피연산자
									const className& 우측 피연산자)
		{
		}
		*/

		Point operator+(const Point& op2)
		{
			Point ret(m_x + op2.m_x, m_y + op2.m_y);
			return ret;
		}

		// * 반환값이 연산자를 중복정의한 클래스 객체가 아니어야하는 경우
		// 비교 연산자나 관계 연산자를 중복정의하는 경우
		// 멤버함수로 ...
		bool operator==(const Point& op2)
		{
			return (m_x == op2.m_x && m_y == op2.m_y);
		}
		// 전역함수로 ...
		// friend bool operator==(const Point& op1, const Point& op2);

		// *  단항 연산자 중복정의
		// 단항 연산자를 멤버함수로 중복정의한다면 
		// 연산자의 우측(이항연산자인 경우에는 좌측)에 있는 피연산자의 멤버가 호출
		// 그래서 단항 연산자를 멤버함수로 구현하면 인자가 존재하지 않음!
		// 만약, 단항 연산자를 전역함수로 구현하면,
		// 연산자의 피연산자 하나가 인자로 전달되므로 하나의 인자를 갖는다.
		// 멤버함수로 ...
		Point operator-()
		{
			Point ret(-m_x, -m_y);
			return ret;
		}
		// 전역함수로 ...
		// friend Point operator-(const Point& op1)

		// *   증/감 단항 연산자 중복정의
		// 전위형(prefix)와 후위형(postfix)
		// 피연산자 자신이 변경
		// - 전위형
		// className operator++[--]();
		// friend className operator++[--](className& 단항피연산자);
		// 멤버함수로 ...
		Point operator++()
		{
			++m_x;
			++m_y;
			return *this;
		}
		// 전역함수로 ...
		// 객체 자신의 값이 변경되지 않지만, 
		// 증감 연산자는 객체 자신의 값이 변경되기 때문에
		// 인자로 전달되는 피연산자에 const가 없음!
		// friend Point operator++(Point& op1);
		
		// - 후위형: 구분을 위한 dummy int 사용
		// className operator++[--](int);
		// friend className operator++[--](className& 단항피연산자, int);
		// 멤버함수로 ...
		Point operator++(int)
		{
			// 임시 객체 생성 문법
			// 클래스이름([생성자 인자1], [생성자 인자2]);
			return Point(m_x++, m_y++);
		}
		// 전역함수로 ...
		// friend Point operator++(Point& op1, int);

		// *  복합 연산자도 연산자 '하나' 이다.
		// 멤버함수로 ...
		Point operator+=(const Point& op2)
		{
			m_x += op2.m_x;
			m_y += op2.m_y;
			return *this;
		}
		// 전역함수로 ...
		// friend Point operator_=(Point& op1, const Point& op2);
	};

	// *********************************************************
	// 선언과 구현의 분리
	// 헤더 중복 참조 방지
	// #ifndef, #define, #endif

	// *********************************************************
	// & 데이터 처리 시작
	// 지역변수는 초기화되지 않는 경우 임의의 값을 가짐
	// 전역변수는 초기화되지 않는 경우 0(NULL) 값을 가짐
	// 정적변수는 초기화되지 않는 경우 0(NULL) 값을 가짐
	// 전역변수와 정적변수는 정적 힘이라는 곳에 생성되고, 지역변수는 스택에 생성됨
	// 전역변수, 정적변수, 지역변수는 동적으로 할당되는 것이 아니므로
	// 반환에 대해 신경쓰지 않아도됨!

	int localVal;
	static int staticVal;

	cout << "Unitialized global value = " << globalVal << endl;
	cout << "Unitialized local value = " << localVal << endl;
	cout << "Unitialized static value = " << staticVal << endl;

	function();

	// *********************************************************
	// &  생성자와 소멸자
	// C++에서 반환값을 가지지 않는 함수는 생성자와 소멸자 두 종류뿐!
	Point pt;	// 여기서 생성자가 호출된다.
	pt.print();

	// *********************************************************
	// &  중복정의(Overload)
	// 디폴트 생성자: 생성자가 어떤 인자도 받지 않고 디폴트 값으로 멤버변수를 초기화
	// 인자가 있는 생성자: 인자를 전달받고 이것을 이용해 멤버변수를 초기화
	// 복제 생성자: 클래스 객체가 생성되면서 자기 자신과 동일한 클래스 타입의 객체를 전달
	// *** 인자가 있는 생성자를 구현할 때 반드시 인자가 없는 생성자도 구현해야 함!
	Point pt2(50, 60);
	pt2.print();

	// *********************************************************
	// &  인자 전달의 관용적 표현
	Point pt3 = 40; // Point pt3(40);으로 해석 <- 객체를 생성할 때만 사용가능!
	pt3.print();
	Point ptlist[] = { Point(), Point(70, 80), Point(50) };

	// *********************************************************
	// & 소멸자
	// 생성자와 달리 소멸자는 인자를 가지지 않음
	// 전역변수로 선언된 객체는 프로그램이 종료될 때 소멸자가 호출되고
	// 지역변수로 선언된 객체의 경우 닫는 중괄호 '}' 에서 소멸자가 호출됨
	// 이 두 경우 모두 소멸자를 호출하는 어떠한 코드도 없다.
	// 소멸자는 할당(e.g. malloc) 개념이 있는 모든 것을 정리하기 위해서 사용할 수 있음!



	return 0;
}


void function()
{
	int localVal2;
	cout << "The 2nd Unitialized local value = " << localVal2 << endl;
}