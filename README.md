# STM32 Sensor Dashboard

A small embedded systems project: an STM32 microcontroller reads live sensor
data and streams it over UART to two different display clients — one built
in Python, one in Qt/C++ — as a way to compare rapid prototyping vs. a full
desktop application for the same data pipeline.

## Status
🚧 Work in progress — built as a summer learning project (2026).

## Project structure
- `firmware/` — STM32 C firmware (sensor reading + UART transmission), simulated in Wokwi
- `display-python/` — Python script for quick data visualization
- `display-qt/` — Qt/C++ desktop app for a full dashboard UI

## Goals
- Practice bare-metal STM32 programming (GPIO, I2C/SPI, UART)
- Compare a scripting-based vs. compiled desktop approach to the same problem
- Build real fluency with Git, debugging tools, and embedded toolchains

## Author
Assil — 2nd year Infotronics Systems Engineering, ENICarthage 