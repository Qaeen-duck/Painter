#include "Paint.h"


Paint::Paint(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//创建工具栏及Action
	QToolBar *toolbar = new QToolBar(this);
	toolbar->setMovable(false); // 设置工具栏不可移动
	QAction *actionPolyLine = new QAction(QIcon(":/Paint/polyline.png"), "Action PolyLine", this);
	QAction *actionRect = new QAction(QIcon(":/Paint/rectangle.png"), "Action Rectangle", this);
	QAction *actionPolygon = new QAction(QIcon(":/Paint/polygon.png"), "Action Polygon", this);
	QAction *actionCircle = new QAction(QIcon(":/Paint/circle.png"), "Action Circle", this);
	QAction *actionCurving = new QAction(QIcon(":/Paint/shan.png"), "Action Curving", this);
	QAction *actionText = new QAction(QIcon(":/Paint/txt.png"), "Action Text", this);
	QAction *actionPicture = new QAction(QIcon(":/Paint/picture.png"), "Action Picture", this);
	QAction *actionRubber = new QAction(QIcon(":/Paint/rubber.png"), "Action Rubber", this);
	QAction *actionClear = new QAction(QIcon(":/Paint/clear.png"), "Action Clear", this);
	QAction *actionBig = new QAction(QIcon(":/Paint/big.png"), "Action Big", this);
	QAction *actionSmall = new QAction(QIcon(":/Paint/small.png"), "Action Small", this);
	QAction *actionColor = new QAction(QIcon(":/Paint/color.png"), "Action Color", this);
	QAction *actionStyle = new QAction(QIcon(":/Paint/style.png"), "Action Style", this);
	toolbar->addAction(actionPolyLine);
	toolbar->addAction(actionRect);
	toolbar->addAction(actionPolygon);
	toolbar->addSeparator(); // 添加分隔符
	toolbar->addAction(actionCircle);
	toolbar->addAction(actionCurving);
	toolbar->addSeparator(); // 添加分隔符
	toolbar->addAction(actionText);
	toolbar->addAction(actionPicture);
	toolbar->addSeparator(); // 添加分隔符
	toolbar->addAction(actionRubber);
	toolbar->addAction(actionClear);
	toolbar->addAction(actionBig);
	toolbar->addAction(actionSmall);
	toolbar->addAction(actionColor);
	toolbar->addAction(actionStyle);
	addToolBar(toolbar);

}
