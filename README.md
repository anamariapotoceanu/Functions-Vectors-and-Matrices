
**Potoceanu Ana-Maria 321CA**

# Tema 1 Functii, Vectori si Matrici
**Programarea Calculatoarelor si Limbajelor de Programare**

    # Problema 1 - Un produs infinit
    
 
    - In program, am folosit o functie pentru transformarea numerelor din baza
opt in baza zece, pentru a face mai usoare calculele. Citirea vectorilor a si
b se face avand in vedere numere in baza opt.
    - In functia main, sunt declarate si initializate variabilele. Se citeste
de la tastatura n, reprezentand dimensiunea celor doi vectori. Prima data,
citim cate o coordonata din fiecare vector si vom calcula de fiecare data
produsul, al doilea maxim pentru ambii vectori si normele, pentru a evita
stocarea in vector.
    - Produsul scalar se initializeaza cu valoarea 0 si pentru fiecare pereche
de coordonate, se adauga produsul lor. Pentru fiecare vector avem doua maxime.
Se verifica unde este pozitionata fiecare coordonata a vectorului, in functie
de acestea. Se calculeaza norma pentru fiecare dintre cei doi vectori.
    - La final, se afiseaza produsul scalar, cele doua maxime si norma cu
sapte zecimale exacte.

    # Problema 2 - Perfectionarea punctajelor
    

    - Pentru rezolvarea cerintei, am folosit functii ajutatoare pentru o
scriere cat mai clara a codului. Mai exact, primele doua functii sunt pentru
citirea vectorilor de note si de puncte credite.A treia functie verifica daca
punctajul elevului a atins sau nu punctajul dorit pentru marire. Urmeaza o
functie care sorteaza descrescator vectorul de mariri si inca o functie care
calculeaza punctajul initial. 
    - In cadrul functiei main, dupa citirea datelor necesare si calcularea
punctajului initial, am creat un vector care contine maririle necesare pentru
obtinerea mediei dorite. Am ales sa sortez acest vector descrescator, deoarece
ne dorim sa obtinem punctajul dorit cat mai repede, iar acest lucru presupune
sa adaugam maririle de la cea mai mare la cea mai mica.
    - Pentru a vedea cate mariri sunt necesare, adaugam la punctajul initial,
pe rand, cate o marire pana cand ajungem la media dorita de elev. De fiecare
data vom verifica daca am ajuns la rezulatul cerut si vom retine numarul
necesar de mariri. 
    - In final, se face o verificare daca s-a atins punctajul dorit, in caz
contrar, vom afisa -1. Altfel, afisam numarul necesar de mariri.


    # Problema 3 - Gigel si tabla de sah 
    

    - Pentru aceasta problema, am avut nevoie de o functie cu ajutorul careia
sa afisam coordonata finala. 
    - In functia main, sunt declarate si initializate variabilele. Se citeste
un numar natural de la tastatura, urmand sa citim matricea. De asemenea, vom
retine intr-un vector valorile 0 sau 1.

    - 0 reprezinta faptul ca patratul nu a mai fost parcurs.
    - 1 reprezinta faptul ca patratul a mai fost parcurs, urmand sa ne oprim.

    - Daca numarul de pe biletel, de pe patrat, este diferit de 0, iar patratul
nu a mai fost parcurs, atunci puntem sa realizam mutarile. Pentru fiecare
patrat, adaugam la suma numarul corespunzator, pentru a obtine in final
distanta parcursa.
    - Verificam daca patratul este alb sau negru. Conditia pentru patratul alb
este ca suma indicelor sa fie un numar par. Pentru patratul alb, ne vom muta
de-a lungul liniei, modificam astfel indicele pentru coloana.
    - Verificam daca indicele obtinut iese sau nu din careu. 
    - In cazul patratului negru, vom face mutarea pe coloana, modificand
indicele liniei.
    - In final, vom afisa distanta totala si coordonatele patratului final,
folosindu-ne de functia pentru conversia asemanatoare foii Excel.

    # Problema 4 -  Monogram checker 
    

    - Pentru rezolvarea acestei probleme, am implementat functii ajutatoare.
Astfel, primele trei functii sunt pentru citirea restrictiilor pentru linie,
pentru coloana si pentru citirea gridului. De asemenea, pentru a verifica daca
una dintre restrictiile pentru linie sau pentru coloana este incalcata, am
implementat verify_row si verify_col. Aceste functii returneaza 0 daca una
dintre conditii nu a fost respectata. Urmeaza o functie care verifica
validitatea fiecarui rand din matrice. 
    - Pentru a numara cate grupuri colorate exista si din cate elemente sunt
ele formate, am ignorat elementele egale cu 0 de pe fiecare rand. In cazul in
care intalnim un element egal cu 1, vom numara cate casute alaturate exista.
Numarul fiecarui grup format din 1 l-am retinut intr-un vector separat, pentru
a putea face verificarea mai usor.Vom verifica, de fiecare data, daca numarul
elementelor dintr-un grup coincide cu cel citit de la tastaura.
    - In mod identic am procedat si pentru verificarea validitatii coloanelor
din matrice. 
    - In final, prin intermediul ultimei functii ajutatoare, programul va afisa
mesajul corespunzator gridului.
