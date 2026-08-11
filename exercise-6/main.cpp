/*
 *
 * Sharing pointer among multiple objects
 *
 */


#include <QCoreApplication>
#include<QSharedPointer>
#include "cat.h"
#include "toy.h"
#include <vector>


void test()
{
    int max = 5;
    QSharedPointer<Toy> toy(new Toy());
    std::vector<QSharedPointer<Cat>> cats(max);
    for(int i = 0; i< max; i++)
    {
        cats[i].reset(new Cat());
        cats[i]->play(toy);
    }
    qInfo() << "All cats are done!";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test();
    return QCoreApplication::exec();
}
