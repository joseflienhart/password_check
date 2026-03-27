#ifndef HAUPTFENSTER_H
#define HAUPTFENSTER_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QProgressBar> // Neu: Für einen schicken Ladebalken/Ausschlag
#include <QTimer>       // Neu: Unsere unsichtbare Stoppuhr

class Hauptfenster : public QWidget {
    Q_OBJECT

public:
    Hauptfenster(QWidget *parent = nullptr);
    ~Hauptfenster();

private:
    QPushButton *first;
    QPushButton *second;
    QPushButton *third;
    QPushButton *fourth;
    QPushButton *fifth;

};

#endif // HAUPTFENSTER_H