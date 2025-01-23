# Zaliczenie 159831
Projekt-zaliczenie ćwiczeń.
W projekcie zostało zaprezentowane szyfrowanie za pomocą RSA, atak typu brute force oraz zabezpieczenie kodu, by utrudnić atak.
W tym przykładzie szyfrowany jest tekst wprowadzany do kodu.
Występują dwie symulacje:
1. Udany atak.
2. Nieudany atak ze wzmocnionymi zabezpieczeniami.

## Spis treści 
- [Algorytmy wykorzystane w projekcie.](#Algorytmy wykorzystane w projekcie.)
- [Zastosowany atak brute force.](#Zastosowany atak brute force.)
- [Propozycja aplikacji](#Propozycja aplikacji)
- [Problemy i rozwiązania](#Problemy i rozwiązania)
- [Jak dodatkowo można zabezpieczyć kod w przyszłości.](#Jak dodatkowo można zabezpieczyć kod w przyszłości.)

## Algorytmy wykorzystane w projekcie.
1. Rivesta-Shamira-Adlemana (RSA) - Jeden z pierwszych i obecnie najpopularniejszy asymetryczny algorytm kryptograficzny z kluczem publicznym. Wykorzystuje on klucz zarówno publiczny, jak i prywatny. Publiczny klucz służy do szyfrowania wprowadzonych przez nas danych, natomiast prywatny służy do deszyfrowania.
2. Algorytm szybkiego potęgowania- funkcja fastexpon
za jej pomocą przyśpieszamy operację szyfrowania i deszyfrowania RSA.
4. Rozszerzony algorytm Euklidesa- Funkcja EkulidesInverse:
znajduje liczbowy odpowiednik (odwrotność) liczby 'a' w ramach innej liczby 'm', co jest potrzebne do uzyskania klucza prywatnego w RSA.

## Zastosowany atak brute force.
Atak brute force polega na systematycznym próbowaniu wszystkich możliwych kombinacji haseł lub kluczy, aż do znalezienia właściwej. Jest to metoda bardzo czasochłonna i wymaga dużej mocy obliczeniowej, ale jest skuteczna, jeśli nie zastosowano żadnych dodatkowych zabezpieczeń.
1. Udany atak:
W projekcie został zasymilowany udany atak brute force. Ze względu na błędy napotkane podczas kompilacji, wartości używane w symulacji musiały być jawne. Poprzednia wersja kodu, którą tworzyłam do deszyfrowania, miała problemy z poprawnym odczytywaniem znaków. Dlatego konieczne było ręczne podanie wartości, aby symulacja mogła zostać pomyślnie przeprowadzona.
W tym przypadku zostały podane małe wartości, które bardziej narażają program na poprawne działanie ataku (p = 13, q = 17). Atak polega na próbowaniu kolejnych kluczy prywatnych jeden po drugim, aby znaleźć ten właściwy. Gdy uda mu się odnaleźć tekst zostaje odszyfrowany.
2. Atak nieudany:
Do programu zostały podane większe wartości, które utrudniają atak (p = 101, q = 103). Dodane zostało również jedno z zabezpieczeń w postaci ograniczenia
możliwości prób. Wpływa ono na zmniejszenie skuteczności ataku i wydłużenie czasu.

## Propozycja aplikacji
Aplikacja może być przydatna jako przykład edukacyjny dla osób rozpoczynających naukę w dziedzinie bezpieczeństwa informatycznego. Demonstruje ona:
1.Podatność systemów szyfrujących na atak brute force w przypadku stosowania małych kluczy.
2.Przykład mechanizmów zabezpieczających, takich jak większe klucze czy ograniczenie liczby prób ataku.

## Problemy i rozwiązania
1.Problem: Małe wartości podawane do szyfrowania RSA ułatwiają atak brute force.
Rozwiązanie: Zastosowanie większych liczb pierwszych (np. p = 101, q = 103).

2.Problem: Brak ograniczeń.
Rozwiązanie: Utworzenie limitu prob.

3.Problem: Złożoność obliczeń dla dużych liczb.
Rozwiązanie: Optymalizacja za pomocą algorytmu szybkiego potęgowania.

## Jak dodatkowo można zabezpieczyć kod w przyszłości.
Aby zwiększyć bezpieczeństwo aplikacji, można wprowadzić dodatkowe mechanizmy, takie jak:
1. Czasowe opóźnienia: Dodanie opóźnień między próbami logowania, co wydłuży czas przeprowadzenia ataku.
2. Wykrywanie nietypowego zachowania: Implementacja systemu wykrywającego próby ataków brute force.
3. Ograniczenia dostępu: Ustalanie reguł dostępu, np. ograniczenie korzystania z aplikacji do wybranych adresów IP.
