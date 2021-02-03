#include <iostream>
using namespace std;


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
