/*
The original source of this contents is '�Ųٷ� �д� c++'
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

// Class �Ļ� �ڷ���
class Student {
public:
	char name[20];
	int kor, eng, math;
	float tot, avg;

public:
	void print();
};

// �Լ��� �Ϲ������� ����� ������ �и���
// ��ȯ�� Ŭ�����̸�::�Լ��̸�(����)
void Student::print()
{
	cout << "Name = " << name << endl;
	cout << "Score\tNational\tEnglish\tMath\tTotal\tAvg." << endl;
	cout << "\t" << kor << "\t\t" << eng << "\t" << math << "\t" << tot << "\t" << avg << endl;
}

// *********************************************************
// ������ ó�� ����
// ��������, �������� �׸��� ��������
int globalVal;

// *********************************************************
// �Լ�����
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
	// � ������ ���� ������ ����� ���� �ڷ����� ������
	// ���ο� ������ ������ �� ���ٴ� ����� ���
	// ������ ������ �ݵ�� ����� �Բ� Ư�������� ����
	int a = 10;
	int& r = a;

	r = 15;

	cout << "a = " << a << endl;
	cout << "r = " << r << endl;

	int b;
	int& r1 = b;
	// ���ο� ������ ������ �� ����.
	r1 = r;
	r1 = 20;
	b = 30;

	cout << " a = " << a << endl;
	cout << " r = " << r << endl;
	cout << " b = " << b << endl;
	cout << " r1 = " << r1 << endl;

	// �������� ���� ȣ��(Call by reference)
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

	// �⺻ �ڷ���: ����, ������, ������, �Ǽ���
	// �Ļ� �ڷ���: �迭, ����ü, ����ü, Ŭ����
	// ����ü Ÿ�� ���� ��
	// C++�� C�� �޸� ������ ������ �� struct Ű���� ��������

	// Ŭ������ ��ü:
	// Ŭ������ ���Ӱ� ������ �ڷ����̰�
	// ���� �޸𸮻� ������ ������ ��ü
	// Ŭ������ �����Ϸ��� ��ü�� �����ϱ� ���� �����ϴ� ���赵
	// Ŭ���� = ������(�������) + �Լ�(����Լ�)

	// Convert STUDENT struct type in C to Student class in C++
	// High cohension - Capsulation -> Increase re-usability
	// ĸ��ȭ�� ������ ���� �Ѵ�.

	// *********************************************************
	/*
	class Ŭ�����̸� [: ���������� ����Ŭ�����̸�] {
	[����������:]
	����Լ�
	�������
	};
	// Ŭ������ ���������ڰ� ������ ��� ����Ʈ ���������ڴ� private ��
	// ����ü(struct)�� ����Ʈ ���������ڴ� public��
	// ����Ʈ ����� struct�� class����
	// STUDENT stdnt = {"Roy", 100, 80, 90}; // ����ü�� ���� �� �߰�ȣ �ʱ�ȭ ����
	// Student stdnt = {"Roy", 100, 100, 100}; // Ŭ������ ������ ���� �߻�
	*/

	// Class - �Ļ� �ڷ���
	Student stdnt;
	strcpy_s(stdnt.name, "Roy");
	stdnt.kor = 100;
	stdnt.eng = 80;
	stdnt.math = 90;
	stdnt.tot = (float)(stdnt.kor + stdnt.eng + stdnt.math);
	stdnt.avg = (float)stdnt.tot / 3;

	// ����Ʈ ������ �ƴ�, public ���������� ���� �� �߰�ȣ �ʱ�ȭ ����
	Student stdnt2 = { "MJ", 100, 100, 100 };
	stdnt2.tot = (float)(stdnt2.kor + stdnt2.eng + stdnt2.math);
	stdnt2.avg = stdnt2.tot / 3;

	stdnt.print();
	stdnt2.print();

	// *********************************************************
	// �������̽�
	// pubilc�� Ŭ���� �ܺο� ����� ������ �� ����ϴµ�,
	// Ư�� ����Լ��� public�� ����� ������ ��� �̸� �������̽���� ��
	// ��� ����� ����� ���¿��� Ŭ���� ���ο� ���� ��� ������ �Ѵٰ� �ؼ�
	// �̸� �������̽���� �ϴ� ���̴�.
	// ������(Set/Get) �������̽�
	// Ŭ���� �ܺο� ��������� �ְ� �ޱ� ���� �Լ�
	// �����ڸ� ���� ��(���� ����)
	// *********************************************************
	class Point {
	private:
		int m_x, m_y;
		enum { MIN_X = 0, MAX_X = 100, MIN_Y = 0, MAX_Y = 100 };

	public:
		// Ŭ���� �����ڰ� �������� �ʴ� ���, 
		// �����Ϸ��� �������ִ�
		// (0) Default ������:
		// ���ڸ� ������ �ʴ� Default ������:
		Point() {
			cout << "Call Default Constructor" << endl;
			m_x = 0; // , or setx(0);
			m_y = 0; // , or sety(0);
		}
		// (1) ���ڰ� 1�� �ִ� ������:
		Point(int xy) {
			setx(xy);
			sety(xy);
		}
		// (2) ���ڰ� 2�� �ִ� ������:
		Point(int x, int y) {
			cout << "Call Constructor with Arguments" << endl;
			setx(x);
			sety(y);
		}
		// Ŭ���� ���ο� ����Լ��� ����� ������ �Բ��ϴ� ��
		// �ζ���(inline) ���
		// inline Ű����� �и��� �Լ��� ����� �����ϱ� ���� ���� ��ġ��
		// Ŭ���� ����� �Բ� �ξ����
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

		// ����� ����Լ�:
		// �Լ������� ������� ���� ������ ���� ���� -> const
		int getx() const { return m_x; }
		int gety() const { return m_y; }
		void print() const {
			cout << "Point = (" << getx() << ", " << gety() << ")" << endl;
		}

		// *********************************************************
		// ������ �ߺ�����
		// ����Լ��� ������ �ߺ����Ǹ� �����ϴ� ���� �Ϲ����̱�� ������,
		// �������� �������� Ŭ���� ��ü�� �ƴ� ���� ����Լ��� �ƴ϶�,
		// �ݵ�� �����Լ��� �����ؾ���.
		// ������ �����ڴ� �����Լ��� ������ �ߺ����Ǹ� �� �� ����.
		// �Ҵ� ������ '='
		// Ŭ���� ��� �׼��� '->'
		// �迭÷�� '[]'
		// �Լ�ȣ�� '()'
		// �� �����ڵ��� �ݵ�� ����Լ��θ� ������ �ߺ����Ǹ� �����ؾ���.
		// ������ �ߺ����� �Լ��� ���ڴ� const ������!
		// MyString Ŭ������ ��� ���������ڸ� �����ؾ��ϱ� ������
		// ������ �ߺ����� �Լ��� ������ ��
		// ���ڸ� const �������� ���� ������ ������尡 �߻�!@
		// *********************************************************

		/*
		// ������ �ߺ����Ǹ� ����Լ��� ...
		class className: ���������� ���� Ŭ�����̸�
		{
		public:
			className operator������(const className& ���� �ǿ�����);
		};

		className className::operator������(const className& ���� �ǿ�����)
		{
		}

		// ������ �ߺ����Ǹ� �����Լ��� ...
		class className: ���������� ���� Ŭ�����̸�
		{
		public:
			friend className operator������(const className& ���� �ǿ�����, 
									const className& ���� �ǿ�����);
		};

		className operator������(const className& ���� �ǿ�����
									const className& ���� �ǿ�����)
		{
		}
		*/

		Point operator+(const Point& op2)
		{
			Point ret(m_x + op2.m_x, m_y + op2.m_y);
			return ret;
		}

		// * ��ȯ���� �����ڸ� �ߺ������� Ŭ���� ��ü�� �ƴϾ���ϴ� ���
		// �� �����ڳ� ���� �����ڸ� �ߺ������ϴ� ���
		// ����Լ��� ...
		bool operator==(const Point& op2)
		{
			return (m_x == op2.m_x && m_y == op2.m_y);
		}
		// �����Լ��� ...
		// friend bool operator==(const Point& op1, const Point& op2);

		// *  ���� ������ �ߺ�����
		// ���� �����ڸ� ����Լ��� �ߺ������Ѵٸ� 
		// �������� ����(���׿������� ��쿡�� ����)�� �ִ� �ǿ������� ����� ȣ��
		// �׷��� ���� �����ڸ� ����Լ��� �����ϸ� ���ڰ� �������� ����!
		// ����, ���� �����ڸ� �����Լ��� �����ϸ�,
		// �������� �ǿ����� �ϳ��� ���ڷ� ���޵ǹǷ� �ϳ��� ���ڸ� ���´�.
		// ����Լ��� ...
		Point operator-()
		{
			Point ret(-m_x, -m_y);
			return ret;
		}
		// �����Լ��� ...
		// friend Point operator-(const Point& op1)

		// *   ��/�� ���� ������ �ߺ�����
		// ������(prefix)�� ������(postfix)
		// �ǿ����� �ڽ��� ����
		// - ������
		// className operator++[--]();
		// friend className operator++[--](className& �����ǿ�����);
		// ����Լ��� ...
		Point operator++()
		{
			++m_x;
			++m_y;
			return *this;
		}
		// �����Լ��� ...
		// ��ü �ڽ��� ���� ������� ������, 
		// ���� �����ڴ� ��ü �ڽ��� ���� ����Ǳ� ������
		// ���ڷ� ���޵Ǵ� �ǿ����ڿ� const�� ����!
		// friend Point operator++(Point& op1);
		
		// - ������: ������ ���� dummy int ���
		// className operator++[--](int);
		// friend className operator++[--](className& �����ǿ�����, int);
		// ����Լ��� ...
		Point operator++(int)
		{
			// �ӽ� ��ü ���� ����
			// Ŭ�����̸�([������ ����1], [������ ����2]);
			return Point(m_x++, m_y++);
		}
		// �����Լ��� ...
		// friend Point operator++(Point& op1, int);

		// *  ���� �����ڵ� ������ '�ϳ�' �̴�.
		// ����Լ��� ...
		Point operator+=(const Point& op2)
		{
			m_x += op2.m_x;
			m_y += op2.m_y;
			return *this;
		}
		// �����Լ��� ...
		// friend Point operator_=(Point& op1, const Point& op2);
	};

	// *********************************************************
	// ����� ������ �и�
	// ��� �ߺ� ���� ����
	// #ifndef, #define, #endif

	// *********************************************************
	// & ������ ó�� ����
	// ���������� �ʱ�ȭ���� �ʴ� ��� ������ ���� ����
	// ���������� �ʱ�ȭ���� �ʴ� ��� 0(NULL) ���� ����
	// ���������� �ʱ�ȭ���� �ʴ� ��� 0(NULL) ���� ����
	// ���������� ���������� ���� ���̶�� ���� �����ǰ�, ���������� ���ÿ� ������
	// ��������, ��������, ���������� �������� �Ҵ�Ǵ� ���� �ƴϹǷ�
	// ��ȯ�� ���� �Ű澲�� �ʾƵ���!

	int localVal;
	static int staticVal;

	cout << "Unitialized global value = " << globalVal << endl;
	cout << "Unitialized local value = " << localVal << endl;
	cout << "Unitialized static value = " << staticVal << endl;

	function();

	// *********************************************************
	// &  �����ڿ� �Ҹ���
	// C++���� ��ȯ���� ������ �ʴ� �Լ��� �����ڿ� �Ҹ��� �� ������!
	Point pt;	// ���⼭ �����ڰ� ȣ��ȴ�.
	pt.print();

	// *********************************************************
	// &  �ߺ�����(Overload)
	// ����Ʈ ������: �����ڰ� � ���ڵ� ���� �ʰ� ����Ʈ ������ ��������� �ʱ�ȭ
	// ���ڰ� �ִ� ������: ���ڸ� ���޹ް� �̰��� �̿��� ��������� �ʱ�ȭ
	// ���� ������: Ŭ���� ��ü�� �����Ǹ鼭 �ڱ� �ڽŰ� ������ Ŭ���� Ÿ���� ��ü�� ����
	// *** ���ڰ� �ִ� �����ڸ� ������ �� �ݵ�� ���ڰ� ���� �����ڵ� �����ؾ� ��!
	Point pt2(50, 60);
	pt2.print();

	// *********************************************************
	// &  ���� ������ ������ ǥ��
	Point pt3 = 40; // Point pt3(40);���� �ؼ� <- ��ü�� ������ ���� ��밡��!
	pt3.print();
	Point ptlist[] = { Point(), Point(70, 80), Point(50) };

	// *********************************************************
	// & �Ҹ���
	// �����ڿ� �޸� �Ҹ��ڴ� ���ڸ� ������ ����
	// ���������� ����� ��ü�� ���α׷��� ����� �� �Ҹ��ڰ� ȣ��ǰ�
	// ���������� ����� ��ü�� ��� �ݴ� �߰�ȣ '}' ���� �Ҹ��ڰ� ȣ���
	// �� �� ��� ��� �Ҹ��ڸ� ȣ���ϴ� ��� �ڵ嵵 ����.
	// �Ҹ��ڴ� �Ҵ�(e.g. malloc) ������ �ִ� ��� ���� �����ϱ� ���ؼ� ����� �� ����!



	return 0;
}


void function()
{
	int localVal2;
	cout << "The 2nd Unitialized local value = " << localVal2 << endl;
}