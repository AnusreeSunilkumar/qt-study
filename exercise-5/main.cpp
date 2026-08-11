/*
 * QScopedPointer
 * QSharedPointer
 * Manual memory management is error prone
 */


#include <QCoreApplication>
#include <QScopedPointer>
#include <QSharedPointer>
#include "test.h"
#include <QDebug>

void test_1()
{
    QScopedPointer<Test> sp(new Test());
    sp.data() -> setObjectName("My test");

    qInfo() << "Scoped pointer" << &sp;
    qInfo() << "pointer data" << sp.data();
    qInfo() << sp->objectName();
}

QSharedPointer<Test> getObject(QString name)
{
    QSharedPointer<Test> sp(new Test());
    sp->setObjectName(name);
    return sp;
}

void doWork(QSharedPointer<Test> sp)
{
    qInfo() << "Work" << sp.data();
    qInfo() << "Sharedpointer" << &sp;
}

void test_2()
{
    qInfo() << "Getting the object";
    QSharedPointer<Test> ptr = getObject("My object");
    qInfo() << "Sharedpointer" << &ptr;
    qInfo() << "Object" << ptr.data();
    doWork(ptr);

    //reference countis zero
    qInfo() << "Complete";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    test_1();
    test_2();

    return QCoreApplication::exec();
}
