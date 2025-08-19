## Formato del archivo de datos `proyect.txt`

Cada empresa ocupa un bloque de 13 líneas, en el siguiente orden:

1. `Nombre de la empresa            :  <texto>`
2. `Responsable                     :  <texto>`
3. `Producto estrella               :  <texto>`
4. `Direccion de la empresa        	:  <texto>`
5. `Ciudad                          :  <texto>`
6. `Telefono convencional o celular	:  <texto>`
7. `Correo electronico empresarial  :  <texto>`
8. `Link de la pagina               :  <texto>`
9. (línea en blanco)
10. `---Porcentaje de Automatizacion---`
11. `<entero>` (porcentaje redondeado)
12. (línea en blanco)
13. (línea en blanco)

Ejemplo de bloque:
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

### Detalles importantes
- El porcentaje mostrado en consola puede incluir decimales, pero se guarda redondeado (`round`) en archivo.
- La opción “Consultas” toma el nombre de empresa desde la línea 1 del bloque y elimina el prefijo fijo `"Nombre de la empresa            :  "` (35 caracteres), convierte a minúsculas y quita espacios para comparar.
- El orden de los bloques y el espaciado deben mantenerse para que “Consultas”, “Nomina” y “Grafico” funcionen correctamente.

