# Parcial práctico — Contador binario de 4 bits con Arduino

Repositorio para documentar el parcial práctico de un contador binario de 4 bits con Arduino, LEDs, simulación en Tinkercad y modificaciones del programa.

## Integrantes

- Integrante 1: Julian Jimenez
- Integrante 2: Juan Chancy
- Integrante 3: Santiago Polo
- Integrante 4: Jhon Olier

## Objetivo

Diseñar, construir, programar y documentar un contador binario de 4 bits utilizando Arduino y LEDs.

## Materiales

- Arduino UNO o compatible
- Protoboard
- 4 LEDs
- 4 resistencias de aproximadamente 220 Ω
- Cables jumper
- Pulsador
- Quinto LED para indicador

## Conexiones

| Elemento | Conexión |
|---|---:|
| LED bit 0 | Ping 9 |
| LED bit 1 | Ping 10 |
| LED bit 2 | Ping 11 |
| LED bit 3 | Ping 12 |
| Pulsador | Ping 8 |
| LED indicador | Ping 13 |

**GND:** Ping GND

## Funcionamiento del contador binario

Los cuatro LEDs representan valores binarios desde 0 (`0000`) hasta 15 (`1111`).

| Decimal | Binario | Estado de los LEDs |
|---:|:---:|---|
| 0 | `0000` | Todos apagados |
| 1 | `0001` | Bit 0 encendido |
| 2 | `0010` | Bit 1 encendido |
| 3 | `0011` | Bits 0 y 1 encendidos |
| ... | ... | ... |
| 15 | `1111` | Todos encendidos |

**Explicación:** El sistema binario es el sistema númerico mas simple que existe, ya que solo necesita poder estar en 2 estados, encendido o apagado, por medio de este sistema se puede crear una logica llamada logica booleana y tambien permite representar valores como números o letras.

## Código

Los programas estarán en [`codigo/`](codigo/).

- [ ] `contador_original.ino`
- [ ] `contador_velocidad.ino`
- [ ] `contador_descendente.ino`
- [ ] `contador_boton.ino`
- [ ] `contador_pares.ino`
- [ ] `contador_led_indicador.ino`

## Retos

### Reto 1 — Velocidad del contador

**Objetivo:** establecer un intervalo de `500 ms` mediante una variable como `waitDelay`.

**Modificación:** El valor de la variable llamada `tiempo_espera` fue cambiado a `500`

**Resultado:** El tiempo en el cual el contador se ejecutaba fue reducido a la mitad, es decir a medio segundo.

### Reto 2 — Contador descendente

**Secuencia:** `15, 14, 13, ... 2, 1, 0`.

**Modificación:** El valor de la variable `contador` fue cambiado a 15 y en vez de aumentar en 1 su valor lo disminuye.

**Resultado:** El número comienza en 15 y va disminuyendo hasta q llega a cero y se desborda asi volviendo a 15.

### Reto 3 — Control mediante botón

Cada pulsación debe avanzar una posición.

**Modificación:** En cuanto a lo físico se añadió un botón con una salida en el Ping 8 y en el Ping GND, y con una entrada en el Ping 5V con una resistencia de 10 KiloOhmios, y en cuanto a código se le dió un valor de `200` a `tiempo_espera` para evitar que se detecten varias pulsaciones con una sola, ademas de definir el boton a su respectivo Ping y aumentar la variable `contador` cuando este se pulse.

**Resultado:** El número aumenta bajo la nueva condición que es el pulsado del boton.

### Reto 4 — Números pares

**Secuencia:** `0, 2, 4, 6, 8, 10, 12, 14`.

**Modificación:** La variable `contador` en vez de aumentar en 1 ahora aumenta en 2.

**Resultado:** El número aumenta de 2 en 2 hasta q llega a 14 y luego desborda a 0.

### Reto 5 — LED indicador

El quinto LED debe encenderse cuando el contador llegue a `15` (`1111`).

**Modificación:** Se añadió un quinto led con Ping 13, en cuanto al código se definió y luego bajo una condicional if, se activa o desactiva al momento en el q el `contador` llegue a 16, porque el `contador` solo acumula valor al final de cada ciclo.

