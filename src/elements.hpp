
#pragma once

#include "vectors.hpp"
#include <QString>
#include <QList>
#include <QColor>

class Element {
protected:
    Element() = default;
public:
    virtual ~Element() = default;
};

class ProcessElement : public Element {
public:
    Vec2 position;
    Vec2 size;
    QString text;
    int textSize;
    QColor foreground;
    QColor background;
    int lineWidth;
public:
    ProcessElement() : position(), size(), text(), textSize(), foreground(), background(), lineWidth() {}
    ~ProcessElement() override = default;
};

class StreamElement : public Element {
public:
    QList<Vec2> points;
    QColor color;
    int lineWidth;
public:
    StreamElement() : points(), color(), lineWidth() {}
    ~StreamElement() override = default;
};

class SquiggleElement : public Element {
public:
    Vec2 startPos;
    Vec2 endPos;
    QString text;
    int textSize;
    QColor color;
public:
    SquiggleElement() : startPos(), endPos(), text(), textSize(), color() {}
    ~SquiggleElement() override = default;
};

class TextElement : public Element {
public:
    Vec2 position;
    QString text;
    int textSize;
    QColor color;
public:
    TextElement() : position(), text(), textSize(), color() {}
    ~TextElement() override = default;
};
