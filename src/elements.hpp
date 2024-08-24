
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
    QColor color;
    int lineWidth;
public:
    ProcessElement() : position(), size(), text(), textSize(), color(), lineWidth() {}
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
public:
    SquiggleElement() : startPos(), endPos(), text(), textSize() {}
    ~SquiggleElement() override = default;
};

class TextElement : public Element {
public:
    Vec2 position;
    QString text;
    int textSize;
public:
    TextElement() : position(), text(), textSize() {}
    ~TextElement() override = default;
};
