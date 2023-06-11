# Oppgave 1 b) - teori

```5 - 3 - fraction1 - 7 - fraction2``` blir tolket på følgende måte.
Her er operasjonene som blir gjort i rekkefølge:

Husk at ```Fraction1 = 3/2 og Fraction2 = 3/4```
````
5 - 3 = 2 (2 er en int her. Vanlig c++ operasjon.)
2 - fraction1 = 1/2 (funksjonen som tar int som parameter og som ikke er en medlemfunksjon blir kalt. 1/2 her er det samme objektet som fraction1, men har nye verdier.)
1/2 - 7 = -13/2 (medlemsfunksjonen som tar inn int og other som paramter blir kalt. 1/2 her er det samme objektet som fraction1, men har nye verdier. -13/2 er de nye verdiene til objektet fraction1.)
-13/2 - fraction2 = -29/4 (vanlig medlemsfunksjon blir mellom to fractions blir kalt.)
````