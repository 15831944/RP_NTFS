//#include <Windows.h>
#include "stdafx.h"
#include "TypeDef.h"
#include "Process.h"
#include <iostream>
#include <sstream>
using namespace std;

extern "C" __declspec( dllexport )  int TestFuction(char* m_strPath);//整个测试


//extern "C" __declspec( dllexport )  int TestInitializeFuction(char* m_way);//初始化通道
//
//extern "C" __declspec( dllexport )  int TestUnInitializeFuction();//释放通道
//
//extern "C" __declspec( dllexport )  int TestSendFuction(char* m_strPath); //发送文件
//
//extern "C" __declspec( dllexport )  int TestClearFuction(); //清空文件



extern "C" __declspec( dllexport )  int TestInitializeFuction(char* m_way,int NodeNum,int Speed,int Mode);//初始化通道

extern "C" __declspec( dllexport )  int TestUnInitializeFuction();//释放通道

extern "C" __declspec( dllexport )  int TestSendFuction(char* m_strPath,int Num); //发送文件

extern "C" __declspec( dllexport )  int TestClearFuction(int Num); //清空文件

extern "C" __declspec(dllexport)  char* TestQueryFunction(int Num);//查询文件
extern "C" __declspec(dllexport) int TestDeleteFunction(int Num,char* fileName);//删除节点文件

