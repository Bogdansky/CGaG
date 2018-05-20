#pragma once
const double pi = 3.14159;

struct CSizeD
{
	double cx;
	double cy;
};

struct CRectD
{
	double left;
	double top;
	double right;
	double bottom;
	CRectD() { left = top = right = bottom = 0; };
	CRectD(double l, double t, double r, double b);
	void SetRectD(double l, double t, double r, double b);
	CSizeD SizeD();
};

CMatrix SpaceToWindow(CRectD& rs, CRect& rw);
// ���������� ������� ��������� ��������� �� ������� � �������
// rs - ������� � ������� ����������� - double
// rw - ������� � ������� ����������� - int
CMatrix CreateViewCoord(double r, double fi, double q);
// ������� ������� ��������� ����� �� ������� ������� ��������� � �������
// (r,fi,q)- ���������� ����� ����������(������ ������� ������� ���������)
// � ������� ����������� ������� ���������( ���� fi � q � ��������)
CMatrix VectorMult(CMatrix& V1, CMatrix& V2);
// ��������� ��������� ������������ �������� V1 � V2
double ScalarMult(CMatrix& V1, CMatrix& V2);
// ��������� ��������� ������������ �������� V1 � V2
double ModVec(CMatrix& V);
// ��������� ������ ������� V
double CosV1V2(CMatrix& V1, CMatrix& V2);
// ��������� ������� ���� ����� ��������� V1 � V2
CMatrix SphereToCart(CMatrix& PView);
// ����������� ����������� ���������� PView  ����� � ���������
// PView(0) - r
// PView(1) - fi - ������(������ �� ��� X), ����.
// PView(2) - q - ����(�������� ��� Z), ����.
// ���������: R(0)- x, R(1)- y, R(2)- z	
