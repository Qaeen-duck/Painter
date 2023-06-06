#pragma once
#include "qgraphicsview.h"
#include <qwheelevent>
#include <qmouseevent>
#include <qpoint.h>

class GraphicsView :
	public QGraphicsView
{
public:
	GraphicsView();
	~GraphicsView();

protected:
	void wheelEvent(QWheelEvent *) override;
	void mousePressEvent(QMouseEvent *) override;
	void mouseMoveEvent(QMouseEvent *) override;
	void mouseReleaseEvent(QMouseEvent *) override;
private:
	QPointF centerAnchor;
	QPoint posAnchor;
	bool isMousePressed;
};

//class View: public QFrame
//{
//public:
//	explicit View(const QString &name, QWidget *parent = 0);
//
//	QGraphicsView *view() const;
//
//private:
//
//};
//
//View: public QFrame::View: public QFrame()
//{
//}
//
//View: public QFrame::~View: public QFrame()
//{
//}

