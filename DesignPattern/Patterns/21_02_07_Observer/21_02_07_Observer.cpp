//정의 한 객체의 상태가 바뀌면 그 객체에 의존하는 다른 객체들(Obserbers)에게 
//전해지고 자동으로 갱신되는 일대 다 양식의 패턴
/*
#include <iostream>
#include <list>
using namespace std;

class CUser abstract
{
public:
	void UpdateNews(string news)
	{
		m_News = news;
	}
	virtual void Attack() = 0;
protected:
	string m_News;
};

class CUser_NO1 : public CUser
{
public:
	void Attack() override
	{
		printf("user1 : Attack %s\n", m_News.c_str());
	}
	~CUser_NO1()
	{
		printf("user1 : 나갔습니다..\n");
	}
};

class CUser_NO2 : public CUser
{
public:
	void Attack() override
	{
		printf("user2 : Attack %s\n", m_News.c_str());
	}
	~CUser_NO2()
	{
		printf("user2 : 나갔습니다..\n");
	}
};

class CUser_NO3 : public CUser
{
public:
	void Attack() override
	{
		printf("user3 : Attack %s\n", m_News.c_str());
	}
	~CUser_NO3()
	{
		printf("user3 : 나갔습니다..\n");
	}
};



class Subject abstract
{
public:
	virtual void ResisterObserver(CUser* ob) = 0;
	virtual void RemoveObserver(CUser* ob) = 0;
	virtual void NotifyObserver() = 0;
protected:
	list<CUser*> m_ObserverList;
	list<CUser*>::iterator it;
};

class CAlarmPopUp : public Subject
{
private:
	string m_strMonster;
public:
	~CAlarmPopUp()
	{
		printf("게임 종료\n");
	}

	void ResisterObserver(CUser* ob) override
	{
		m_ObserverList.push_back(ob);
		printf("User이 들어왔습니다..\n" );
	}
	void RemoveObserver(CUser* ob) override
	{
		m_ObserverList.pop_back();
		printf("User가 나갔습니다..\n" );
	}
	void NotifyObserver() override
	{
		printf("%s 출몰!!!!\n", m_strMonster.c_str());
		
		for (it = m_ObserverList.begin(); it != m_ObserverList.end(); ++it)
		{
			(*it)->UpdateNews(GetNews());
		}
	}
	string GetNews() { return m_strMonster; }
	void setNews(string news) { m_strMonster = news; }
};

int main()
{
	list<CUser*> m_UserList;
	list<CUser*>::iterator it_UserList;

	CAlarmPopUp* alarm = new CAlarmPopUp();

	//주황버섯 
	CUser_NO1* user1 = new CUser_NO1();
	CUser_NO2* user2 = new CUser_NO2();
	CUser_NO3* user3 = new CUser_NO3();

	m_UserList.push_back(user1);
	m_UserList.push_back(user2);
	m_UserList.push_back(user3);

	//리스트에 등록
	for (it_UserList = m_UserList.begin(); it_UserList != m_UserList.end(); ++it_UserList)
	{
		if (*it_UserList == user2) {
			continue; // user2는 등록을 안한다.
		}
		alarm->ResisterObserver(*it_UserList);
	}

	alarm->setNews("머쉬맘");
	// 등록된 옵저버들에게 유저가 생겼음을 알려준다.(등록된 유저들에게 주황버섯이 출몰됬음을 알려준다.)
	alarm->NotifyObserver();

	for (it_UserList = m_UserList.begin(); it_UserList != m_UserList.end(); ++it_UserList)
	{
		(*it_UserList)->Attack();
	}
	
	for (it_UserList = m_UserList.begin(); it_UserList != m_UserList.end(); ++it_UserList)
	{
		delete(*it_UserList);
	}
	
	delete(alarm);
}
*/

//Observer.h
#include <vector>
#include <iostream>

class Observer
{
public:
	void notify();
};
class ConcreteObserverA : Observer {};
class ConcreteObserverB : Observer {};
//Observer.cpp
#pragma once
void Observer::notify()
{
	std::cout << "notified" << std::endl;
}
//Subject.h
#pragma once
class Subject
{
private:
	std::vector<Observer*> observers;
public:
	void addObserver(Observer* observer);
	void removeObserver(Observer* observer);
	void notifyObservers();
};
//subject.cpp

void Subject::addObserver(Observer* observer)
{
	observers.push_back(observer);
}
void Subject::removeObserver(Observer* observer)
{
	for (std::vector<Observer*>::iterator to_remove = observers.begin(); to_remove != observers.end(); ++to_remove)
	{
		if (*to_remove == observer)
		{
			observers.erase(to_remove);
			break;
		}
	}
}
void Subject::notifyObservers()
{
	for (auto o : observers)
	{
		if (o != nullptr)
			o->notify();
	}
}