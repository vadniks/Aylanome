
#include "ControlsWidget.hpp"

ControlsWidget::ControlsWidget() : mLayout(this) {
    mSelectorModeButton.setText("Selector");
    connect(&mSelectorModeButton, &QPushButton::clicked, this, [this](){ emit drawModeChanged(DrawMode::SELECTOR); });
    mLayout.addWidget(&mSelectorModeButton);

    mProcessModeButton.setText("Process");
    connect(&mSelectorModeButton, &QPushButton::clicked, this, [this](){ emit drawModeChanged(DrawMode::PROCESS); });
    mLayout.addWidget(&mProcessModeButton);

    mStreamModeButton.setText("Stream");
    connect(&mSelectorModeButton, &QPushButton::clicked, this, [this](){ emit drawModeChanged(DrawMode::STREAM); });
    mLayout.addWidget(&mStreamModeButton);

    mZipperModeButton.setText("Zipper");
    connect(&mSelectorModeButton, &QPushButton::clicked, this, [this](){ emit drawModeChanged(DrawMode::ZIPPER); });
    mLayout.addWidget(&mZipperModeButton);
}
