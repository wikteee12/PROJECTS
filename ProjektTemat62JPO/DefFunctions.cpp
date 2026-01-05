#include "DefFunctions.h"


using namespace std;

void program_loop(map<shared_ptr<Product>, int>& summary, const vector<shared_ptr<Product>>& list, int *discount) //G³ówna pêtla programu
{
    int page = 1; //aktualnie wyœwietlana strona
    int elements_on_page = 5; //aktualnie wyœwietlana liczba elementów na stronie
    string command = ""; 
    string full_command = ""; 
    

    displayshop(list, page, elements_on_page);

    while (1)
    {
        
        cout << "Enter command: ";

        string full_command;

        getline(cin, full_command);

        stringstream ss(full_command);

        ss >> command; 

        if (command == "exit") //Wyjœcie z programu
        {   
            string trash;
            // Summary nie powinno przyjmowaæ argumentów
            if (ss >> trash) {
                cout << "Error -> Exit command takes no arguments!" << endl;
                system("pause");
                system("cls");
                displayshop(list, page, elements_on_page);
                continue;
            }

            cout << "Thanks for visiting out store" << endl;
            break;
        }
        else if ("add" == command) //Dodawanie produktów do koszyka
        {
            string id_str, qty_str;

 
            if (ss >> id_str >> qty_str) //weryfikacja iloœci argumentów w komendzie
            {

                string trash;
                if (ss >> trash) //sprawdzenie czy nie wystêpuje za du¿o argumentów w komendzie
                {
                    cout <<  "Error -> Too many arguments! Use format: add <id> <qty>"  << endl;
                    system("pause");
                    system("cls");
                    displayshop(list, page, elements_on_page);
                    continue;
                }

                // Walidacja czy to liczby 
                if (!isInteger(id_str) || !isInteger(qty_str))
                {
                    cout <<  "Error -> Incorrect argument!"  << endl;
                    system("pause");
                    system("cls");
                    displayshop(list, page, elements_on_page);
                    continue;
                }

                int number_of_product = stoi(id_str);
                int quantity = stoi(qty_str);

                // Weryfikacja sensu wpisanych wartoœci
                if (number_of_product <= 0 || quantity <= 0 || number_of_product > list.size())
                {
                    cout <<  "Error -> Invalid ID or Quantity."  << endl;
                    system("pause");
                    system("cls");
                    displayshop(list, page, elements_on_page);
                    continue;
                }

                if (summary.count(list[number_of_product - 1])) //sprawdzenie czy w koszuku ju¿ jest dany produkt
                {
                    summary.find(list[number_of_product - 1])->second += quantity; //jak jest to zwiêksz jego iloœæ
                }
                else
                {
                    summary[list[number_of_product - 1]] = quantity; //je¿eli produkt nie wystêpuje w koszyku do dodaj go do niego w odpowiedniej iloœci
                }

                cout <<  "Product added to cart!"  << endl;
                system("pause"); 
                system("cls");
                displayshop(list, page, elements_on_page);

            }
            else
            {
                //Walidacja iloœci elementów w komendzie
                cout <<  "Error -> Command requires 3 arguments! Format: add <id> <qty>"  << endl;
                system("pause");
                system("cls");
                displayshop(list, page, elements_on_page);
            }



        }
        else if ("rem" == command) //Usuwanie produktów z koszyka
        {
            string id_str, qty_str;

            // Sprawdzamy czy podano 2 argumenty
            if (ss >> id_str >> qty_str)
            {
                string trash;
                // Sprawdzamy czy nie podano za du¿o argumentów
                if (ss >> trash) {
                    cout << "Error -> Too many arguments! Use format: rem <id> <qty>" << endl;
                    system("pause");
                    system("cls");
                    displayshop(list, page, elements_on_page);
                    continue;
                }
                // Walidacja liczb
                if (!isInteger(id_str) || !isInteger(qty_str)) {
                    cout << "Error -> Incorrect argument!" << endl;
                    system("pause");
                    system("cls");
                    displayshop(list, page, elements_on_page);
                    continue;
                }

                int number_of_product = stoi(id_str);
                int quantity = stoi(qty_str);

                // Walidacja sensu podanych liczb
                if (number_of_product <= 0 || quantity <= 0 || number_of_product > list.size()) {
                    cout << "Error -> Invalid ID or Quantity." << endl;
                    system("pause");
                    system("cls");
                    displayshop(list, page, elements_on_page);
                    continue;
                }

                if (summary.count(list[number_of_product - 1])) //Sprawdzenie czy produkt jest w koszu
                {
                    summary.find(list[number_of_product - 1])->second -= quantity; //Je¿eli produkt znajduje siê w koszuku to zmniejsz jego iloœæ

                    if (summary.find(list[number_of_product - 1])->second <= 0) //Je¿eli produkt zosta³ ca³kowicie usuniêty to usuñ go z mapy
                    {
                        summary.erase(summary.find(list[number_of_product - 1]));
                        cout << "Item removed from cart completely." << endl;
                        system("pause");
                        system("cls");
                        displayshop(list, page, elements_on_page);
                    }
                    else {
                        cout << "Quantity updated." << endl;
                        system("pause");
                        system("cls");
                        displayshop(list, page, elements_on_page);
                    }
                }
                else
                {
                    cout << "Error -> This product is not in your cart." << endl;
                    system("pause");
                    system("cls");
                    displayshop(list, page, elements_on_page);
                }

            }



        }
        else if ("page" == command) //Wybór ogl¹danej strony
        {
            string page_str;
            string trash;
            //Walidacja iloœci argumentów je¿eli za ma³o to zwróæ b³¹d
            if (ss >> page_str)
            {  
                //Walidacja iloœci argumentów czy nie za du¿o
                if (ss >> trash) {
                    cout << "Error -> Too many arguments! Use format: page <number>" << endl;
                    system("pause");
                    system("cls");
                    displayshop(list, page, elements_on_page);
                    continue;
                }
                // Walidacja czy to liczba 
                if (!isInteger(page_str)) {
                    cout << "Error -> Incorrect argument!" << endl;
                    system("pause");
                    system("cls");
                    displayshop(list, page, elements_on_page);
                    continue;
                }

                int page_h = stoi(page_str); //Przekonwertowanie na typ int wpisanej z klawiatury strony
                int possible_pages = (list.size() + elements_on_page - 1) / elements_on_page; //Liczba mo¿liwych stron

                if (page_h <= 0 || page_h > possible_pages) //Walidacja czy istnieje taka strona 
                {
                    cout << "Error -> Page out of range (1 - " << possible_pages << ")" << endl;
                    system("pause");
                    system("cls");
                    displayshop(list, page, elements_on_page);
                    continue;
                }

                page = page_h; //Je¿eli strona przesz³a walidacje ustaw j¹ jako aktualnie ogl¹dan¹
                system("cls");
                displayshop(list, page, elements_on_page);
            }
            else {
                cout << "Error -> Command requires page number! Format: page <number>" << endl;
                system("pause");
                system("cls");
                displayshop(list, page, elements_on_page);
            }
        }  
        else if ("eop" == command) //Ustaw liczbê elementów na stronie
        {
            string eop_str;
            string trash;

            if (ss >> eop_str) //Walidacja czy nie wprowadzono za ma³o argumentów
            {
                if (ss >> trash) //Walidacja czy nie wprowadzono za du¿o argumentów
                {
                    cout << "Error -> Too many arguments! Use format: eop <number>" << endl;
                    system("pause");
                    system("cls");
                    displayshop(list, page, elements_on_page);
                    continue;
                }
                //Walidacja czy liczba elementów wprowadzona jest liczb¹ ca³kowit¹
                if (!isInteger(eop_str)) 
                {
                    cout << "Error -> Incorrect argument!" << endl;
                    system("pause");
                    system("cls");
                    displayshop(list, page, elements_on_page);
                    continue;
                }

                int eop_h = stoi(eop_str);
                //Walidacja logiczna
                if (eop_h <= 0 || eop_h > list.size()) 
                {
                    cout << "Error -> Invalid number of elements." << endl;
                    system("pause");
                    system("cls");
                    displayshop(list, page, elements_on_page);
                    continue;
                }

                elements_on_page = eop_h;
                page = 1; // Ustawiamy pierwsz¹ stronê, ¿eby nie wyjœæ poza zakres

                system("cls");
                displayshop(list, page, elements_on_page);
            }
            else {
                cout << "Error -> Command requires a number! Format: eop <number>" << endl;
                system("pause");
                system("cls");
                displayshop(list, page, elements_on_page);
            }
        }
        else if ("summary" == command) //Wypisz podsumowanie 
        {   
            string trash;
            // Summary nie powinno przyjmowaæ argumentów
            if (ss >> trash) {
                cout << "Error -> Summary command takes no arguments!" << endl;
                system("pause");
                system("cls");
                displayshop(list, page, elements_on_page);
                continue;
            }

            system("cls");
            cout << "       ____  _   _   ___   ____  ____  ___  _   _   ____       ____    _    ____  _____" << endl;
            cout << "      / ___|| | | | / _ \\ |  _ \\|  _ \\|_ _|| \\ | | / ___|     / ___|  / \\  |  _ \\|_   _|" << endl;
            cout << "      \\___ \\| |_| || / \\ || |_) | |_) || | |  \\| || |  _     | |     / _ \\ | |_) | | |" << endl;
            cout << "       ___) |  _  || \\_/ ||  __/|  __/ | | | |\\  || |_| |    | |___ / ___ \\|  _ <  | |" << endl;
            cout << "      |____/|_| |_| \\___/ |_|   |_|   |___||_| \\_| \\____|     \\____/_/   \\_\\_| \\_\\ |_|" << endl;
            cout << endl;
            cout << " |============================================================================================|" << endl;
            cout << " | " << right << setw(4) << "ID"          
                << " | " << right << setw(35) << "NAME"       
                << " | " << right << setw(6) << "Qty."        
                << " | " << right << setw(10) << "BR. UNIT"        
                << " | " << right << setw(10) << "NET. UNIT"         
                << " | " << right << setw(10) << "TOTAL BR."
               
                << " |" << endl;
            cout << " |--------------------------------------------------------------------------------------------|" << endl;

            float bruttoprice = 0;
            float nettoprice = 0;

            for (auto element : summary)  //Wypisywanie produktów w podsumowaniu
            {
                auto it = find(list.begin(), list.end(), element.first); //Szukaj iteratora w wektorze na dany wskaŸnik (potrzebne do okreœlenia ID produktu)

                cout << " | " << setw(4) << distance(list.begin(), it + 1) << " | " << setw(35) << element.first->get_name()
                    << " | " << setw(6) << element.second << " | " << setw(10) << element.first->get_bruttoprice()
                    << " | " << setw(10) <<  element.first->get_nettoprice() << " | " << setw(10) << element.first->get_bruttoprice() * element.second << " | " << endl; //Wypisywanie produktów w podsumowaniu

                nettoprice += element.first->get_nettoprice() * element.second; //Zsumuj cene netto
                bruttoprice += element.first->get_bruttoprice() * element.second; //Zsumuj cene brutto
            }

            cout << " |============================================================================================|" << endl;
            cout << " | " << setw(80) << "Summary netto price: "<< setw(10) << nettoprice << " |" << endl << " |" << setw(93) << " |" << endl;
           
            cout << " | " << setw(80) << "Summary brutto price: " << setw(10) << bruttoprice << " |"  << endl;
            cout << " |============================================================================================|" << endl;

            if (*discount != 0) //Je¿eli wpisany zosta³ kod promocyjny uwzglêdnij go
            {   
                float dis = static_cast<float>(*discount) / 100;
                cout << " | " << setw(19) << left << "Promocode activated : "  << *discount << "% discount" << setw(58) << right << " |" << endl;
                cout << " |============================================================================================|" << endl;
                cout << " | " <<  setw(80)  << "Summary netto price: " << setw(10) << nettoprice * (1- dis) << " |" << endl << " |" << setw(93) << " |" << endl;

                cout << " | " << setw(80) << "Summary brutto price: " << setw(10) << bruttoprice * (1 - dis) << " |" << endl;
                cout << " |============================================================================================|" << endl;
            }

            cout << "Press any key to go back to shop" << endl;
            system("pause > nul");
          
            system("cls");
            displayshop(list, page, elements_on_page);
        }
        else if ("clear" == command) //Wyczyœæ koszyk
        {
            string trash;
            //Operacja nie przyjmuje argumentów (sprawdzenie)
            if (ss >> trash) {
                cout << "Error -> Clear command takes no arguments!" << endl;
                system("pause");
                system("cls");
                displayshop(list, page, elements_on_page);
                continue;
            }

            summary.clear(); //Czyszczenie mapy (koszyka)
            cout << "Cart cleared!" << endl;
            system("pause"); 

            system("cls");
            displayshop(list, page, elements_on_page);
            }
        else if ("discount" == command) //Naliczanie zni¿ki oraz jej usuwanie
        {
            string trash;
            string code_input;
            //Walidacja czy komenda zawiera³a minimum 2 argumenty
            if (ss >> code_input)
            {   
                // Walidacja czy komenda nie posiada³a za du¿o argumentów (wiêcej ni¿ 2)
                if (ss >> trash) {
                    cout << "Error -> Too many arguments! Use format: discount <promocode>" << endl;
                    system("pause");
                    system("cls");
                    displayshop(list, page, elements_on_page);
                    continue;
                }
                //Sprawdzanie czy podano prawid³owy kod promocyjny
                if (code_input == "promo1") //kod promocyjny
                {
                    cout << "That promocode gives you 10% discount" << endl;
                    *discount = 10;
                    system("pause");
                    system("cls");
                    displayshop(list, page, elements_on_page);
                    continue;
                }
                else if (code_input == "promo2") // kod promocyjny
                {
                    cout << "That promocode gives you 20% discount" << endl;
                    *discount = 20;
                    system("pause");
                    system("cls");
                    displayshop(list, page, elements_on_page);
                    continue;
                }
                //Usuñ kod z podsumowania
                else if (code_input == "clear")
                {
                    cout << "Promocode has been deleted" << endl;
                    *discount = 0;
                    system("pause");
                    system("cls");
                    displayshop(list, page, elements_on_page);
                    continue;
                }
                else
                {
                    cout << "Promocode not found" << endl;
                    system("pause");
                    system("cls");
                    displayshop(list, page, elements_on_page);
                    continue;
                }

            }
            else {
                cout << "Error -> Command requires promo code! Format: discount <promocode>" << endl;
                system("pause");
                system("cls");
                displayshop(list, page, elements_on_page);
            }
        }
        else //Nie znaleziono komendy
        {
            system("cls");
            displayshop(list, page, elements_on_page);
            cout << "No command found" << endl;
            continue;
        }

    }
} 

