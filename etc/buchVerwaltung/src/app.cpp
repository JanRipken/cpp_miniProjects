#include "../header/buchListe.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

bool auswahlAusgabe(buchListe &_buchListe) {
  using namespace std;
  int auswahl{};
  cout << "==========================================\n";
  cout << "Was soll getan werden ?\n";
  cout << "Neues Buch: 1\n";
  cout << "Buch Löschen: 2\n";
  cout << "Buch Bearbeiten: 3\n";
  cout << "Liste Anzeigen: 4\n";
  cout << "Liste Speichern: 5\n";
  cout << "Liste Einlesen: 6\n";
  cout << "Programm Ende: 7\n";
  cout << "==========================================\n";
  cin >> auswahl;
  cout << "\n";

  switch (auswahl) {
  case 1:
    _buchListe.dummyBuch();
    //_buchListe.neuesBuch();
    break;
  case 2:
    _buchListe.buchLoeschen();
    break;
  case 3:
    _buchListe.buchBearbeiten();
    break;
  case 4:
    _buchListe.printBuchListe();
    break;
  case 5:
    _buchListe.speichernBuchListe();
    break;
  case 6:
    _buchListe.einlesenBuchListe();
    break;
  case 7:
    return false;
    break;
  }
  return true;
}

int main(int argc, char *argv[]) {
  buchListe _buchListe;
  bool runMenu = true;
  while (runMenu) {
    runMenu = auswahlAusgabe(_buchListe);
  }

  return 0;
}
