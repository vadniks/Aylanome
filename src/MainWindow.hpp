
#pragma once

#include "defs.hpp"
#include "BoardWidget.hpp"
#include <QMainWindow>

class MainWindow final : public QMainWindow {
    Q_OBJECT
private:
    BoardWidget mMainWidget;
public:
    MainWindow();

    DISABLE_COPY(MainWindow)
    DISABLE_MOVE(MainWindow)
};
