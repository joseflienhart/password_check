#include "hauptfenster.h"
#include <QVBoxLayout>
#include <QHBoxLayout> // Neu: Ein Layout, das Dinge Horizontal (nebeneinander) anordnet
#include <QRandomGenerator> // Neu: Um Fake-Sensordaten zu generieren

Hauptfenster::Hauptfenster(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Sensor-Simulator");
    resize(400, 200);

    // Das horizontale Haupt-Layout (von oben nach unten)
    QHBoxLayout *hauptLayout = new QHBoxLayout(this);

        // Wir erstellen ein kleines vertikales Layout
        QVBoxLayout *unterLayout = new QVBoxLayout();

            // Wir erstellen ein noch untergeordnertes Layout
            QHBoxLayout *unterstes_Layout_1 = new QHBoxLayout();

            // Wir erstellen ein noch untergeordnertes Layout
            QHBoxLayout *unterstes_Layout_2 = new QHBoxLayout();

    unterstes_Layout_1->addWidget(first);
    unterstes_Layout_1->addWidget(second);
    unterstes_Layout_2->addWidget(third);
    unterstes_Layout_2->addWidget(fourth);

    hauptLayout->addWidget(fifth);
    hauptLayout->addLayout(unterLayout);
    unterLayout->addLayout(unterstes_Layout_1);
    unterLayout->addLayout(unterstes_Layout_2);

    first = new QPushButton("First");
    second = new QPushButton("Second");
    third = new QPushButton("Third");
    fourth = new QPushButton("Fourth");
    fifth = new QPushButton("Fifth");

}

Hauptfenster::~Hauptfenster() {
}