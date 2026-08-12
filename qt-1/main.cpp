/*
 *
 * QObject - base class of everything
 * Q_OBJECT Macro - tells MOC to convert the class into a true object
 * Signals and slots - Easy communication between QObjects
 *
 */


#include <QCoreApplication>
#include "test.h"

void lifecycle()
{
    Test t;
}

void notifications()
{
    Test mom;
    Test child;
    mom.setObjectName("Mom");
    child.setObjectName("Child");
    qDebug() << &mom;
    qDebug() << &child;

    QObject::connect(&mom, &Test::alarm, &child, &Test::wake, Qt::AutoConnection);
    mom.testing();
    // child.wake("Now!!!");

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // lifecycle();
    notifications();

    return a.exec();
}
