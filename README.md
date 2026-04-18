# AES-128 CTR Performance Analysis on ESP32

## 📌 Overview
This project evaluates the performance of AES-128 encryption in CTR mode on an ESP32 device. The goal is to analyze encryption time, memory usage, and system stability over 50 iterations.

The system uses Arduino IDE with the mbedTLS cryptographic library and logs results into a CSV file for analysis using Python.

---

## ⚙️ Hardware & Software
- ESP32 WROOM-32
- Arduino IDE
- mbedTLS library (AES implementation)
- Python (pandas, matplotlib)

---

## 📊 Metrics Collected
- Encryption time (µs)
- Decryption time (µs)
- Free heap memory (bytes)
- Iteration count (50 samples)

---

## 🧪 Methodology
1. ESP32 executes AES-128 CTR encryption and decryption.
2. Execution time is measured using microsecond precision timers.
3. Free heap memory is recorded during each iteration.
4. Data is exported to a CSV file.
5. Python is used to visualize results.

---

## 📈 Results

### 🔐 Encryption Performance
- Initial iteration shows higher latency (~47 µs)
- Stabilizes around ~11 µs after warm-up phase

### 🧠 Memory Usage
- Free heap remains stable (~334 KB)
- No memory leaks detected

---

## 📉 Graphical Analysis

The following graph shows encryption time and memory stability:

![AES Results](images/aes_memory_encrypt.png)

---

## 🧠 Interpretation
- AES-128 CTR execution stabilizes after initial iterations due to system warm-up.
- Memory usage remains constant, indicating efficient resource handling in ESP32.
- Results suggest that hardware acceleration (if present) improves consistency.

---

## 🚀 Conclusion
AES-128 CTR on ESP32 demonstrates stable encryption performance and negligible memory variation, making it suitable for IoT applications requiring lightweight cryptography.

---

## 📁 Project Structure
