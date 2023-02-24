#include "../header/buchListe.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void buchListe::neuesBuch() {
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

  _buchListe.push_back(newBook);
}
void buchListe::buchLoeschen() {
  std::cout << "==========================================\n";
  std::cout << "Die Elemente im Vektor sind:\n";
  for (int i = 0; i < _buchListe.size(); i++) {
    std::cout << i << " " << _buchListe[i].getTitel()
              << _buchListe[i].getAuthor() << std::endl;
  }
  std::cout << "Bitte geben Sie den Index des Elements ein, das Sie löschen "
               "möchten (-1 zum Beenden): ";
  int index;
  std::cin >> index;
  if (index == -1) {
    return;
  }
  if (index >= 0 && index < _buchListe.size()) {
    _buchListe.erase(_buchListe.begin() + index);
    std::cout << "Element mit dem Index " << index << " wurde gelöscht."
              << std::endl;
  } else {
    std::cout << "Falscher Index." << std::endl;
  }
  std::cout << "==========================================\n";
}
void buchListe::buchBearbeiten() {
  std::cout << "==========================================\n";
  std::cout << "Bücher in der Liste:\n";
  for (int i = 0; i < _buchListe.size(); i++) {
    std::cout << i << ": " << _buchListe[i].getTitel() << " von "
              << _buchListe[i].getAuthor() << std::endl;
  }

  int index;
  std::cout << "Welches Buch möchten Sie bearbeiten? Bitte geben Sie die "
               "Nummer ein: ";
  std::cin >> index;

  if (index >= 0 && index < _buchListe.size()) {
    std::cout << "Sie bearbeiten das Buch: " << _buchListe[index].getTitel()
              << " von " << _buchListe[index].getAuthor() << std::endl;

    std::cout << "Bitte geben Sie den neuen Titel ein: ";
    std::string newTitel;
    std::cin >> newTitel;
    _buchListe[index].setTitle(newTitel);

    std::cout << "Bitte geben Sie den neuen Autor ein: ";
    std::string newAutor;
    std::cin >> newAutor;
    _buchListe[index].setAuthor(newAutor);

    std::cout << "Bitte geben Sie die neue Seitenzahl an: ";
    int seitenzahl;
    std::cin >> seitenzahl;
    _buchListe[index].setSeitenzahl(seitenzahl);

    std::cout << "Bitte geben Sie die neue Wertung an: ";
    double wertung;
    std::cin >> wertung;
    _buchListe[index].setWertung(wertung);

    std::cout << "Bitte geben Sie die neue Wertung an: ";
    bool gelesen;
    std::cin >> gelesen;
    _buchListe[index].setGelesen(gelesen);

    std::cout << "Das Buch wurde erfolgreich aktualisiert.\n";
  } else {
    std::cout << "Ungültige Nummer. Bitte versuchen Sie es erneut.\n";
  }

  std::cout << "==========================================\n";
}
void buchListe::printBuchListe() {
  std::cout << "==========================================\n";
  std::cout << "Ihre Aktuelle Liste: \n";
  for (buch b : _buchListe) {
    std::cout << b.getTitel() << "|" << b.getAuthor() << "|"
              << b.getSeitenzahl() << "|" << b.getWertung() << "|"
              << b.getGelesen() << "\n";
  }
  std::cout << "==========================================\n";
}

void buchListe::dummyBuch() {
  buch newBook;
  newBook.setTitle("Java");
  newBook.setAuthor("Meyer");
  newBook.setSeitenzahl(200);
  newBook.setWertung(10.4);
  newBook.setGelesen(true);
  _buchListe.push_back(newBook);
}
void buchListe::speichernBuchListe() {
  std::ofstream datei("data/liste.txt");
  if (datei.is_open()) {
    for (buch b : _buchListe) {
      datei << b.getTitel() << ";" << b.getAuthor() << ";" << b.getSeitenzahl()
            << ";" << b.getWertung() << ";" << b.getGelesen() << "\n";
    }
    datei.close();
    std::cout << "Buchliste erfolgreich gespeichert.\n";
  } else {
    std::cerr << "Fehler: konnte Datei nicht öffnen.\n";
  }
}

void buchListe::einlesenBuchListe() {
  std::ifstream file("data/liste.txt");
  if (!file.is_open()) {
    std::cerr << "Fehler beim Öffnen der Datei\n";
    return;
  }

  std::string line;
  while (std::getline(file, line)) {
    std::istringstream ss(line);
    std::string titel, author, seitenzahl_str, wertung_str, gelesen_str;

    if (!std::getline(ss, titel, ';')) {
      std::cerr << "Ungültige Zeile in der Datei: " << line << "\n";
      continue;
    }
    if (!std::getline(ss, author, ';')) {
      std::cerr << "Ungültige Zeile in der Datei: " << line << "\n";
      continue;
    }
    if (!std::getline(ss, seitenzahl_str, ';')) {
      std::cerr << "Ungültige Zeile in der Datei: " << line << "\n";
      continue;
    }
    if (!std::getline(ss, wertung_str, ';')) {
      std::cerr << "Ungültige Zeile in der Datei: " << line << "\n";
      continue;
    }
    if (!std::getline(ss, gelesen_str, ';')) {
      std::cerr << "Ungültige Zeile in der Datei: " << line << "\n";
      continue;
    }

    buch buch;
    buch.setTitle(titel);
    buch.setAuthor(author);

    try {
      buch.setSeitenzahl(std::stoi(seitenzahl_str));
    } catch (const std::invalid_argument &) {
      std::cerr << "Ungültige Seitenzahl in der Zeile: " << line << "\n";
      continue;
    }

    try {
      buch.setWertung(std::stod(wertung_str));
    } catch (const std::invalid_argument &) {
      std::cerr << "Ungültige Wertung in der Zeile: " << line << "\n";
      continue;
    }

    if (gelesen_str == "1") {
      buch.setGelesen(true);
    } else if (gelesen_str == "0") {
      buch.setGelesen(false);
    } else {
      std::cerr << "Ungültiger Wert für gelesen in der Zeile: " << line << "\n";
      continue;
    }

    _buchListe.push_back(buch);
  }
}
