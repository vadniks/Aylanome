
#pragma once

#include "DrawMode.hpp"
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>

class ControlsWidget : public QWidget {
    Q_OBJECT
private:
    QHBoxLayout mLayout;
    QPushButton mSelectModeButton;
    QPushButton mProcessModeButton;
    QPushButton mStreamModeButton;
    QPushButton mSquiggleModeButton;
    QPushButton mTextModeButton;
public:
    ControlsWidget();
signals:
    void drawModeChanged(DrawMode mode);
};
