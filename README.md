# NRTF-CONQUERS
# Energy Monitoring and Forecasting System

## Description

This project consists of three code snippets demonstrating different aspects related to energy monitoring, blockchain implementation, and time-series forecasting using ARIMA model.

1. **Blockchain Implementation**
    - File: `blockchain.py`
    - Description: Implements a basic blockchain data structure in Python.

2. **WiFi Connectivity with ESP32 and Sensor Data Transmission**
    - File: `sensor_wifi_esp32.ino`
    - Description: Arduino code for ESP32 microcontroller to read sensor data (BMP180 pressure and temperature sensor) and transmit it over WiFi to a server.

3. **Time-Series Forecasting using ARIMA Model**
    - File: `energy_forecasting.py`
    - Description: Python code to perform time-series forecasting on historical energy data using the ARIMA model. It also includes data preprocessing, model training, and forecast evaluation.

## Usage

### Blockchain Implementation
- Run the `blockchain.py` script in a Python environment.
- This script demonstrates the implementation of a basic blockchain.

### WiFi Connectivity with ESP32 and Sensor Data Transmission
- Upload the `sensor_wifi_esp32.ino` code to an ESP32 microcontroller using the Arduino IDE.
- Ensure to replace placeholders for WiFi SSID, password, and server address with appropriate values.
- The ESP32 will read data from the BMP180 sensor and transmit it over WiFi to the specified server.

### Time-Series Forecasting using ARIMA Model
- Run the `energy_forecasting.py` script in a Python environment.
- Ensure to have the required dependencies installed (`pandas`, `numpy`, `statsmodels`, `sklearn`).
- This script performs time-series forecasting on historical energy data using the ARIMA model and evaluates the forecast performance.

## Dependencies

- For Blockchain Implementation (Python):
    - hashlib
    - json
    - time

- For WiFi Connectivity with ESP32 (Arduino):
    - Adafruit_BMP085 library
    - WiFi library
    - Wire library

- For Time-Series Forecasting (Python):
    - pandas
    - numpy
    - statsmodels
    - sklearn

## Data
- Ensure to provide historical energy data in CSV format (`historical_energy_data.csv`) for the time-series forecasting code.

## Integration with Energy Management Systems (EMS)
- The forecasted energy demand/generation values can be integrated into an EMS for further actions such as load scheduling, energy procurement, etc.
