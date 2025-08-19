## Guía de uso

### Requisitos previos
- Windows (por uso de `windows.h` y `conio.h`).
- Compilador C++ con soporte para C++11 o superior.

### Compilación
Con MinGW (g++):
```
g++ -std=c++17 -O2 -o proyecto.exe "proyecto_parcial2_10 (1).cpp"
```
Sugerencia: renombre el archivo fuente para evitar espacios/paréntesis y simplificar el comando.

### Ejecución
```
proyecto.exe
```
El programa creará (o actualizará) `proyect.txt` en el mismo directorio.

### Flujo de la aplicación
Al iniciar, verá un marco con el menú:
- 1. Ingresos
- 2. Consultas
- 3. Nomina
- 4. Grafico
- 5. Salir

Use el número de la opción y presione Enter.

### 1) Ingresos
Capture los campos de la empresa. Validaciones clave:
- Nombre de la Empresa: solo letras y espacios; no vacío.
- Responsable: solo letras, espacios y guiones; no vacío.
- Producto estrella: no vacío.
- Dirección: no vacío.
- Ciudad: no vacío.
- Teléfono: dígitos y símbolos comunes `+ ( ) -` y espacio. Puede dejarse vacío previa confirmación.
- Correo electrónico: validación por expresión regular estándar.
- Link de la página: debe iniciar con `http://` o `https://` y ser válido.
- Criterios (0–100%): se ingresan 5 valores numéricos.

El programa calcula el promedio con `F_Criterios` y lo muestra como “Porcentaje de Automatizacion”. Luego escribe un bloque de 13 líneas en `proyect.txt` con los datos y el porcentaje redondeado.

### 2) Consultas
- Ingrese el nombre de la empresa a buscar. La búsqueda:
  - No distingue mayúsculas/minúsculas.
  - Ignora espacios en el nombre.
- Si se encuentra, se imprime el bloque completo de esa empresa desde `proyect.txt`.
- Si no existe, se muestra un mensaje y se le permite intentar nuevamente.

### 3) Nomina
Lista paginada del archivo `proyect.txt`.
- Controles: `s` (siguiente página), `a` (página anterior), `q` (salir).
- Tamaño de página: 26 líneas.

### 4) Grafico
Muestra barras horizontales en la consola con el porcentaje de automatización y el nombre de cada empresa. Las barras se dibujan con caracteres ASCII.

### 5) Salir
Termina la ejecución.

### Consejos
- Para nombres largos, evite agregar espacios al final. La búsqueda elimina espacios, pero mantenga nombres consistentes.
- Si aparecen caracteres extraños en acentos, cambie la página de códigos de la consola a UTF-8: `chcp 65001`.

