
#pragma once

#include "defs.hpp"
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>

class MainWidget final : public QOpenGLWidget, public QOpenGLFunctions_3_3_Core {
    Q_OBJECT
public:
    MainWidget();
    ~MainWidget() override;

    DISABLE_COPY(MainWidget)
    DISABLE_MOVE(MainWidget)

    QSize minimumSizeHint() const override;
protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;
    void keyPressEvent(QKeyEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
private:
    void updateProjection();
};
