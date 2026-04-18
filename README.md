# AES-128 CTR Performance Analysis on ESP32 (IoT Experiment)

## Overview
Este proyecto evalúa el rendimiento del algoritmo AES-128 en modo CTR implementado en un ESP32. El objetivo es analizar el tiempo de cifrado, descifrado y el uso de memoria en un entorno IoT real.

Se realizaron 50 iteraciones para observar la estabilidad del sistema y el comportamiento del algoritmo en condiciones repetitivas de ejecución.

---

## Hardware y software utilizados
Se utilizó un ESP32 WROOM-32 conectado por USB a una computadora. El desarrollo se realizó en Arduino IDE utilizando la librería mbedTLS para la implementación de AES.

Para el análisis de datos se utilizó Python con las librerías pandas y matplotlib.

---

## Metodología
El ESP32 ejecuta el cifrado AES-128 en modo CTR y registra en cada iteración:

- Tiempo de cifrado (microsegundos)
- Tiempo de descifrado (microsegundos)
- Memoria libre del sistema (heap)

Los datos se almacenan en un archivo CSV y posteriormente se procesan en Python para generar visualizaciones del comportamiento del sistema.

---

## Estructura del proyecto

AES-ESP32-CTR/
├── data/
│   └── results.csv
├── src/
│   └── aes_ctr.ino
├── plot.py
├── aes_results.png
└── README.md

---

## Resultados

En las mediciones se observa un comportamiento bastante estable del sistema.

El tiempo de cifrado se mantiene aproximadamente en 11 µs y el tiempo de descifrado en 10 µs durante la mayoría de las iteraciones.

Sin embargo, en la primera iteración se registra un valor mayor en el tiempo de cifrado (≈47 µs). Este comportamiento puede explicarse como un overhead inicial del sistema, asociado a la inicialización del contexto criptográfico AES, la preparación interna de la librería mbedTLS y la activación de optimizaciones del procesador en el ESP32.

Después de esta fase inicial, los valores se estabilizan y permanecen constantes durante el resto de las ejecuciones.

La memoria libre del sistema se mantiene estable alrededor de 334 KB, sin variaciones significativas.

---

## Visualización

Los datos fueron graficados utilizando Python. El gráfico muestra la evolución del tiempo de cifrado y descifrado a lo largo de las 50 iteraciones.

El resultado se guarda como:

aes_results.png

---

## Conclusión

El ESP32 muestra un rendimiento estable al ejecutar AES-128 en modo CTR. La baja variación en los tiempos de ejecución sugiere un comportamiento optimizado, posiblemente debido a soporte de aceleración por hardware para operaciones criptográficas.

El comportamiento inicial más alto no afecta la estabilidad general del sistema, ya que se normaliza rápidamente en las siguientes iteraciones.

---

## Posibles mejoras

Como trabajo futuro, se podría ampliar el estudio comparando AES con transmisión sin cifrado, integrar comunicación MQTT para un entorno IoT más real, y analizar el consumo energético del sistema durante el proceso de cifrado.

---

## Autor
Proyecto de experimentación en IoT y criptografía con ESP32.
