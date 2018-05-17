//#include <Windows.h>
#include "stdafx.h"
#pragma once
#include  "TestPQ.h"


HMODULE comlibModule = LoadLibrary(_T("ComLib.dll"));

//初始化通道；返回值：0 两个通道打开失败；1 通道一成功，通道二失败，2 通道一失败，通道二成功；3 两个通道打开成功
//通道的通信速度标志:  0: 19200 bps ; 1: 38400 bps ;2: 57600 bps ;3: 115200 bps ;
int InitializeFunc(CString a[]/*通道的串口名称*/,int b[]/*通道实际节点个数*/,int c[]/*通道的通信速度标志*/, int d[]/*工作方式*/)
{
	typedef int (*fnInitializeFunc)(CString [],int [],int [], int []); 

	fnInitializeFunc pInitializeFunc = (fnInitializeFunc)GetProcAddress(comlibModule,"?InitializeFunc@@YAHQAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@QAH11@Z");

	int n = pInitializeFunc(a,b,c,d);
	
	return n;
}
                   
//释放通道
void UnInitializeFunc(void)
{
	typedef void (*fnUnInitializeFunc)(void); 

	fnUnInitializeFunc pUnInitializeFunc = (fnUnInitializeFunc)GetProcAddress(comlibModule,"?UnInitializeFunc@@YAXXZ");

	pUnInitializeFunc();
}

//获到通道的节点数组首指针，通道参数 0 通道一；1 通道二
suNetNode * GetNodeArrayHeadFunc(int/*通道参数*/a)
{
	typedef suNetNode * (*fnGetNodeArrayHeadFunc)(int); 

	fnGetNodeArrayHeadFunc pGetNodeArrayHeadFunc = (fnGetNodeArrayHeadFunc)GetProcAddress(comlibModule,"?GetNodeArrayHeadFunc@@YAPAUsuNetNode@@H@Z");

	suNetNode * n = pGetNodeArrayHeadFunc(a);

	
	return n;
}

//向通道添加任务，返回值：1 添加任务成功；0失败
//查询文件
int QueryFunc(int/*通道参数*/a,CTaskData * /*任务*/b)
{
	typedef int (*fnQueryFunc)(int ,CTaskData *); 

	fnQueryFunc pQueryFunc = (fnQueryFunc)GetProcAddress(comlibModule,"?QueryFunc@@YAHHPAVCTaskData@@@Z");

	int n = pQueryFunc(a,b);
	
	return n;
}

//发送文件
int SendFunc(int/*通道参数*/a,CTaskData * /*任务*/b)
{
	typedef int (*fnSendFunc)(int,CTaskData *); 

	fnSendFunc pSendFunc = (fnSendFunc)GetProcAddress(comlibModule,"?SendFunc@@YAHHPAVCTaskData@@@Z");
	int  n = pSendFunc(a,b);
	return n;
}

//删除节点文件
int DeleteFunc(int/*通道参数*/ a,CTaskData * /*任务*/b)
{
	typedef int (*fnDeleteFunc)(int,CTaskData *); 

	fnDeleteFunc pSendFunc = (fnDeleteFunc)GetProcAddress(comlibModule,"?DeleteFunc@@YAHHPAVCTaskData@@@Z");

	int  n = pSendFunc(a,b);

	return n;
}

//清空文件
int ClearFunc(int/*通道参数*/ a,CTaskData * /*任务*/b)
{
	typedef int (*fnClearFunc)(int,CTaskData *); 

	fnClearFunc pClearFunc = (fnClearFunc)GetProcAddress(comlibModule,"?ClearFunc@@YAHHPAVCTaskData@@@Z");

	int  n = pClearFunc(a,b);

	return n;
}

//取消任务
int CancelFunc(int/*通道参数*/ a,CTaskData * /*任务*/b)
{
	typedef int (*fnCancelFunc)(int,CTaskData *); 

	fnCancelFunc pCancelFunc = (fnCancelFunc)GetProcAddress(comlibModule,"?CancelFunc@@YAHHPAVCTaskData@@@Z");

	int  n = pCancelFunc(a,b);

	return n;
}

