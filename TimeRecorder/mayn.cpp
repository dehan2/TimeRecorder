// timeChecker.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>

#include "TimeRecorder.h"

using namespace std;

float method1(int a, float b)
{
	cout << "a = " << a << ", b = " << b << endl;
	return a+b;
}

int main()
{
	string tag1("vero-method1");
	TimeRecorder<float, int, float> method1_with_timeRecorder(tag1, method1);

	float resultValue = method1_with_timeRecorder(10, 30.3);

	cout << "Result : " << resultValue << endl;
	cout << "Record: " << method1_with_timeRecorder.get_record() << endl;

    return 0;
}