#include <iostream>
#include <string>

void mod(int &eingabe,int &summe){
	for (int i = 3 ;i<eingabe;++i) {
		if (i%3==0 &&i%5==0 ) {
			summe += i;	
			std::cout<<i<<std::endl;
		}
	}
}


int main(int argc, const char *argv[]){
	int eingabe{};
	if (argc>1) {
			eingabe = std::stoi(argv[1]);
	}
	else{
		std::cout<<"Bitte geben sie eine zahl eine Zahl als Grenze an"<<std::endl;
		std::cin>>eingabe;
		std::cout<<" "<<std::endl;
	}

	int summe = 0;
	mod(eingabe,summe);
	std::cout<<" "<<std::endl;
	std::cout<<"Die summe ist der Natürlichen Zahlen ist: "<<summe<<std::endl;
}
