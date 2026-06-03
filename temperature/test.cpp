#include <iostream>
#include <fstream>
#include <sstream>
#include "test.h"



using namespace std;

void inserisciConsumi(float m[APP][GIORNI]) {
    for (int i = 0; i < APP; i++) {
        for (int j = 0; j < GIORNI; j++) {
            do {
                cout << "Consumo appartamento " << i << " giorno " << j << ": ";
                cin >> m[i][j];
            } while (m[i][j] < 0);
            //Il ciclo continua a chiedere il dato finché il valore inserito non è valido.
            //In questo caso, il valore è valido solo se è maggiore o uguale a zero.
            //  appartamento i
            //   giorno j
        }
    }
}


/*
La funzione riceve come parametro una matrice di numeri reali, cioè un array bidimensionale con APP righe e GIORNI colonne.
Le righe rappresentano gli appartamenti, mentre le colonne rappresentano i giorni.
Il ciclo esterno scorre gli appartamenti, cioè le righe della matrice.
Il ciclo interno scorre i giorni, cioè le colonne della matrice.
Per ogni appartamento e per ogni giorno, viene stampato il valore m[i][j], cioè il valore che si trova alla riga i e alla colonna j.
*/
void mostraTabella(float m[APP][GIORNI]) {
    for (int i = 0; i < APP; i++) {
        for (int j = 0; j < GIORNI; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}
void totaleAppartamento(float m[APP][GIORNI]) {
    int a;

    do {
        cout << "Inserisci appartamento (0 o 1): ";
        cin >> a;

        if (a != 0 && a != 1) {
            cout << "Valore non valido. Inserisci solo 0 oppure 1.\n";
        }

    } while (a != 0 && a != 1);

    float somma = 0;
    for (int j = 0; j < GIORNI; j++) {
        somma += m[a][j];
    }

    cout << "Totale: " << somma << endl;
}

void salvaCsv(float m[APP][GIORNI]) {
    //ofstream file;
    //file.open("consumi.csv");

    ofstream file("consumi.csv");
    if (!file) {
        cout <<"Errore nel salvataggio del file";
        return;
    }
    for (int i=0; i<APP;i++) {
        file << i;
        //scrive nel file il numero dell'appartamento
        for (int j=0;j<GIORNI;j++) {
            file << "," << m[i][j];
        } //scrive una virgola e poi il consumo del giorno j

        file << "\n";
        //finiti tutti i gironi di quell'appartamento,
        //va a capo e passa alla riga dell'appartamento successivo'
    }
    file.close();
    cout << "Dati salvati in consumi.csv";

}

void leggiCsv(float m[APP][GIORNI]) {
    ifstream file("consumi.csv");

    if (!file) {
        cout << "File non trovato!";
        return;
    }

    string riga;
    //variabile che conterrà una riga intera letta dal file

    for (int i=0; i<APP; i++) {
        if (!getline(file,riga)) {
            cout <<"Dati non presenti";
            file.close();
            return;
        }
        //getline = prova a leggere una riga del file
        //se non riesce, significa file vuoto
        if (riga == "") {
            cout << "Dati non presenti nel file";
            //se la riga letta è vuota no ci sono dati da caricare
            file.close();
            return;
        }

//Stringstream è una classe che permette di leggere da una stringa
//come se fosse un flusso di input.

        stringstream ss(riga);
//trasformo la riga in un flusso di lettura, in questo modo posso leggere
        // i valori una alla volta separati dalla virgola.

        string valore;
        //variabile temporanea che conterrà ogni singolo valore letto nel file

//----


        for (int j=0;j<GIORNI;j++) {
            if (!getline(ss,valore,',')){
                cout << "Dati non presenti";
                file.close();
                return;
            }

            if (valore == "") {
                cout << "Dati non presenti";
                file.close();
                return;
            }

            m[i][j]=stof(valore);
            //per trasformare la stringa in float
        }
    }
    file.close();
    cout << "Dati caricati da csv";

}
/*
*La classe stringstream serve per leggere una stringa come se fosse
un file.
I dati letti dal file CSV vengono inizialmente salvati come stringhe.
Con stringstream, la riga viene trasformata in un flusso da cui si
possono leggere i valori uno alla volta, separati dalla virgola.
Senza stringstream sarebbe più difficile dividere la riga nei
singoli valori.

Ci sono due cicli for perché la matrice è composta da righe e colonne:
APP = numero di appartamenti - righe
GIORNI = numero di giorni - colonne

Il primo for scorre le righe del file (gli appartamenti), mentre il secondo for scorre i valori presenti in ogni riga (i giorni).

==
Per flusso (“stream” in inglese) si intende una sequenza
di dati che viene letta un pezzo alla volta.
In C++ un flusso funziona come un “canale” da cui
il programma prende dati in ordine.

Esempi:
cin - flusso di input dalla tastiera
ifstream - flusso di input da un file
stringstream - flusso di input da una stringa

La funzione:
apre un file CSV,
legge i dati riga per riga,
separa i valori tramite le virgole,
converte i valori in numeri float,
li salva nella matrice m.
*/