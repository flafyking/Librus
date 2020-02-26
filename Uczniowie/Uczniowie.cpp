#include "pch.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

	//10 rekordow - zrobione
	// uzuplenianie danych - zrobione
	// wyswietlenie danych - zrobione
	// srednia z wszystkich przedmiotow ucznia - zrobione
	// srednia poszczegolnego przedmiotu - zrobione


	int test,xd;
	int licznik, nrDziennika;
	float suma;
	float srednia;
	int licz;


	class Uczen {
	public:
		string Imie;
		string Nazwisko;
		string Klasa;
		int MatOceny[4];
		int PrzyrodaOceny[4];
		int PolskiOceny[4];
		int AngOceny[4];
		int WFOceny[4];
		Uczen(string Imie, string Nazwisko, string Klasa);

	};

	vector < Uczen > tab;
	int x = 0;

	int Uzupelnienie() {
		string Imie, Nazwisko, Klasa;
		cout << "Podaj imie ucznia: ";
		cin >> Imie;
		cout << "Podaj nazwisko ucznia: ";
		cin >> Nazwisko;
		cout << "Podaj klase ucznia: ";
		cin >> Klasa;
		Uczen *uczen1 = new Uczen(Imie, Nazwisko, Klasa);
		tab.push_back(*uczen1);
		delete uczen1;
		return 0;
	};
	int LosowanieOcen() {
		return ((std::rand() % 6) + 1);
	}

		int Wyswietl(int nrDziennika) {
			cout << tab[nrDziennika].Imie << endl;
			cout << tab[nrDziennika].Nazwisko << endl;
			cout << tab[nrDziennika].Klasa << endl;
			cout << "Matematyka: ";
			for (int i = 0; i < 4; i++) {
				cout << "  " << tab[nrDziennika].MatOceny[i];
			}
			cout << endl;
			cout << "WF: ";
			for (int i = 0; i < 4; i++) {
				cout << "  " << tab[nrDziennika].WFOceny[i];
			}
			cout << endl;
			cout << "Angielski: ";
			for (int i = 0; i < 4; i++) {
				cout << "  " << tab[nrDziennika].AngOceny[i];
			}
			cout << endl;
			cout << "Przyroda: ";
			for (int i = 0; i < 4; i++) {
				cout << "  " << tab[nrDziennika].PrzyrodaOceny[i];
			}
			cout << endl;
			cout << "Polski: ";
			for (int i = 0; i < 4; i++) {
				cout << "  " << tab[nrDziennika].PolskiOceny[i];
			} 
			cout << endl;
			return 0;
		};
		Uczen::Uczen(string pmImie, string pmNazwisko, string pmKlasa) {
			Imie = pmImie;
			Nazwisko = pmNazwisko;
			Klasa = pmKlasa;
			for (int i = 0; i < 4; i++) {
				MatOceny[i] = LosowanieOcen();
				PrzyrodaOceny[i] = LosowanieOcen();
				PolskiOceny[i] = LosowanieOcen();
				AngOceny[i] = LosowanieOcen();
				WFOceny[i] = LosowanieOcen();
			}

		};
	
	float Srednia(int ocena[]) {
		srednia = 0;
		suma = 0;
		for (int i = 0; i < 4; i++) {
			suma += ocena[i];
		}
		return srednia = suma / 4;
	}
	
	int main(int argc, char** argv) {

		srand(time(NULL));

		Uczen uczen1("Andrzej", "Puder", "2c");
		tab.push_back(uczen1);
		
		Uczen uczen2("Kuba", "Zolw", "2c");
		tab.push_back(uczen2);
		Uczen uczen3("Kamil", "Slimak", "2c");
		tab.push_back(uczen3);
		Uczen uczen4("Mikolaj", "Pilot", "2c");
		tab.push_back(uczen4);
		Uczen uczen5("Natalia", "Lod", "2c");
		tab.push_back(uczen5);
		Uczen uczen6("Milosz", "Cichacz", "2c");
		tab.push_back(uczen6);
		Uczen uczen7("Marta", "Murarz", "2c");
		tab.push_back(uczen7);
		Uczen uczen8("Szymon", "Jaglany", "2c");
		tab.push_back(uczen8);
		Uczen uczen9("Anastazja", "Akordeon", "2c");
		tab.push_back(uczen9);
		Uczen uczen10("Geralt", "Zrovi", "2c");
		tab.push_back(uczen10);
	
		do{
			cout << "Wcisnij enter" << endl;
			_getch();
			
			system("CLS");
			cout << "------------------------------------------------------LIBRUS------------------------------------------------------" << endl;
			cout << endl;
			cout << "1. Dodac Nowego Ucznia" << endl;
			cout << "2. Wyświetlic wszystkich uczniow" << endl;
			cout << "3. Wyswietlic Dane Ucznia" << endl;
			cout << "4. Wyswietlic Srednia Ucznia" << endl;
			cout << "5. Wyswietlic Srednia Ucznia (konkretny przedmiot)" << endl;
			cout << "6. Zakonczyc program" << endl;
			cout << endl;
			cout << "Co chcesz zrobic?" << endl;
			cin >> test;
			cout << endl;

			switch (test) {
			case 1:
				system("CLS");
				Uzupelnienie();
				break;
			case 2:
				system("CLS");
				for (int i = 0; i < tab.size(); i++) {
					Wyswietl(i);
					cout << "------------------------------------------------------------------------------------------------------------------" << endl;
				}
				break;
			case 3:
				system("CLS");
				cout << "Wybierz numer z dziennika, ktorej dane maja byc wyswietlone (1 - " << tab.size() << "): " << endl;
				cin >> nrDziennika;
				Wyswietl(nrDziennika -1);
				break;
			case 4:
				system("CLS");
				cout << "Wybierz numer z dziennika, ktorej srednia z wszystkich przedmiotow ma byc wyswietlona (1 - " << tab.size() << "): " << endl;
				cin >> nrDziennika;
				cout << "Srednia z wszystkich przedmiotow ucznia " << tab[nrDziennika -1].Imie << " " << tab[nrDziennika -1].Nazwisko << ":";
				xd = (Srednia(tab[nrDziennika -1].MatOceny) + Srednia(tab[nrDziennika -1].AngOceny) + Srednia(tab[nrDziennika -1].WFOceny) + Srednia(tab[nrDziennika -1].PolskiOceny) + Srednia(tab[nrDziennika -1].PrzyrodaOceny)) / 5;
				cout << xd << endl;
				break;
			case 5:
				system("CLS");
				cout << "Wybierz numer z dziennika, ktorej srednia ma byc wyswietlona (1 - " << tab.size() << "): " << endl;
				cin >> nrDziennika;
				cout << endl;
				cout << "1.Matematyka" << endl;
				cout << "2.Angielski" << endl;
				cout << "3.WF" << endl;
				cout << "4.Polski" << endl;
				cout << "5.Przyroda" << endl;
				cout << endl;
				cout << "Z jakiego przedmiotu chcesz zobaczyc srednia? " << endl;
				cin >> test;
				cout << endl;
				cout << tab[nrDziennika -1].Imie << "  " << tab[nrDziennika -1].Nazwisko << endl;
				switch (test) {
				case 1:
					cout << "Matematyka: ";
					for (int i = 0; i < 4; i++) {
						cout << "  " << tab[nrDziennika -1].MatOceny[i];
					}
					cout << endl;
					cout << "Srednia: ";
					cout << Srednia(tab[nrDziennika -1].MatOceny) << endl;
					break;
				case 2:
					cout << "Angielski: ";
					for (int i = 0; i < 4; i++) {
						cout << "  " << tab[nrDziennika -1].AngOceny[i];
					}
					cout << endl;
					cout << "Srednia: ";
					cout << Srednia(tab[nrDziennika -1].AngOceny) << endl;
					break;
				case 3:
					cout << "WF: ";
					for (int i = 0; i < 4; i++) {
						cout << "  " << tab[nrDziennika -1].WFOceny[i];
					}
					cout << endl;
					cout << "Srednia: ";
					cout << Srednia(tab[nrDziennika -1].WFOceny) << endl;
					break;
				case 4:
					cout << "Polski: ";
					for (int i = 0; i < 4; i++) {
						cout << "  " << tab[nrDziennika -1].PolskiOceny[i];
					}
					cout << endl;
					cout << "Srednia: ";
					cout << Srednia(tab[nrDziennika -1].PolskiOceny) << endl;
					break;
				case 5:
					cout << "Przyroda: ";
					for (int i = 0; i < 4; i++) {
						cout << "  " << tab[nrDziennika -1].PrzyrodaOceny[i];
					}
					cout << endl;
					cout << "Srednia: ";
					cout << Srednia(tab[nrDziennika -1].PrzyrodaOceny) << endl;
					break;
				default:
					break;

				}
				break;
			case 6:
				licz = 1;
				break;
			default:
				break;
			}
		}
		while (licz == 0);
			

		return 0;
	}


