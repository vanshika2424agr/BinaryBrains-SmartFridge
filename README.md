# 🧊 BinaryBrains – Smart Fridge

IoT based Smart Fridge system for food spoilage detection and real-time monitoring using Arduino.

## 📌 Problem Statement

Food wastage occurs due to lack of real-time monitoring of stored food items. Traditional refrigerators cannot detect spoilage gases, temperature variation, or door mismanagement, leading to health risks and financial loss.


## 💡 Proposed Solution

The Smart Fridge is an IoT-enabled hardware system that monitors food quality using sensors and automated logic.

The system uses:

- Arduino UNO (Main Controller)
- MQ-135 Gas Sensor (Spoilage Detection)
- DHT22 Sensor (Temperature & Humidity Monitoring)
- Magnetic Reed Switch (Door Detection)
- LCD Display (Real-time Status)
- Relay Module (Cooling Control)
- Buzzer (Alert System)

The system classifies food as:
FRESH / MODERATE / SPOILED


## ⚙️ Features

✔ Real-time gas detection  
✔ Temperature & humidity monitoring  
✔ Automatic door-open alert  
✔ Food spoilage classification  
✔ LCD live display  
✔ Low-cost IoT prototype  


## 🔄 Working Principle

1. Sensors collect temperature, humidity, and gas data.
2. Arduino processes sensor readings.
3. If gas level exceeds threshold → Food marked as spoiled.
4. If temperature rises → Cooling system controlled via relay.
5. If door remains open → Buzzer alert triggered.
6. LCD displays real-time system status.

---

## 🏗 System Architecture

INPUT → PROCESSING → OUTPUT

Inputs:
- MQ-135 Gas Sensor
- DHT22 Sensor
- Door Sensor

Processing:
- Arduino UNO

Outputs:
- LCD Display
- Buzzer Alert


## 📂 Repository Structure

code/ – Arduino source code  
circuit-diagram/ – Circuit schematic  
images/ – Prototype photos, block diagram, flowchart  
documentation/ – Project report & PPT  
bom/ – Bill of materials  

---

## 💰 Bill of Materials (Approx Cost)

| Component | Cost (INR) |
|------------|------------|
| Arduino UNO | 500 |
| MQ-135 | 250 |
| DHT22 | 300 |
| LCD 16x2 | 200 |
| Relay Module | 150 |
| Misc Components | 200 |

Total Estimated Cost: ₹1600 approx

---

## 🎯 Applications

- Households  
- Hotels & Restaurants  
- Hostels & Mess Facilities  
- Cold Storage Units  
- Smart Kitchens  

---

## 🚀 Future Scope

- Mobile App Integration  
- Cloud Data Logging  
- AI-based Food Recognition  
- Smart Restocking Integration  

---

## 👥 Team

Team Name: BINARY BRAINS  

---

