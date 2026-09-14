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

| Elemento | Pin Arduino | Función |
|---|---:|---|
| LED bit 0 (LSB) | [Pendiente] | Bit menos significativo |
| LED bit 1 | [Pendiente] | Segundo bit |
| LED bit 2 | [Pendiente] | Tercer bit |
| LED bit 3 (MSB) | [Pendiente] | Bit más significativo |
| Pulsador | [Pendiente] | Entrada digital |
| LED indicador | [Pendiente] | Indicador de 15 |

**GND:** [Pendiente]

## 🔢 Funcionamiento del contador binario

Los cuatro LEDs representan valores binarios desde 0 (`0000`) hasta 15 (`1111`).

| Decimal | Binario | Estado de los LEDs |
|---:|:---:|---|
| 0 | `0000` | Todos apagados |
| 1 | `0001` | Bit 0 encendido |
| 2 | `0010` | Bit 1 encendido |
| 3 | `0011` | Bits 0 y 1 encendidos |
| ... | ... | ... |
| 15 | `1111` | Todos encendidos |

**Explicación:** [Pendiente]

## Código

Los programas estarán en [`codigo/`](codigo/).

- [ ] `contador_original.ino`
- [ ] `contador_descendente.ino`
- [ ] `contador_boton.ino`
- [ ] `contador_pares.ino`
- [ ] `contador_led_indicador.ino`

## Retos

### Reto 1 — Velocidad del contador

**Objetivo:** establecer un intervalo de `500 ms` mediante una variable como `waitDelay`.

**Modificación:** [Pendiente]

**Resultado:** [Pendiente]

### Reto 2 — Contador descendente

**Secuencia:** `15, 14, 13, ... 2, 1, 0`.

**Modificación:** [Pendiente]

**Resultado:** [Pendiente]

### Reto 3 — Control mediante botón

Cada pulsación debe avanzar una posición.

**Modificación:** [Pendiente]

**Resultado:** [Pendiente]

### Reto 4 — Números pares

**Secuencia:** `0, 2, 4, 6, 8, 10, 12, 14`.

**Modificación:** [Pendiente]

**Resultado:** [Pendiente]

### Reto 5 — LED indicador

El quinto LED debe encenderse cuando el contador llegue a `15` (`1111`).

**Modificación:** [Pendiente]

**Resultado:** [Pendiente]

## Operaciones bit a bit

Se utilizará una expresión como:

```cpp
numero & (1 << bit)
```

### `&`

[Explicación pendiente]

### `<<`

[Explicación pendiente]

### Determinación del estado de cada LED

[Explicación pendiente]

## Explicación del código

- `setup()`: [Pendiente]
- `loop()`: [Pendiente]
- `pinMode()`: [Pendiente]
- `digitalWrite()`: [Pendiente]
- `digitalRead()`: [Pendiente]
- `delay()`: [Pendiente]
- Arreglos: [Pendiente]
- Ciclos `for`: [Pendiente]
- Operador `%`: [Pendiente, si se utiliza]
- Operadores bitwise: [Pendiente]

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
