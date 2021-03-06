/*
The original source of this contents is '거꾸로 읽는 c++'
*/

#include <iostream>
#include "Point.h"
#include "DrawObj.h"
#include "Rectangle.h"

using namespace std;

/* Type 재정의 (정적 바인딩) */
class Base
{
public:
	void Display()
	{
		cout << "Base\n";
	}
};

class Derived : public Base
{
public:
	void Display()
	{
		cout << "Derived\n";
	}
};

/* 가상함수 (동적 바인딩) */
class Base2
{
public:
	virtual void Display()
	{}
};

class Derived2 : public Base2
{
public:
	virtual void Display()
	{}
};

/* Template */
template<class T>
T max(T a, T b)
{
	return (a > b) ? a : b;
}

template<class T>
class Counter
{
	T value;
public:
	T access_value();
};

template<class T>
T Counter<T>::access_value()
{
	return value;
}

template<class T>
T max(T data[], int count)
{
	int max = data[0];
	for (int i = 0; i < count; i++)
		if (max < data[i])
			max = data[i];

	return max;
}


int main()
{
	cout << "C++ Programming Basic Things 2nd.\n";

	//*********************************************************************
	// & 재사용: 포함과 상속
	// 1. 포함에 의한 재사용
	//  - 문서는 동영상을 가질 수 있다. 또는 문서는 이미지를 가질 수 있다.
	//  - B는 A를 가지고 있다.
	// 포함은 완전히 구현된 클래스를 이용
	//
	// 2. 상속에 의한 재사용(다양한 이력서 제출)
	//  - 영문 이력서는 이력서다.
	//  - A는 B다 라고 표현했을 때 이것이 의미나 논리가 자연스러우면
	// 구현이 완벽하지 않는 클래스를 사용할 수 있는 재사용 기법
	// 상속으로 클래스를 설계할 때 가급적 상속관계에 있는 각 클래스를 
	// 작은 단위로 분리
	// 명확한 하위 클래스부터 설계
	// 클래스 기능을 설계할 때는 상위 클래스부터 내려오는 것이 편리
	// 상위클래스는 하위 클래스를 위한 공통기능 구현
	// 그래야 하위 클래스에서 이것을 재사용
	// 멤버변수와는 달리 멤버함수는 하위 클래스에서 몇가지 형식으로 재사용
	// - (1) 멤버함수가 하위 클래스를 위한 공통적인 동작을 구현하는 경우,
	// - (2) 멤버함수가 하위 클래스를 위한 공통적인 동작을 선언하는 경우,
	// - (3) 멤버함수가 하위 클래스를 위한 공통적인 동작을 선언하고,
	//       일부 하위 클래스 동작을 구현할 수 있는 경우
	//
	// DrawObj obj;// 사용할 수 없음 추상 클래스
	// DrawObj의 Input과 Draw함수는 (3)번에 해당됨.
	// 즉, 하위 클래스에서 모두 재정의(Override)되어야하는 경우
	// DrawObj의 Offset 함수는 (1)번에 해당됨. 재정의 불필요
	//obj.Input();
	//obj.Draw();

	Rectangle rect;
	rect.Input();
	rect.Draw();

	//*********************************************************************
	// 재정의(Override)는 상속받는 상위 클래스 멤버함수를 다시 정의하는 것
	// 항상 상속관계에서만 사용하고 중복정의(Overloading)은 상속관계가 아닌
	// 클래스에서 더 많이 사용
	// 재정의는 함수이름, 인자 개수, 인자 자료형, 반환값이 모두 동일해야함!!
	// 중복정의는 코드의 직관성을 높이기 위해서 사용
	// 재정의는 클래스의 재사용을 높이기 위해서 사용
	// 생성자와 소멸자는 상속관계에 있는 클래스 사이에서 상속되지 않음 ~!!!!

	//*********************************************************************
	// & 다중상속
	// 1. 다중상속은 두개 이상의 클래스를 상속받기 때문에 뜻하지 않게 이름이
	// 충돌하는 문제가 발생
	// 2. 포인터 형변환의 문제
	// C++는 다중상속을 지원하지만 지양해야하는 요소

	//*********************************************************************
	// & 자료형 추상화(Abstract)
	// 클래스 사이의 형변환: B는 A다. -> B는 A가 될수 있지만, 
	// A는 B가 될 수 없다.!!!!!
	// 1. B 클래스 객체를 A 클래스 객체에 대입하는 경우
	// 2. B 클래스 객체를 A 클래스 참조형에 대입하는 경우
	// *3. B 클래스 객체 포인터를 A 클래스 포인터형에 대입하는 경우
	// 상위 클래스 타입으로 형변환해 사용하는 것을 자료형 추상화라고 함!
	// 최상위 클래스인 DrawObj는 객체가 되기 위해 존재하는 것이 아니라,
	// 하위 클래스 객체의 형변환 대상이 되기 위해 자료형으로만 존재함!
	// 그래서 이것을 추상 클래스라고 함.

	//*********************************************************************
	//& 정적 바인딩 / 동적 바인딩
	// 정적 바인딩으로 함수를 호출하는 것은 일반적인 멤버함수일 때는 바람직,
	// 상속 관계의 재정의된 함수를 호출할 때는 그렇지 못함
	// 재정의를 정상적으로 사용하려고하면 자료형 추상화를 할 수 없고,
	// 자료형을 단순화시키기 위해 자료형 추상화를 사용하려고 하면 재정의가
	// 동작하지 않는 문제!!
	// * virtual keyword(가상함수)
	// 자료형 추상화와 재정의를 동시에 구현할 수 있는 키워드!

	//*********************************************************************
	// & 형변환 연산
	// (type), static_cast, const_cast, reinterpret_cast, dynamic_cast
	//
	// * static_cast
	// 는 묵시적 캐스트(implicit_cast)와 일차적으로 같다.
	// 컴파일러에 의한 값 변환을 위하여 컴파일러가 기계어 코드를 만들어내는 
	// 시점이 컴파일 시점
	// 그래서 이것을 정적 캐스트
	// 포인터 타입 캐스트에 대한 동일 타입인 경우에 한하여 허용
	// 클래스 포인트에 대한 묵시적 캐스트는 'B는 A다' 관계가 성립하는 경우만
	// 형변환을 허용
	// 정적 캐스트는 'B는 A다' 관계가 성립하거나 상속관계가 성립한다면 항상 허용
	//
	// * reinterpret_case
	// 는 C/C++ 개발자가 일반적으로 사용했던 강제 캐스트 ((type)) 연산자와 비슷
	// 포인터 타입에 대한 캐스트만 수행
	//
	// * const_cast
	// 동일 타입의 포인터와 참조형에 대해서만 사용

	//*********************************************************************
	// & 가상함수, 추상 클래스
	// - 재정의
	// -- 타입으로 호출되는 재정의 (정적 바인딩)
	// -- 객체를 기준으로 호출되는 재정의 (동적 바인딩)
	Derived derived;
	derived.Display();		// Derived::Display() 가 호출
	
	// 위 재정의 함수는 함수를 호출할 때 사용한 자료형을 기준으로 함!
	Base* pbase = &derived;
	pbase->Display();		// Base::Display() 가 호출
	
	// 자료형으로 재정의된 함수가 호출되면 안되는 이유 두가지:(정적 바인딩)
	// 1. 상속관계를 가지는 클래스를 책체로 생성할 때 자료형 추상화 불가
	//    자료형 추상화란 클래스 객체를 생성하면서 상위 클래스로 형변환하는 것
	// 2. 자료형을 기준으로 재정의된 함수가 호출되면 과거에 개발된 알고리즘이
	//    미래에 개발될 클래스의 멤버함수를 호출할 수 없다.
	// 따라서 생산성이 떨어짐
	// 
	// * 동적 바인딩
	// virtual - 가상함수를 이용한 재정의 또는 가상함수
	// 실행시간에 재정의된 함수가 결정됨
	// 멤버함수를 호출할 때 사용한 객체에 따라 재정의된 함수가 호출됨
	// Display() 호출할 때 사용한 실제 객체를 이용
	Derived2 derived2;
	Base2* pbase2 = &derived2;
	pbase2->Display();			// Derived::Display()가 호출
	Base2 base2;
	pbase2 = &base2;
	pbase2->Display();			// Base2::Display()가 호출

	DrawObj* pDObj10;
	pDObj10 = new Rectangle;
	pDObj10->Input();
	pDObj10->Draw();
	delete pDObj10;

	// 객체를 이용한 재정의를 가능하게 함으로써 코드에서 사용되는 자료형을
	// 상위 클래스인 DrawObj 하나로 단순화함!

	//*********************************************************************
	// * 순수 가상함수
	// 선언만하고 구현은 할 필요가 없는 가상함수
	// DrawObj의 Draw()
	// virtual void Draw() const = 0;

	//*********************************************************************
	// * 추상 클래스
	// 순수 가상함수를 가지는 클래스는 객체로 생성할 수 없다!!!
	// 순수 가상함수를 가지는 클래스는 객체를 생성하기 위해 존재하는 것이 아님
	// 순수 가상함수를 하나라도 가지는 클래스는 자료형을 위해 존재한다.
	// 이렇게 자료형만을 위해 존재하는 클래스를 추상클래스(Abstract class)라고
	// 한다.
	// 추상클래스는 하위 클래스 객체를 생성한 다음 형변환을 위해 존재함
	// 멤버함수나 가상함수가 많아지는 것과 객체의 메모리 사용량과는 관계가 없다.
	// 소멸자는 항상 가상함수로 구현한다.
	// 상속되지 않는 클래스의 구현(Closed class)
	// 이런 경우에는 소멸자는 가상함수로 구현하지 않아도 됨

	//*********************************************************************
	// * 가상함수의 메모리 구조
	// 멤버함수는 객체에 포함되지 않는다.
	// 멤버함수가 많이 있는 클래스를 객체로 생성한다고해도 실제 객체에 
	// 생성되는 메모리는 멤버변수뿐이다.
	// 클래스 단위로 생성되는 가상함수 테이블
	// 함수 포인터의 배열
	// 상속과 가상함수 테이블
	// 가상함수를 상속받는 클래스가 해당 가상함수를 재정의하면 가상함수 테이블
	// 에 새로 정의한 함수주소가 설정되고, 재정의하지 않으면,
	// 상위 클래스에서 정의한 가상함수 주소가 설정
	// 가상함수 포인터 테이블은 객체와 가상함수 테이블을 연결하기 위한 고리
	// 생성자: 가상함수 테이블 포인터 초기화
	// 생성자에서는 가상함수를 호줄하지 못함
	// 개발자가 생성자를 하나도 구현하지 않는 경우, 그리고 클래스에 가상함수
	// 하나 이상이 있는 경우
	// 컴파일러는 숨겨진 디폴트 생성자를 구현함

	//*********************************************************************
	// & RTTI(Run-Time Type Information)
	// 실행 중에 객체의 자료형 정보를 알 수 있도록 하는 C++ 언어 기능
	// 클래스 자료형 정보를 가지고 있는 또 다른 클래스(type_info) 객체이다.

	//*********************************************************************
	// & Template(Generic Programming)
	// 템플릿은 코드 라이브러리를 만들때 가장 인지 있는 방법
	// - 함수 템플릿
	// - 클래스 템플릿
	// 1. 상속은 항상 수정을 전제로 한다. - 알고리즘 수정
	// 2. 변수의 자료형만 변경하고자 하는 경우 - 컴파일러에 의해 처리
	//
	// * 함수 템플릿
	// template<class T[, class S, class N]>
	//
	// 명시적 일반함수와 템플릿 함수가 공존할 때 어떤 함수가 우선적으로
	// 연결되는가?
	// 1. 컴파일러는 명시적인 일반함수에 의해 인자의 자료형이 정확하게
	// 일치하는 함수를 찾아 함수 호출을 연결
	// 2. 1단계에서 연결될 수 있는 일반함수가 없는 경우 컴파일러는 
	// 인자의 자료형이 정확하게 일치하는 템플릿 함수가 생성될 수 있는지
	// 보고, 생성될 수 있다면 해당 함수 템플릿을 복사하고 컴파일한 다음
	// 함수 호출을 연결
	// 3. 1단계외 2단계에 정확히 일치하는 함수가 없는 경우 컴파일러는
	// 일반함수에 대해서만 자료 형변환 방법을 통해 
	// 대응하는 적절한 함수를 찾아 함수 호출 연결
	// 템플릿은 소스코드를 줄일수는 있지만, 실행코드를 줄이지는 못한다.
	//
	// * 클래스 템플릿
	/*
	template<class T[, class S, class N]>
	class 클래스템플릿이름
	{
		// 클래스 템플릿 정의
	};
	*/
	//
	// 이렇게 선언한 다음에 템플릿 클래슨 멤버함수 코드를 클래스 외부에 
	// 구현해야함!!
	// 템플릿 클래스를 선언한 다음 클래스를 사용할 때, 
	// 템플릿 함수와는 달리 템플릿 클래스는 바로 사용할 수 없다.!!!
	// 클래스는 객체로 선언되어야하기 때문에 객체를 선언하기 위한 형식이 필요
	/*
	클래스이름<자료형리스트> 변수명;
	클래스이름* 포인터변수명 = new 클래스이름<자료형리스트>;
	*/

	Counter<int> counter1;
	Counter<double> counter2;
	Counter<int>* pcounter = new Counter<int>;

	// Stack 템플릿 구현
	// 재정의는 상속에서만 사용하는 것이 아니다.
	// 템플릿에서 이야기하는 재정의는 일반적인 상속관계의 재정의와는 달리
	// 상속을 전제하지 않는다.
	// 템플릿 인자도 함수인자 규칙과 비슷하다.
	// 템플릿 클래스의 정적멤버


	return 0;
}
