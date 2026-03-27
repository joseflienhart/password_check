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

private slots:
    // Wir brauchen jetzt drei eigene Funktionen
    void startSensor();
    void stopSensor();
    void leseDaten(); // Diese Funktion wird vom Timer aufgerufen

private:
    QLabel *wertLabel;
    QProgressBar *balken;
    QPushButton *startButton;
    QPushButton *stopButton;

    // Unser Timer als Member-Variable, damit wir ihn überall starten/stoppen können
    QTimer *sensorTimer;
};

#endif // HAUPTFENSTER_H