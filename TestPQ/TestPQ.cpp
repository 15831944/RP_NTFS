//#include <Windows.h>
#include "stdafx.h"
#pragma once
#include  "TestPQ.h"


HMODULE comlibModule = LoadLibrary(_T("ComLib.dll"));

//��ʼ��ͨ��������ֵ��0 ����ͨ����ʧ�ܣ�1 ͨ��һ�ɹ���ͨ����ʧ�ܣ�2 ͨ��һʧ�ܣ�ͨ�����ɹ���3 ����ͨ���򿪳ɹ�
//ͨ����ͨ���ٶȱ�־:  0: 19200 bps ; 1: 38400 bps ;2: 57600 bps ;3: 115200 bps ;
int InitializeFunc(CString a[]/*ͨ���Ĵ�������*/,int b[]/*ͨ��ʵ�ʽڵ����*/,int c[]/*ͨ����ͨ���ٶȱ�־*/, int d[]/*������ʽ*/)
{
	typedef int (*fnInitializeFunc)(CString [],int [],int [], int []); 

	fnInitializeFunc pInitializeFunc = (fnInitializeFunc)GetProcAddress(comlibModule,"?InitializeFunc@@YAHQAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@QAH11@Z");

	int n = pInitializeFunc(a,b,c,d);
	
	return n;
}
                   
//�ͷ�ͨ��
void UnInitializeFunc(void)
{
	typedef void (*fnUnInitializeFunc)(void); 

	fnUnInitializeFunc pUnInitializeFunc = (fnUnInitializeFunc)GetProcAddress(comlibModule,"?UnInitializeFunc@@YAXXZ");

	pUnInitializeFunc();
}

//��ͨ���Ľڵ�������ָ�룬ͨ������ 0 ͨ��һ��1 ͨ����
suNetNode * GetNodeArrayHeadFunc(int/*ͨ������*/a)
{
	typedef suNetNode * (*fnGetNodeArrayHeadFunc)(int); 

	fnGetNodeArrayHeadFunc pGetNodeArrayHeadFunc = (fnGetNodeArrayHeadFunc)GetProcAddress(comlibModule,"?GetNodeArrayHeadFunc@@YAPAUsuNetNode@@H@Z");

	suNetNode * n = pGetNodeArrayHeadFunc(a);

	
	return n;
}

//��ͨ��������񣬷���ֵ��1 �������ɹ���0ʧ��
//��ѯ�ļ�
int QueryFunc(int/*ͨ������*/a,CTaskData * /*����*/b)
{
	typedef int (*fnQueryFunc)(int ,CTaskData *); 

	fnQueryFunc pQueryFunc = (fnQueryFunc)GetProcAddress(comlibModule,"?QueryFunc@@YAHHPAVCTaskData@@@Z");

	int n = pQueryFunc(a,b);
	
	return n;
}

//�����ļ�
int SendFunc(int/*ͨ������*/a,CTaskData * /*����*/b)
{
	typedef int (*fnSendFunc)(int,CTaskData *); 

	fnSendFunc pSendFunc = (fnSendFunc)GetProcAddress(comlibModule,"?SendFunc@@YAHHPAVCTaskData@@@Z");
	int  n = pSendFunc(a,b);
	return n;
}

//ɾ���ڵ��ļ�
int DeleteFunc(int/*ͨ������*/ a,CTaskData * /*����*/b)
{
	typedef int (*fnDeleteFunc)(int,CTaskData *); 

	fnDeleteFunc pSendFunc = (fnDeleteFunc)GetProcAddress(comlibModule,"?DeleteFunc@@YAHHPAVCTaskData@@@Z");

	int  n = pSendFunc(a,b);

	return n;
}

//����ļ�
int ClearFunc(int/*ͨ������*/ a,CTaskData * /*����*/b)
{
	typedef int (*fnClearFunc)(int,CTaskData *); 

	fnClearFunc pClearFunc = (fnClearFunc)GetProcAddress(comlibModule,"?ClearFunc@@YAHHPAVCTaskData@@@Z");

	int  n = pClearFunc(a,b);

	return n;
}

