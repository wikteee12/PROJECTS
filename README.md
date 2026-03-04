# [cite_start]62. Shopping Cart Simulator [cite: 4]
[cite_start]Projekt z przedmiotu: Języki programowania obiektowego [cite: 5, 6]
[cite_start]Kierunek: Elektronika i Telekomunikacja, 3 rok [cite: 7]
[cite_start]Autor: Wiktor Baran [cite: 8]

---

## [cite_start]1. Opis projektu [cite: 12]
[cite_start]Celem projektu jest symulacja funkcjonowania wielobranżowego sklepu w środowisku konsolowym (CLI)[cite: 13]. [cite_start]Interakcja z systemem odbywa się poprzez intuicyjny zestaw komend sterujących[cite: 14]. [cite_start]Aplikacja oferuje pełną obsługę procesu zakupowego: od przeglądania asortymentu, przez precyzyjne zarządzanie zawartością koszyka (dodawanie i usuwanie produktów), aż po weryfikację podsumowania zamówienia[cite: 15]. [cite_start]Program prezentuje kalkulację kosztów, uwzględniając ceny netto, brutto oraz aktywne rabaty oraz umożliwia zapisanie aktualnego stanu koszyka[cite: 16].

## [cite_start]2. Project description [cite: 17]
[cite_start]The objective of this project is to simulate the operation of a multi-category store within a console environment (CLI)[cite: 18]. [cite_start]Interaction with the system is conducted via an intuitive set of control commands[cite: 19]. [cite_start]The application offers comprehensive support for the purchasing process: from browsing the assortment and precise cart management (adding and removing products) to verifying the order summary[cite: 20]. [cite_start]The program presents cost calculations, including net and gross prices as well as active discounts, and allows for saving the current state of the cart[cite: 21].

## [cite_start]3. Instrukcja użytkownika [cite: 22]
[cite_start]Program po uruchomieniu wyświetla pierwszą stronę sklepu na, której znajduje się maksymalnie 5 produktów wraz z ich opisami oraz historię koszyka z poprzedniej sesji wraz z aktualnie obowiązującą zniżką (jeśli została zapisana)[cite: 23]. [cite_start]W przypadku wystąpienia błędów w bazie danych sklepu program wyświetla o tym informacje oraz pomija uszkodzone rekordy (walidacja typów zmiennych)[cite: 24]. [cite_start]W stopce interfejsu widoczna jest informacja o aktualnie przeglądanej stronie sklepu oraz ilości wszystkich produktów w sklepie[cite: 25].

[cite_start]Interakcja ze sklepem odbywa się poprzez wpisywanie następujących komend[cite: 26]:
* [cite_start]`page <numer strony>` - polecenie pozwala na przechodzenie między kolejnymi stronami sklepu[cite: 27].
* [cite_start]`eop <liczba elementów na stronie>` - polecenie pozwala na zmianę ilości wyświetlanych produktów na poszczególnej stronie oraz przenosi automatycznie na stronę pierwszą sklepu[cite: 28].
* [cite_start]`add <id produktu> <ilość>` - polecenie pozwala na dodanie produktu w danej ilości do koszyka[cite: 29].
* [cite_start]`rem <id produktu> <ilość>` - polecenie pozwala na usunięcie produktu w danej ilości z koszyka[cite: 30].
* [cite_start]`clear` - polecenie pozwala na wyczyszczenie koszyka[cite: 31].
* [cite_start]`summary` - polecenie wyświetla aktualny stan koszyka wraz z informacjami na temat zniżek podatków jak i ceny wszystkich produktów w koszyku[cite: 32].
* [cite_start]`discount <kod promocyjny>` - polecenie pozwala dodać zniżkę do finalnej ceny wszystkich produktów (aktualnie zaimplementowane kody to: promo1 - 10% zniżki oraz promo2 - 20% zniżki)[cite: 33].
* [cite_start]`discount clear` - polecenie pozwala usunąć aktualnie obowiązującą zniżkę[cite: 34].
* [cite_start]`exit` - zakończenie działania programu[cite: 35].

[cite_start]Po wpisaniu komendy `exit`, program zapyta użytkownika, czy chce zapisać aktualny stan koszyka wraz z aktualnie obowiązującą zniżką[cite: 36]. [cite_start]Wybranie opcji twierdzącej (y) pozwoli na odtworzenie zakupów przy kolejnym uruchomieniu aplikacji[cite: 37]. 
[cite_start]Program do działania wymaga predefiniowanej listy produktów w pliku `database.txt`, jest w stanie wychwycić błędy w linijkach polegające na nieprawidłowym typie wprowadzonej danej aczkolwiek nie weryfikuje listy pod względem sensu logicznego danych[cite: 38]. [cite_start]Po każdej edycji pliku `database.txt` należy wyczyścić plik `history_summary.txt` przechowujący historie koszyka[cite: 39].

