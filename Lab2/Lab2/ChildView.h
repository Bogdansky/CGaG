#pragma once

class CChildView : public CWnd
{
	// Создание
public:
	CChildView();

	// Атрибуты
public:

	// Операции
public:

	// Переопределение
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

	// Реализация
public:
	virtual ~CChildView();

protected:
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT, CPoint);
	afx_msg void OnLButtonUp(UINT, CPoint);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnImageOpen();
	afx_msg void OnImageOpeninpoint();
	afx_msg void OnImageSave();
	afx_msg void OnImageClear();
};