#include "..//header/buch.hpp"

std::string buch::getAuthor() { return buchAuthor; };
void buch::setAuthor(std::string Author) { buchAuthor = Author; };

std::string buch::getTitel() { return buchTitel; };
void buch::setTitle(std::string Titel) { buchTitel = Titel; };

int buch::getSeitenzahl() { return buchSeitenanzahl; };
void buch::setSeitenzahl(int seitenzahl) { buchSeitenanzahl = seitenzahl; };

double buch::getWertung() { return buchWertung; };
void buch::setWertung(double wertung) { buchWertung = wertung; };

bool buch::getGelesen() { return buchGelesen; };
void buch::setGelesen(bool gelesen) { buchGelesen = gelesen; };
