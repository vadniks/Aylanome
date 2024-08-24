
#include "BoardWidget.hpp"
#include <QKeyEvent>
#include <glm/ext/matrix_clip_space.hpp>

BoardWidget::BoardWidget() :
    mRenderer(nullptr),
    mProjection(),
    mDrawMode(DrawMode::SELECT),
    mElements(),
    mCurrentProcessElement(nullptr),
    mCurrentStreamElement(nullptr),
    mCurrentSquiggleElement(nullptr),
    mCurrentTextElement(nullptr),
    mMousePos()
{
    setFocusPolicy(Qt::FocusPolicy::ClickFocus);
    setFixedSize(minimumSizeHint());
    setMouseTracking(true);
}

BoardWidget::~BoardWidget() {
    delete mRenderer;

    delete mCurrentProcessElement;
    delete mCurrentStreamElement;
    delete mCurrentSquiggleElement;
    delete mCurrentTextElement;

    for (auto i : mElements)
        delete i;
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

    for (Element* element : mElements) {
        if (dynamic_cast<ProcessElement*>(element) != nullptr) {
            const auto xElement = dynamic_cast<ProcessElement*>(element);

            const bool hovered =
                mMousePos.x >= xElement->position.x && mMousePos.x <= xElement->position.x + xElement->size.x &&
                mMousePos.y >= xElement->position.y && mMousePos.y <= xElement->position.y + xElement->size.y;

            const auto widthAdjustment = hovered ? 2 : 0;
            mRenderer->drawHollowRectangle(xElement->position, xElement->size, {0.0f, 0.0f, 0.0f, 1.0f}, 1.0f + widthAdjustment);
        }
    }
}

void BoardWidget::resizeGL(int w, int h) {
    updateProjection();
}

void BoardWidget::keyPressEvent(QKeyEvent* event) {

}

void BoardWidget::mouseMoveEvent(QMouseEvent* event) {
    switch (mDrawMode) {
        case DrawMode::SELECT:
            mMousePos = {event->pos().x(), event->pos().y()};
            break;
    }

    update();
}

void BoardWidget::mousePressEvent(QMouseEvent* event) {
    const int x = event->pos().x();
    const int y = event->pos().y();

    switch (mDrawMode) {
        case DrawMode::PROCESS:
            mCurrentProcessElement = new ProcessElement();
            mCurrentProcessElement->position = {x, y};
            mCurrentProcessElement->size = {16 * 10, 9 * 10};
            break;
    }

    update();
}

void BoardWidget::mouseReleaseEvent(QMouseEvent* event) {
    switch (mDrawMode) {
        case DrawMode::PROCESS:
            mElements.push(mCurrentProcessElement);
            mCurrentProcessElement = nullptr;
            break;
    }

    update();
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

    const auto number = "1"; // TODO: stub
    const auto numberSize = mRenderer->textMetrics(number, secondaryFontSize);
    mRenderer->drawText(number, primaryFontSize, {
        (width() - margin + titleNumberLine) / 2 - numberSize.width() / 2,
        heightEnd - numberSize.height() - margin * 2
    }, color);
}

void BoardWidget::drawModeChanged(DrawMode mode) {
    mDrawMode = mode;
}
