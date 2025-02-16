
#include "SD.h"
#include "FS.h"
#include "Wire.h"
#include "BluetoothA2DPSink.h"
#include "Rtc_Pcf8563.h"

#define SD_CS 5
#define INL 25
#define INR 26

Rtc_Pcf8563 rtc;
BluetoothA2DPSink a2dp_sink;
File musicFile;

// Array to hold song filenames for 7 days
const char* songList[7] = {
  "/song1.mp3",
  "/song2.mp3",
  "/song3.mp3",
  "/song4.mp3",
  "/song5.mp3",
  "/song6.mp3",
  "/song7.mp3"
};

void setup() {
  Serial.begin(115200);
  Wire.begin();
  rtc.begin();

  if (!SD.begin(SD_CS)) {
    Serial.println("Card Mount Failed");
    return;
  }

  a2dp_sink.start("ESP32_Music_Player");
  Serial.println("Bluetooth audio started.");
}

void loop() {
  RtcDateTime now = rtc.now();
  int day = now.Day() % 7;

  if (SD.exists(songList[day])) {
    musicFile = SD.open(songList[day]);
    if (musicFile) {
      a2dp_sink.set_stream_reader(read_music_stream);
      Serial.println("Playing: " + String(songList[day]));
    } else {
      Serial.println("Failed to open file");
    }
  }

  delay(60000); // Check once per minute
}

int read_music_stream(uint8_t *data, int length) {
  if (!musicFile.available()) {
    musicFile.close();
    return 0;
  }
  return musicFile.read(data, length);
}
