# PESER
- `Versión actual`: 0.0.0a

## Versión 0.0.0b
- [ ] `camara`: simular envio de imagen al nodo _procesador_ imitando el envio de imagenes de la camara. Enviar imagen en `data/img/` para simular dicho envio.
  - [ ] Comprobar si es mejor enviar la imagen en formato _OpenCV_ u otro formato.
  - [ ] Estudiar pasar imagen haciendo uso de _nodelets_.
- [ ] `procesador`: guardar imagen en formato _VisionWorks_ y _OpenCV_ crear función para comparar tiempo de ejecución de posibles funciones a utilizar de una libreria y otra.
- [x] Crear un _launch_ para ejecutar todos los nodos en orden y de forma cómoda.
- [ ] Poner el tipo de dato que se manda entre los elementos del sistema en los nodos

## Versión 0.0.0c
- [ ] Crear nodo `infoHandler`, encargado de guardar información en el sistema y llevar logs. 
- [ ] Hacer que el nodo `infoHandler` pueda recibir imágenes e información de los nodos `camara` y `procesador` para almacenarlas en disco 
- [ ] Explorar el uso de _SQLite_ para almacenar la información.
