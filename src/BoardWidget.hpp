
#pragma once

#include "defs.hpp"
#include "Renderer.hpp"
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>

class BoardWidget final : public QOpenGLWidget, public QOpenGLFunctions_3_3_Core {
    Q_OBJECT
private:
    Renderer* mRenderer;
    glm::mat4 mProjection;
public:
    BoardWidget();
    ~BoardWidget() override;

    DISABLE_COPY(BoardWidget)
    DISABLE_MOVE(BoardWidget)

    QSize minimumSizeHint() const override;
protected:
    void initializeGL() override;
    void paintGL() override;
    void keyPressEvent(QKeyEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
private:
    void updateProjection();
    void drawBorder();
    void drawDescription();
};
