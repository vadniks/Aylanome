
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
