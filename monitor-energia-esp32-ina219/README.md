# Sistema-IoT-de-consumo-energetico
Monitor de energía con ESP32 + INA219 y dashboard web (Web Serial)
# Sistema IoT de Consumo Energético

## Monitor de energía con ESP32 e INA219

Aplicación web desarrollada con HTML, CSS y JavaScript que permite visualizar las mediciones eléctricas obtenidas mediante un sensor INA219 conectado a un ESP32. La comunicación entre el microcontrolador y la aplicación se realiza mediante el puerto serial USB utilizando la API Web Serial del navegador.

El sistema permite visualizar el voltaje, la corriente y la potencia eléctrica en tiempo real, representar las mediciones mediante un gráfico, identificar estados estimados de las cargas conectadas y exportar los registros en formato CSV.

---

## 1. Características principales

- Conexión directa con el ESP32 mediante USB.
- Comunicación serial a 115200 baudios.
- Visualización del voltaje en carga.
- Visualización de la corriente eléctrica.
- Visualización de la potencia activa.
- Gráfico de voltaje y corriente en tiempo real.
- Registro de las últimas 50 mediciones.
- Clasificación estimada del uso de las cargas mediante rangos de potencia.
- Visualización de los datos recibidos desde el ESP32.
- Exportación de mediciones en formato CSV compatible con Excel.
- Interfaz web adaptable a diferentes tamaños de pantalla.

## 2. Tecnologías utilizadas

| Tecnología | Función |
|---|---|
| HTML5 | Estructura de la interfaz web. |
| CSS3 | Diseño y presentación visual. |
| JavaScript | Procesamiento de mediciones y funcionamiento de la aplicación. |
| Web Serial API | Comunicación entre el navegador y el ESP32 mediante USB. |
| Chart.js | Generación de gráficos de voltaje y corriente. |
| ESP32 | Adquisición y transmisión de las mediciones. |
| INA219 | Medición de voltaje, corriente y potencia. |

## 3. Requisitos del sistema

### 3.1. Requisitos de hardware

Para utilizar la aplicación se necesita:

- Una computadora con puerto USB.
- Una placa de desarrollo ESP32.
- Un sensor de corriente y voltaje INA219.
- Cable USB compatible con la placa ESP32 y que permita transferencia de datos.
- Circuito de pruebas con las cargas eléctricas utilizadas en el proyecto.

### 3.2. Requisitos de software

Instalar o disponer de los siguientes programas:

| Software | Requisito | Uso |
|---|---|---|
| Google Chrome | Versión de escritorio compatible con Web Serial | Ejecutar la aplicación. |
| Microsoft Edge | Versión de escritorio compatible con Web Serial | Alternativa para ejecutar la aplicación. |
| Visual Studio Code | Opcional | Editar y administrar los archivos. |
| Live Server | Opcional | Ejecutar la aplicación desde un servidor local. |
| Arduino IDE | Necesario para preparar el ESP32 | Compilar y cargar el firmware. |

**Importante:** No se necesita instalar Node.js, npm, PHP, MySQL, PostgreSQL ni configurar un backend para ejecutar el archivo `index.html`.

## 4. Dependencias de la aplicación web

La aplicación utiliza Chart.js para generar el gráfico de mediciones.

La biblioteca se incorpora mediante el siguiente enlace incluido en el archivo HTML:

```html
<script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
```

Esto significa que:

- No es necesario instalar Chart.js mediante npm.
- No es necesario descargar manualmente la biblioteca.
- Se necesita conexión a Internet para cargarla desde el CDN, salvo que se disponga de una copia local.
- Si Chart.js no se carga, las mediciones y la tabla pueden seguir funcionando, pero el gráfico no estará disponible.

La comunicación serial se realiza mediante Web Serial API, que forma parte de las funcionalidades del navegador compatible. No necesita instalarse como una biblioteca adicional.

## 5. Instalación y configuración

### 5.1. Obtener el proyecto

Clonar el repositorio desde GitHub:

```bash
git clone https://github.com/NestorRamirezCaero/Sistema-IoT-de-consumo-energetico.git
```

Ingresar a la carpeta del proyecto:

```bash
cd Sistema-IoT-de-consumo-energetico
```

Ingresar a la carpeta de la aplicación:

```bash
cd monitor-energia-esp32-ina219
```

La organización lógica de los archivos principales es la siguiente:

```text
Sistema-IoT-de-consumo-energetico/
│
└── monitor-energia-esp32-ina219/
    │
    ├── esp32_ina.ino
    │
    ├── index.html
    │
    └── README.md
```

