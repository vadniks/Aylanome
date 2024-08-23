
#include "ControlsWidget.hpp"

ControlsWidget::ControlsWidget() : mLayout(this) {
    mSelectorModeButton.setText("Select");
    connect(&mSelectorModeButton, &QPushButton::clicked, this, [this](){ emit drawModeChanged(DrawMode::SELECT); });
    mLayout.addWidget(&mSelectorModeButton);

    mProcessModeButton.setText("Process");
    connect(&mProcessModeButton, &QPushButton::clicked, this, [this](){ emit drawModeChanged(DrawMode::PROCESS); });
    mLayout.addWidget(&mProcessModeButton);

    mStreamModeButton.setText("Stream");
    connect(&mStreamModeButton, &QPushButton::clicked, this, [this](){ emit drawModeChanged(DrawMode::STREAM); });
    mLayout.addWidget(&mStreamModeButton);

    mSquiggleModeButton.setText("Squiggle");
    connect(&mSquiggleModeButton, &QPushButton::clicked, this, [this](){ emit drawModeChanged(DrawMode::SQUIGGLE); });
    mLayout.addWidget(&mSquiggleModeButton);

    mTextModeButton.setText("Text");
    connect(&mTextModeButton, &QPushButton::clicked, this, [this](){ emit drawModeChanged(DrawMode::TEXT); });
    mLayout.addWidget(&mTextModeButton);
}
