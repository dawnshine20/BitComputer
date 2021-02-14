/*
#include <iostream>

class CSort
{
public:
    virtual void AlgorithmInterface() = 0;
};

class CQuickSort : public CSort
{
public:
    void AlgorithmInterface() override
    {
        printf("Quick Sorting..\n");
    }
};

class CBubbleSort : public CSort
{
public:
    void AlgorithmInterface() override
    {
        printf("Bubble Sorting..\n");
    }
};

class CMergeSort : public CSort
{
public:
    void AlgorithmInterface() override
    {
        printf("Merge Sorting..\n");
    }
};

class Context
{
private:
    CSort* m_pSort;
public:
    Context() : m_pSort(0) {}
    ~Context() { if (m_pSort) delete m_pSort; }
public:
    void ChangeStrategy(CSort* pStrategy)
    {
        if (m_pSort) delete m_pSort;
        this->m_pSort = pStrategy;
    }
    void ContextInterface() { m_pSort->AlgorithmInterface(); }
};

int main()
{
    Context* pContext = new Context();

    pContext->ChangeStrategy(new CQuickSort());
    pContext->ContextInterface();

    pContext->ChangeStrategy(new CBubbleSort());
    pContext->ContextInterface();

    pContext->ChangeStrategy(new CMergeSort());
    pContext->ContextInterface();

    delete pContext;

    return 0;
}

*/
//Strategy.h
#include <iostream>
using namespace std;
#pragma once
class Strategy {
public:
    virtual void AlgorithmInterface() = 0;
};
//Strategy Algorithms
class ConcreteStrategyA : public Strategy { // 
public:
    void AlgorithmInterface() override { cout << "Call A" << endl; };
};
class ConcreteStrategyB : public Strategy {
public:
    void AlgorithmInterface() override { cout << "Call B" << endl; };
};
class ConcreteStrategyC : public Strategy {
public:
    void AlgorithmInterface() override { cout << "Call C" << endl; };
};
class Context {
public:
    Context() : _Strategy(0) {}
    ~Context() { if (_Strategy) delete _Strategy; }
    void ChangeStrategy(Strategy* pStrategy) {
        if (_Strategy) delete _Strategy;
        _Strategy = pStrategy;
    }
    void ContextInerface() { _Strategy->AlgorithmInterface(); }
private:
    Strategy* _Strategy;
};
///////////////////////////////////////
// main.cpp

int main() {
    Context* _Context = new Context();
    _Context->ChangeStrategy(new ConcreteStrategyA());
    _Context->ContextInerface();
    _Context->ChangeStrategy(new ConcreteStrategyB());
    _Context->ContextInerface();
    _Context->ChangeStrategy(new ConcreteStrategyC());
    _Context->ContextInerface();
    delete _Context;
    return 0;
}