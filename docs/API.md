## API interna

### `float F_Criterios(float a, float b, float c, float d, float e)`
- Ubicación: `crite.h`
- Descripción: devuelve el promedio aritmético simple de los 5 criterios.
- Parámetros: valores en rango recomendado 0–100.
- Retorno: promedio en punto flotante.
- Uso:
```cpp
float promedio = F_Criterios(c1, c2, c3, c4, c5);
```

### Procedimientos principales (internos)
- `void p_ingreso()`: captura datos, valida y persiste.
- `void p_consultas()`: consulta por nombre.
- `void p_nomina()`: listado paginado.
- `void p_graficos()`: gráfico de barras ASCII.
- `void p_borde()`, `void p_datos()`, `void p_dmenu()`: interfaz y navegación.

Nota: estas funciones dependen de consola Windows y no constituyen una API pública estable; están sujetas a cambios internos.

