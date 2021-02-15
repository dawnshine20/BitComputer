// 어댑터 패턴은 클래스의 인터페이스를 사용자가 기대하는 다른 인터페이스로 변환하는 패턴으로,
// 호환성이 없는 인터페이스 때문에 함께 동작할 수 없는 클래스들이 함께 작동하도록 해 준다.
// 예) 회사 시스템 인수 합병 및 사용 논리
#include <iostream>

using namespace std;

class Duck
{
public:
    virtual ~Duck() { };
 
    virtual void quack() = 0;
    virtual void fly() = 0;
};
 
class Turkey
{
public:
    virtual ~Turkey() { };
 
    virtual void gobble() = 0;
    virtual void jump() = 0;
};
 
// 천둥 오리 기능 정의
class MallardDuck : public Duck
{
public:
    ~MallardDuck() { };
 
    void quack()
    {
        printf("꽥꽥\n");
    }
 
    void fly()
    {
        printf("난 날 수 있어요\n");
    }
};
 
// 야생 칠면조 기능 정의
class WildTurkey : public Turkey 
{
public:
    ~WildTurkey() { };

    void gobble()
    {
        printf("궉궉\n");
    }

    void jump()
    {
        printf("폴짝폴짝\n");
    }
};

class TurkeyAdapter : public Duck
{
private:
Turkey *turkey; // 기본적으로 내장된 칠면조의 기능

public:
TurkeyAdapter(Turkey *turkey)
{
    this->turkey = turkey;
}

void quack() // 재정의
{
    turkey->gobble();
}

void fly() // 재정의
{
    for( int i=0; i<5; i++ )
        turkey->jump();  // 5번은 뛰어야 오리가 1번 나는 것 동일하다고 정의
}
};

void testDuck(Duck *duck)
{
    duck->quack();
    duck->fly();
}

void main()
{
    MallardDuck malladDuck;
    WildTurkey wildTurkey;
    
    Duck *turkeyAdapter = new TurkeyAdapter(&wildTurkey);
    
    printf("---청둥 오리 테스트---\n");
    testDuck(&malladDuck);
    
    printf("\n");
    printf("---어댑터 적용한 칠면조 테스트---\n");
    testDuck(turkeyAdapter);
}