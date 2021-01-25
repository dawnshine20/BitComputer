#pragma once
class CMyClass {
private:
	int m_Data1;
	int m_Data2;
	int m_Data3;
	int result;
public:
	void SetData1(int Data);
	void SetData2(int Data);
	void SetData3(int Data);
	int GetData1();
	int GetData2();
	int GetData3();
	int GetResult();
	void CalcData();

};

