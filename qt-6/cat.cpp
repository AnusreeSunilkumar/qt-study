#include "cat.h"
#include <QDebug>

Cat::Cat(QObject *parent)
    : QObject{parent}
{
    qInfo() << "Constructed" << this;
}

Cat::~Cat()
{
     qInfo() << "Deconstructed" << this;
}

void Cat::play(QSharedPointer<Toy> toy)
{
    m_toy.swap(toy);
    qInfo() << this << "Playing with" << m_toy.data();
}