## [cite_start]4. Kompilacja [cite: 40]
[cite_start]Projekt został zaimplementowany i przetestowany w środowisku Microsoft Visual Studio[cite: 42]. [cite_start]Kod źródłowy korzysta wyłącznie ze standardowych bibliotek języka C++ (STL), w związku z czym wymagana jest jedynie standardowa kompilacja[cite: 43]. [cite_start]Nie jest konieczne instalowanie ani dołączanie żadnych zewnętrznych bibliotek czy niestandardowa konfiguracja linkera[cite: 44].

[cite_start]**Wymagania systemowe i kompilacyjne:** [cite: 45]
* [cite_start]**System operacyjny:** Microsoft Windows[cite: 46]. [cite_start]Uzasadnienie: Program wykorzystuje funkcje systemowe specyficzne dla konsoli Windows (`system("cls")` do czyszczenia ekranu oraz `system("pause")` do zatrzymywania działania), co czyni go nieprzenośnym na systemy Linux/macOS bez modyfikacji kodu[cite: 47].
* [cite_start]**Standard języka:** C++14 lub nowszy[cite: 48]. [cite_start]Uzasadnienie: Projekt wykorzystuje nowoczesne mechanizmy zarządzania pamięcią, w tym funkcję `std::make_unique` (do tworzenia inteligentnych wskaźników), która jest dostępna od standardu C++14[cite: 49].
* [cite_start]**Instrukcja kompilacji:** Proces budowania aplikacji odbywa się poprzez standardowe polecenie kompilacji w środowisku Microsoft Visual Studio (opcja Build Solution / Kompiluj rozwiązanie)[cite: 50].

## [cite_start]5. Pliki źródłowe [cite: 51]
[cite_start]Projekt składa się z następujących plików źródłowych[cite: 52]:
* [cite_start]`Book.h`, `Book.cpp` - deklaracja i implementacja klasy Book [cite: 53]
* [cite_start]`Clothes.h`, `Clothes.cpp` - deklaracja i implementacja klasy Clothes [cite: 53]
* [cite_start]`Electronics.h`, `Electronics.cpp` - deklaracja i implementacja klasy Electronics [cite: 53]
* [cite_start]`Furniture.h`, `Furniture.cpp` - deklaracja i implementacja klasy Furniture [cite: 53]
* [cite_start]`Toys.h`, `Toys.cpp` - deklaracja i implementacja klasy Toys [cite: 53]
* [cite_start]`Product.h`, `Product.cpp` - deklaracja i implementacja klasy Product [cite: 54]
* [cite_start]`DefFunctions.h`, `DefFunctions.cpp` - deklaracja i implementacja funkcji [cite: 54]
* [cite_start]`Projekt Temat62JPO.cpp` - główny plik programu [cite: 54]

## [cite_start]6. Zależności [cite: 55]
[cite_start]Brak[cite: 56].

## [cite_start]7. Opis klas [cite: 57]
[cite_start]W projekcie utworzono następujące klasy[cite: 58]:

* [cite_start]**Product** - klasa bazowa reprezentująca ogólny produkt w sklepie[cite: 59].
  * [cite_start]`string get_name() const` - zwraca nazwę produktu[cite: 60].
  * [cite_start]`float get_nettoprice() const` - zwraca cenę netto produktu[cite: 61].
  * [cite_start]`float get_bruttoprice() const` - zwraca cenę brutto produktu[cite: 61].
  * [cite_start]`virtual void display() const` - metoda wirtualna, wyświetla podstawowe informacje o produkcie na standardowe wyjście[cite: 63].
* [cite_start]**Furniture** - klasa reprezentująca meble, dziedzicząca po klasie Product[cite: 64].
  * [cite_start]`string get_material() const` - zwraca informację o materiale wykonania[cite: 65].
  * [cite_start]`string get_dimensions() const` - zwraca wymiary mebla[cite: 66].
  * [cite_start]`string get_color() const` - zwraca kolor mebla[cite: 67].
  * [cite_start]`void display() const` - nadpisuje metodę bazową, wyświetlając dodatkowo specyfikację mebla[cite: 68].
* [cite_start]**Clothes** - klasa reprezentująca odzież, dziedzicząca po klasie Product[cite: 69].
  * [cite_start]`int get_size() const` - zwraca rozmiar ubrania[cite: 70].
  * [cite_start]`string get_material() const` - zwraca rodzaj tkaniny[cite: 71].
  * [cite_start]`string get_colour() const` - zwraca kolor ubrania[cite: 72].
  * [cite_start]`void display() const` - nadpisuje metodę bazową, prezentując atrybuty odzieżowe[cite: 73].
* [cite_start]**Electronics** - klasa reprezentująca sprzęt elektroniczny, dziedzicząca po klasie Product[cite: 74].
  * [cite_start]`string get_brand() const` - zwraca markę urządzenia[cite: 75].
  * [cite_start]`string get_model() const` - zwraca model urządzenia[cite: 76].
  * [cite_start]`int get_warranty_months() const` - zwraca długość gwarancji w miesiącach[cite: 77].
  * [cite_start]`void display() const` - nadpisuje metodę bazową, wyświetlając specyfikację techniczną[cite: 78].
