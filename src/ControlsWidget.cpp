
#include "ControlsWidget.hpp"

ControlsWidget::ControlsWidget() : mLayout(this) {
    mSelectorModeButton.setText("Selector");
    mLayout.addWidget(&mSelectorModeButton);

    mProcessModeButton.setText("Process");
    mLayout.addWidget(&mProcessModeButton);

    mStreamModeButton.setText("Stream");
    mLayout.addWidget(&mStreamModeButton);

    mZipperModeButton.setText("Zipper");
    mLayout.addWidget(&mZipperModeButton);
}
