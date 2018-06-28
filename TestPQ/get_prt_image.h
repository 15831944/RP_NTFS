#pragma once
#include <afxwin.h>
#include <string>

#include <Gdiplus.h>
#pragma comment(lib,"gdiplus.lib")
using namespace Gdiplus;
using namespace std;

int GetEncoderClsid(const WCHAR* format, CLSID* pClsid)
{
	ULONG_PTR m_gdiplusToken;
	Gdiplus::GdiplusStartupInput StartupInput;
	GdiplusStartup(&m_gdiplusToken, &StartupInput, NULL);
	UINT  num = 0;
	UINT  size = 0;
	ImageCodecInfo* pImageCodecInfo = NULL;
	GetImageEncodersSize(&num, &size);
	if (size == 0)        return -1;

	pImageCodecInfo = (ImageCodecInfo*)(malloc(size));
	if (pImageCodecInfo == NULL)        return -1;

	GetImageEncoders(num, size, pImageCodecInfo);
	for (UINT j = 0; j < num; ++j)
	{
		if (wcscmp(pImageCodecInfo[j].MimeType, format) == 0)
		{
			*pClsid = pImageCodecInfo[j].Clsid;
			free(pImageCodecInfo);
			return j;
		}
	}
	free(pImageCodecInfo);
	GdiplusShutdown(m_gdiplusToken);
	return -1;
}

extern "C" __declspec(dllexport) void get_thumb(char* file_name, char* bmppath)
{
	CLSID bmpClsid;
	GetEncoderClsid(L"image/bmp", &bmpClsid);
	wchar_t WStr[MAX_PATH];
	MultiByteToWideChar(CP_ACP, 0, file_name, -1, WStr, MAX_PATH);
	Gdiplus::Image * pImage = Gdiplus::Image::FromFile(WStr);
	Gdiplus::Image * smage = pImage->GetThumbnailImage(400, 400);
	string path2 = bmppath;
	size_t len2 = path2.size() + 1;
	size_t converted2 = 0;
	wchar_t *WStr2;
	WStr2 = (wchar_t*)malloc(len2 * sizeof(wchar_t));
	mbstowcs_s(&converted2, WStr2, len2, path2.c_str(), _TRUNCATE);
	pImage->~Image();
	Status rr = smage->Save(WStr2, &bmpClsid);

}

extern "C" __declspec(dllexport) int get_prt_image(char* file_name, char* bmppath)
{
	IStorage* pStorage = NULL;
	HRESULT hResult;
	wchar_t path_file[MAX_PATH];
	MultiByteToWideChar(CP_ACP, 0, file_name, -1, path_file, MAX_PATH);
	hResult = StgOpenStorage(path_file, NULL, STGM_READ | STGM_SHARE_DENY_WRITE, NULL, 0, &pStorage);
	if (hResult != S_OK)return-1;
	IStorage* pSubStorage = NULL;
	HRESULT hr = pStorage->OpenStorage(L"images", NULL, STGM_READ | STGM_SHARE_EXCLUSIVE, NULL, 0, &pSubStorage);

	IStream *pStream;          pStream = NULL;
	DWORD dwMode = STGM_READ | STGM_SHARE_EXCLUSIVE;
	if (pSubStorage != NULL) pSubStorage->OpenStream(L"preview", NULL, dwMode, 0, &pStream);

	if (pStream != NULL)
	{
		CLSID bmpClsid;
		GetEncoderClsid(L"image/bmp", &bmpClsid);
		Image *image1 = Image::FromStream(pStream);
		//image1=image1->GetThumbnailImage(300,300);
		if (image1 != NULL)
		{
			wchar_t path_file[MAX_PATH];
			MultiByteToWideChar(CP_ACP, 0, bmppath, -1, path_file, MAX_PATH);
			image1->Save(path_file, &bmpClsid, NULL);

		}
		pStream->Release();
	}
	pStorage->Release();
	pStorage = NULL;
	//get_thumb(bmppath,bmppath);
	return 0;
}