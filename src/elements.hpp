
#pragma once

#include "vectors.hpp"
#include <QString>
#include <QList>
#include <QColor>

class Element {
public:
    enum Type {PROCESS, STREAM, SQUIGGLE, TEXT};
private:
    Type mType;
protected:
    explicit Element(Type type) : mType(type) {}
public:
    virtual ~Element() = default;
    Type type() { return mType; }
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
    ProcessElement() : Element(Type::PROCESS), position(), size(), text("Process"), textSize(12), foreground(0, 0, 0), background(255, 255, 255), lineWidth(1) {}
    ~ProcessElement() override = default;
};

class StreamElement : public Element {
public:
    QList<Vec2> points;
    QColor color;
    int lineWidth;
public:
    StreamElement() : Element(Type::STREAM), points(), color(), lineWidth() {}
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
    SquiggleElement() : Element(Type::SQUIGGLE), startPos(), endPos(), text(), textSize(), color() {}
    ~SquiggleElement() override = default;
};

class TextElement : public Element {
public:
    Vec2 position;
    QString text;
    int textSize;
    QColor color;
public:
    TextElement() : Element(Type::TEXT), position(), text(), textSize(), color() {}
    ~TextElement() override = default;
};
