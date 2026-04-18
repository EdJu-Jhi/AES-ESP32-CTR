import pandas as pd
import matplotlib.pyplot as plt

# 📂 cargar CSV
df = pd.read_csv("data/results.csv")

# 🧠 crear figura con 2 gráficos
fig, ax = plt.subplots(2, 1, figsize=(10, 8))

# 🔐 1. Cifrado (Encrypt)
ax[0].plot(df["iteracion"], df["encrypt_us"], color="blue")
ax[0].set_title("Tiempo de Cifrado AES-128 CTR (ESP32)")
ax[0].set_xlabel("Iteración")
ax[0].set_ylabel("Tiempo (µs)")
ax[0].grid(True)

# 🧠 2. Memoria
ax[1].plot(df["iteracion"], df["free_heap"], color="green")
ax[1].set_title("Memoria Libre (Heap) en ESP32")
ax[1].set_xlabel("Iteración")
ax[1].set_ylabel("Bytes libres")
ax[1].grid(True)

# 📊 ajuste final
plt.tight_layout()

# 💾 guardar imagen
plt.savefig("aes_memory_encrypt.png")

# 👀 mostrar
plt.show()
