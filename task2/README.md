## Oppgave 2
Du vil få en segmentation fault: Process finished with exit code 139 (interrupted by signal 11: SIGSEGV).
Nullpointer er utenfor minneadressen som programmet har tilgang til. 

## Oppgave 3
Hva kan gå galt her?
```
char text[5];
char *pointer = text;
char search_for = 'e';
cin >> text;
while (*pointer != search_for) {
  *pointer = search_for;
  pointer++;
}
```

Hvis brukeren skriver inne et ord som har mer enn 5 tegn, kommer en segmentation fault. Dette er fordi 
listen med bokstaver kan makse være 4. Grunnen til at lengden kan være 4, og ikke 5 er fordi 