//ȡ������
int CancelFunc(int/*ͨ������*/ a,CTaskData * /*����*/b)
{
	typedef int (*fnCancelFunc)(int,CTaskData *); 

	fnCancelFunc pCancelFunc = (fnCancelFunc)GetProcAddress(comlibModule,"?CancelFunc@@YAHHPAVCTaskData@@@Z");

	int  n = pCancelFunc(a,b);

	return n;
}

//***************************************************����**********************************************************
//DLL��������
//����ֵ0 ����ʼ������ʧ�ܻ��߻�ȡ�׽ڵ�ʧ�� ,����ֵ1�������ļ��ɹ�
//int main(int argc, TCHAR* argv[])
int TestFuction(char* m_strPath)
{	
	//char *m_strPath = "D:\\Program Files (x86)\\�人��ģ\\EACT\\EDM\\10000092\\16534-BI001\\12-F1.nc";//Ҫ���͵��ļ��������ã�
	
	CChannelInfo ChannelInfo;
	ChannelInfo.m_strChannelNameArray[0] = _T("COM3");
	ChannelInfo.m_iNodeNumArray[0] = 1;
	ChannelInfo.m_iSpeedArray[0] = 3;
	ChannelInfo.m_iModeArray[0] = 4;
	
	int m_iInitCom;

	//��ʼ������
	m_iInitCom = InitializeFunc(&ChannelInfo.m_strChannelNameArray[0], &ChannelInfo.m_iNodeNumArray[0], &ChannelInfo.m_iSpeedArray[0], &ChannelInfo.m_iModeArray[0]);

	if(m_iInitCom==0)
	{
		 printf("������ͨ����ʧ��\n");
		 return 0;
	}
	else if(m_iInitCom==1)
	{ 
		 printf("ͨ��һ�ɹ���ͨ����ʧ��\n");
	}
	else if (m_iInitCom==2)
	{ 
		 printf("ͨ��һʧ�ܣ�ͨ�����ɹ�\n");
	}
	else if (m_iInitCom==3)
	{
		printf("����ͨ���򿪳ɹ�\n");
	}

	su_TaskInfo *pTaskInfo;
	pTaskInfo = new su_TaskInfo;
	CTaskData *pTask;
    pTask = new CTaskData;
    pTask->m_bNodeFlagArr[0] = 1;//ѡ��ڵ�
	//pTaskInfo->m_strPath = "D:\\Program Files (x86)\\�人��ģ\\EACT\\EDM\\10000092\\16534-BI001\\12-F1.nc";//Ҫ���͵��ļ�
	//char *m_strPath = "D:\\Test\\1-2-3-4-5.nc";//Ҫ���͵��ļ�
	pTaskInfo->m_strPath = m_strPath;
	pTask->m_TaskInfoList.AddTail(pTaskInfo);
	pTask->m_type =0;


	int errCode = 0;
	int count=0;
	int a = SendFunc(0,pTask);  //�����ļ�
	errCode = GetLastError();
	printf("�����ļ�:%d �������:%d\n",a,errCode);
	suNetNode *NodeInfo= GetNodeArrayHeadFunc(0);	//��ȡ�׽ڵ������
	if(!NodeInfo)
	{
	  printf("��ȡ�׽ڵ�ʧ��\n");
	  return 0;
	}
	while(a == 1 && NodeInfo->comminfo != 4)
	{
	   Sleep(100);
	   count++;
	   printf("��%d��\n",count);
	}
	printf("���ͳɹ�\n");
	printf("һ��ѭ����%d��\n",count);
	//printf("**********************************���ͳɹ����ļ�*************************************");
	//UnInitializeFunc();	//�ͷ�ͨ��
	FreeLibrary(comlibModule);//�ͷż��ص�DLL
	return 1;
}

