#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Paint.h"
#include <QtWidgets/QToolBar>
#include <QtWidgets/QAction>
#include <qicon.h>

class Paint : public QMainWindow
{
	Q_OBJECT

public:
	Paint(QWidget *parent = Q_NULLPTR);

private:
	Ui::PaintClass ui;
};
