
#include "BoardWidget.hpp"
#include <QKeyEvent>
#include <glm/ext/matrix_clip_space.hpp>

BoardWidget::BoardWidget() : mRenderer(nullptr), mProjection(), mDrawMode(DrawMode::SELECTOR) {
    setFocusPolicy(Qt::FocusPolicy::ClickFocus);
    setFixedSize(minimumSizeHint());
}

BoardWidget::~BoardWidget() {
    delete mRenderer;
}

QSize BoardWidget::minimumSizeHint() const {
    return {16 * 115, 9 * 115};
}

void BoardWidget::initializeGL() {
    QOpenGLFunctions_3_3_Core::initializeOpenGLFunctions();

    mRenderer = new Renderer(*this);
    updateProjection();

    glEnable(GL_MULTISAMPLE);
    glEnable(GL_BLEND);

    glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_ALPHA);
}

void BoardWidget::paintGL() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    drawBorder();
    drawDescription();
}

void BoardWidget::resizeGL(int w, int h) {
    updateProjection();
}

void BoardWidget::keyPressEvent(QKeyEvent* event) {

}

void BoardWidget::mouseMoveEvent(QMouseEvent* event) {

}

void BoardWidget::mousePressEvent(QMouseEvent* event) {

}

void BoardWidget::mouseReleaseEvent(QMouseEvent* event) {

}

void BoardWidget::updateProjection() {
    const auto xSize = size();

    mProjection = glm::ortho(
        0.0f,
        static_cast<float>(xSize.width()),
        static_cast<float>(xSize.height()),
        0.0f,
        -1.0f,
        1.0f
    );

    mRenderer->setProjection(mProjection);
}

void BoardWidget::drawBorder() {
    mRenderer->drawHollowRectangle({5.0f, 5.0f}, {width() - 5 - 5, height() - 5 - 5}, {0.0f, 0.0f, 0.0f, 1.0f}, 1.0f);
}

void BoardWidget::drawDescription() {
    const auto primaryFontSize = 24, secondaryFontSize = 14;

    const glm::vec4 color = {0.0f, 0.0f, 0.0f, 1.0f};

    const auto margin = 5;
    const auto widthStart = static_cast<float>(margin);
    const auto heightStart = static_cast<float>(height() - margin * 2 - 50);
    const auto heightEnd = static_cast<float>(height() - margin);

    mRenderer->drawLine({widthStart, heightStart}, {width() - margin, heightStart}, 1.0f, color);

    //

    const auto nodeTitleLine = margin + width() / 8;
    mRenderer->drawLine({nodeTitleLine, heightStart}, {nodeTitleLine, heightEnd}, 1.0f, color);

    const auto nodeText = "Node:";
    mRenderer->drawText(nodeText, secondaryFontSize, {margin * 2, heightStart + margin}, color);

    const auto node = "A0"; // TODO: stub
    const auto nodeSize = mRenderer->textMetrics(node, primaryFontSize);
    mRenderer->drawText(node, primaryFontSize, {
        (nodeTitleLine - margin) / 2 - nodeSize.width() / 2,
        heightEnd - nodeSize.height() - margin
    }, color);

    //

    const auto titleNumberLine = width() / 8 * 7;
    mRenderer->drawLine({titleNumberLine, heightStart}, {titleNumberLine, heightEnd}, 1.0f, color);

    const auto titleText = "Title:";
    mRenderer->drawText(titleText, secondaryFontSize, {nodeTitleLine + margin, heightStart + margin}, color);

    const auto title = "Test"; // TODO: stub
    const auto titleSize = mRenderer->textMetrics(title, primaryFontSize);
    mRenderer->drawText(title, primaryFontSize, {
        (titleNumberLine - margin + nodeTitleLine) / 2 - titleSize.width() / 2,
        heightEnd - titleSize.height() - margin
    }, color);

    //

    const auto numberText = "Number:";
    mRenderer->drawText(numberText, secondaryFontSize, {titleNumberLine + margin, heightStart + margin}, color);

    const auto number = "2"; // TODO: stub
    const auto numberSize = mRenderer->textMetrics(number, secondaryFontSize);
    mRenderer->drawText(number, primaryFontSize, {
        (width() - margin + titleNumberLine) / 2 - numberSize.width() / 2,
        heightEnd - numberSize.height() - margin * 2
    }, color);
}

void BoardWidget::drawModeChanged(DrawMode mode) {

}
