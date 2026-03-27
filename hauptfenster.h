//
// Created by joseflienhart on 27.03.26.
//

#ifndef UNTITLED_HAUPTFENSTER_H
#define UNTITLED_HAUPTFENSTER_H
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>


class hauptfenster : public QWidget {
    /////////////////////////////////////Wichtiges Makro!!!!!
    Q_OBJECT

public:
    //Konstruktor und Destruktor
    hauptfenster(QWidget* parent = nullptr);
    ~hauptfenster();

    //Definition von Slots als eigene Funktionen auf Reaktionen von Eingaben
private slots:
    void rueckgabe();

private:
    //Member_Variablen speichern:
    QLabel *aufforderung_m;
    QLineEdit *eingabe_m;
    QPushButton *druckknopf_m;
    QLabel *ausgabe_m;
};

#endif //UNTITLED_HAUPTFENSTER_H