void displayshop(const vector<shared_ptr<Product>>& list,int page,int elements_on_page) //Wypisywanie sklepu
{

    cout << "       ____  _    _  ___  ____  " << endl;
    cout << "      / ___|| |  | |/ _ \\|  _ \\ " << endl;     
    cout << "      \\___ \\| |__| | | | | |_) |" << endl;
    cout << "       ___) |  __  | |_| |  __/ " << endl;
    cout << "      |____/|_|  |_|\\___/|_|    " << endl << endl;
    cout << "========================================" << endl;


	for (int i = (page - 1) * elements_on_page;i < (elements_on_page * page); i++) //Wypisywanie odpowiedniej iloœci elementów na stronie
	{
		if (i == list.size())
		{
			break;
		}
		cout << i+1 << ")";
		list[i]->display();
	}
   
    cout << " PAGE: " << page << "  (PRODUCTS: " << list.size() << ")" << endl;
    cout << "========================================" << endl << endl;
   
    cout << " AVAILABLE COMMANDS:" << endl;
    cout << " " <<  "add <id> <qty>"  << "  - Add item to cart" << endl;
    cout << " " <<  "rem <id> <qty>"  << "  - Remove item from cart" << endl;
    cout << " " <<  "page <num>" <<  "      - Go to specific page" << endl;
    cout << " " <<  "eop <num>" <<  "       - Set items per page" << endl;
    cout << " " <<  "summary" <<  "         - Show cart summary" << endl;
    cout << " " << "clear" << "           - Clear your cart history" << endl;
    cout << " " << "discount <code>" << " - Add promocode" << endl;
    cout << " " << "discount clear" << "  - Clear promocode" << endl;
     cout << " " <<  "exit" <<  "            - Quit application" << endl;
    cout << "____________________________________________________________" << endl;
}

