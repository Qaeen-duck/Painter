#include "GraphicsView.h"



GraphicsView::GraphicsView()
{
}

void GraphicsView::wheelEvent(QWheelEvent *event)
{
	// 获取滚轮滚动的角度
	int delta = event->angleDelta().y();

	// 根据滚动方向来缩放视图
	if (delta > 0) {
		scale(1.1, 1.1); // 放大
	}
	else {
		scale(0.9, 0.9); // 缩小
	}

	event->accept();
}

void GraphicsView::mousePressEvent(QMouseEvent *event)
{
	//p = event->pos();

	// 记录鼠标按下时的中心点坐标
	centerAnchor = mapToScene(event->pos()) - event->pos() + QPointF(width() / 2, height() / 2);
	// 记录当前鼠标在view中的位置，用来在mouseMove事件中计算偏移
	// 此处不将view坐标转换成scene坐标的原因是优化性能，在move的过程中会产生抖动
	posAnchor = event->pos();
	isMousePressed = true;
}

void GraphicsView::mouseMoveEvent(QMouseEvent *event)
{

	QPointF offsetPos = event->pos() - posAnchor;
	if (isMousePressed)
	{
		setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
		centerOn(centerAnchor - offsetPos);
	}

}

void GraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
	isMousePressed = false;
}



GraphicsView::~GraphicsView()
{
}
