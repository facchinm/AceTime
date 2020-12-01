#!/usr/bin/python3
#
# Python script that regenerates the README.md from the embedded template. Uses
# ./generate_table.awk to regenerate the ASCII tables from the various *.txt
# files.

from subprocess import check_output

nano_results = check_output(
    "./generate_table.awk < nano.txt", shell=True, text=True)
micro_results = check_output(
    "./generate_table.awk < micro.txt", shell=True, text=True)
samd_results = check_output(
    "./generate_table.awk < samd.txt", shell=True, text=True)
esp8266_results = check_output(
    "./generate_table.awk < esp8266.txt", shell=True, text=True)
esp32_results = check_output(
    "./generate_table.awk < esp32.txt", shell=True, text=True)
teensy32_results = check_output(
    "./generate_table.awk < teensy32.txt", shell=True, text=True)

print(f"""\
# Memory Benchmark

The `MemoryBenchmark.ino` was compiled with each `FEATURE_*` and the flash
memory and static RAM sizes were recorded. The `FEATURE_BASELINE` selection is
the baseline, and its memory usage  numbers are subtracted from the subsequent
`FEATURE_*` memory usage.

**NOTE**: This file was auto-generated using `make README.md`. DO NOT EDIT.

**Version**: AceTime v1.3

## How to Regenerate

To regenerate this README.md:

```
$ make clean_benchmarks
$ make benchmarks
$ make README.md
```

The `make benchmarks` target uses `collect.sh` script which calls `auniter.sh`
(https://github.com/bxparks/AUniter) to invoke the Arduino IDE programmatically.
It produces a `*.txt` file with the flash and ram usage information (e.g.
`nano.txt`). It now takes about 16 minutes to generate the `*.txt` files on my
quad-core Intel Core i7-3840QM CPU @ 2.80GHz laptop.

The `make README.md` command calls the `generated_readme.py` Python script which
generates this `README.md` file. The ASCII tables below are generated by the
`generate_table.awk` script, which takes each `*.txt` file and converts it to an
ASCII table.

## Library Size Changes

In v1.3, the `BasicZoneManager` and `ExtendedZoneManager` classes were unified
under a new parent interface `ZoneManager`. This seems to have caused the flash
size to increase by around 1200 bytes on the AVR processors (Nano, Pro Micro),
about 500 bytes on a SAMD, about 800 bytes on a ESP8266, 100 bytes on a ESP32,
and 1400 bytes on a Teensy 3.2. The 8-bit processors suffer the most
flash size increase proportional to their limited 32kB limit.

Adding the `ZoneManager` interface simplifies a lot of the complexity with
saving and restoring time zones using the `TimeZoneData` object, and I think it
is worth the extra cost of flash size. The mitigating factor is that
applications targetted towards 8-bit processors will normally have fixed number
of timezones at compile time, so they can avoid using a `ZoneManager`, and avoid
this penalty in flash size.

## Arduino Nano

* Arduino IDE 1.8.13
* Arduino AVR Boards 1.8.3

```
{nano_results}
```

## Sparkfun Pro Micro

* Arduino IDE 1.8.13
* SparkFun AVR Boards 1.1.13

```
{micro_results}
```

## SAMD21 M0 Mini

* Arduino IDE 1.8.13
* Arduino SAMD Boards 1.8.9

```
{samd_results}
```

(SAMD compiler does not produce RAM usage numbers.)

## ESP8266

* Arduino IDE 1.8.13
* ESP8266 Boards 2.7.4

```
{esp8266_results}
```

## ESP32

* Arduino IDE 1.8.13
* ESP32 Boards 1.0.4

```
{esp32_results}
```

RAM usage remains constant as more objects are created, which indicates that an
initial pool of a certain minimum size is created regardless of the actual RAM
usage by objects.

## Teensy 3.2

* Arduino IDE 1.8.13
* Teensyduino 1.53

```
{teensy32_results}
```
""")
