
# 💧 Smart Pot Water Level Monitoring System

This Arduino project monitors the water level in smart plant pots using a load cell sensor and sends SMS alerts with GPS location when the level drops below a critical threshold.

## 🛠️ Components Used

- **Arduino Uno/Nano**
- **HX711 Module** (for load cell/weight sensor)
- **Load Cell**
- **SIM900A GSM Module**
- **TinyGPS++ compatible GPS Module**
- **SoftwareSerial Library**

## ⚙️ How It Works

1. The **load cell** measures the weight of the pot (which indicates water level).
2. The **HX711 module** amplifies and sends this data to the Arduino.
3. If the measured value drops below 500 units:
   - GPS coordinates are fetched.
   - An SMS alert is sent via GSM containing the exact location of the low-water pot.

## 📡 Libraries Required

Install the following Arduino libraries before uploading the code:

- `HX711`
- `SoftwareSerial`
- `TinyGPS++`

## 📲 SMS Format

When triggered, the system sends an SMS with the format:

```
Water level low!
Location:
Latitude: <lat>
Longitude: <lon>
```

## 🚀 Getting Started

1. Connect all components as per pin configuration in the code:
   - HX711: `DOUT → Pin 6`, `CLK → Pin 7`
   - GPS: `TX → Pin 10`, `RX → Pin 11`
   - GSM: `RX → Pin 8`, `TX → Pin 9`
2. Upload the `main.ino` file to your Arduino board.
3. Ensure GSM module has a SIM card with SMS capabilities.

## 📏 Calibration

The current scale calibration factor is set to `100`. Adjust `cal` if needed to fine-tune weight measurements.
