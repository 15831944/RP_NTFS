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
	CString m_strFileName;//�ļ���
	DWORD m_dwFileLength;//�ļ�����
	CString m_strFilePath;//�ļ�·��
};

class CNodeInfo 
{
public:
	CNodeInfo()
	{
		m_iSeleteNode = 0;
		m_iImage = 0;
		m_iStationID = -1;//վ��
		m_iTaskNum = 0;//������
		m_iCurrTask = 0;//��ǰ����
	    m_iTaskRate = 0;//����
	    m_iFileNum = 0;//�ļ���
		m_lFreeMemory = 0;//ʣ��ռ�	
		m_iCommInfo = 0;//ͨ����Ϣ
		m_strChannel = "";//ͨ��
		m_strMacName = "";//����˵��
		m_strInfo = "";
	}
public:
	int m_iSeleteNode;
	int m_iImage;
	int m_iStationID;//վ��
	CString m_strStation;//վ��ӳ��
	int m_iTaskNum;//������
	int m_iCurrTask;//��ǰ����
	int m_iTaskRate;//����
	int m_iFileNum;//�ļ���
	long m_lFreeMemory;//ʣ��ռ�	
	int m_iCommInfo;//ͨ����Ϣ
	CString m_strChannel;//ͨ��
	CString m_strMacName;//����˵��
	CString m_strInfo;//ͨ����Ϣ
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
	int m_iFileNumber;//�ļ���
	DWORD m_dwFilesLength;//�ļ��鳤��
	CList<CSelFile *, CSelFile *>  m_FileQueue;//�ļ�����
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
void CharToString(const char *in_pchrSrc, CString &out_strDec);//���ַ�ת�ַ���
void CharToString(const TCHAR *in_pchrSrc, CString &out_strDec);//���ַ�ת�ַ���
int StringToChar(const CString &in_strSrc, const int &in_iMaxLen, char *out_pchrDec);//�ַ���ת���ַ�
int StringToChar(const CString &in_strSrc, const int &in_iMaxLen, TCHAR *out_pchrDec);//�ַ���ת���ַ�

#endif