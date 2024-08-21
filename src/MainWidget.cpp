
#include "MainWidget.hpp"
#include <glm/ext/matrix_clip_space.hpp>

MainWidget::MainWidget() : mRenderer(nullptr) {

}

MainWidget::~MainWidget() {
    delete mRenderer;
}

QSize MainWidget::minimumSizeHint() const {
    return {16 * 115, 9 * 115};
}

void MainWidget::initializeGL() {
    QOpenGLFunctions_3_3_Core::initializeOpenGLFunctions();

    mRenderer = new Renderer(*this);
    updateProjection();

    glEnable(GL_MULTISAMPLE);
    glEnable(GL_BLEND);

    glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_ALPHA);
}

void MainWidget::paintGL() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    mRenderer->drawHollowRectangle(glm::vec2(10.0f, 10.0f), glm::vec2(100.0f, 100.0f), glm::vec4(0.0f, 0.0f, 0.0f, 1.0f), 1.0f);
    mRenderer->drawTextWrapped("Hello World!", 14, glm::vec2(10.0f, 10.0f), glm::vec4(0.0f, 0.0f, 0.0f, 1.0f), {100, 100});
}

void MainWidget::resizeGL(int w, int h) {
    updateProjection();
}

void MainWidget::keyPressEvent(QKeyEvent* event) {
    QWidget::keyPressEvent(event);
}

void MainWidget::mouseMoveEvent(QMouseEvent* event) {
    QWidget::mouseMoveEvent(event);
}

void MainWidget::mousePressEvent(QMouseEvent* event) {
    QWidget::mousePressEvent(event);
}

void MainWidget::mouseReleaseEvent(QMouseEvent* event) {
    QWidget::mouseReleaseEvent(event);
}

void MainWidget::updateProjection() {
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
