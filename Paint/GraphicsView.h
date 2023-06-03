#pragma once
#include "qgraphicsview.h"
class GraphicsView :
	public QGraphicsView
{
public:
	GraphicsView();
	~GraphicsView();
protected:
	void wheelEvent(QWheelEvent *) override;
public slots:
void ZoomIn(int level = 1);
void ZoomOut(int level = 1);

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

