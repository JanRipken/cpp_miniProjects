#include "../header/buch.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

int auswahlAusgabe() {
  using namespace std;
  int auswahl{};
  cout << "==========================================\n";
  cout << "Was soll getan werden ?\n";
  cout << "Neues Buch: 1\n";
  cout << "Buch Löschen: 2\n";
  cout << "Buch Bearbeiten: 3\n";
  cout << "Liste Anzeigen: 4\n";
  cout << "Programm Ende: 5\n";
  cout << "==========================================\n";
  cin >> auswahl;
  cout << "\n";

  switch (auswahl) {
  case 1:
    return 1;
    break;
  case 2:
    return 2;
    break;
  case 3:
    return 3;
    break;
  case 4:
    return 4;
    break;
  case 5:
    return 5;
    break;
  }
  return 0;
}

buch neuesBuch() {
  buch newBook{};
  std::string title{};
  std::string author{};
  int seitenzahl{};
  double wertung{};
  bool gelesen{};

  std::cout << "==========================================\n";
  std::cout << "Informationen zum Buch\n";
  std::cout << "\n";
  std::cout << "Titel: ";
  std::cin >> title;
  std::cout << "Author: ";
  std::cin >> author;
  std::cout << "Seitenzahl: ";
  std::cin >> seitenzahl;
  std::cout << "Wertung: ";
  std::cin >> wertung;
  std::cout << "Gelesen: ";
  std::cin >> gelesen;
  std::cout << "==========================================\n";

  newBook.setTitle(title);
  newBook.setAuthor(author);
  newBook.setSeitenzahl(seitenzahl);
  newBook.setWertung(wertung);
  newBook.setGelesen(gelesen);

  return newBook;
}

void buchLoeschen(std::vector<buch> &liste) {
  std::cout << "==========================================\n";
  std::cout << "Die Elemente im Vektor sind:\n";
  for (int i = 0; i < liste.size(); i++) {
    std::cout << i << " " << liste[i].getTitel() << liste[i].getAuthor()
              << std::endl;
  }
  std::cout << "Bitte geben Sie den Index des Elements ein, das Sie löschen "
               "möchten (-1 zum Beenden): ";
  int index;
  std::cin >> index;
  if (index == -1) {
    return;
  }
  if (index >= 0 && index < liste.size()) {
    liste.erase(liste.begin() + index);
    std::cout << "Element mit dem Index " << index << " wurde gelöscht."
              << std::endl;
  } else {
    std::cout << "Falscher Index." << std::endl;
  }
  std::cout << "==========================================\n";
}

void buchBearbeiten(std::vector<buch> &liste) {
  std::cout << "==========================================\n";
  std::cout << "Bücher in der Liste:\n";
  for (int i = 0; i < liste.size(); i++) {
    std::cout << i << ": " << liste[i].getTitel() << " von "
              << liste[i].getAuthor() << std::endl;
  }

  int index;
  std::cout << "Welches Buch möchten Sie bearbeiten? Bitte geben Sie die "
               "Nummer ein: ";
  std::cin >> index;

  if (index >= 0 && index < liste.size()) {
    std::cout << "Sie bearbeiten das Buch: " << liste[index].getTitel()
              << " von " << liste[index].getAuthor() << std::endl;

    std::cout << "Bitte geben Sie den neuen Titel ein: ";
    std::string newTitel;
    std::cin >> newTitel;
    liste[index].setTitle(newTitel);

    std::cout << "Bitte geben Sie den neuen Autor ein: ";
    std::string newAutor;
    std::cin >> newAutor;
    liste[index].setAuthor(newAutor);

    std::cout << "Bitte geben Sie die neue Seitenzahl an: ";
    int seitenzahl;
    std::cin >> seitenzahl;
    liste[index].setSeitenzahl(seitenzahl);

    std::cout << "Bitte geben Sie die neue Wertung an: ";
    double wertung;
    std::cin >> wertung;
    liste[index].setWertung(wertung);

    std::cout << "Bitte geben Sie die neue Wertung an: ";
    bool gelesen;
    std::cin >> gelesen;
    liste[index].setGelesen(gelesen);

    std::cout << "Das Buch wurde erfolgreich aktualisiert.\n";
  } else {
    std::cout << "Ungültige Nummer. Bitte versuchen Sie es erneut.\n";
  }

  std::cout << "==========================================\n";
}

void ausfuehren(int auswahl, std::vector<buch> &liste) {
  if (auswahl == 1) {
    liste.push_back(neuesBuch());
  }
  if (auswahl == 2) {
    buchLoeschen(liste);
  }
  if (auswahl == 3) {
    buchBearbeiten(liste);
  }
  if (auswahl == 4) {
    std::cout << "==========================================\n";
    std::cout << "Ihre Aktuelle Liste: \n";
    for (buch b : liste) {
      std::cout << b.getTitel() << "|" << b.getAuthor() << "|"
                << b.getSeitenzahl() << "|" << b.getWertung() << "|"
                << b.getGelesen() << "\n";
    }
    std::cout << "==========================================\n";
  }
}

int main(int argc, char *argv[]) {
  std::vector<buch> buchListe;
  int auswahl{};
  while (true) {

    auswahl = auswahlAusgabe();
    if (auswahl == 5) {
      break;
    } else {
      ausfuehren(auswahl, buchListe);
    }
  }

  return 0;
}