void load_database(string database_name, vector<shared_ptr<Product>>& list) //Do³¹czenie do programu predefiniowanej listy przedmiotów w sklepie i tworzenie obiektów (przedmiotów)
{
	ifstream file(database_name);
	
	string item_data;

	try 
	{
		if (file.is_open() == 0) //Jeœli plik nie otworzy siê zg³oœ wyj¹tek
		{
			throw ifstream::failure("No database with this name exsists");
		}

		int iterator = 0;

		while (getline(file, item_data)) //Dynamiczne tworzenie obiektów na podstawie bazy danych
		{	
			if (item_data.empty()) continue; //pomiñ puste linijki w bazie danych

			iterator++;
			stringstream ss(item_data);

			char type;

			ss >> type;

			switch (type) //Wybór typu obiektu na podstawie 1 litery w ka¿dej linijce pliku bazy danych
			{	
				case 'C': //Ubrania
				{	
					string name; float nettoprice; float bruttoprice; int size; string material; string colour; //zmienne pomocnicze

					ss >> name >> nettoprice >> bruttoprice >> size >> material >> colour; //wpisanie kolejnych danych zlini do zmiennych pomocniczych

					if (ss.fail())
					{
						cout << "Error in the line " << iterator << " in data base" << endl; //pomija linie w których s¹ z³e typy danych i powiadamia o tym u¿ytkownika
					}
					else
					{
						list.push_back(make_unique<Clothes>(name, nettoprice, bruttoprice, size, material, colour)); //dodawanie do listy wskaŸników dynamicznie stworzonej klasy
					}
					break;
				}

				case 'E': //Elektronika
				{
					string name; float nettoprice; float bruttoprice; string brand; string model; int warranty_months; //zmienne pomocnicze

					ss >> name >> nettoprice >> bruttoprice >> brand >> model >> warranty_months; //wpisanie kolejnych danych zlini do zmiennych pomocniczych
					if (ss.fail())
					{
						cout << "Error in the line " << iterator << " in data base" << endl; //pomija linie w których s¹ z³e typy danych i powiadamia o tym u¿ytkownika
					}
					else
					{

						list.push_back(make_unique<Electronics>(name, nettoprice, bruttoprice, brand, model, warranty_months)); //dodawanie do listy wskaŸników dynamicznie stworzonej klasy
					}
					break;
				}
                case 'F': //Furniture
                {
                    string name; float nettoprice; float bruttoprice; string material; string dimensions; string color; //zmienne pomocnicze

                    ss >> name >> nettoprice >> bruttoprice >> material >> dimensions >> color; //wpisanie kolejnych danych zlini do zmiennych pomocniczych
                    if (ss.fail())
                    {
                        cout << "Error in the line " << iterator << " in data base" << endl; //pomija linie w których s¹ z³e typy danych i powiadamia o tym u¿ytkownika
                    }
                    else
                    {

                        list.push_back(make_unique<Furniture>(name, nettoprice, bruttoprice, material, dimensions, color)); //dodawanie do listy wskaŸników dynamicznie stworzonej klasy
                    }
                    break;
                }
                case 'B': //Books
                {
                    string name; float nettoprice; float bruttoprice; string author; string isbn; int pages; //zmienne pomocnicze

                    ss >> name >> nettoprice >> bruttoprice >> author >> isbn >> pages; //wpisanie kolejnych danych zlini do zmiennych pomocniczych
                    if (ss.fail())
                    {
                        cout << "Error in the line " << iterator << " in data base" << endl; //pomija linie w których s¹ z³e typy danych i powiadamia o tym u¿ytkownika
                    }
                    else
                    {

                        list.push_back(make_unique<Book>(name, nettoprice, bruttoprice, author, isbn, pages)); //dodawanie do listy wskaŸników dynamicznie stworzonej klasy
                    }
                    break;
                }
                case 'T': //Toys
                {
                    string name; float nettoprice; float bruttoprice; int min_age; string material; string type; //zmienne pomocnicze

                    ss >> name >> nettoprice >> bruttoprice >> min_age >> material >> type; //wpisanie kolejnych danych zlini do zmiennych pomocniczych
                    if (ss.fail())
                    {
                        cout << "Error in the line " << iterator << " in data base" << endl; //pomija linie w których s¹ z³e typy danych i powiadamia o tym u¿ytkownika
                    }
                    else
                    {

                        list.push_back(make_unique<Toys>(name, nettoprice, bruttoprice, min_age, material, type)); //dodawanie do listy wskaŸników dynamicznie stworzonej klasy
                    }
                    break;
                }

				default:
				{
					cout << "Badly defined product in line " << iterator << " in data base" << endl;
					break;
				}
				
			}
		}

		file.close();
	}
	catch (const ifstream::failure& error) // je¿eli nie istnieje taki plik to program siê koñczy
	{
		cout << error.what() << endl;
		exit(0);
	}
}

