#pragma once
#include "qwidget.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QInputDialog>

class Layer {
public:
	Layer(const QString& name) : name(name), isActive(false) {}

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

private:
	QString name;
	bool isActive;
};


class LayerManager : public QWidget
{
public:
	LayerManager(QWidget* parent = nullptr);
	void addLayer();
	void removeLayer();
	void activateLayer();
	QList<Layer*> getAllLayer();
	~LayerManager();

private:
	QListWidget* listWidget;
	QPushButton* addButton;
	QPushButton* removeButton;
	QPushButton* activateButton;
	QList<Layer*> layers;
};

