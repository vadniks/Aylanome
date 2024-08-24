
#pragma once

#include "defs.hpp"
#include "elements.hpp"
#include "DrawMode.hpp"
#include <QWidget>
#include <QPainter>
#include <QStack>

class BoardWidget final : public QWidget {
    Q_OBJECT
private:
    DrawMode mDrawMode;
    QStack<Element*> mElements;
    ProcessElement* mCurrentProcessElement; // nullable
    StreamElement* mCurrentStreamElement; // nullable
    SquiggleElement* mCurrentSquiggleElement; // nullable
    TextElement* mCurrentTextElement; // nullable
    Element* mSelectedElement; // nullable
    bool mMousePressed;
public:
    BoardWidget();
    ~BoardWidget() override;

    DISABLE_COPY(BoardWidget)
    DISABLE_MOVE(BoardWidget)

    QSize minimumSizeHint() const override;
protected:
    void paintEvent(QPaintEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
private:
    void drawBorder(QPainter& painter);
    void drawDescription(QPainter& painter);
public slots:
    void drawModeChanged(DrawMode mode);
};
