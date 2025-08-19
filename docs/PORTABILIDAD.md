## Portabilidad (Linux/macOS)

El código actual depende de Windows por `windows.h`, `conio.h` y el uso de la API de consola (posición del cursor, color, `getch`). Para portar:

### Reemplazos sugeridos
- `gotoxy(x,y)`: usar secuencias ANSI o una librería como `ncurses`.
- `getch()`: usar `ncurses` (`getch`) o lectura no bloqueante con `termios`.
- `system("cls")` y color: reemplazar por secuencias ANSI (`"\x1b[2J"` para limpiar; `"\x1b[3Xm"` para color).

Ejemplo mínimo de `gotoxy` con ANSI:
```cpp
#include <iostream>
void gotoxy_ansi(int x, int y) {
    std::cout << "\x1b[" << y << ";" << x << "H";
}
```

### Compilación
En Linux, elimine/ajuste las inclusiones específicas de Windows y compile con:
```
g++ -std=c++17 -O2 -o proyecto "proyecto.cpp"
```

### Notas
- Los caracteres de borde y las barras ASCII se mostrarán correctamente en terminales con codificación UTF-8.
- Ajuste el escalado de gráficos si el ancho del terminal es diferente.

