//#include <Windows.h>
#include "stdafx.h"
#include "TypeDef.h"
#include "Process.h"
#include <iostream>
#include <sstream>
using namespace std;

extern "C" __declspec( dllexport )  int TestFuction(char* m_strPath);//��������


//extern "C" __declspec( dllexport )  int TestInitializeFuction(char* m_way);//��ʼ��ͨ��
//
//extern "C" __declspec( dllexport )  int TestUnInitializeFuction();//�ͷ�ͨ��
//
//extern "C" __declspec( dllexport )  int TestSendFuction(char* m_strPath); //�����ļ�
//
//extern "C" __declspec( dllexport )  int TestClearFuction(); //����ļ�



extern "C" __declspec( dllexport )  int TestInitializeFuction(char* m_way,int NodeNum,int Speed,int Mode);//��ʼ��ͨ��

extern "C" __declspec( dllexport )  int TestUnInitializeFuction();//�ͷ�ͨ��

extern "C" __declspec( dllexport )  int TestSendFuction(char* m_strPath,int Num); //�����ļ�

extern "C" __declspec( dllexport )  int TestClearFuction(int Num); //����ļ�

extern "C" __declspec(dllexport)  char* TestQueryFunction(int Num);//��ѯ�ļ�
extern "C" __declspec(dllexport) int TestDeleteFunction(int Num,char* fileName);//ɾ���ڵ��ļ�

