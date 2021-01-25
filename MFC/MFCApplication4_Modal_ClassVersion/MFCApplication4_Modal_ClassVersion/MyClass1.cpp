#include "pch.h"
#include "MyClass1.h"

void CMyClass::SetData1(int Data) 
{ this->m_Data1 = Data; }

void CMyClass::SetData2(int Data) 
{ this->m_Data2 = Data; }

void CMyClass::SetData3(int Data) 
{ this->m_Data3 = Data; }

int CMyClass::GetData1() 
{ return m_Data1; }

int CMyClass::GetData2() 
{ return m_Data2; }

int CMyClass::GetData3() 
{ return m_Data3; }
int CMyClass::GetResult()
{ return result; }
void CMyClass::CalcData() 
{
	result = m_Data1 + m_Data2 + m_Data3;
}
