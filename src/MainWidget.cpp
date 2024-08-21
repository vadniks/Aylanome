
#include "MainWidget.hpp"
#include <QKeyEvent>
#include <glm/ext/matrix_clip_space.hpp>

static QString test;

MainWidget::MainWidget() : mRenderer(nullptr), mProjection() {
    setFocusPolicy(Qt::FocusPolicy::ClickFocus);
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
    mRenderer->drawTextWrapped(test, 14, glm::vec2(10.0f, 10.0f), glm::vec4(0.0f, 0.0f, 0.0f, 1.0f), {100, 100});
}

void MainWidget::resizeGL(int w, int h) {
    updateProjection();
}

void MainWidget::keyPressEvent(QKeyEvent* event) {
    if (event->key() != Qt::Key::Key_Backspace)
        test = test + event->text();
    else
        test = test.mid(0, test.size() - 1);
    update();
}

void MainWidget::mouseMoveEvent(QMouseEvent* event) {

}

void MainWidget::mousePressEvent(QMouseEvent* event) {

}

void MainWidget::mouseReleaseEvent(QMouseEvent* event) {

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
