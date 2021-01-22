#include "pch.h"
#include "MyClass1.h"

void CMyClass::SetData1(int Data) 
{ this->m_Data1 = Data; }

void CMyClass::SetData2(int Data) 
{ this->m_Data2 = Data; }

void CMyClass::SetData3(int Data) 
{ this->m_Data3 = Data; }

int CMyClass::getData1() 
{ return m_Data1; }

int CMyClass::getData2() 
{ return m_Data2; }

int CMyClass::getData3() 
{ return m_Data3; }

void CMyClass::CalcData() 
{
	m_Data3 = m_Data1 + m_Data2;
}
