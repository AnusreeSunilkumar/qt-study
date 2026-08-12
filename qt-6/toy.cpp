#include "toy.h"
#include <QDebug>

Toy::Toy(QObject *parent)
    : QObject{parent}
{
    qInfo() << "Constructed" << this;
}

Toy::~Toy()
{
    qInfo() << "Deconstructed" << this;
}
