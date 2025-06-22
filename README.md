# 📦 Pomodoro Box – A Hardware Fix for Digital Distraction

### A DIY embedded solution to help beat mobile addiction using STM32, a servo lock, and an LCD display.

---

## ✨ About the Project

Like many people, I struggle with mobile distraction during study hours. Apps didn’t help — so I built a **hardware-based solution**.

The **Pomodoro Box** is a microcontroller-powered, timer-based lockbox. Once you set the timer and press OK, the box locks shut using a servo-driven latch. It stays locked until the countdown ends. No app hacks, no snoozing.

---

## 🔧 Built With

- **STM32F4** (STM32CubeIDE, HAL drivers)
- **I2C 16x2 LCD** (with PCF8574 backpack)
- **Servo Motor (SG90)**
- **Pushbuttons** for input
- **Timers & PWM** for countdown + servo control
- **C (baremetal/HAL)**

---



## 🚀 How It Works

1. Power up the device.
2. LCD prompts: *“Hey Rudra, Study! Let's set timer now, ok?”*
3. Use pushbuttons to increase/decrease minutes.
4. Press OK — the servo locks the box.
5. Timer counts down in MM:SS format.
6. Once time is up, the servo unlocks.

---

## 💡 Future Improvements

- 🔐 Add **Wi-Fi override (ESP8266)** to unlock in emergencies.
- 🌙 Switch to **OLED display** to save power.
- 🔋 Make it **portable**: add 3.7V Li-ion + TP4056 + boost converter.
- 💤 Use **STM32's STOP/STANDBY** modes to improve battery life.
- ⏱️ Consider using an **RTOS** if complexity increases in v2.

---

## 🤝 Contributing

If you’re into embedded systems and have ideas for version 2, I’d love to hear from you! Open an issue or fork the repo and suggest a pull request.

---

## 📄 License

This project is open-sourced under the terms provided in the `LICENSE` file (or you can apply the MIT License).

---

## 🔗 Connect

📫 [Connect with me on LinkedIn](https://www.linkedin.com/in/rudradeep-palit/)

---

> *The Pomodoro Box began as a personal solution to a focus problem — but became a fun embedded learning experience. Let's build more things that actually solve our own problems.*
