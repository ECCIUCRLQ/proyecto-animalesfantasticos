# Introducción

En el actual proyecto se buscará hacer una simulación de un dispositivo. Específicamente el dispositivo se deberá de: capturar, transformar y filtrar fotos e imágenes. Esto se implementará a través de una serie de componentes, uno de ellos siendo el controlador o "driver". El "driver" cumplirá la función de comunicar algún programa con el dispositivo PCI. Por último, el componente faltante a este proyecto sería el programa de usuario. El programa de usuario es la manera que se tendrá de interactuar con el dispositivo y así verificar el funcionamiento correcto del mismo así como del driver y PCI. Una vez definido esto se debe aclarar que todo el proyecto se hará con la ayuda de la plataforma de Intel Simics en Linux, ahí es donde tendrá lugar la virtualización del dispositivo.

Como se mencionó anteriormente, el dispositivo tendrá la capacidad de capturar y filtrar imágenes. El formato para utilizar estas imágenes será BMP, ya que nos permite tener un mejor control de los píxeles de las imágenes sin ningún tipo de compresión. Esto llega a ser importante para el proyecto ya que facilita la implementación de los filtros, una de las funcionalidades que se busca implementar dentro del dispositivo. Una vez que el dispositivo sea capaz de capturar, procesar y aplicar filtros, a través del programa de usuario se deberá poner a prueba todo el sistema a través de pruebas de validación para verificar su correcto funcionamiento. Esta es una propuesta de trabajo por lo que está sujeta a cambios.
# Diagrama del dispositivo
![Diagrama Del sispositivo](/Diseño/Diagrama.jpg)

## Integrantes del repositorio actual:

Fabián Navarro Parraga - B85610

Esteban Rojas Carranza - C06816

Erlien Foulkes Barrantes - B93073

Kembly Paniagua Jiménez	 - B95822
