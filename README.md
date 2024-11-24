# ESP32 FreeRTOS LED Blinking Example

This project demonstrates how to create two FreeRTOS tasks to control two LEDs connected to the ESP32 microcontroller.

### Features:
- Task 1 toggles LED connected to GPIO2 every 500ms.
- Task 2 toggles LED connected to GPIO4 every 1000ms.

## Prerequisites

Before you begin, make sure you have the following installed:

1. **ESP32 Toolchain**
   - Install the official [ESP32 toolchain](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/).
   
2. **ESP-IDF (Espressif IoT Development Framework)**
   - Follow the [official guide](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/) to set up ESP-IDF on your system. This includes:
     - Cloning the ESP-IDF repository.
     - Setting up the required Python packages.
     - Setting up the environment for ESP32 development.

3. **Python (for ESP-IDF setup)**
   - Python version 3.6 or higher is required.

## Setup Instructions

1. **Clone the repository**
   - Clone this repository to your local machine:
   
     ```bash
     git clone https://github.com/your-repository/esp32-led-blink.git
     cd esp32-led-blink
     ```

2. **Set up ESP-IDF environment**
   - Initialize the ESP-IDF environment:

     ```bash
     . $HOME/esp/esp-idf/export.sh
     ```

3. **Install required Python dependencies**

   ```bash
   pip install -r requirements.txt
   ```

4. **Configure the project**
   - Run the configuration tool to set up your ESP32 device settings:

     ```bash
     idf.py menuconfig
     ```

   - In this menu, you can configure parameters like your target ESP32 board, flash size, and other settings. For basic flashing, the default options should be sufficient.

## Compiling the Code

1. **Compile the project**
   - To compile the code for your ESP32 device, run:

     ```bash
     idf.py build
     ```

   - This command will compile the source code and generate the necessary binary files.

## Flashing the Firmware to ESP32

1. **Connect your ESP32 device to your computer**
   - Use a USB-to-serial adapter if necessary.

2. **Flash the firmware**
   - Once your ESP32 is connected, run the following command to flash the compiled firmware:

     ```bash
     idf.py -p (YOUR_PORT) flash
     ```

     Replace `(YOUR_PORT)` with the correct serial port for your ESP32 device (e.g., `/dev/ttyUSB0` on Linux or `COMx` on Windows).

3. **Monitor the ESP32 output**
   - After flashing, you can monitor the output of your ESP32 via the serial terminal:

     ```bash
     idf.py -p (YOUR_PORT) monitor
     ```

   - You should see the LEDs blinking based on the defined timings (500ms for LED1 and 1000ms for LED2).

## Code Explanation

- **`task1`**: This task controls the LED connected to GPIO2 and toggles it every 500ms.
- **`task2`**: This task controls the LED connected to GPIO4 and toggles it every 1000ms.
- **`app_main`**: This function initializes the GPIO pins for LED control and creates the two tasks using FreeRTOS.

## Troubleshooting

- If the serial monitor shows no output, check that the ESP32 is properly connected to the correct port.
- If you encounter any build errors, ensure that you have correctly set up the ESP-IDF environment and dependencies.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