//***************************************************导出**********************************************************
//DLL导出函数
//返回值0 ：初始化串口失败或者获取首节点失败 ,返回值1：发送文件成功
//int main(int argc, TCHAR* argv[])
int TestFuction(char* m_strPath)
{	
	//char *m_strPath = "D:\\Program Files (x86)\\武汉益模\\EACT\\EDM\\10000092\\16534-BI001\\12-F1.nc";//要发送的文件（测试用）
	
	CChannelInfo ChannelInfo;
	ChannelInfo.m_strChannelNameArray[0] = _T("COM3");
	ChannelInfo.m_iNodeNumArray[0] = 1;
	ChannelInfo.m_iSpeedArray[0] = 3;
	ChannelInfo.m_iModeArray[0] = 4;
	
	int m_iInitCom;

	//初始化串口
	m_iInitCom = InitializeFunc(&ChannelInfo.m_strChannelNameArray[0], &ChannelInfo.m_iNodeNumArray[0], &ChannelInfo.m_iSpeedArray[0], &ChannelInfo.m_iModeArray[0]);

	if(m_iInitCom==0)
	{
		 printf("两个都通道打开失败\n");
		 return 0;
	}
	else if(m_iInitCom==1)
	{ 
		 printf("通道一成功，通道二失败\n");
	}
	else if (m_iInitCom==2)
	{ 
		 printf("通道一失败，通道二成功\n");
	}
	else if (m_iInitCom==3)
	{
		printf("两个通道打开成功\n");
	}

	su_TaskInfo *pTaskInfo;
	pTaskInfo = new su_TaskInfo;
	CTaskData *pTask;
    pTask = new CTaskData;
    pTask->m_bNodeFlagArr[0] = 1;//选择节点
	//pTaskInfo->m_strPath = "D:\\Program Files (x86)\\武汉益模\\EACT\\EDM\\10000092\\16534-BI001\\12-F1.nc";//要发送的文件
	//char *m_strPath = "D:\\Test\\1-2-3-4-5.nc";//要发送的文件
	pTaskInfo->m_strPath = m_strPath;
	pTask->m_TaskInfoList.AddTail(pTaskInfo);
	pTask->m_type =0;


	int errCode = 0;
	int count=0;
	int a = SendFunc(0,pTask);  //发送文件
	errCode = GetLastError();
	printf("发送文件:%d 错误代码:%d\n",a,errCode);
	suNetNode *NodeInfo= GetNodeArrayHeadFunc(0);	//获取首节点的类型
	if(!NodeInfo)
	{
	  printf("获取首节点失败\n");
	  return 0;
	}
	while(a == 1 && NodeInfo->comminfo != 4)
	{
	   Sleep(100);
	   count++;
	   printf("第%d次\n",count);
	}
	printf("发送成功\n");
	printf("一共循环了%d次\n",count);
	//printf("**********************************传送成功个文件*************************************");
	//UnInitializeFunc();	//释放通道
	FreeLibrary(comlibModule);//释放加载的DLL
	return 1;
}

int TestDeleteFunction(int Num, char* fileName)
{
	su_TaskInfo *pTaskInfo;
	pTaskInfo = new su_TaskInfo;
	CTaskData *pTask;
	pTask = new CTaskData;

	pTask->m_bNodeFlagArr[Num] = 1;//选择通道

	pTaskInfo->m_strPath = fileName;
	pTask->m_TaskInfoList.AddTail(pTaskInfo);
	pTask->m_type = TYPE_TASK_DELETE;

	printf("删除节点文件:%s\n",fileName);

	int errCode = 0;
	int count = 0;
	int a = DeleteFunc(0, pTask);  //查询文件
	errCode = GetLastError();
	printf("删除节点文件:%d 错误代码:%d\n", a, errCode);
	suNetNode *NodeInfo = GetNodeArrayHeadFunc(0);	//获取首节点的类型
	if (!NodeInfo)
	{
		printf("获取首节点失败\n");
		return 0;
	}

	suNetNode * item = NodeInfo + Num;
	if (!item)
	{
		printf("获取次节点失败\n");
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
			printf("删除节点文件超时\n");
			return 2;
		}
		printf("第%d次\n", count);
	}
	printf("删除节点文件成功\n");
	printf("一共循环了%d次\n", count);

	return 1;
}

