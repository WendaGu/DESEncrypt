#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class FileEx  
{
public:
	FileEx();
	virtual ~FileEx();
	////
	bool    OpenFile(const char *OutFile,const char *InFile);//����������ļ�
	void    CloseFile();//�ر���������ļ�
	void    RunError(const char *OutFile);//������
protected:
    HFILE	fh_out,fh_in;//��������ļ����
};