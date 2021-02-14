// 프록시 패턴이란 ?
// 대리자로써 일을 맡기면 그 일을 처리하고 완료되면 그 결과를 알려주는 패턴

// 예)
// 이미지 파일을 디스크에서 읽어오는 경우 최초 사용시에 한번 디스크에서 이미지를 로딩하여 캐싱하고
// 그 다음부터는 캐싱이미지로 처리
#include<iostream>

class Subject // client
{
public:
	virtual void request() = 0;
};

// RealSubject 상속 클래스
class RealSubject : public Subject
{
public:
	void request() { printf("Response by RealSubject\n"); }
};

//Proxy 상속 클래스
class Proxy : public Subject
{
public:
	Proxy() : mReal(NULL) {}
	~Proxy() { if (mReal) delete mReal; }

public:
	void request()
	{
		if (!mReal)
			mReal = new RealSubject;

		mReal->request();
	}

private:
	RealSubject* mReal;
};

int main()
{
	Subject* pProxy = new Proxy();
	pProxy->request();
	pProxy->request();
	pProxy->request();
	delete pProxy;

	return 0;
}