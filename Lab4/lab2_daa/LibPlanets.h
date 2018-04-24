#pragma once
#include "CMATRIX.H"

struct CMyPen
{
	int PenStyle;
	int PenWidth;
	COLORREF color;
	CMyPen()
	{
		PenStyle = PS_SOLID;
		PenWidth = 1;
		color = RGB(0, 0, 0);
	}

	void Set(int PS, int PW, COLORREF col)
	{
		PenStyle = PS; // ����� ����
		PenWidth = PW; // ������� ����
		color = col; // ����
	}
};
struct CSizeD
{
	double cx;
	double cy;
};
class CRectD // ������������� ������� � ���
{
public:
	double top, bottom, left, right;
	CRectD()
	{
		top = bottom = left = right = 0;
	}
	CRectD(double t, double b, double l, double r)
	{
		top = t;
		bottom = b;
		left = l;
		right = r;
	};
	void SetRectD(double l, double t, double r, double b);
	CSizeD SizeD();
};

CMatrix SpaceToWindow(CRectD& rs, CRect& rw);
// ���������� ������� ��������� ��������� �� ������� � �������
// rs - ������� � ������� ����������� - double
// rw - ������� � ������� ����������� - int

void SetMyMode(CDC& dc, CRect& RW, CRectD& RS);
// ������������� ����� ����������� MM_ANISOTROPIC � ��� ���������
// dc - ������ �� ����� CDC MFC
// RS -  ������� � ������� ����������� 
// RW -	 ������� � ������� ����������� - int 

const double pi = 3.14;

CMatrix CreateTranslate2D(double dx, double dy);
// ��������� ������� ��� �������������� ��������� ������� ��� ��� �������� 
// �� dx �� ��� X � �� dy �� ��� Y � ������������� ������� ���������

CMatrix CreateRotate2D(double fi);
// ��������� ������� ��� �������������� ��������� ������� ��� ��� ��������
// �� ���� fi (��� fi>0 ������ ������� �������) � ������������� ������� ���������

class CSunSystem
{
	CRect Sun;		      // ������������� ������
	CRect Earth;          // ������������� �����
	CRect Moon;		      // ������������� ����
	CRect EarthOrbit;     // �������������, ��������� ������ ������ �����
	CRect MoonOrbit;      // �������������, ��������� ������ ������ ����
	CRect Planet51;       // ������������� �����
	CRect Planet51Orbit;  // �������������, ��������� ������ ������ �����
	CMatrix ECoords;      // ������� ���������� ����� � �� ������ ( x,y,1)
	CMatrix MCoords;      // ������� ���������� ���� � �� ����� ( x,y,1)
	CMatrix VCoords;
	CRect RW;		      // ������������� � ����
	CRectD RS;		      // ������������� ������� � ���
	double wEarth;		  // ������� �������� ����� ������������ ������, ����./���.
	double wMoon;		  // ������� �������� ���� ������������ ������, ����./���.
	double wPlanet51;     // ������� �������� ����� ������������ ������, ����./���.
	double fiE;			  // ������� ��������� ����� � ������� �������� ������, ����
	double fiM;			  // ������� ��������� ���� � ������� �������� �����, ����
	double fiV;           // ������� ��������� ����� � ������� �������� �����, ����
	double dt;			  // �������� �������������, ���.
public:
	CSunSystem();
	void SetDT(double dtx) // ��������� ��������� �������������
	{
		dt = dtx;
	};
	void SetNewCoords();     // ��������� ����� ���������� ������
	void GetRS(CRectD& RSX); // ���������� ������� ������� � ������� ��
	CRect GetRW() 
	{ 
		return RW;           // ���������� ������� ������� � ����	
	};	   
	void Draw(CDC& dc);		 // ��������� ��� ���������������� ��������� ���������
};
