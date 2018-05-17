#ifndef  _H_PROCESS_
#define  _H_PROCESS_

////////////////////
///Process.h
////////////////////
class CUser
{
public:
   CString    m_strUserName;
   BYTE       m_byUserRightArray[2];
   BYTE       m_byNewRightArray[2];
   bool       m_bAdministrator;
   bool       m_bPermit;
   CString    m_strUName;
   int        m_iUFlag;
   CString    m_strSysNotePath;
   int        m_iUserIndex;
};

class CChannelInfo
{
public:
	CString m_strChannelNameArray[MAX_COMM_NUM];
	int m_iNodeNumArray[MAX_COMM_NUM];
	int m_iNodeOneArray[MAX_COMM_NUM];
	int m_iSpeedArray[MAX_COMM_NUM];
	int m_iModeArray[MAX_COMM_NUM];
	CString m_strMacNameArray[MAX_COMM_NUM][MAX_RTU_NUM];
	CString m_strMacTypeArray[MAX_COMM_NUM][MAX_RTU_NUM];
	int m_iMacVisibleArray[MAX_COMM_NUM][MAX_RTU_NUM];
};

class CSelFile
{
public:
	CString m_strFileName;//文件名
	DWORD m_dwFileLength;//文件长度
	CString m_strFilePath;//文件路径
};

class CNodeInfo 
{
public:
	CNodeInfo()
	{
		m_iSeleteNode = 0;
		m_iImage = 0;
		m_iStationID = -1;//站号
		m_iTaskNum = 0;//任务数
		m_iCurrTask = 0;//当前任务
	    m_iTaskRate = 0;//进度
	    m_iFileNum = 0;//文件数
		m_lFreeMemory = 0;//剩余空间	
		m_iCommInfo = 0;//通道信息
		m_strChannel = "";//通道
		m_strMacName = "";//机器说明
		m_strInfo = "";
	}
public:
	int m_iSeleteNode;
	int m_iImage;
	int m_iStationID;//站号
	CString m_strStation;//站号映射
	int m_iTaskNum;//任务数
	int m_iCurrTask;//当前任务
	int m_iTaskRate;//进度
	int m_iFileNum;//文件数
	long m_lFreeMemory;//剩余空间	
	int m_iCommInfo;//通道信息
	CString m_strChannel;//通道
	CString m_strMacName;//机器说明
	CString m_strInfo;//通道信息
};

class CSelFiles
{
public:
	CSelFiles()
	{
		m_iFileNumber = 0;
		m_dwFilesLength = 0;
	}
	~CSelFiles()
	{
		POSITION pos;
		CSelFile *pSelFile;
		
		pos = m_FileQueue.GetHeadPosition();
		while(pos)
		{
			pSelFile = m_FileQueue.GetNext(pos);
			delete pSelFile;
		}
		m_FileQueue.RemoveAll();
	}
public:
	int m_iFileNumber;//文件数
	DWORD m_dwFilesLength;//文件组长度
	CList<CSelFile *, CSelFile *>  m_FileQueue;//文件队列
};

typedef struct 
{
	int iNodeFlag;
	int iImage;
	CString strStationID;
	CString strChannel;
	CString strMacName;
	CString strTaskNum;
	CString strCurrTask;
	CString strTaskRate;
	CString strFileNum;
	CString strFreeMemory;	
	CString strCommInfo;

	CString strIndex;
	CString strFileName;
	CString strFileLength;
}ITEMINFO;

HKEY GetNtSectionKey(LPCTSTR lpszSection);
int SetNtRegValue(LPCTSTR lpszSection,LPCTSTR lpszEntry,void *nValue,int WriteSize);
int QueryNtRegValue(LPCTSTR lpszSection, LPCTSTR lpszEntry,LPBYTE lpData,int QuerySize);
int QueryPassword(CString *UserName,CString *Password,bool *bAdministrator,WORD *right);
bool DelNtRegValue(LPCTSTR lpszSection, LPCTSTR lpszEntry);
void AddSysNoteFile(int iChannel, CString UserName, CString strTime, int iEvent, int iNode, CString strName,CString strPath);
CString GetTodayStr();
void ReadSysTime(BYTE *strTime);
CString ReadSysTime();
void CharToString(const char *in_pchrSrc, CString &out_strDec);//多字符转字符串
void CharToString(const TCHAR *in_pchrSrc, CString &out_strDec);//多字符转字符串
int StringToChar(const CString &in_strSrc, const int &in_iMaxLen, char *out_pchrDec);//字符串转多字符
int StringToChar(const CString &in_strSrc, const int &in_iMaxLen, TCHAR *out_pchrDec);//字符串转多字符

#endif