- `esp32_ina.ino`: firmware encargado de obtener y transmitir las mediciones desde el ESP32.
- `index.html`: aplicación web que recibe, procesa y presenta las mediciones.
- `README.md`: documentación de instalación, configuración y ejecución del proyecto.

### 5.2. Preparar el ESP32

Para utilizar el sistema, el ESP32 debe tener cargado el firmware correspondiente al proyecto.

1. Instalar Arduino IDE desde su página oficial: https://www.arduino.cc/en/software
2. Configurar el soporte para placas ESP32 mediante el administrador de placas de Arduino IDE.
3. Instalar la biblioteca `Adafruit INA219` desde el administrador de bibliotecas.
4. Abrir el archivo `esp32_ina.ino`.
5. Seleccionar la placa ESP32 correspondiente.
6. Seleccionar el puerto COM asignado por el sistema operativo.
7. Compilar y cargar el programa en el ESP32.

**Configuración de comunicación:**

| Parámetro | Configuración |
|---|---|
| Velocidad serial | 115200 baudios |
| Comunicación con INA219 | I2C |
| Pin SDA | GPIO 21 |
| Pin SCL | GPIO 22 |
| Alimentación del sensor | 3.3 V |
| Referencia de tierra | GND |

La conexión física debe respetar el esquema eléctrico del prototipo.

### 5.3. Verificar la transmisión serial

Después de cargar el firmware:

1. Abrir el Monitor Serie de Arduino IDE.
2. Configurar la velocidad en 115200 baudios.
3. Verificar que el ESP32 transmita los datos de medición.
4. Comprobar que aparezcan las etiquetas utilizadas por la aplicación.
5. Cerrar el Monitor Serie antes de utilizar la aplicación web.

La aplicación espera recibir información con las siguientes etiquetas:

```text
Voltaje en Carga: valor
Corriente Actual: valor
Potencia Activa: valor
```

Los valores deben corresponder a las mediciones realizadas por el INA219. La aplicación procesa las líneas recibidas y registra una medición cuando dispone de los tres valores.

**Importante:** El Monitor Serie y la aplicación web no deben utilizar simultáneamente el mismo puerto COM.

## 6. Ejecución de la aplicación web

Existen dos alternativas para ejecutar el archivo `index.html`.

### 6.1. Opción 1: utilizando Visual Studio Code y Live Server

1. Abrir Visual Studio Code.
2. Seleccionar la opción `File > Open Folder`.
3. Abrir la carpeta `monitor-energia-esp32-ina219`.
4. Instalar la extensión **Live Server** desde el apartado de extensiones.
5. Abrir el archivo `index.html`.
6. Hacer clic derecho sobre el archivo.
7. Seleccionar `Open with Live Server`.

El navegador abrirá una dirección local similar a:

```text
http://127.0.0.1:5500/index.html
```

### 6.2. Opción 2: utilizando Python

Si se tiene Python instalado, también se puede iniciar un servidor local sin instalar extensiones adicionales.

Abrir una terminal dentro de la carpeta donde se encuentra `index.html` y ejecutar:

```bash
python -m http.server 8000
```

En Windows, si el comando anterior no funciona, probar:

```bash
py -m http.server 8000
```

Después, abrir Google Chrome o Microsoft Edge y acceder a:

```text
http://localhost:8000
```

Para detener el servidor, regresar a la terminal y presionar:

```text
Ctrl + C
```

**Nota:** Se recomienda utilizar `localhost` o `127.0.0.1` para ejecutar la aplicación. Web Serial necesita un contexto seguro y estos orígenes locales están permitidos por los navegadores compatibles.

## 7. Conexión con el ESP32

Una vez abierta la aplicación:

1. Conectar el ESP32 a la computadora mediante USB.
2. Verificar que el firmware esté cargado correctamente.
3. Cerrar el Monitor Serie de Arduino IDE.
4. Abrir la aplicación web en Google Chrome o Microsoft Edge de escritorio.
5. Presionar el botón **Conectar ESP32**.
6. Seleccionar el puerto correspondiente a la placa ESP32 en la ventana del navegador.
7. Confirmar la conexión.

Cuando la comunicación se establezca correctamente, el estado cambiará de `DESCONECTADO` a `CONECTADO`.

La aplicación comenzará a recibir las mediciones transmitidas por el microcontrolador aproximadamente cada dos segundos.

## 8. Funcionamiento de la interfaz

### 8.1. Indicadores de medición

La interfaz presenta los siguientes valores:

