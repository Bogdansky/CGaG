// ChildView.h : interface of the CChildView class
//
#pragma once

#define DROW1 1
#define SURFACE1 2
#define LIGHT 3
#define DIFFUZE 4
#define ZERKALO 5

class CChildView : public CWnd
{

public:
	CChildView();

public:
	CRect WinRect;	
	CMatrix PView;	
	CMatrix PLight;
	int Index;

	// ��������
	CMatrix VA, VB, VC, VD;	// ���������� ������ A,B,C,D ��������
//	CMatrix PView;          // ���������� ����� ����������
	CRect RS, RW;            // ������� � ������� � ������� ����������� - int
	int IsData, Rezult, IsRotateX, IsRotateY, IsRotateZ;
	double fx, fy, fz, dfi, dT, f0;      // ��� �������� ������ ���� X, Y, Z
										 // �����������
	POINT **MasPOINT;
	int Nx, Ny;
	CRectD RD;
	//  �����
	double Radius;
	CMatrix PSourceLight;
	double Ks;
	COLORREF Color;
	int TypeModel;

protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

public:
	virtual ~CChildView();

protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
public:
	afx_msg void OnSphere_Mirror();
	afx_msg void OnSphere_Diffuse();
};

