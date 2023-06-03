#pragma once
#include "qwidget.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QListWidgetItem>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QInputDialog>
#include <QtWidgets/QCheckBox>
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include <QtWidgets/QFrame>
#include <qframe.h>
#include <qpen.h>
#include <qbrush.h>
#include <qcolor.h>


class Layer {
public:
	Layer(const QString& name) : name(name), isActive(false), scene(new QGraphicsScene()) {}

	QString getName() const 
	{
		return name;
	}
	bool isActiveLayer() const 
	{
		return isActive;
	}
	void setActive(bool active) 
	{
		isActive = active;
	}
	QGraphicsScene* getScene() const 
	{
		return scene;
	}

private:
	QString name;
	bool isActive;
	QGraphicsScene *scene;
	//QVector<Geometry*> geometry;   //´æ´¢Í¼²ãÉÏµÄÍ¼Ôª
};


class LayerManager : public QWidget
{
public:
	LayerManager(QWidget* parent = nullptr);
	void addLayer();
	void removeLayer();
	//void activateLayer();
	QList<Layer*> getAllLayer();
	~LayerManager();

private:
	QListWidget* listWidget;
	QPushButton* addButton;
	QPushButton* removeButton;
	//QPushButton* activateButton;
	QList<Layer*> layers;
	QGraphicsView* view;
};

