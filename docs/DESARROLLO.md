## 🔧 Guía de desarrollo

### 🖥️ Entorno recomendado (Windows)
- Compilador: MinGW-w64 (g++), MSVC, o TDM-GCC.
- IDE opcional: Code::Blocks, Dev-C++, Visual Studio.

### 📦 Dependencias
- C++11 o superior (uso de `<regex>`).
- Cabeceras específicas de Windows: `windows.h`, `conio.h`.

### 🛠️ Compilar desde línea de comandos (MinGW)
```
g++ -std=c++17 -O2 -Wall -Wextra -o proyecto.exe "proyecto_parcial2_10 (1).cpp"
```
Sugerencias:
- Renombre el archivo fuente para evitar espacios y paréntesis si su shell/IDE presenta problemas.
- Mantenga `crite.h` en el mismo directorio del `.cpp`.

### 📁 Estructura del repositorio
- `proyecto_parcial2_10 (1).cpp`: lógica principal.
- `crite.h`: función `F_Criterios`.
- `proyect.txt`: datos persistidos.
- `docs/`: documentación.

### ✨ Estilo y convenciones
- Comentarios en español, claros y concisos.
- Validaciones de entradas y manejo de errores antes de continuar el flujo.
- Evitar anidamientos profundos; usar retornos tempranos cuando sea posible.

### 🐞 Ejecución y depuración
- Ejecute `proyecto.exe` desde una consola con codificación UTF-8 (`chcp 65001`) para acentos.
- Borre `proyect.txt` si desea iniciar datos desde cero.

