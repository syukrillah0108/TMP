#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

// Deklarasi layar OLED dengan I2C address 0x3C
#define OLED_RESET     -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// 'output_image', 128x32px
const unsigned char epd_bitmap_output_image [] PROGMEM = {
0xcf, 0x07, 0xff, 0x9c, 0x00, 0x3f, 0xff, 0xfb, 0xff, 0xc0, 0x00, 0x07, 0xf8, 0x3f, 0xc0, 0x00, 
	0xc7, 0x00, 0x7f, 0x9c, 0x00, 0x07, 0xff, 0x73, 0xff, 0xc0, 0x00, 0x07, 0xe0, 0x07, 0xc0, 0x00, 
	0xc7, 0x18, 0x1f, 0x9c, 0x7f, 0xc3, 0xfe, 0x73, 0xcf, 0xc7, 0xff, 0xc7, 0x83, 0xc3, 0xfe, 0x3f, 
	0xc7, 0x3f, 0x87, 0x9c, 0xff, 0xf1, 0xfc, 0x73, 0xc7, 0xcf, 0xff, 0xc7, 0x1f, 0xf1, 0xfe, 0x3f, 
	0xc7, 0x3f, 0xe3, 0x9c, 0xff, 0xf8, 0xf8, 0xf3, 0xe3, 0xcf, 0xff, 0x8e, 0x3f, 0xf8, 0xfe, 0x3f, 
	0xc7, 0x3f, 0xf1, 0x9c, 0xff, 0xfc, 0x71, 0xf3, 0xf3, 0xcf, 0xff, 0x1e, 0x7f, 0xfc, 0x7e, 0x3f, 
	0xc7, 0x3f, 0xf8, 0x1c, 0xff, 0xfe, 0x73, 0xf3, 0xf1, 0xcf, 0xfe, 0x1c, 0x7f, 0xfe, 0x7e, 0x3f, 
	0xc7, 0x3f, 0xfc, 0x1c, 0xff, 0xfe, 0x73, 0xf3, 0xf1, 0xc0, 0x00, 0x7c, 0x7f, 0xfe, 0x7e, 0x3f, 
	0xc7, 0x3f, 0xfe, 0x1c, 0xff, 0xfe, 0x73, 0xfb, 0xf1, 0xc0, 0x00, 0x7c, 0x7f, 0xfe, 0x7e, 0x3f, 
	0xc7, 0x3f, 0xfe, 0x1c, 0xff, 0xfe, 0x73, 0xff, 0xf1, 0xc7, 0xfc, 0x3c, 0x7f, 0xfe, 0x7e, 0x3f, 
	0xc7, 0x3f, 0xff, 0x1c, 0xff, 0xfc, 0x71, 0xff, 0xf3, 0xcf, 0xff, 0x1e, 0x7f, 0xfc, 0x7e, 0x3f, 
	0xc7, 0x3f, 0xff, 0x1c, 0xff, 0xf8, 0xf8, 0xff, 0xe3, 0xcf, 0xff, 0x8e, 0x3f, 0xf8, 0xfe, 0x3f, 
	0xc7, 0x3f, 0xff, 0x1c, 0xff, 0xf1, 0xfc, 0x7f, 0xc7, 0xcf, 0xff, 0xc7, 0x1f, 0xf0, 0xfe, 0x3f, 
	0xc7, 0x3f, 0xff, 0x9c, 0x7f, 0xe3, 0xfe, 0x3f, 0x0f, 0xc7, 0xff, 0xc7, 0x87, 0xe1, 0xfe, 0x3f, 
	0xc7, 0x3f, 0xff, 0x9c, 0x00, 0x07, 0xff, 0x00, 0x1f, 0xc0, 0x00, 0x07, 0xc0, 0x07, 0xfe, 0x3f, 
	0xcf, 0x3f, 0xff, 0x9c, 0x00, 0x3f, 0xff, 0xe0, 0xff, 0xc0, 0x00, 0x07, 0xf8, 0x3f, 0xfe, 0x3f, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xf8, 0xff, 0xfe, 0x07, 0xff, 0xc7, 0xff, 0xc0, 0x3f, 0xfc, 0x03, 0xfe, 0x7f, 0xcf, 0xf3, 0xf3, 
	0xf8, 0x7f, 0xf8, 0xf3, 0xff, 0xc3, 0xff, 0xc7, 0x0f, 0xfc, 0xff, 0xfe, 0x3f, 0x8f, 0xf9, 0xf3, 
	0xf2, 0x7f, 0xf1, 0xff, 0xff, 0x93, 0xff, 0xcf, 0xcf, 0xfc, 0xff, 0xfe, 0x1f, 0x0f, 0xfc, 0xe7, 
	0xf3, 0x3f, 0xf3, 0xff, 0xff, 0x99, 0xff, 0xcf, 0xe7, 0xfc, 0xff, 0xfe, 0x0e, 0x0f, 0xfe, 0x4f, 
	0xe7, 0x3f, 0xf3, 0xff, 0xff, 0x39, 0xff, 0xcf, 0xe7, 0xfc, 0x07, 0xfe, 0x4e, 0xcf, 0xfe, 0x1f, 
	0xe7, 0x1f, 0xf1, 0xff, 0xff, 0x38, 0xff, 0xcf, 0xe7, 0xfc, 0xff, 0xfe, 0x60, 0xcf, 0xff, 0x1f, 
	0xc0, 0x1f, 0xf1, 0xff, 0xfe, 0x00, 0xff, 0xcf, 0xcf, 0xfc, 0xff, 0xfe, 0x71, 0xcf, 0xff, 0x1f, 
	0x8f, 0xcf, 0xf8, 0xf3, 0xfc, 0x7e, 0x7f, 0xc7, 0x0f, 0xfc, 0xff, 0xfe, 0x7b, 0xcf, 0xff, 0x1f, 
	0x9f, 0xcf, 0xfe, 0x07, 0xfc, 0xfe, 0x7f, 0xc0, 0x3f, 0xfc, 0x03, 0xfe, 0x7f, 0xcf, 0xff, 0x3f, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

// Fungsi untuk menampilkan bitmap di layar OLED
void drawBitmap(const unsigned char* bitmap) {
  display.clearDisplay(); // Hapus layar
  // Gambar bitmap di posisi x=0, y=16 (bagian bawah layar, area biru)
  display.drawBitmap(0, 0, bitmap, 128, 32, WHITE); // Gambar bitmap
  display.display(); // Tampilkan di layar
}

void setup() {
  // Inisialisasi layar OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  
  display.display();
  delay(2000); // Tunggu 2 detik

  // Tampilkan gambar bitmap
  drawBitmap(epd_bitmap_output_image);
}

void loop() {
  // Kosongkan loop, tidak ada yang perlu dilakukan di sini
}