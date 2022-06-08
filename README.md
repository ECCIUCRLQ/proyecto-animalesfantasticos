# Introducción

En el actual proyecto se buscará hacer una simulación de un dispositivo. Específicamente el dispositivo se deberá de: capturar, transformar y filtrar fotos e imágenes. Esto se implementará a través de una serie de componentes, uno de ellos siendo el controlador o "driver". El "driver" cumplirá la función de comunicar el dispositivo PCI con el sistema operativo. Por último, el componente faltante a este proyecto sería el programa de usuario. El programa de usuario es la manera que se tendrá de interactuar con el dispositivo y así verificar el funcionamiento correcto del mismo así como del driver y PCI. Una vez definido esto se debe aclarar que todo el proyecto se hará con la ayuda de la plataforma de Intel Simics en Linux, ahí es donde tendrá lugar la virtualización del dispositivo.

Como se mencionó anteriormente, el dispositivo tendrá la capacidad de capturar y filtrar imágenes. El formato para utilizar estas imágenes será BMP, ya que nos permite tener un mejor control de los píxeles de las imágenes sin ningún tipo de compresión. Esto llega a ser importante para el proyecto ya que facilita la implementación de los filtros, una de las funcionalidades que se busca implementar dentro del dispositivo. Una vez que el dispositivo sea capaz de capturar, procesar y aplicar filtros, a través del programa de usuario se deberá poner a prueba todo el sistema a través de pruebas de validación para verificar su correcto funcionamiento. Esta es una propuesta de trabajo por lo que está sujeta a cambios.

# Lista de habilidades necesarias para la realización del proyecto.

Somos conscientes como grupo de trabajo que implementar un dispositivo virtualizado el cual tenga una función de capturar y procesar imágenes no será nada fácil, por cual es importante definir las habilidades que serán importantes para lógralo. En primer lugar, las habilidades de tipo social serán indispensables, ya que se deber contar con una buena comunicación y coordinación. Esto se puede ver ejemplificado en el caso de la comunicación de dudas, para hacerlas de la manera más concisa, clara y puntual posible.
 
Otra habilidad indispensable para el desarrollo de este proyecto es el de la investigación, ya que algunos de los requerimientos necesarios para llevar a cabo una buena implementación del dispositivo es la búsqueda de información y el que se amplíe el conocimiento de los miembros del equipo lo más posible en los temas relacionados.Por ejemplo. Algunos de estos  temas pueden llegar a ser: la creación de un driver o la aplicación de los filtros a las imágenes, lenguaje ensamblador, correcto uso de simics y cómo virtualizar un dispositivo PCI.
 
Así mismo, la habilidad de la perseverancia debe de estar puesta en uso, ya que al programar un proyecto de este nivel con un equipo de trabajo, se tiene que tener en cuenta que las cosas no van a salir bien siempre a la primera, por eso las habilidades de perseverar y comunicarse con el equipo siempre deben estar ahí. Esto en la parte más abstracta, ya que en la parte práctica vamos a tener que ejercitar nuestra habilidad para aprender y crear código donde se debe concentrar casi todos los esfuerzos, ya que si la parte práctica se ejecuta bien, el resto de cosas tienden a salir bien también. 

# Filtros a usar

* Blanco y negro: Este filtro se caracteriza por volver negro los colores oscuros, y blanco los colores mas claros.
* Negativo: Este filtro se enfoca en volver las luces en tonos oscuros, y las sombras en tonos claros.
* Desenfoque Gaussiano: Este filtro consiste en aplicar una función matemática a una imagen para desenfocar y así crear un efecto borroso.
* Sepia: Este filtro busca imitar las fotos antiguas las cuales eran impresas y tenían una coloración del tinte de sepia, el cual es oscuro y semi rojizo.

# Diseño del proyecto

![Diagrama Del dispositivo](/Diseño/Diagrama.jpg)
![Leyenda Del sispositivo](/Diseño/Leyenda_Diagrama.jpg)

## Integrantes del repositorio actual:

Fabián Navarro Parraga - B85610

Esteban Rojas Carranza - C06816

Erlien Foulkes Barrantes - B93073

Kembly Paniagua Jiménez	 - B95822
