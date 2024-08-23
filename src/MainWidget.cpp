
#include "MainWidget.hpp"

MainWidget::MainWidget() : mLayout(this) {
    mLayout.addWidget(&mControlsWidget);
    mLayout.addWidget(&mBoardWidget);
    connect(&mControlsWidget, &ControlsWidget::drawModeChanged, &mBoardWidget, &BoardWidget::drawModeChanged);
}
