/*
 *
 * QObjects cannot be copied
 * the memory address is the object's identity
 *
 */

#include <QCoreApplication>
#include <QDebug>

void testPointer(QObject *obj)
{
    qInfo() << obj;
}

void testAddress(QObject &obj)
{
    qInfo() << &obj;
}

void testCopy(QObject obj)
{
    qInfo() << &obj;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject person;
    person.setObjectName("Anu");

    testPointer(&person);
    testAddress(person);
    // testCopy(person); // fails

    return QCoreApplication::exec();
}
