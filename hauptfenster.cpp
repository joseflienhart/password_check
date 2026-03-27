#include "hauptfenster.h"
#include <QVBoxLayout>
#include <QHBoxLayout> // Neu: Ein Layout, das Dinge Horizontal (nebeneinander) anordnet
#include <QRandomGenerator> // Neu: Um Fake-Sensordaten zu generieren

Hauptfenster::Hauptfenster(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Sensor-Simulator");
    resize(400, 200);

    // Das vertikale Haupt-Layout (von oben nach unten)
    QVBoxLayout *hauptLayout = new QVBoxLayout(this);

    wertLabel = new QLabel("Aktueller Wert: 0");
    wertLabel->setAlignment(Qt::AlignCenter);
    hauptLayout->addWidget(wertLabel);

    // Eine Fortschrittsanzeige erstellen
    balken = new QProgressBar();
    balken->setRange(0, 100); // Der Sensor misst Werte von 0 bis 100
    balken->setValue(0);
    hauptLayout->addWidget(balken);

    // --- Layout-Trick: Buttons nebeneinander ---
    // Wir erstellen ein kleines horizontales Layout (links nach rechts)
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    startButton = new QPushButton("Start");
    stopButton = new QPushButton("Stopp");
    stopButton->setEnabled(false); // Stopp ist am Anfang ausgegraut

    // Buttons in das kleine Layout packen
    buttonLayout->addWidget(startButton);
    buttonLayout->addWidget(stopButton);

    // Das kleine horizontale Layout in das große vertikale Layout packen
    hauptLayout->addLayout(buttonLayout);


    // --- Der Timer ---
    // Wir erschaffen den Timer und geben ihm das Fenster als Elternteil (this)
    sensorTimer = new QTimer(this);


    // --- Die Verbindungen (Kabel verlegen) ---
    connect(startButton, &QPushButton::clicked, this, &Hauptfenster::startSensor);
    connect(stopButton, &QPushButton::clicked, this, &Hauptfenster::stopSensor);

    // MAGIE: Wenn der Timer "abläuft", rufen wir "leseDaten" auf
    connect(sensorTimer, &QTimer::timeout, this, &Hauptfenster::leseDaten);
}

Hauptfenster::~Hauptfenster() {
}

void Hauptfenster::startSensor() {
    // Timer starten! Er tickt jetzt alle 500 Millisekunden (0,5 Sekunden)
    sensorTimer->start(500);

    // Buttons umschalten
    startButton->setEnabled(false);
    stopButton->setEnabled(true);
}

void Hauptfenster::stopSensor() {
    // Timer anhalten
    sensorTimer->stop();

    // Buttons zurücksetzen
    startButton->setEnabled(true);
    stopButton->setEnabled(false);
}

void Hauptfenster::leseDaten() {
    // Hier würden wir später echte Linux-Systemdateien auslesen.
    // Für heute simulieren wir die Hardware mit einer Zufallszahl zwischen 0 und 100.
    int sensorWert = QRandomGenerator::global()->bounded(0, 101);

    // Die GUI mit den neuen Daten aktualisieren
    wertLabel->setText("Aktueller Wert: " + QString::number(sensorWert));
    balken->setValue(sensorWert);
}