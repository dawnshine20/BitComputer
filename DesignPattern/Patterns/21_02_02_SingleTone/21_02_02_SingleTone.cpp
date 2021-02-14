/*
#include <iostream>
using namespace std;


-다른 객체가 생성 될 수 없도록 하는 설계기법
-공통적으로 쓰이는 자원을 관리, 저장하는 역할(ex.connection pool)
-메모리 낭비를 방지
-프로그램 초기화에서 로딩이 이루어지고 종료시에 메모리 해제
-수학함수들의 집합(issue,논쟁 이루어짐--만약 수함 함수 사용 안하면... 완전 손해)
- 프레임워크,리소스에 사용(뼈대는 한개만 있어야한다.)

객체가 2개가 생성되면 무슨일이 발생하는가
1. 메모리가 엄청 낭비된다.
(메모리 낭비하는 프로그래머의 실수를 미연에 방지한다.)
(아예 컴파일 단에서 생성이 불가하도록 유도)



// 보스몹과 싱글톤은 사용 매칭이 맞지 않다.
class CBoss          //싱글톤 클래스이다.
{
private:
    static CBoss* pUnit_;
    int hp;

public:
    CBoss() {
        hp = 100;
    }
    static CBoss* CreateInstance()
    {
        if (pUnit_ == nullptr)
        {
            printf("머쉬맘 생성\n");
            pUnit_ = new CBoss;
        }
        else
            printf("머쉬맘 이미 존재함\n");

        return pUnit_;
    }
    static void DestroyUnit(CBoss* boss)
    {
        delete pUnit_;
        pUnit_ = nullptr;
        return;
    }

    int GetHp()
    {
        return hp;
    }
    void LoseHp(int lose)
    {
        hp -= lose;
    }
    
};

// -- 클래스 변수 정의

CBoss* CBoss::pUnit_ = nullptr;
int main()
{
    CBoss* MushMom = CBoss::CreateInstance();
    CBoss* MushMom2 = CBoss::CreateInstance();
   
    printf("보스의 체력은 : %d\n", MushMom->GetHp());

    for (int i = 0; i < 20; i++)
    {
        MushMom->LoseHp(5);
    }
    
    if (MushMom->GetHp() <= 0)
    {
        CBoss::DestroyUnit(MushMom);
        printf("머쉬맘 죽음\n");
        MushMom = CBoss::CreateInstance();
    }
    
    if(MushMom != nullptr)
        CBoss::DestroyUnit(MushMom);

    return 0;
}
*/




//Singleton.h
#include <iostream>
using namespace std;

#pragma once    //한번만 실행
class Singleton {
private:
    // 외부에서 객체 생성 불가
    // 객체.함수() 호출 불가(사용하기 위해서는 static을 사용해서  메모리를 위로 올리는 방법밖에 없다.)
    // static 함수 내에서는 반드시 static 함수, static 변수만 사용 가능
    Singleton() {}; //생성자가 private 내에 존재하기 때문에 외부에서 객체 생성이 불가하다.
    static Singleton* instance;
    
public:
    static Singleton* getInstance()
    {
        if (instance == nullptr)
            instance = new Singleton();
        return instance;
    }
    void showMessage()
    {
        printf("Singleton  \n");
    }
};

//Singletoncpp-----------------------------------------------
Singleton* Singleton::instance = nullptr;

int main(void)
{
    //생성불가
    //Singleton s;
    //Singleton* s = new Singleton;
    
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();// 메모리 공유하는 개념(없으면 만들고 기존에 존재하면 공유하겠다는 논리)
    Singleton* s3 = Singleton::getInstance();// 메모리 공유하는 개념(없으면 만들고 기존에 존재하면 공유하겠다는 논리)
    s1->showMessage();
    s2->showMessage();
    s3->showMessage();
    
    return 0;
}