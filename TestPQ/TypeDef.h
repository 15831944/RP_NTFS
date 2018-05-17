#pragma once

// System capacity definitions
#define MAX_COMM_NUM		2//通道数
#define MAX_RTU_NUM         32//每个通道链接的最大节点数
#define MAX_FILES_SUM       224//每个仿真软驱存储的最大文件数
#define MAX_ERRPACKS_SUM    2880//360 * 8
#define FILE_NAME_LEN       12//每个文件的名字长度，实际上只用12个bytes，采用短文件名8.3格式
#define FILE_LENGTH_LEN     4//文件长度结构的长度
//任务类型
#define TYPE_TASK_NONE        0//无任务
#define TYPE_TASK_QUERY       1//查询状态 1...1
#define TYPE_TASK_SEND		  2//发送文件
#define TYPE_TASK_SEND_H      2//发送文件头1...n
#define TYPE_TASK_SEND_P      3//发送文件包1...n
#define TYPE_TASK_SEND_Q      4//查询文件发送1...n
#define TYPE_TASK_DELETE      5//删除文件1...1
#define TYPE_TASK_CLEAR       6//清空文件1...n
#define TYPE_TASK_OPEN        7//打开文件1...n
#define TYPE_TASK_CANCEL	  8//取消任务
#define TYPE_TASK_TMP         20//临时锁定
//文件信息
typedef struct
{
	BYTE  filename[FILE_NAME_LEN + 1];//文件名，8.3格式
	BYTE  filelen[FILE_LENGTH_LEN];//文件长度, 先低后高
}suFileList;
//任务信息
typedef struct 
{
	unsigned long lNo;//任务序号
	int iType;//任务类型
	CString strNote;//任务备注
	int iSelFlag;//选择标志
}suTaskList;
//网络节点信息结构
typedef struct
{
	int  comminfo;//0: 节点未连接；1：文件头错；2、校验错；3、连接节点失败；4、发送成功；
	              //5、节点容量不足； 6、文件数越限 7、有出错包；8、接收数据错误；
	              //9、查询无回复；10、连接正常；11、文件已删除；12、文件已清空； 13、系统终止；
				  //14、正在查询；15、重新查询；16、正在删除；17、重新删除；18、正在清空；19、重新清空；
				  //20、正在发文件头；21、正在发文件包；22、用户取消了任务
	long total_room;//节点实际最大空间
	long unit_room;//节点最小分配
	long max_file_sum;//节点实际可容纳的最大文件数
	int  totalfiles;//总文件个数
	int  filesnum;//当前节点的文件个数
	long freememory;//节点的剩余空间
	
	int iProgress;//节点进度
	int iTaskNum;//总任务数
	unsigned long lCurTask;//当前任务
	CList<suTaskList *, suTaskList *> TaskList;//节点的任务列表信息
		
	suFileList fileList[MAX_FILES_SUM];//节点的文件列表信息
	int  iNodeFlag;//通道标志: 0 未连通；1 连通

	int  errorPackSum;//保留
	int  errorPackflag[MAX_ERRPACKS_SUM];//保留	 
	int  totalPack;//保留

	bool bRefurbish;//是否刷新
}suNetNode;

typedef struct
{
	suNetNode *pRTU;//节点信息，为NULL则无意义
	int iTaskPos;//任务在任务队列中的位置
}suNodeData;

typedef struct
{
	bool m_bNodeFlagArr[MAX_RTU_NUM];//站点选择：0 未选择; 1选择 	
	CString m_strPath;//文件全路径	
}su_TaskInfo;

//任务结构
class CTaskData
{
public:
	/*__declspec(dllimport) */CTaskData(){};	
	/*__declspec(dllimport) */virtual ~CTaskData(){};	

public:
	CList<su_TaskInfo *, su_TaskInfo *> m_TaskInfoList;//任务信息
	CList<ULONG, ULONG> m_lDelTaskList;//删除任务
	bool m_bNodeFlagArr[MAX_RTU_NUM];//站点选择：0 未选择; 1选择 	
	CString m_strSendFilePath;//发送文件的路径
	BYTE m_byOpenFlagArr[4];//文件标志，不重复，且不全为0；
	unsigned long m_lTaskNo;//任务序号	
//protected:
    int m_type;//任务类型

public:
    int GetType();//得到任务类型
	void SetType(int type);//设置任务类型
	void Copy(CTaskData *pTask);
	void DelTaskInfo(CList<su_TaskInfo *, su_TaskInfo *> &in_TaskInfoList);	
};


////dll Import Functions
//
////初始化通道；返回值：0 两个通道打开失败；1 通道一成功，通道二失败，2 通道一失败，通道二成功；3 两个通道打开成功
////通道的通信速度标志:  0: 19200 bps ; 1: 38400 bps ;2: 57600 bps ;3: 115200 bps ;
//__declspec(dllimport) int InitializeFunc(CString []/*通道的串口名称*/,int []/*通道实际节点个数*/,int []/*通道的通信速度标志*/, int []/*工作方式*/); 
//                   
////释放通道
//__declspec(dllimport) void UnInitializeFunc(void);
//
////获到通道的节点数组首指针，通道参数 0 通道一；1 通道二
//__declspec(dllimport) suNetNode * GetNodeArrayHeadFunc(int/*通道参数*/);
//
////向通道添加任务，返回值：1 添加任务成功；0失败
////查询文件
//__declspec(dllimport) int QueryFunc(int/*通道参数*/,CTaskData * /*任务*/);
////发送文件
//__declspec(dllimport) int SendFunc(int/*通道参数*/,CTaskData * /*任务*/);
////删除节点文件
//__declspec(dllimport) int DeleteFunc(int/*通道参数*/,CTaskData * /*任务*/);
////清空文件
//__declspec(dllimport) int ClearFunc(int/*通道参数*/,CTaskData * /*任务*/);
////取消任务
//__declspec(dllimport) int CancelFunc(int/*通道参数*/,CTaskData * /*任务*/);