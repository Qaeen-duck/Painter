#include "LayerManager.h"

LayerManager::LayerManager(QWidget* parent):QWidget(parent)
{
	QVBoxLayout *layout = new QVBoxLayout(this);
	listWidget = new QListWidget(this);
	listWidget->setFixedSize(200, 500);
	layout->addWidget(listWidget);

	addButton = new QPushButton("Add Layer", this);
	connect(addButton, &QPushButton::clicked, this, &LayerManager::addLayer);
	layout->addWidget(addButton);

	removeButton = new QPushButton("Remove Layer", this);
	connect(removeButton, &QPushButton::clicked, this, &LayerManager::removeLayer);
	layout->addWidget(removeButton);

	activateButton = new QPushButton("Activate Layer", this);
	connect(activateButton, &QPushButton::clicked, this, &LayerManager::activateLayer);
	layout->addWidget(activateButton);
}

void LayerManager::addLayer()
{
	bool ok;
	QString layerName = QInputDialog::getText(this, "Add Layer", "Enter layer name:", QLineEdit::Normal, QString(), &ok);
	if (ok && !layerName.isEmpty()) 
	{
		Layer* layer = new Layer(layerName);
		layers.append(layer);
		listWidget->addItem(layer->getName());
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

void LayerManager::activateLayer()
{
	int selectedIndex = listWidget->currentRow();
	if (selectedIndex >= 0) 
	{
		for (Layer* layer : layers) 
		{
			layer->setActive(false);
		}

		Layer* activeLayer = layers.at(selectedIndex);
		activeLayer->setActive(true);

		// Update UI or perform other actions for the activated layer
	}
}

QList<Layer*> LayerManager::getAllLayer()
{
	return layers;
}

LayerManager::~LayerManager()
{
}
