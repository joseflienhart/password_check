//
// Created by joseflienhart on 27.03.26.
//

#include "hauptfenster.h"
#include "hauptfenster.h"


//Konstruktor mit member-Initialisierungsliste: "QWidget *parent" ist Eingabeparameter, in "QWidget(parent) wird dieser verwendet
hauptfenster::hauptfenster(QWidget *parent) : QWidget(parent) {
    setWindowTitle("persönlicher Passwortmanager");
    resize(500,200);

    //this-Zeiger zeigt auf DIESES Fenster
    QVBoxLayout *layout = new QVBoxLayout(this);

    //Widgets erstellen und den Membern zuweisen:
    aufforderung_m= new QLabel("Geben Sie ihr Passwort ein:");
    layout->addWidget(aufforderung_m);

    eingabe_m = new QLineEdit();
    eingabe_m->setPlaceholderText("Ihr Passwort");
    layout->addWidget(eingabe_m);

    druckknopf_m = new QPushButton("bestaetigen");
    layout->addWidget(druckknopf_m);

    ausgabe_m = new QLabel("");
    layout->addWidget(ausgabe_m);

    //Der clou: Die Verbindung
    connect(druckknopf_m, &QPushButton::clicked, this, &hauptfenster::rueckgabe);
}

//Der Destruktor:
hauptfenster::~hauptfenster() {

}

//Die Slot-Funktion
void hauptfenster::rueckgabe() {
    //Variable definieren und Textfeld auslesen
    QString eingegebenes_passwort = eingabe_m->text();

    if (eingegebenes_passwort == "VdH2503/+()") {
        ausgabe_m->setText("Passwort ist korrekt!");
    }else if (eingegebenes_passwort == "") {
        ausgabe_m->setText("Bitte geben Sie ein gültiges Passwort ein!");
    }else {
        ausgabe_m->setText("Das Passwort ist nicht korrekt!");
    }
}