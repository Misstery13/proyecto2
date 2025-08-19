## 🖼️ Capturas de pantalla (consola)

Debido a que la aplicación es de consola en Windows, aquí se incluyen capturas en ASCII que representan el aspecto de la interfaz. También se detalla cómo agregar capturas reales (PNG).

### 🧭 Menú principal
```
┌──────────────────────────────────────────────────────────────────────────────┐
│ Universidad Estatal Peninsula de Santa Elena.                               │
│ Facultad de Sistemas y Telecomunicaciones.                                  │
├──────────────────────────────────────────────────────────────────────────────┤
│ Menu de Opciones.                                                           │
│ 1. Ingresos.                                                                │
│ 2. Consultas.                                                               │
│ 3. Nomina.                                                                  │
│ 4. Grafico.                                                                 │
│ 5. Salir.                                                                   │
│                                                                              │
│ Digite la opcion a utilizar: _                                               │
└──────────────────────────────────────────────────────────────────────────────┘
```

### ✍️ Ingresos (ejemplo de campos)
```
Nombre de la Empresa: Razer
Responsable: Min-Liang Tan
Producto estrella: Razer Blade
Direccion de la empresa: 3339 S. Broadway, Suite 100
Ciudad: Los Angeles, CA
Telefono convencional o celular: 888-697-2037
Correo electronico empresarial: support@razer.com
Link de la pagina: https://www.razer.com

----------Criterios de automatizacion----------
Creacion de productos            (0-100%) : 85 %
Validacion de garantia           (0-100%) : 70 %
Equipo especializado             (0-100%) : 90 %
Ventas, produccion y exportacion (0-100%) : 75 %
Innovacion                       (0-100%) : 80 %
-----------------------------------------------
Porcentaje de Automatizacion: 80 %
```

### 🔎 Consultas (resultado)
```
Nombre de la empresa            :  Razer
Responsable                     :  Min-Liang Tan
Producto estrella               :  Razer Blade
Direccion de la empresa        	:  3339 S. Broadway, Suite 100
Ciudad                          :  Los Angeles, CA
Telefono convencional o celular	:  888-697-2037
Correo electronico empresarial  :  support@razer.com
Link de la pagina               :  https://www.razer.com

 ---Porcentaje de Automatizacion---
80
```

### 🧾 Nómina (paginación)
```
... (26 líneas por página) ...
Presiona 's'(siguiente pagina), 'a'(pagina anterior), 'q'(cerrar): _
```

### 📈 Gráfico (barras ASCII)
```
██████████████████████████ 80%   Razer

███████████████████ 62%   Pronaca

████████████████████████ 77%   Tesla
```

Nota: Los bloques reales usan el carácter 178 (▓) y el escalado interno del programa.

---

## 🧩 Cómo agregar capturas reales (PNG)
1. Ejecute la aplicación en Windows en una consola lo suficientemente ancha.
2. Tome capturas con `Win + Shift + S` o la Herramienta Recortes.
3. Guarde los archivos en `docs/assets/` con estos nombres sugeridos:
   - `menu.png`
   - `ingresos.png`
   - `consultas.png`
   - `nomina.png`
   - `grafico.png`
4. Opcional: inserte las imágenes en este documento justo debajo de cada sección:

```markdown
![Menú](assets/menu.png)
```

5. Verifique que las rutas funcionen correctamente en GitHub.

### 📂 Placeholders
Este repositorio incluye archivos placeholder en `docs/assets/` con la extensión `.placeholder`:
- `menu.png.placeholder`
- `ingresos.png.placeholder`
- `consultas.png.placeholder`
- `nomina.png.placeholder`
- `grafico.png.placeholder`

Para reemplazarlos:
- Elimine el archivo placeholder correspondiente y agregue la captura real con el mismo nombre sin la extensión `.placeholder` (por ejemplo, `menu.png`).