- **Voltaje en carga:** voltaje registrado por el sensor INA219.
- **Corriente actual:** corriente eléctrica registrada en miliamperios.
- **Potencia activa:** potencia calculada y transmitida por el ESP32, expresada en milivatios.
- **Voltaje total inicial:** campo para introducir manualmente el voltaje inicial.
- **Voltaje total usado:** diferencia calculada entre el voltaje inicial ingresado y el voltaje medido en la carga.

El último indicador representa una diferencia de voltaje, no un cálculo de energía consumida.

### 8.2. Gráfico en tiempo real

El gráfico permite observar el comportamiento de:

- Voltaje en carga (V).
- Corriente actual (mA).

Los valores se actualizan conforme llegan nuevas mediciones desde el ESP32.

### 8.3. Registro de mediciones

La tabla presenta las últimas 50 mediciones recibidas, incluyendo:

- Número de registro.
- Hora de medición.
- Voltaje.
- Corriente.
- Potencia.
- Uso estimado de las cargas.

Los registros se mantienen temporalmente en la memoria de la aplicación mientras esta permanece abierta. No se utiliza una base de datos ni almacenamiento permanente.

### 8.4. Exportación de datos

Para exportar las mediciones:

1. Esperar a que la aplicación reciba registros.
2. Presionar el botón **Exportar a Excel (CSV)**.
3. El navegador descargará un archivo con nombre similar a:

```text
mediciones_ina219_2026-11-07.csv
```

El archivo puede abrirse mediante Microsoft Excel u otros programas compatibles con CSV.

**Importante:** La exportación corresponde a los registros disponibles en la memoria de la aplicación. Si se recarga o se cierra la página, las mediciones que no se hayan exportado se pierden.

## 9. Solución de problemas

| Problema | Posible causa | Solución |
|---|---|---|
| El navegador no permite conectar el ESP32. | Navegador incompatible o contexto no seguro. | Utilizar Chrome o Edge de escritorio y abrir la aplicación desde localhost. |
| No aparece el puerto COM. | Cable USB sin transferencia de datos, controlador faltante o placa desconectada. | Comprobar el cable, la conexión USB y el controlador correspondiente al chip USB-serial de la placa. |
| No se puede abrir el puerto. | Otro programa está utilizando el puerto serial. | Cerrar el Monitor Serie de Arduino IDE u otro programa que utilice el puerto. |
| La aplicación se conecta, pero no muestra mediciones. | El firmware no está transmitiendo o utiliza una velocidad diferente. | Verificar que el firmware esté cargado y configurado a 115200 baudios. |
| Los valores no se actualizan. | Problema de comunicación entre el ESP32 y el navegador. | Revisar el cable USB, el puerto seleccionado y la transmisión serial. |
| El gráfico no aparece. | Chart.js no pudo cargarse. | Comprobar la conexión a Internet y volver a cargar la página. |
| El INA219 no registra valores correctos. | Conexiones incorrectas o problema de alimentación. | Revisar las conexiones I2C, SDA, SCL, VCC y GND. |
| No se descarga el CSV. | No existen mediciones registradas. | Esperar a recibir datos antes de exportar. |

## 10. Consideraciones y limitaciones

- La aplicación requiere un navegador de escritorio compatible con Web Serial API.
- La comunicación con el ESP32 se realiza mediante USB y puerto serial.
- La velocidad de comunicación configurada es de 115200 baudios.
- Las mediciones se reciben aproximadamente cada dos segundos.
- Los datos se almacenan temporalmente en memoria y se limita el registro a las últimas 50 mediciones.
- No se utiliza una base de datos ni almacenamiento permanente.
- Chart.js se carga desde un CDN externo.
- La identificación de las cargas se realiza mediante rangos de potencia configurados en el código; por tanto, representa una estimación del estado de las cargas y no una medición independiente de cada una.
- La aplicación no requiere conexión Wi-Fi entre el ESP32 y la computadora.

## 11. Referencias

- Arduino. Documentación oficial de Arduino IDE. https://docs.arduino.cc/software/ide/
- Adafruit Industries. Documentación del sensor INA219. https://learn.adafruit.com/adafruit-ina219-current-sensor-breakout/overview
- Espressif Systems. Documentación de Arduino ESP32. https://docs.espressif.com/projects/arduino-esp32/en/latest/
- MDN Web Docs. Web Serial API. https://developer.mozilla.org/en-US/docs/Web/API/Web_Serial_API
- Chart.js. Documentación oficial. https://www.chartjs.org/docs/latest/

---

**Proyecto:** Sistema IoT de Consumo Energético  
**Plataforma:** ESP32 + INA219 + Aplicación Web  
**Comunicación:** USB / Puerto Serial  
**Interfaz:** HTML5, CSS3 y JavaScript  
**Visualización:** Chart.js
