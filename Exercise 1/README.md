Zadanie 1 Zaimplementuj w czystym C listę jednokierunkową z następującymi operacjami: 
- insert – wstawiającą element do listy; 
- delete – usuwającą element z listy; 
- isempty – sprawdzającą czy lista jest pusta; 
- findMTF – sprawdzająca czy podany element jest na liście i w przypadku jego znalezienia przesuwający go na przód listy; 
- findTRANS – sprawdzająca czy podany element jest na liście i w przypadku jego znalezienia przesuwający go o jedno miejsce do przodu listy. 

Funkcje realizujące podane operacje nie mogą korzystać ze zmiennych globalnych, wszystkie dane powinny być przekazywane przez parametry. 
Jako wartości boolowskie przyjmujemy 0 jako fałsz a 1 jako prawdę. Kod powinien być zdokumentowany. 
Sprawdź średnią liczbę porównań potrzebną na przeprowadzenie następującego scenariusza działań: 


- wstaw w losowej kolejności elementy od 1 do 100 (100 elementów) na listę; 
- dopóki lista nie będzie pusta: sprawdź czy elementy od 1 do 100 są na liście a następnie usuń element maksymalny. 


Rozpatrz oba warianty operacji sprawdzającej. Która z nich daje mniejszą średnią liczbę porównań. 
Licznik porównań można zrealizować jako zmienną globalną
