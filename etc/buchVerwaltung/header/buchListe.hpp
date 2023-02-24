#include "buch.hpp"
#include <vector>
class buchListe {
public:
  void neuesBuch();
  void buchLoeschen();
  void buchBearbeiten();
  void printBuchListe();
  void dummyBuch();
  void speichernBuchListe();
  void einlesenBuchListe();

private:
  std::vector<buch> _buchListe;
};
