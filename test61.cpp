
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream> 
#include <io.h>
#include <Windows.h>
#include "opencv\cv.h"
#include "opencv\highgui.h"
#include <direct.h>

using namespace cv;
using namespace std;
int test61(int argc, char *argv[])
{

	string inputPathtxt = "I:\\calibration\\21-澳\\txt-right\\0_plate_pos-right.txt";
	string outputPathtxt = "I:\\calibration\\21-澳\\txt-right\\0_plate_pos-right1.txt";

	fstream finRead;
	finRead.open(inputPathtxt, ios::in);
	if (!finRead.is_open())
	{
		cout << "finRead1 文件数据打开错误！" << endl;
		system("pause");
		return false;
	}

	fstream finWrite;
	finWrite.open(outputPathtxt, ios::out);
	if (!finWrite.is_open())
	{
		cout << "finRead1 文件数据打开错误！" << endl;
		system("pause");
		return false;
	}

	
	string line;
	while (getline(finRead, line))
	{
		string str1;
		int x1, y1, x2, y2;
		stringstream str_s(line);
		str_s >>str1 >> x1>>y1>>x2>>y2;

		if (x1<x2)
		{
			finWrite << str1 << " " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
		}
		else
		{
			finWrite << str1 << " " << x1 << " " << y1 << " " << x1+x2 << " " << y1+y2 << endl;
		}
		
	}

	finRead.close();
	finWrite.close();



	return 0;
}