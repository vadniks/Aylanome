
#include "MainWidget.hpp"

MainWidget::MainWidget() {

}

MainWidget::~MainWidget() {

}

QSize MainWidget::minimumSizeHint() const {
    return {16 * 75, 9 * 75};
}

void MainWidget::initializeGL() {
    QOpenGLFunctions_3_3_Core::initializeOpenGLFunctions();

    glEnable(GL_MULTISAMPLE);
}

void MainWidget::paintGL() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void MainWidget::resizeGL(int w, int h) {
    QOpenGLWidget::resizeGL(w, h);
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

}
