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

void ausfuehren(int auswahl, std::vector<buch> &liste) {
  if (auswahl == 1) {
    liste.push_back(neuesBuch());
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
