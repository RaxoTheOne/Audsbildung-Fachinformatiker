// Korrektur Aufgabe 8a)
if (var >= 0 && var <= 10) {
    a = 0;
    printf("Wert im zulaessigen Bereich!\n");
} else if (var > 10) {
    a = 1;
} else {
    a = -1;
}


// Korrektur Aufgabe 8b)
a = (var == 0) ? 0 : 1;
printf("a = %d\n", a);


// Korrektur Aufgabe 8c)
switch (var) {
    case 0:
    case 1:
        printf("var ist 0 oder 1\n");
        break;
    default:
        if (var < 0)
            printf("var ist negativ\n");
        else
            printf("var ist groesser als 1\n");
}
