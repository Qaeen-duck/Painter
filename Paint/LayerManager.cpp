#include "LayerManager.h"

LayerManager::LayerManager(QWidget* parent):QWidget(parent)
{
	//页面布局
	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->parentWidget()->setFixedSize(1300, 700);
	listWidget = new QListWidget(this);
	listWidget->setFixedSize(200, 500);
	//listWidget->setFrameStyle(QFrame::Plain | QFrame::StyledPanel);
	layout->addWidget(listWidget);
	QWidget *hwidget = new QWidget();
	hwidget->setLayout(layout);
	QHBoxLayout *layoutView = new QHBoxLayout(this);
	layoutView->addWidget(hwidget);
	view = new GraphicsView();
	view->setFixedSize(1000, 700);  //固定视图大小
	view->setDragMode(QGraphicsView::ScrollHandDrag);  //设置拖拽模式
	layoutView->addWidget(view);



	addButton = new QPushButton("Add Layer", this);
	connect(addButton, &QPushButton::clicked, this, &LayerManager::addLayer);
	layout->addWidget(addButton);

	removeButton = new QPushButton("Remove Layer", this);
	connect(removeButton, &QPushButton::clicked, this, &LayerManager::removeLayer);
	layout->addWidget(removeButton);

	//activateButton = new QPushButton("Activate Layer", this);
	//connect(activateButton, &QPushButton::clicked, this, &LayerManager::activateLayer);
	//layout->addWidget(activateButton);
}

void LayerManager::addLayer()
{
	bool ok;
	QString layerName = QInputDialog::getText(this, "Add Layer", "Enter layer name:", QLineEdit::Normal, QString(), &ok);
	if (ok && !layerName.isEmpty()) 
	{
		Layer* layer = new Layer(layerName);
		layers.append(layer);
		QListWidgetItem *item = new QListWidgetItem(listWidget);
		QCheckBox *checkbox = new QCheckBox();  //给图层列表中每个图层前面添加复选框
		checkbox->setText(layer->getName());
		listWidget->addItem(item);
		listWidget->setItemWidget(item, checkbox);

		layer->getScene()->setSceneRect(0, 0, 2000, 2000);
		view->centerOn(1000, 1000);
		layer->getScene()->addRect(500, 500, 100, 100);
		view->setScene(layer->getScene());
	}
}

void LayerManager::removeLayer()
{
	int selectedIndex = listWidget->currentRow();
	if (selectedIndex >= 0) 
	{
		Layer* layer = layers.at(selectedIndex);
		layers.removeAt(selectedIndex);
		delete layer;
		delete listWidget->takeItem(selectedIndex);
	}
}

//void LayerManager::activateLayer()
//{
//	int selectedIndex = listWidget->currentRow();
//	if (selectedIndex >= 0) 
//	{
//		for (Layer* layer : layers) 
//		{
//			layer->setActive(false);
//		}
//
//		Layer* activeLayer = layers.at(selectedIndex);
//		activeLayer->setActive(true);
//
//		// Update UI or perform other actions for the activated layer
//	}
//}

QList<Layer*> LayerManager::getAllLayer()
{
	return layers;
}

LayerManager::~LayerManager()
{
}
