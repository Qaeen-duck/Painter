#include "GraphicsView.h"



GraphicsView::GraphicsView()
{
}

void GraphicsView::wheelEvent(QWheelEvent *event)
{
	// ��ȡ���ֹ����ĽǶ�
	int delta = event->angleDelta().y();

	// ���ݹ���������������ͼ
	if (delta > 0) {
		scale(1.1, 1.1); // �Ŵ�
	}
	else {
		scale(0.9, 0.9); // ��С
	}

	event->accept();
}

void GraphicsView::mousePressEvent(QMouseEvent *event)
{
	//p = event->pos();

	// ��¼��갴��ʱ�����ĵ�����
	centerAnchor = mapToScene(event->pos()) - event->pos() + QPointF(width() / 2, height() / 2);
	// ��¼��ǰ�����view�е�λ�ã�������mouseMove�¼��м���ƫ��
	// �˴�����view����ת����scene�����ԭ�����Ż����ܣ���move�Ĺ����л��������
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
