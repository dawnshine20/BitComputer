#pragma once
class CMyClass {
private:
	int m_Data1;
	int m_Data2;
	int m_Data3;
public:
	void SetData1(int Data);
	void SetData2(int Data);
	void SetData3(int Data);
	int getData1();
	int getData2();
	int getData3();

	void CalcData();
};

