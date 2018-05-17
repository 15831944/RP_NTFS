#pragma once

// System capacity definitions
#define MAX_COMM_NUM		2//ͨ����
#define MAX_RTU_NUM         32//ÿ��ͨ�����ӵ����ڵ���
#define MAX_FILES_SUM       224//ÿ�����������洢������ļ���
#define MAX_ERRPACKS_SUM    2880//360 * 8
#define FILE_NAME_LEN       12//ÿ���ļ������ֳ��ȣ�ʵ����ֻ��12��bytes�����ö��ļ���8.3��ʽ
#define FILE_LENGTH_LEN     4//�ļ����Ƚṹ�ĳ���
//��������
#define TYPE_TASK_NONE        0//������
#define TYPE_TASK_QUERY       1//��ѯ״̬ 1...1
#define TYPE_TASK_SEND		  2//�����ļ�
#define TYPE_TASK_SEND_H      2//�����ļ�ͷ1...n
#define TYPE_TASK_SEND_P      3//�����ļ���1...n
#define TYPE_TASK_SEND_Q      4//��ѯ�ļ�����1...n
#define TYPE_TASK_DELETE      5//ɾ���ļ�1...1
#define TYPE_TASK_CLEAR       6//����ļ�1...n
#define TYPE_TASK_OPEN        7//���ļ�1...n
#define TYPE_TASK_CANCEL	  8//ȡ������
#define TYPE_TASK_TMP         20//��ʱ����
//�ļ���Ϣ
typedef struct
{
	BYTE  filename[FILE_NAME_LEN + 1];//�ļ�����8.3��ʽ
	BYTE  filelen[FILE_LENGTH_LEN];//�ļ�����, �ȵͺ��
}suFileList;
//������Ϣ
typedef struct 
{
	unsigned long lNo;//�������
	int iType;//��������
	CString strNote;//����ע
	int iSelFlag;//ѡ���־
}suTaskList;
//����ڵ���Ϣ�ṹ
typedef struct
{
	int  comminfo;//0: �ڵ�δ���ӣ�1���ļ�ͷ��2��У���3�����ӽڵ�ʧ�ܣ�4�����ͳɹ���
	              //5���ڵ��������㣻 6���ļ���Խ�� 7���г������8���������ݴ���
	              //9����ѯ�޻ظ���10������������11���ļ���ɾ����12���ļ�����գ� 13��ϵͳ��ֹ��
				  //14�����ڲ�ѯ��15�����²�ѯ��16������ɾ����17������ɾ����18��������գ�19��������գ�
				  //20�����ڷ��ļ�ͷ��21�����ڷ��ļ�����22���û�ȡ��������
	long total_room;//�ڵ�ʵ�����ռ�
	long unit_room;//�ڵ���С����
	long max_file_sum;//�ڵ�ʵ�ʿ����ɵ�����ļ���
	int  totalfiles;//���ļ�����
	int  filesnum;//��ǰ�ڵ���ļ�����
	long freememory;//�ڵ��ʣ��ռ�
	
	int iProgress;//�ڵ����
	int iTaskNum;//��������
	unsigned long lCurTask;//��ǰ����
	CList<suTaskList *, suTaskList *> TaskList;//�ڵ�������б���Ϣ
		
	suFileList fileList[MAX_FILES_SUM];//�ڵ���ļ��б���Ϣ
	int  iNodeFlag;//ͨ����־: 0 δ��ͨ��1 ��ͨ

	int  errorPackSum;//����
	int  errorPackflag[MAX_ERRPACKS_SUM];//����	 
	int  totalPack;//����

	bool bRefurbish;//�Ƿ�ˢ��
}suNetNode;

typedef struct
{
	suNetNode *pRTU;//�ڵ���Ϣ��ΪNULL��������
	int iTaskPos;//��������������е�λ��
}suNodeData;

typedef struct
{
	bool m_bNodeFlagArr[MAX_RTU_NUM];//վ��ѡ��0 δѡ��; 1ѡ�� 	
	CString m_strPath;//�ļ�ȫ·��	
}su_TaskInfo;

//����ṹ
class CTaskData
{
public:
	/*__declspec(dllimport) */CTaskData(){};	
	/*__declspec(dllimport) */virtual ~CTaskData(){};	

public:
	CList<su_TaskInfo *, su_TaskInfo *> m_TaskInfoList;//������Ϣ
	CList<ULONG, ULONG> m_lDelTaskList;//ɾ������
	bool m_bNodeFlagArr[MAX_RTU_NUM];//վ��ѡ��0 δѡ��; 1ѡ�� 	
	CString m_strSendFilePath;//�����ļ���·��
	BYTE m_byOpenFlagArr[4];//�ļ���־�����ظ����Ҳ�ȫΪ0��
	unsigned long m_lTaskNo;//�������	
//protected:
    int m_type;//��������

public:
    int GetType();//�õ���������
	void SetType(int type);//������������
	void Copy(CTaskData *pTask);
	void DelTaskInfo(CList<su_TaskInfo *, su_TaskInfo *> &in_TaskInfoList);	
};


////dll Import Functions
//
////��ʼ��ͨ��������ֵ��0 ����ͨ����ʧ�ܣ�1 ͨ��һ�ɹ���ͨ����ʧ�ܣ�2 ͨ��һʧ�ܣ�ͨ�����ɹ���3 ����ͨ���򿪳ɹ�
////ͨ����ͨ���ٶȱ�־:  0: 19200 bps ; 1: 38400 bps ;2: 57600 bps ;3: 115200 bps ;
//__declspec(dllimport) int InitializeFunc(CString []/*ͨ���Ĵ�������*/,int []/*ͨ��ʵ�ʽڵ����*/,int []/*ͨ����ͨ���ٶȱ�־*/, int []/*������ʽ*/); 
//                   
////�ͷ�ͨ��
//__declspec(dllimport) void UnInitializeFunc(void);
//
////��ͨ���Ľڵ�������ָ�룬ͨ������ 0 ͨ��һ��1 ͨ����
//__declspec(dllimport) suNetNode * GetNodeArrayHeadFunc(int/*ͨ������*/);
//
////��ͨ��������񣬷���ֵ��1 �������ɹ���0ʧ��
////��ѯ�ļ�
//__declspec(dllimport) int QueryFunc(int/*ͨ������*/,CTaskData * /*����*/);
////�����ļ�
//__declspec(dllimport) int SendFunc(int/*ͨ������*/,CTaskData * /*����*/);
////ɾ���ڵ��ļ�
//__declspec(dllimport) int DeleteFunc(int/*ͨ������*/,CTaskData * /*����*/);
////����ļ�
//__declspec(dllimport) int ClearFunc(int/*ͨ������*/,CTaskData * /*����*/);
////ȡ������
//__declspec(dllimport) int CancelFunc(int/*ͨ������*/,CTaskData * /*����*/);