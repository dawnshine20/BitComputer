// 주어진 상황 및 용도에 따라 어떤 객체에 책임을 덧붙이는 패턴
// 기능 확장이 필요할 때 서브클래싱 대신 쓸 수 있는 유연한 대안
// 동적으로 객체의 추가적인 기능들을 가진 객체를 덧붙여 꾸밀 수 있다.
#include <iostream>
#include <locale>
using namespace std;

class ICoffeeComponent
{
public:
    virtual int GetCost() = 0;
    virtual wstring GetIngredients() = 0;
};

class Coffee : public ICoffeeComponent
{
public:
    int GetCost() { return 1000; }
    wstring GetIngredients() { return (L"커피"); }
};

class CoffeeDecorator : public ICoffeeComponent
{
private:
    ICoffeeComponent* pComponent;
public:
    CoffeeDecorator(ICoffeeComponent* c) : pComponent(c) {}
    ~CoffeeDecorator() { if (pComponent) delete pComponent; }

public:
    // 커피가 있다는 가정하에 가격을 GET할 수 있다.
    int GetCost() { if (pComponent) return pComponent->GetCost(); else return 0; }
    wstring GetIngredients() { if (pComponent) return pComponent->GetIngredients(); else return (L""); }
};

class MilkDecorator : public CoffeeDecorator
{
public:
    MilkDecorator(ICoffeeComponent* d) : CoffeeDecorator(d) {}

public:
    int GetCost() { return CoffeeDecorator::GetCost() + 200; }
    wstring GetIngredients() { return (L"우유 + ") + CoffeeDecorator::GetIngredients(); }
};

class WhipCreamDecorator : public CoffeeDecorator
{
public:
    WhipCreamDecorator(ICoffeeComponent* d) : CoffeeDecorator(d) {}

public:
    int GetCost() { return CoffeeDecorator::GetCost() + 200; }
    wstring GetIngredients() { return (L"휘핑크림 + ") + CoffeeDecorator::GetIngredients(); }
};

int main()
{
    _wsetlocale(LC_ALL, L"korean");

    ICoffeeComponent* pComponent = new MilkDecorator(new WhipCreamDecorator(new CoffeeDecorator(new Coffee())));
    printf("%ls : %d\n", L"비용",pComponent->GetCost());
    printf("%ls : %ls\n", L"재료", pComponent->GetIngredients().c_str());
    delete pComponent;

    return 0;
}