<div align="center">

<img src="https://capsule-render.vercel.app/api?type=waving&color=0:005C97,100:363795&height=200&section=header&text=IoT%20Hovercraft&fontSize=48&fontColor=ffffff&desc=Steered%20over%20Wi-Fi%20from%20your%20phone&descAlignY=72&descSize=18&animation=fadeIn" width="100%" alt="IoT Hovercraft banner"/>

### 🛥️ A lightweight hovercraft that rides on a cushion of air — steered over Wi-Fi.

![ESP8266](https://img.shields.io/badge/NodeMCU%20ESP8266-E7352C?style=for-the-badge&logo=espressif&logoColor=white)
![Blynk](https://img.shields.io/badge/Blynk%20IoT-23C48E?style=for-the-badge)
![C++](https://img.shields.io/badge/Arduino%20C%2B%2B-00599C?style=for-the-badge&logo=arduino&logoColor=white)
![Servo](https://img.shields.io/badge/Servo%20steering-363795?style=for-the-badge)

</div>

---

## 📌 At a glance

> A lightweight hovercraft boat driven by **high-speed DC motors**, with a **servo** for steering. A **NodeMCU** connects it to the **Blynk** app, so the whole craft is controlled from a phone.

---

## 🔄 How it works

```mermaid
flowchart LR
    P[📱 Blynk app] <-->|Wi-Fi| N[NodeMCU ESP8266]
    N --> D[Motor driver] --> MA[🌀 High-speed motor A]
    D --> MB[💨 High-speed motor B]
    N --> R[4-ch relay] --> X[Extra loads]
    N --> S[Servo steering]
```

| Part | Role |
|---|---|
| **NodeMCU (ESP8266)** | Wi-Fi link and control |
| **2 × high-speed DC motors** | Propulsion |
| **Motor driver** | Forward / reverse for each motor |
| **4-channel relay** | Extra switched loads |
| **Servo** | Steering |

---

## 🎮 Controls

| Blynk pin | Action |
|:---:|---|
| `V4` / `V5` | Motor A forward / reverse |
| `V6` / `V7` | Motor B forward / reverse |
| `V0` – `V3` | Relays 1–4 |

---

## 💻 Code

[`IOT_based_Hovercraft.ino`](IOT_based_Hovercraft.ino):

```cpp
BLYNK_WRITE(V4) {                   // motor A forward
  if (param.asInt()) {
    digitalWrite(ENB, HIGH);
    digitalWrite(MOTORB_1, LOW);
    digitalWrite(MOTORB_2, HIGH);
  } else {
    digitalWrite(ENB, LOW);
  }
}
```

<details>
<summary><b>▶ How to run it</b></summary>

1. Install the **ESP8266 board package** and **Blynk** library
2. Enter **your own** Blynk auth token and Wi-Fi details
3. Connect the motor driver, relays and servo as defined at the top of the sketch
4. Add buttons for `V0`–`V7` in the Blynk app

</details>

---

## 🧠 What I learned

- ⚖️ **Lightweight design** — every gram matters on an air cushion
- 📶 **IoT control** of a craft that has no wheels and very little friction

---

<div align="center">

### 👋 Built by **Ajay Arjun Mannolkar**
[![Portfolio](https://img.shields.io/badge/Portfolio-technolkar.github.io-363795?style=for-the-badge&logo=githubpages&logoColor=white)](https://technolkar.github.io)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-ajaymannolkar-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/ajaymannolkar)
[![YouTube](https://img.shields.io/badge/YouTube-TECHNOL%20KAR-FF0000?style=for-the-badge&logo=youtube&logoColor=white)](https://www.youtube.com/@TechnolkarInnovations)

<img src="https://capsule-render.vercel.app/api?type=waving&color=0:363795,100:005C97&height=100&section=footer" width="100%"/>

</div>
