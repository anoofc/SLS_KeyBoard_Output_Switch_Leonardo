
# 🕹️ DFRobot Leonardo Ethernet PoE - Keyboard + NeoPixel Switch Trigger

This Arduino sketch is designed to work with the **DFRobot Leonardo Ethernet PoE** board. It simulates a keyboard keypress when a button is pressed and provides visual feedback using a NeoPixel LED strip.

## 🔧 Hardware Requirements

- DFRobot Leonardo Ethernet with PoE (ATmega32u4)
- Push button (momentary switch)
- Adafruit NeoPixel LED strip (WS2812 or compatible)
- Resistor (330Ω recommended for data line)
- Capacitor (1000µF, 6.3V or higher recommended across power)
- Power source (via PoE, USB, or external 5V)
- Breadboard and jumper wires

## 📌 Pin Configuration

| Component        | Pin on Leonardo Board  |
|------------------|------------------------|
| NeoPixel DIN     | D3                     |
| Push Button      | D2 (with INPUT_PULLUP) |
| NeoPixel VCC     | 5V                     |
| NeoPixel GND     | GND                    |

## 💡 Behavior

- **Idle State (No Button Pressed):**
  - NeoPixels display solid **Red**
  - No keyboard activity

- **Button Pressed:**
  - NeoPixels change to **Blue**
  - Sends and holds keyboard key `'t'`

- **Button Released:**
  - NeoPixels return to **Red**
  - Releases all keyboard keys

## ⌨️ Keyboard Output

- Presses key `'t'` via USB HID interface when the button is pressed.
- Releases key when the button is released.
- Requires host system (PC/macOS/Linux) to accept USB keyboard input.

## 🧾 Constants and Definitions

```cpp
#define LED_PIN 3              // NeoPixel data pin
#define NUM_PIXELS 20          // Number of LEDs in the strip
#define SWITCH 2               // Button input pin
#define KEY 't'                // Key to press on trigger
#define DEBOUNCE 100           // Debounce time (ms)
#define RED 255,0,0
#define GREEN 0,255,0
#define BLUE 0,0,255
```

## 🔌 Setup Instructions

1. Wire the NeoPixel strip and button as per the pin configuration above.
2. Connect the DFRobot Leonardo to your computer via USB for programming.
3. Install the following libraries via the Arduino Library Manager:
   - `Adafruit NeoPixel`
   - `Keyboard` (built-in for ATmega32u4-based boards)
4. Upload the code using the Arduino IDE.
5. Open Serial Monitor (115200 baud) to see debug messages if `DEBUG` is enabled.

## 🧪 Testing

1. Once uploaded, the LEDs should glow **Red**.
2. Press the button → LEDs turn **Blue**, key `'t'` is sent.
3. Release the button → LEDs return to **Red**, key is released.

## 🛠️ Notes

- Use an external power supply or PoE if driving more than a few NeoPixels.
- Always use a resistor on the data line to protect the first LED.
- Use a capacitor across the NeoPixel VCC and GND for stability.

## 📜 License

MIT License. For Non-Commercial Use Only. Give credit to the author.

## 👨‍💻 Author

Developed by Anoof Chappangathil
Designed for DFRobot Leonardo Ethernet PoE projects.
