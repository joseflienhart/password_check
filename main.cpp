#include <QApplication>
#include <QPushButton>

#include "hauptfenster.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    //Objekt aus Klasse erstellen
    Hauptfenster fenster;
    fenster.show();

    return app.exec();
}
