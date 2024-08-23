
#pragma once

#include "DrawMode.hpp"
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>

class ControlsWidget : public QWidget {
    Q_OBJECT
private:
    QHBoxLayout mLayout;
    QPushButton mSelectorModeButton;
    QPushButton mProcessModeButton;
    QPushButton mStreamModeButton;
    QPushButton mZipperModeButton;
public:
    ControlsWidget();
signals:
    void modeChanged(DrawMode mode);
};
