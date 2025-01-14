/*

ESTE ES EL PROMPR QUE LE DI A CHATGPT PARA QUE DEVUELVA ESTE CODIGO 


tengo una matriz de 8x8 (788AS) conectada al arduino nano, te voy a dar las conecciones y tu dame un codigo sencillo para mostrar imagenes en la matriz,  pines 9, 14, 8, 12, 1, 7, 2 , y 5 de la matriz, son negativos y son las filas y van conectados respectivamente al d2, d3, d4, d5, d6, d7, d8 , y d9, del nano, estan conectados en este orden que te di van de orden acendente de fila 1 a fila 8, por favor no los confuncas, estos son los catodos. Los positivos son los pines 13, 3, 4, 10,6 11, 15, 16, son los anodos y estan conectados respectivamente al nano a los pines d10, d11, d12, a0 , a1, a2, a3, y a4 estos son las columnas, y y van en orden acendente de columna 1 a columna 8.


*/




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
