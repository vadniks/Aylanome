
#pragma once

#include <QString>
#include <QList>
#include <glm/glm.hpp>

class Element {
protected:
    Element() = default;
public:
    virtual ~Element() = default;
};

class ProcessElement : public Element {
public:
    glm::ivec2 position;
    glm::ivec2 size;
    QString text;
    int textSize;
    glm::vec4 color;
    int lineWidth;
public:
    ProcessElement() : position(), size(), text(), textSize(), color(), lineWidth() {}
    ~ProcessElement() override = default;
};

class StreamElement : public Element {
public:
    QList<glm::ivec2> points;
    glm::vec4 color;
    int lineWidth;
public:
    StreamElement() : points(), color(), lineWidth() {}
    ~StreamElement() override = default;
};

class SquiggleElement : public Element {
public:
    glm::ivec2 startPos;
    glm::ivec2 endPos;
    QString text;
    int textSize;
public:
    SquiggleElement() : startPos(), endPos(), text(), textSize() {}
    ~SquiggleElement() override = default;
};

class TextElement : public Element {
public:
    glm::ivec2 position;
    QString text;
    int textSize;
public:
    TextElement() : position(), text(), textSize() {}
    ~TextElement() override = default;
};
