## Oppgave 2
Du vil få en segmentation fault: Process finished with exit code 139 (interrupted by signal 11: SIGSEGV).
Nullpointer er utenfor minneadressen som programmet har tilgang til og det er derfor ikke mulig å bruke string copy.

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
listen med bokstaver kan maks være 4. Grunnen til at lengden kan være 4, og ikke 5 er fordi når cin 
blir brukt, legges det til et ekstra tegn, "\0", i slutten av strengern. Det er mulig å bruke
cin.getline() for å komme unna dette.

Hvis teksten man skriver inn ikke inneholder en "e", vil det være en uendelig loop som til slutt går
 til en ugyldig minneadresse.



