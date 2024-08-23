
#pragma once

#include "ControlsWidget.hpp"
#include "BoardWidget.hpp"
#include <QWidget>
#include <QVBoxLayout>

class MainWidget : public QWidget {
    Q_OBJECT
private: // TODO: add widget that displays current context
    QVBoxLayout mLayout;
    ControlsWidget mControlsWidget;
    BoardWidget mBoardWidget;
public:
    MainWidget();
};
