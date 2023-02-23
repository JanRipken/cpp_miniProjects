#include <string>
class buch {
public:
  std::string getAuthor();
  void setAuthor(std::string Author);

  std::string getTitel();
  void setTitle(std::string Title);

  int getSeitenzahl();
  void setSeitenzahl(int seitenzahl);

  double getWertung();
  void setWertung(double wertung);

  bool getGelesen();
  void setGelesen(bool gelesen);

private:
  std::string buchAuthor;
  std::string buchTitel;
  int buchSeitenanzahl;
  float buchWertung;
  bool buchGelesen;
};
