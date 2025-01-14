// Pines de las filas (cátodos)
const int filas[] = {2, 3, 4, 5, 6, 7, 8, 9};

// Pines de las columnas (ánodos)
const int columnas[] = {10, 11, 12, A0, A1, A2, A3, A4};

// Matriz de imagen: 1 = LED encendido, 0 = LED apagado
const byte imagen[8][8] = {
    {1, 0, 0, 0, 0, 0, 0, 1},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {1, 0, 0, 0, 0, 0, 0, 1}
};

void setup() {
    // Configurar pines de filas como salida y apagados inicialmente
    for (int i = 0; i < 8; i++) {
        pinMode(filas[i], OUTPUT);
        digitalWrite(filas[i], HIGH); // Apagado (cátodos en HIGH)
    }

    // Configurar pines de columnas como salida y apagados inicialmente
    for (int i = 0; i < 8; i++) {
        pinMode(columnas[i], OUTPUT);
        digitalWrite(columnas[i], LOW); // Apagado (ánodos en LOW)
    }
}

void loop() {
    for (int fila = 0; fila < 8; fila++) {
        // Activar la fila actual (cátodo en LOW)
        digitalWrite(filas[fila], LOW);

        for (int columna = 0; columna < 8; columna++) {
            // Encender o apagar el LED correspondiente
            if (imagen[fila][columna] == 1) {
                digitalWrite(columnas[columna], HIGH); // Encender
            } else {
                digitalWrite(columnas[columna], LOW); // Apagar
            }
        }

        // Esperar un poco para mantener el LED encendido
        delay(2);

        // Apagar la fila actual (cátodo en HIGH)
        digitalWrite(filas[fila], HIGH);
    }
}
