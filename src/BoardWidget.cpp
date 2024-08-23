
#include "BoardWidget.hpp"
#include <QKeyEvent>
#include <glm/ext/matrix_clip_space.hpp>

BoardWidget::BoardWidget() : mRenderer(nullptr), mProjection() {
    setFocusPolicy(Qt::FocusPolicy::ClickFocus);
    setFixedSize(minimumSizeHint());
}

BoardWidget::~BoardWidget() {
    delete mRenderer;
}

QSize BoardWidget::minimumSizeHint() const {
    return {16 * 110, 9 * 110};
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
    mRenderer->drawText(nodeText, 14, {margin * 2, heightStart + margin}, color);

    const auto nodeName = "A0"; // TODO: stub
    const auto nodeNameSize = mRenderer->textMetrics(nodeName, 24);
    mRenderer->drawText(nodeName, 24, {
        (nodeTitleLine - margin) / 2 - nodeNameSize.width() / 2,
        heightEnd - nodeNameSize.height() - margin
    }, color);

    //

    const auto titleNumberLine = width() / 8 * 7;
    mRenderer->drawLine({titleNumberLine, heightStart}, {titleNumberLine, heightEnd}, 1.0f, color);

}
