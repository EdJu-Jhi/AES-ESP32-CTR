#include <mbedtls/aes.h>

mbedtls_aes_context aes;

unsigned char key[16] = {
  0x00,0x01,0x02,0x03,
  0x04,0x05,0x06,0x07,
  0x08,0x09,0x0A,0x0B,
  0x0C,0x0D,0x0E,0x0F
};

unsigned char input[16] = "SensorData12345";
unsigned char encrypted[16];
unsigned char decrypted[16];

// ⚠️ IMPORTANTE: ESP32 usa size_t aquí
size_t nc_off_enc = 0;
size_t nc_off_dec = 0;

unsigned char nonce_counter[16] = {0};
unsigned char stream_block[16] = {0};

void setup() {
  Serial.begin(115200);
  delay(2000);

  mbedtls_aes_init(&aes);
  mbedtls_aes_setkey_enc(&aes, key, 128);

  Serial.println("iteracion,encrypt_us,decrypt_us,free_heap");
}

void loop() {

  for (int i = 1; i <= 50; i++) {

    uint32_t mem = ESP.getFreeHeap();

    unsigned long t1 = micros();

    // 🔐 CIFRADO CTR
    mbedtls_aes_crypt_ctr(
      &aes,
      16,
      &nc_off_enc,
      nonce_counter,
      stream_block,
      input,
      encrypted
    );

    unsigned long t2 = micros();

    // 🔓 DESCIFRADO CTR
    mbedtls_aes_crypt_ctr(
      &aes,
      16,
      &nc_off_dec,
      nonce_counter,
      stream_block,
      encrypted,
      decrypted
    );

    unsigned long t3 = micros();

    Serial.print(i);
    Serial.print(",");
    Serial.print(t2 - t1);
    Serial.print(",");
    Serial.print(t3 - t2);
    Serial.print(",");
    Serial.println(mem);

    delay(200);
  }

  while (1);
}
