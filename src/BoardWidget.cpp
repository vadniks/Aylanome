
#include "BoardWidget.hpp"
#include <QKeyEvent>

BoardWidget::BoardWidget() :
    mDrawMode(DrawMode::SELECT),
    mElements(),
    mCurrentProcessElement(nullptr),
    mCurrentStreamElement(nullptr),
    mCurrentSquiggleElement(nullptr),
    mCurrentTextElement(nullptr),
    mSelectedElement(nullptr),
    mMousePressed(false)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFocusPolicy(Qt::FocusPolicy::ClickFocus);
    setFixedSize(minimumSizeHint());
    setMouseTracking(true);
}

BoardWidget::~BoardWidget() {
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

void BoardWidget::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.setRenderHints(QPainter::RenderHint::Antialiasing | QPainter::RenderHint::TextAntialiasing);
    painter.fillRect(QRect(0, 0, width(), height()), QBrush(QColor(255, 255, 255)));

    drawBorder(painter);
    drawDescription(painter);

    for (auto element : mElements) {
        if (dynamic_cast<ProcessElement*>(element) != nullptr) {
            const auto xElement = dynamic_cast<ProcessElement*>(element);

            QRect rect = {xElement->position.x, xElement->position.y, xElement->size.x, xElement->size.y};

            painter.setPen(QPen(QBrush(xElement->foreground), xElement->lineWidth + (mSelectedElement == xElement ? 5 : 0)));
            painter.setBrush(QBrush(xElement->background));
            painter.drawRect(rect);

            painter.setFont(QFont("Roboto", xElement->textSize));
            painter.drawText(rect, Qt::TextFlag::TextWordWrap | Qt::AlignmentFlag::AlignCenter, xElement->text);
        }
    }
}

void BoardWidget::keyPressEvent(QKeyEvent* event) {

}

void BoardWidget::mouseMoveEvent(QMouseEvent* event) {
    const int x = event->pos().x();
    const int y = event->pos().y();

    switch (mDrawMode) {
        case DrawMode::SELECT:
            if (mMousePressed && mSelectedElement != nullptr) {
                switch (mSelectedElement->type()) {
                    case Element::PROCESS:
                        dynamic_cast<ProcessElement*>(mSelectedElement)->position = {x, y};
                        break;
                }
            }
            break;
    }

    update();
}

void BoardWidget::mousePressEvent(QMouseEvent* event) {
    mMousePressed = true;

    const int x = event->pos().x();
    const int y = event->pos().y();

    bool selected = false;

    switch (mDrawMode) {
        case DrawMode::SELECT:
            for (auto element : mElements) {
                if (dynamic_cast<ProcessElement*>(element) != nullptr) {
                    auto xElement = dynamic_cast<ProcessElement*>(element);

                    if (x >= xElement->position.x && x <= xElement->position.x + xElement->size.x &&
                        y >= xElement->position.y && y <= xElement->position.y + xElement->size.y) {
                        mSelectedElement = xElement;
                        selected = true;
                    }
                }
            }

            if (!selected)
                mSelectedElement = nullptr;
            break;
        case DrawMode::PROCESS:
            mCurrentProcessElement = new ProcessElement();
            mCurrentProcessElement->position = {x, y};
            mCurrentProcessElement->size = {16 * 10, 9 * 10};
            break;
    }

    update();
}

void BoardWidget::mouseReleaseEvent(QMouseEvent* event) {
    mMousePressed = false;

    switch (mDrawMode) {
        case DrawMode::SELECT:

            break;
        case DrawMode::PROCESS:
            mElements.push(mCurrentProcessElement);
            mCurrentProcessElement = nullptr;
            break;
    }

    update();
}

void BoardWidget::drawBorder(QPainter& painter) {
    painter.setPen(QPen(QBrush(QColor(0, 0, 0)), 1));
    painter.setBrush(QBrush(QColor(0, 0, 0, 0)));
    painter.drawRect(5, 5, width() - 5 * 2, height() - 5 * 2);
}

void BoardWidget::drawDescription(QPainter& painter) {
    painter.setPen(QPen(QBrush(QColor(0, 0, 0)), 1));
    painter.setBrush(QBrush(QColor(0, 0, 0)));

    QFont primaryFont("Roboto", 20), secondaryFont("Roboto", 12);
    QFontMetrics primaryFontMetrics(primaryFont), secondaryFontMetrics(secondaryFont);

    const auto margin = 5;
    const auto widthStart = margin;
    const auto heightStart = height() - margin * 2 - 50;
    const auto heightEnd = height() - margin;

    painter.drawLine(widthStart, heightStart, width() - margin, heightStart);

    //

    const auto nodeTitleLine = margin + width() / 8;
    painter.drawLine(nodeTitleLine, heightStart, nodeTitleLine, heightEnd);

    const auto nodeText = "Node:";
    painter.setFont(secondaryFont);
    painter.drawText(margin * 2, heightStart + margin + secondaryFontMetrics.capHeight(), nodeText);

    const auto node = "A0"; // TODO: stub
    painter.setFont(primaryFont);
    painter.drawText(
        (nodeTitleLine - margin) / 2 - primaryFontMetrics.horizontalAdvance(node) / 2,
        heightEnd - margin,
        node
    );

    //

    const auto titleNumberLine = width() / 8 * 7;
    painter.drawLine(titleNumberLine, heightStart, titleNumberLine, heightEnd);

    const auto titleText = "Title:";
    painter.setFont(secondaryFont);
    painter.drawText(nodeTitleLine + margin, heightStart + margin + secondaryFontMetrics.capHeight(), titleText);

    const auto title = "Test"; // TODO: stub
    painter.setFont(primaryFont);
    painter.drawText(
        (titleNumberLine - margin + nodeTitleLine) / 2 - primaryFontMetrics.horizontalAdvance(title) / 2,
        heightEnd - margin,
        title
    );

    //

    const auto numberText = "Number:";
    painter.setFont(secondaryFont);
    painter.drawText(titleNumberLine + margin, heightStart + margin + secondaryFontMetrics.capHeight(), numberText);

    const auto number = "1"; // TODO: stub
    painter.setFont(primaryFont);
    painter.drawText(
        (width() - margin + titleNumberLine) / 2 - primaryFontMetrics.horizontalAdvance(number) / 2,
        heightEnd - margin * 2,
        number
    );
}

void BoardWidget::drawModeChanged(DrawMode mode) {
    mDrawMode = mode;
}