int TestDeleteFunction(int Num, char* fileName)
{
	su_TaskInfo *pTaskInfo;
	pTaskInfo = new su_TaskInfo;
	CTaskData *pTask;
	pTask = new CTaskData;

	pTask->m_bNodeFlagArr[Num] = 1;//ѡ��ͨ��

	pTaskInfo->m_strPath = fileName;
	pTask->m_TaskInfoList.AddTail(pTaskInfo);
	pTask->m_type = TYPE_TASK_DELETE;

	printf("ɾ���ڵ��ļ�:%s\n",fileName);

	int errCode = 0;
	int count = 0;
	int a = DeleteFunc(0, pTask);  //��ѯ�ļ�
	errCode = GetLastError();
	printf("ɾ���ڵ��ļ�:%d �������:%d\n", a, errCode);
	suNetNode *NodeInfo = GetNodeArrayHeadFunc(0);	//��ȡ�׽ڵ������
	if (!NodeInfo)
	{
		printf("��ȡ�׽ڵ�ʧ��\n");
		return 0;
	}

	suNetNode * item = NodeInfo + Num;
	if (!item)
	{
		printf("��ȡ�νڵ�ʧ��\n");
		return 0;
	}

	while (a == 1 && item->comminfo != 11)
	{
		printf("item comminfo:%d\n", item->comminfo);
		printf("item comminfo:%d\n", item->filesnum);
		Sleep(100);
		count++;
		if (count == 600)
		{
			printf("ɾ���ڵ��ļ���ʱ\n");
			return 2;
		}
		printf("��%d��\n", count);
	}
	printf("ɾ���ڵ��ļ��ɹ�\n");
	printf("һ��ѭ����%d��\n", count);

	return 1;
}

//��ѯ
char* TestQueryFunction(int Num)
{
	char* result = "2";
	CTaskData *pTask;
	pTask = new CTaskData;

	pTask->m_bNodeFlagArr[Num] = 1;//ѡ��ڵ�

	int errCode = 0;
	int count = 0;
	int a = QueryFunc(0, pTask);  //��ѯ�ļ�
	errCode = GetLastError();
	printf("��ѯ�ļ�:%d �������:%d\n", a, errCode);
	suNetNode *NodeInfo = GetNodeArrayHeadFunc(0);	//��ȡ�׽ڵ������
	if (!NodeInfo)
	{
		printf("��ȡ�׽ڵ�ʧ��\n");
		return result;
	}

	suNetNode * item = NodeInfo + Num;
	if (!item)
	{
		printf("��ȡ�νڵ�ʧ��\n");
		return result;
	}

	while (a == 1 && item->comminfo != 10)
	{
		printf("item comminfo:%d\n", item->comminfo);
		Sleep(100);
		count++;
		if (count == 600)
		{
			printf("��ѯ�ļ���ʱ\n");
			return result;
		}
		printf("��%d��\n", count);
	}
	printf("��ѯ�ɹ�\n");
	printf("item comminfo:%d\n", item->filesnum);
	CString str = "";
	for (int i = 0; i < item->filesnum; i++)
	{
		char* temp= (char*)item->fileList[i].filename;
		str.AppendFormat("%s", temp);
	}

	result = (char*)str.GetBuffer(str.GetLength());
	printf("%s\n", result);
	

	printf("һ��ѭ����%d��\n", count);

	return result;
}

//int main(int argc, TCHAR* argv[])
int TestInitializeFuction(char* m_way,int NodeNum,int Speed,int Mode)
{
	//char * m_way="COM3";int NodeNum = 1;int Speed = 3;int Mode = 4 ;
	//int NodeNum1;
	//istringstream iss(NodeNum);   
	//iss >> NodeNum1;
	//int Speed1;
	//istringstream iss(Speed);   
	//iss >> Speed1;
	//int Mode1;
	//istringstream iss(Mode);   
	//iss >> Mode1;

	CChannelInfo ChannelInfo;
	ChannelInfo.m_strChannelNameArray[0] = _T(m_way);
	ChannelInfo.m_iNodeNumArray[0] = NodeNum;
	ChannelInfo.m_iSpeedArray[0] = Speed;
	ChannelInfo.m_iModeArray[0] = Mode;
	
	int m_iInitCom;

	//��ʼ������
	m_iInitCom = InitializeFunc(&ChannelInfo.m_strChannelNameArray[0], &ChannelInfo.m_iNodeNumArray[0], &ChannelInfo.m_iSpeedArray[0], &ChannelInfo.m_iModeArray[0]);

	if(m_iInitCom==0)
	{
		 printf("������ͨ����ʧ��\n");
		 return 0;
	}
	else if(m_iInitCom==1)
	{ 
		 printf("ͨ��һ�ɹ���ͨ����ʧ��\n");
		 return 1;
	}
	else if (m_iInitCom==2)
	{ 
		 printf("ͨ��һʧ�ܣ�ͨ�����ɹ�\n");
		 return 2;
	}
	else if (m_iInitCom==3)
	{
		printf("����ͨ���򿪳ɹ�\n");
		return 3;
	}
}