* [cite_start]**Book** - klasa reprezentująca książki, dziedzicząca po klasie Product[cite: 79].
  * [cite_start]`string get_author() const` - zwraca autora książki[cite: 80].
  * [cite_start]`string get_isbn() const` - zwraca numer identyfikacyjny ISBN[cite: 81].
  * [cite_start]`int get_pages() const` - zwraca liczbę stron[cite: 82].
  * [cite_start]`void display() const` - nadpisuje metodę bazową, prezentując dane bibliograficzne[cite: 83].
* [cite_start]**Toys** - klasa reprezentująca zabawki, dziedzicząca po klasie Product[cite: 84].
  * [cite_start]`int get_min_age() const` - zwraca minimalny wiek dziecka[cite: 85].
  * [cite_start]`string get_material() const` - zwraca materiał wykonania zabawki[cite: 86].
  * [cite_start]`string get_type() const` - zwraca typ zabawki (np. edukacyjna)[cite: 87].
  * [cite_start]`void display() const` - nadpisuje metodę bazową, wyświetlając parametry zabawki[cite: 88].

## [cite_start]8. Zasoby [cite: 89]
[cite_start]W projekcie wykorzystywane są następujące pliki zasobów[cite: 90]:
* [cite_start]`database.txt` - plik zawierający definicje asortymentu sklepu[cite: 91]. [cite_start]Na podstawie zawartych w nim rekordów program, podczas sekwencji startowej, dynamicznie inicjalizuje obiekty produktów i dodaje je do danych aplikacji[cite: 91]. [cite_start]Plik ten jest niezbędny do prawidłowego działania programu[cite: 92].
  * [cite_start]Ogólny schemat wiersza: `[TYP] [NAZWA] [CENA_NETTO] [CENA_BRUTTO] [ATRYBUTY_SPECYFICZNE]`[cite: 94]. [cite_start]Dane są oddzielane znakami białymi[cite: 94].
  * [cite_start]Gdzie `[TYP]` przyjmuje jedną z wartości[cite: 95]:
    * [cite_start]`C` - Clothes [cite: 96]
    * [cite_start]`E` - Electronics [cite: 97]
    * [cite_start]`F` - Furniture [cite: 98]
    * [cite_start]`B` - Books [cite: 99]
    * [cite_start]`T` - Toys [cite: 100]
* [cite_start]`history_summary.txt` - plik generowany automatycznie przez program, zawierający zrzut stanu koszyka (indeksy produktów i ich ilości), wartość zmiennej discount, umożliwiający odtworzenie sesji zakupowej oraz liczbę wszystkich pozycji w podsumowaniu[cite: 101].
  * [cite_start]Schemat zapisu: `[LICZBA_POZYCJI] ([INDEKS_PRODUKTU] [ILOŚĆ]) ([INDEKS_PRODUKTU] [ILOŚĆ]) ([INDEKS_PRODUKTU] [ILOŚĆ]) ... [WARTOŚĆ_ZNIŻKI w %]`[cite: 102].

## [cite_start]9. Dalszy rozwój i ulepszenia [cite: 103]
[cite_start]Projekt można w przyszłości rozbudować o następujące funkcjonalności[cite: 104]:
1. [cite_start]**System Kontroli Magazynowej:** Obecnie sklep pozwala na zakup nieskończonej liczby sztuk danego towaru[cite: 105].
2. [cite_start]**System kont użytkowników i administratora:** Rozbudowa aplikacji o system logowania[cite: 106].
   * [cite_start]Klient: Możliwość posiadania własnej, odseparowanej historii zakupów i zapisanych adresów dostawy[cite: 107].
   * [cite_start]Administrator: Dostęp do ukrytego menu, pozwalającego na dodawanie, usuwanie i edycję produktów w sklepie bezpośrednio z poziomu konsoli, bez konieczności ręcznej edycji pliku tekstowego[cite: 108].
3. [cite_start]**Zaawansowane filtrowanie i sortowanie:** Implementacja algorytmów sortowania (np. po cenie rosnąco/malejąco, alfabetycznie) oraz filtrowania (np. wyświetl tylko produkty z kategorii "Elektronika" tańsze niż 500 zł)[cite: 109]. [cite_start]Zwiększyłoby to znacznie użyteczność sklepu przy dużej liczbie produktów[cite: 110].
4. [cite_start]**Moduł symulacji płatności i generowania faktur:** Obecnie proces zakupowy kończy się na wyświetleniu podsumowania (summary)[cite: 111]. [cite_start]Kolejnym krokiem w rozwoju aplikacji byłaby implementacja symulacji bramki płatniczej[cite: 112].
5. [cite_start]**Implementacja Graficznego Interfejsu Użytkownika (GUI):** Obecna wersja aplikacji opiera się na interfejsie tekstowym (CLI), co jest rozwiązaniem wydajnym, ale mało intuicyjnym dla przeciętnego użytkownika końcowego[cite: 113].
