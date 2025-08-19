## 🤖 Proyecto II Parcial — Porcentaje de Automatización de Empresas

Aplicación de consola en C++ que permite registrar empresas y calcular su porcentaje de automatización a partir de 5 criterios, además de consultar registros, listar la nómina en forma paginada y visualizar gráficos de barras en la consola.

### 👥 Integrantes
- Baque De La Cruz Joffre Darío
- Burgos Mero Erick Ariel
- Gutiérrez Suarez Mario Miguel
- Laínez Dominguez Diego Isaías
- Melena Santander Diana Lucia
- Nuñez Zamora Miguel Alejandro
- Pacha Rivera Kleber Slader
- Rocafuerte Tomala Jair Ariel
- Rodríguez Catuto Ángel José
- Salcedo Tomala Sammy Jordy
- Suarez Ricardo Bryan Estuar
- Suárez Yagual Vanessa Angelica
- Tomalí Bernabé Richard Enrique
- Villaprado Laje Max Anderson

### 📝 Descripción general
El sistema gestiona la información básica de una empresa y calcula el promedio porcentual de automatización en base a 5 criterios:
- Creación de productos
- Validación de garantía
- Equipo especializado
- Ventas, producción y exportación
- Innovación

El promedio se calcula con la función `F_Criterios` definida en `crite.h` como la media aritmética simple de los 5 valores: `(c1 + c2 + c3 + c4 + c5) / 5`.

Los datos se almacenan en el archivo `proyect.txt` (modo append), donde cada empresa ocupa un bloque de líneas con un formato fijo.

### 🧰 Requisitos
- Compilador C++ con soporte de C++11 o superior (se usa `<regex>`).
- Entorno Windows para ejecución directa, ya que se utilizan `windows.h`, `conio.h` y manejo de consola específico de Windows.

Opcional para desarrollo:
- MinGW-w64, MSYS2, o IDEs como Dev-C++, Code::Blocks o Visual Studio (con ajustes de consola).

Nota sobre Linux/macOS: el código no es portable de forma nativa por `windows.h` y `conio.h`. Para portar, reemplace `gotoxy`, `getch` y la limpieza de pantalla/color por alternativas de curses o APIs equivalentes y elimine dependencias de Windows.

### 🛠️ Compilación (Windows)
Ubique `proyecto_parcial2_10 (1).cpp` y `crite.h` en el mismo directorio.

- MinGW (g++):
```
g++ -std=c++17 -O2 -o proyecto.exe "proyecto_parcial2_10 (1).cpp"
```

Si prefiere evitar comillas, renombre el archivo fuente para quitar espacios y paréntesis y ajuste el comando.

### ▶️ Ejecución
```
proyecto.exe
```
El programa creará (o agregará a) `proyect.txt` en el mismo directorio.

### 📋 Menú y funcionalidades
- ✍️ Ingresos: captura validada de campos de la empresa. Validaciones destacadas:
  - Nombre/Responsable: solo letras y espacios (el responsable admite guiones).
  - Teléfono: dígitos y símbolos comunes (+, (), -, espacio). Se permite dejarlo vacío previa confirmación.
  - Correo: validación por expresión regular.
  - Link: validación por expresión regular `(http|https)`.
  - Criterios: números entre 0 y 100 para los 5 criterios.
  - Se calcula y muestra “Porcentaje de Automatización” (promedio) y se guarda redondeado en el archivo.
- 🔎 Consultas: búsqueda por nombre de empresa (no sensible a mayúsculas y sin espacios). Muestra el bloque completo de la empresa.
- 🧾 Nómina: listado paginado del archivo (`26` líneas por “página”). Navegación: `s` (siguiente), `a` (anterior), `q` (salir).
- 📈 Gráficos: barras horizontales en consola usando caracteres ASCII, mostrando el porcentaje y el nombre de la empresa.

### 🗂️ Formato del archivo `proyect.txt`
Cada empresa se guarda como un bloque de 13 líneas. Ejemplo:
```
Nombre de la empresa            :  Razer 
Responsable                     :  Min-Liang Tan 
Producto estrella               :  Razer Blade (latop para juegos) 
Direccion de la empresa	        :  3339 S. Broadway, Suite 100 
Ciudad                          :  Los Angeles, CA 
Telefono convencional o celular	:  888-697-2037 
Correo electronico empresarial  :  support@razer.com 
Link de la pagina               :  https://www.razer.com 

 ---Porcentaje de Automatizacion--- 
80 

```
Notas:
- El porcentaje se guarda como número redondeado en una línea separada.
- El nombre de la empresa en la primera línea es el índice usado por “Consultas”.

### 📁 Estructura del repositorio
- `proyecto_parcial2_10 (1).cpp`: fuente principal (menú, validaciones, ingreso, consultas, nómina, gráficos).
- `crite.h`: función `F_Criterios` para calcular el promedio de los 5 criterios.
- `proyect.txt`: archivo de datos (incluye ejemplos).
- `proyecto_parcial2_10 (1).exe`: binario compilado para Windows.
- `.gitattributes`: configuración de Git.
- `README.md`: este documento.

### ⚠️ Limitaciones y notas
- Dependencias de consola de Windows (`windows.h`, `conio.h`); no compila sin cambios en Linux/macOS.
- Codificación de caracteres: si se observan símbolos extraños en acentos, ajuste la página de códigos de la consola (`chcp 65001`) o configure el IDE/terminal a UTF-8.

### 📝 Pendientes
- Incrementar el tamaño de la ventana (consultar por switch gráficos) (Diana)
- Investigar almacenamiento de datos sin sobreescribir (append implementado, validar escenarios) (Bryan)
- Agregar gráficos estadísticos (Diana)
- Agregar opción de consultas (Richard)
- Agregar opción de nóminas (Ángel)

### 📚 Documentación adicional
- Uso: `docs/USO.md`
- Formato de datos: `docs/FORMATO_DATOS.md`
- Arquitectura: `docs/ARQUITECTURA.md`
- Desarrollo: `docs/DESARROLLO.md`
- Portabilidad: `docs/PORTABILIDAD.md`
- API: `docs/API.md`
- Cambios: `CHANGELOG.md`
- Capturas: `docs/SCREENSHOTS.md`

### ⚖️ Licencia
Distribuido bajo la licencia MIT. Consulte `LICENSE` para más información.