**Resultado:** Al prenderse todas las luces q representan a los bits, tambien se enciende el led indicador.

## Operaciones bit a bit

Se utilizará una expresión como:

```cpp
numero & (1 << bit)
```

### `&`

El operador `&` realiza una operación **AND bit a bit** entre dos números. Esto significa que compara los bits de ambos números y el resultado de cada posición solo es `1` cuando los dos bits que se comparan son `1`. Si uno de los dos es `0`, el resultado es `0`.

En el contador se utiliza para comprobar el estado de un bit específico del número. Por ejemplo, al hacer `numero & 1`, se puede comprobar si el bit 0 del número está encendido.

### `<<`

El operador `<<` realiza un **desplazamiento de bits hacia la izquierda**. Cada desplazamiento mueve los bits una posición hacia la izquierda y agrega ceros por la derecha.

Por ejemplo, `1 << 0` produce `0001`, mientras que `1 << 1` produce `0010`, `1 << 2` produce `0100` y `1 << 3` produce `1000`.

En el contador se utiliza para crear una máscara que permite seleccionar el bit que corresponde a cada LED.

### Determinación del estado de cada LED

La expresión utilizada es:

```cpp
int bit = (contador >> i) & 1;
```

Primero, `contador >> i` desplaza el número hacia la derecha tantas posiciones como indique `i`. De esta manera, el bit que queremos revisar queda en la posición 0.

Después, `& 1` comprueba ese bit. Si el resultado es `1`, significa que el bit está encendido y el LED correspondiente recibe `HIGH`. Si el resultado es `0`, el LED recibe `LOW` y permanece apagado.

Por ejemplo, si `contador = 5`, su representación es `0101`. Al recorrer `i` desde 0 hasta 3, el programa obtiene los estados `1, 0, 1, 0`, haciendo que los LEDs representen correctamente el número 5.

## Explicación del código

- `setup()`: Es una función predeterminada que se ejecuta una sola vez, ideal para definir.
- `loop()`: Es una función predeterminada que se ejecuta todo el tiempo en bucle, aque suele estar el nucleo del codigo
- `pinMode()`: Define que labor hará el ping, se le da el nombre y se establece si es entrada o salida.
- `digitalWrite()`: Permite enviar un estado `HIGH` o `LOW` a un pin digital, por ejemplo para encender o apagar un LED.
- `digitalRead()`: Permite leer el estado de un pin digital, por ejemplo para saber si un botón está presionado.
- `delay()`: Detiene temporalmente la ejecución del programa durante el tiempo indicado en milisegundos.
- Arreglos: Permiten guardar varios valores relacionados en una misma variable. En este caso se utiliza para guardar los pines de los LEDs.
- Ciclos `for`: Permiten repetir un bloque de código varias veces sin tener que escribirlo repetidamente.
- Operador `%`: Obtiene el residuo de una división. Puede utilizarse para comprobar si un número es par o impar.
- Operadores bitwise: Permiten trabajar directamente con los bits de un número. En este contador se utilizan para determinar qué LEDs deben estar encendidos.

## Evidencias

### Montaje físico

Guardar fotografías en [`evidencias/montaje_fisico/`](evidencias/montaje_fisico/).

- [ ] Montaje completo
- [ ] Arduino conectado
- [ ] Diferentes valores del contador
- [ ] Funcionamiento real
- [ ] Botón
- [ ] Quinto LED

### Simulación en Tinkercad

Guardar capturas en [`evidencias/simulacion/`](evidencias/simulacion/).

- [ ] Circuito base
- [ ] 500 ms
- [ ] Descendente
- [ ] Botón
- [ ] Números pares
- [ ] LED indicador

## Diagramas

Guardar los diagramas del circuito en [`diagramas/`](diagramas/).

- [ ] Circuito original
- [ ] Circuito con pulsador
- [ ] Circuito con LED indicador

## Lista de entrega

- [ ] Montaje físico
- [ ] Simulación Tinkercad
- [ ] Cinco programas
- [ ] Cinco retos documentados
- [ ] Operaciones bitwise explicadas
- [ ] README completado
- [ ] Fotografías
- [ ] Capturas de simulación
- [ ] Diagramas
- [ ] Video de funcionamiento
