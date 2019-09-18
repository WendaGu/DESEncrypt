#pragma once

class Convert 
{
public:
	static  bool Transform(bool *Out,bool *In,const char *Table,UINT len);//�任
	static  bool Xor(bool *InA,const bool *InB,UINT len);//���
	static  bool RotateL(char *In,UINT len,UINT loop);//ѭ������
	static  bool ByteToBit(bool *Out,const char *In,UINT len,UINT num=8);//�ֽ���ת����λ��
	static  bool BitToByte(char *Out,const bool *In,UINT len,UINT num=8);//λ��ת�����ֽ���
	static  bool HalfByteToByte(char *Out,const char *In,UINT len);//���ֽ���ת�����ֽ���
	static  bool ByteToHalfByte(char *Out,const char *In,UINT len);//�ֽ���ת���ɰ��ֽ���
	static  int  StrToHalfByte(char *Out,char *In,UINT len);//�ַ���ת���ɰ��ֽ���
	static  int  HalfByteToStr(char *Out,char *In,UINT len);//���ֽ���ת�����ַ���

	static  void Browse(CString &input,CString &output);
    static  void BuildOutputFileName(CString &input,CString &output,bool run_t,CString p,CString f);

};
