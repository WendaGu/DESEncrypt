#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class FileEx  
{
public:
	FileEx();
	virtual ~FileEx();
	////
	bool    OpenFile(const char *OutFile,const char *InFile);//打开输入输出文件
	void    CloseFile();//关闭输入输出文件
	void    RunError(const char *OutFile);//错误处理
protected:
    HFILE	fh_out,fh_in;//输入输出文件句柄
};