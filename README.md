# 🚨 XIAO ESP32C3 SOS Alert System (SIM800L + NEO-6M GPS)

## 🧭 Overview
An emergency SOS system using **XIAO ESP32C3**, **SIM800L GSM**, and **NEO-6M GPS** modules.  
It sends **SMS alerts with real-time GPS coordinates** and makes **automatic calls** via two buttons — one for **fire** 🔥 and one for **injury** 🩸.  
Fully standalone and works **without Wi-Fi**, ideal for remote or portable safety devices.

---

## ⚙️ Features
- 📍 Real-time GPS tracking using NEO-6M  
- 📲 SMS alerts with location via SIM800L  
- ☎️ Automatic phone call on second button press  
- 🔋 Battery powered for field use  
- 🧠 Simple and reliable hardware design  

---

## 🧩 Components
| Component | Description |
|------------|-------------|
| XIAO ESP32C3 | Main controller (Wi-Fi + BLE) |
| SIM800L | GSM module for SMS and calls |
| NEO-6M GPS | Provides latitude & longitude |
| Push Buttons (x2) | Fire and Injury triggers |
| Li-Po Battery | Portable power source |
| 10kΩ Resistors | Button pull-up/pull-down |

---

## 🔌 Wiring Summary
| Module | ESP32C3 Pin | Description |
|---------|--------------|-------------|
| SIM800L TX | D8 | ESP32 RX |
| SIM800L RX | D9 | ESP32 TX *(via resistor divider)* |
| NEO-6M TX | D6 | GPS to ESP32 RX |
| Fire Button | D2 | Fire alert trigger |
| Injury Button | D3 | Injury alert trigger |
| GND | GND | Common ground |
| Power | 4.0–4.2V | Stable supply for SIM800L |

---

## 🧠 How It Works
1. Press the **Fire** or **Injury** button once → sends SMS with GPS location.  
2. Press the same button again → system makes an emergency phone call.  
3. The GPS module continuously updates coordinates.  
4. SIM800L handles all GSM communication (SMS + call).  

---

## 🧾 Libraries Required
Install via Arduino Library Manager:
- `TinyGPS++`
- `SoftwareSerial`
- `Arduino Core for ESP32`

---

## 🧪 Example SMS Output
```
🔥 FIRE ALERT! Location: Lat: 22.5726, Lon: 88.3639
```

---

## 🚀 Future Improvements
- Add battery monitoring  
- Add LED or buzzer feedback  
- Create enclosure for portability  
- Integrate with IoT dashboard or Telegram alerts  

---

## 📜 License
Released under the **MIT License**.

---

### 💬 Short Description (for GitHub Summary)
> An emergency SOS system using XIAO ESP32C3, SIM800L, and NEO-6M GPS. Sends SMS alerts with live GPS location and makes automatic calls for fire 🔥 or injury 🩸 emergencies. Fully standalone and battery-powered.
