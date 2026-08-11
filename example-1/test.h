#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);
    ~Test();

    void testing();

signals:
    // always public
    // always defined
    // never implemented
    void alarm(QString noise);

public slots:
    // public, private or protected
    // always defined adn implemented
    // should match the signal
    void wake(QString noise);
};

#endif // TEST_H