int TestUnInitializeFuction()
{
	UnInitializeFunc();	//�ͷ�ͨ��
	//if(comlibModule)
	//    FreeLibrary(comlibModule);//�ͷż��ص�DLL
	return 1;
}

int TestSendFuction(char* m_strPath,int Num)
{
	// Num = 1;
	//int NodeNum1;
	//istringstream iss(Num);   
	//iss >> NodeNum1;

	su_TaskInfo *pTaskInfo;
	pTaskInfo = new su_TaskInfo;
	CTaskData *pTask;
    pTask = new CTaskData;

	pTask->m_bNodeFlagArr[Num] = 1;//ѡ��ͨ��

	pTaskInfo->m_strPath = m_strPath;
	pTask->m_TaskInfoList.AddTail(pTaskInfo);
	pTask->m_type =0;

	int errCode = 0;
	int count=0;
	int a = SendFunc(0,pTask);  //�����ļ�
	errCode = GetLastError();
	printf("�����ļ�:%d �������:%d\n",a,errCode);
	suNetNode *NodeInfo= GetNodeArrayHeadFunc(0);	//��ȡ�׽ڵ������
	if(!NodeInfo)
	{
	  printf("��ȡ�׽ڵ�ʧ��\n");
	  return 0;
	}

	suNetNode * item = NodeInfo + Num;
	if (!item)
	{
		printf("��ȡ�νڵ�ʧ��\n");
		return 0;
	}

	while(a == 1 && item->comminfo != 4)
	{
		printf("item comminfo:%d\n", item->comminfo);
	   Sleep(100);
	   count++;
	   if(count == 600)
	   {
	     printf("�ϴ��ļ���ʱ\n");
		 return 2;
	   }
	   printf("��%d��\n",count);
	}
	printf("���ͳɹ�\n");
	printf("һ��ѭ����%d��\n",count);

	return 1;
}

//int main(int argc, TCHAR* argv[])
int TestClearFuction(int Num)
{
	// Num = 1;
	//int NodeNum1;
	//istringstream iss(Num);   
	//iss >> NodeNum1;

	CTaskData *pTask;
    pTask = new CTaskData;

	pTask->m_bNodeFlagArr[Num] = 1;//ѡ��ڵ�

	int errCode = 0;
	int count=0;
	int a = ClearFunc(0,pTask);  //����ļ�
	errCode = GetLastError();
	printf("����ļ�:%d �������:%d\n",a,errCode);
	suNetNode *NodeInfo= GetNodeArrayHeadFunc(0);	//��ȡ�׽ڵ������
	if(!NodeInfo)
	{
	  printf("��ȡ�׽ڵ�ʧ��\n");
	  return 0;
	}

	suNetNode * item = NodeInfo + Num;
	if (!item)
	{
		printf("��ȡ�νڵ�ʧ��\n");
		return 0;
	}

	while(a == 1 && item->comminfo != 12)
	{
		printf("item comminfo:%d\n", item->comminfo);
		Sleep(100);
		count++;
	   	if(count == 600)
	   {
	     printf("����ļ���ʱ\n");
		 return 2;
	   }
	   printf("��%d��\n",count);
	}
	printf("��ճɹ�\n");
	printf("һ��ѭ����%d��\n",count);

	return 1;

}

void main()
{
	int  a = TestInitializeFuction("COM3",1,3,4);
	int  b = TestSendFuction("D:\\Test\\1-2-3-4-5.nc",1);
	if(b==1)
	{
	  printf("�ϴ��ɹ�\n",1);
	}
	else if (b==2)
	{
	  printf("�ϴ���ʱ\n",1);
	}

	system("pause");
}