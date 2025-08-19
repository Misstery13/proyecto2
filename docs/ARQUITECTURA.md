## 🧱 Arquitectura del sistema

### 🧩 Estructuras de datos
- `struct criterios`: contiene `c1..c5` (criterios) y `ct` (promedio calculado).
- `struct empresa`: campos de identificación (nombre, responsable, etc.) y un miembro `criterios dc`.
- Instancia global `de` de `empresa` para el flujo de captura.

### 🧪 Funciones y procedimientos
- `gotoxy(int x, int y)`: posiciona el cursor en la consola (WinAPI).
- `p_borde()`: dibuja el marco y separadores de la consola.
- `p_datos()`: imprime datos de encabezado institucional.
- `p_dmenu()`: muestra el menú, valida la opción y despacha a la funcionalidad.
- `p_ingreso()`: captura con validaciones, calcula el promedio y persiste en `proyect.txt` (modo append).
- `p_consultas()`: indexa nombres desde `proyect.txt`, normaliza entrada y muestra el bloque correspondiente.
- `p_nomina()`: pagina la salida del archivo en consola (26 líneas por página) con controles `s/a/q`.
- `p_graficos()`: construye un gráfico de barras ASCII a partir de porcentajes guardados.
- `removeFirstN(std::string&, int)`: elimina prefijo fijo para extraer el nombre limpio.
- `getIndex(vector<string>, string)`: utilidad para obtener índice; no es utilizada en el flujo principal.
- `F_Criterios(float a,b,c,d,e)`: en `crite.h`; retorna la media aritmética.

### 🔧 Flujo principal
`main()` limpia pantalla, configura color, dibuja borde y encabezado, muestra menú y procesa la opción seleccionada; el menú se repite mientras el usuario responda `S/s` a continuar.

### 🗃️ Entrada/Salida
- Mezcla de APIs C (`FILE*`, `fprintf`, `fopen`) y C++ (`ifstream`, `getline`).
- Persistencia: `proyect.txt` en el directorio de ejecución.
- Renderizado: consola Windows con caracteres ASCII (límites del cuadro, bloques `178` para barras).

### 🧠 Consideraciones de diseño
- Validaciones intensivas para robustez en la captura.
- Dependencia de consola Windows para coordenadas y entrada sin eco (`getch`).
- El gráfico usa `max_value = 50` para escalar barras a un ancho cómodo; porcentajes mayores se visualizan más largos, pero el factor de escala es fijo.