bool isInteger(const string& isint) //sprawdzenie czy liczba jest typu integer
{
    if (isint.empty()) return false;
    for (char c : isint)
    {
        if (!isdigit(c)) return false; 
    }
    return true;
}

void save_summary(const map<shared_ptr<Product>, int>& summary, const vector<shared_ptr<Product>>& list,int *discount) //zapisanie podsumowania do pliku(zni¿ka,koszyk)
{
    ofstream file("history_summary.txt");

    file << summary.size() << " "; //na poczatku wypisz liczbe produktów

    for (auto element : summary)
    {
        
        auto it = find(list.begin(), list.end(), element.first); //szuka iteratora w wektorze na dany wskaŸnik
        file << distance(list.begin(), it) << " "; //zapisanie numeru produktu
        file << element.second << " "; //zapisanie iloœci produktów
    }
    file << *discount; //zapisanie zni¿ki w pliku na samym koñcu

        file.close();
}

void load_summary(map<shared_ptr<Product>, int>& summary, const vector<shared_ptr<Product>>& list,int *discount) //odczytanie podsumowania z pliku (zni¿ka,koszyk)
{
    string data;

    try
    {
        ifstream file("history_summary.txt");

        if (file.is_open() == 0) //Sprawdzenie czy plik jest otwarty je¿eli nie to wyj¹tek
        {
            throw ifstream::failure("No history file with this name exsists"); 
        }

        getline(file, data);

        stringstream ss(data);

        int number_of_elements = 0;

        ss >> number_of_elements; // 1 element pliku to iloœæ produktów

        for (int i = 0; i < number_of_elements; i++)
        {   
          

            int quantity = 0;
            int address = 0;

            ss >> address >> quantity;

            summary[list[address]] = quantity; //na podstawie numeru przedmiotu z bazy danych wpis do mapy iloœci i wskaŸnika
             
        }
        ss >> *discount; // wczytanie na samym koñcu zni¿ki

        file.close();
    }

    catch (const ifstream::failure& error)
    {
        cout << error.what() << endl;
        exit(0); //Zamknij program
    }
}