//查询
char* TestQueryFunction(int Num)
{
	char* result = "2";
	CTaskData *pTask;
	pTask = new CTaskData;

	pTask->m_bNodeFlagArr[Num] = 1;//选择节点

	int errCode = 0;
	int count = 0;
	int a = QueryFunc(0, pTask);  //查询文件
	errCode = GetLastError();
	printf("查询文件:%d 错误代码:%d\n", a, errCode);
	suNetNode *NodeInfo = GetNodeArrayHeadFunc(0);	//获取首节点的类型
	if (!NodeInfo)
	{
		printf("获取首节点失败\n");
		return result;
	}

	suNetNode * item = NodeInfo + Num;
	if (!item)
	{
		printf("获取次节点失败\n");
		return result;
	}

	while (a == 1 && item->comminfo != 10)
	{
		printf("item comminfo:%d\n", item->comminfo);
		Sleep(100);
		count++;
		if (count == 600)
		{
			printf("查询文件超时\n");
			return result;
		}
		printf("第%d次\n", count);
	}
	printf("查询成功\n");
	printf("item comminfo:%d\n", item->filesnum);
	CString str = "";
	for (int i = 0; i < item->filesnum; i++)
	{
		char* temp= (char*)item->fileList[i].filename;
		str.AppendFormat("%s", temp);
	}

	result = (char*)str.GetBuffer(str.GetLength());
	printf("%s\n", result);
	

	printf("一共循环了%d次\n", count);

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

	//初始化串口
	m_iInitCom = InitializeFunc(&ChannelInfo.m_strChannelNameArray[0], &ChannelInfo.m_iNodeNumArray[0], &ChannelInfo.m_iSpeedArray[0], &ChannelInfo.m_iModeArray[0]);

	if(m_iInitCom==0)
	{
		 printf("两个都通道打开失败\n");
		 return 0;
	}
	else if(m_iInitCom==1)
	{ 
		 printf("通道一成功，通道二失败\n");
		 return 1;
	}
	else if (m_iInitCom==2)
	{ 
		 printf("通道一失败，通道二成功\n");
		 return 2;
	}
	else if (m_iInitCom==3)
	{
		printf("两个通道打开成功\n");
		return 3;
	}
}

int TestUnInitializeFuction()
{
	UnInitializeFunc();	//释放通道
	//if(comlibModule)
	//    FreeLibrary(comlibModule);//释放加载的DLL
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

	pTask->m_bNodeFlagArr[Num] = 1;//选择通道

	pTaskInfo->m_strPath = m_strPath;
	pTask->m_TaskInfoList.AddTail(pTaskInfo);
	pTask->m_type =0;

	int errCode = 0;
	int count=0;
	int a = SendFunc(0,pTask);  //发送文件
	errCode = GetLastError();
	printf("发送文件:%d 错误代码:%d\n",a,errCode);
	suNetNode *NodeInfo= GetNodeArrayHeadFunc(0);	//获取首节点的类型
	if(!NodeInfo)
	{
	  printf("获取首节点失败\n");
	  return 0;
	}

	suNetNode * item = NodeInfo + Num;
	if (!item)
	{
		printf("获取次节点失败\n");
		return 0;
	}

	while(a == 1 && item->comminfo != 4)
	{
		printf("item comminfo:%d\n", item->comminfo);
	   Sleep(100);
	   count++;
	   if(count == 600)
	   {
	     printf("上传文件超时\n");
		 return 2;
	   }
	   printf("第%d次\n",count);
	}
	printf("发送成功\n");
	printf("一共循环了%d次\n",count);

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

	pTask->m_bNodeFlagArr[Num] = 1;//选择节点

	int errCode = 0;
	int count=0;
	int a = ClearFunc(0,pTask);  //清空文件
	errCode = GetLastError();
	printf("清空文件:%d 错误代码:%d\n",a,errCode);
	suNetNode *NodeInfo= GetNodeArrayHeadFunc(0);	//获取首节点的类型
	if(!NodeInfo)
	{
	  printf("获取首节点失败\n");
	  return 0;
	}

	suNetNode * item = NodeInfo + Num;
	if (!item)
	{
		printf("获取次节点失败\n");
		return 0;
	}

	while(a == 1 && item->comminfo != 12)
	{
		printf("item comminfo:%d\n", item->comminfo);
		Sleep(100);
		count++;
	   	if(count == 600)
	   {
	     printf("清空文件超时\n");
		 return 2;
	   }
	   printf("第%d次\n",count);
	}
	printf("清空成功\n");
	printf("一共循环了%d次\n",count);

	return 1;

}

void main()
{
	int  a = TestInitializeFuction("COM3",1,3,4);
	int  b = TestSendFuction("D:\\Test\\1-2-3-4-5.nc",1);
	if(b==1)
	{
	  printf("上传成功\n",1);
	}
	else if (b==2)
	{
	  printf("上传超时\n",1);
	}

	system("pause");
}