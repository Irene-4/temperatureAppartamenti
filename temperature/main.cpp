#include <iostream>
#include "test.h"
using namespace std;

int main() {
    float m[APP][GIORNI];
    int scelta;
    bool datiInseriti = false;   // indica se la matrice contiene dati validi

    do {
        cout << "\nMENU\n";
        cout << "1. Inserire consumi\n";
        cout << "2. Visualizzare tabella\n";
        cout << "3. Totale appartamento\n";
        cout << "4. Salva su CSV\n";
        cout << "5. carica da CSV\n";

        cout << "0. Esci\n";
        cout << "Scelta: ";

        cin >> scelta;

        switch (scelta) {

            case 1:
                inserisciConsumi(m);
                datiInseriti = true;
                break;

            case 2:
                if (!datiInseriti) {
                    cout << "Inserire prima i dati oppure caricarli da CSV\n";
                } else {
                    mostraTabella(m);
                }
                break;

            case 3:
                if (!datiInseriti) {
                    cout << "Inserire prima i dati oppure caricarli da CSV\n";
                } else {
                    totaleAppartamento(m);
                }
                break;

            case 4:
                if (!datiInseriti) {
                    cout << "Inserire prima i dati oppure caricarli da CSV\n";
                } else {
                    salvaCsv(m);
                }
                break;

            case 5:
                leggiCsv(m);
                datiInseriti=true;
                break;

            case 0:
                cout << "Uscita\n";
                break;

            default:
                cout << "Scelta non valida\n";
        }

    } while (scelta != 0);

    return 0;
}