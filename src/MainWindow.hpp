
#pragma once

#include "defs.hpp"
#include "MainWidget.hpp"
#include <QMainWindow>

class MainWindow final : public QMainWindow {
    Q_OBJECT
private:
    MainWidget mMainWidget;
public:
    MainWindow();

    DISABLE_COPY(MainWindow)
    DISABLE_MOVE(MainWindow)
};
