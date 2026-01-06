# Software I2C (Bit-Banged) Real-Time Clock Display System  
**Arduino Mega | Embedded C | Systems-Level Design**

## Overview
This project presents a **software-implemented (bit-banged) I2C communication stack** developed in **Embedded C** for the Arduino Mega platform. The system interfaces with a **DS1307 Real-Time Clock (RTC)** and displays real-time data on a **16x2 LCD** via a **PCF8574 I/O expander**, without using Arduino’s hardware I2C (`Wire`) library.

The work is designed with a **product-oriented and research-driven mindset**, focusing on **protocol-level understanding, portability, and deterministic timing control**—key requirements in real-world embedded systems and hardware-focused startups such as **Neonflake**.



## Why This Project
This project demonstrates:
- Protocol implementation from scratch  
- Hardware abstraction through reusable drivers  
- Embedded C practices aligned with production firmware  

---

## Key Features
- Full **software I2C (bit-banged) master implementation**
- Direct **DS1307 RTC communication** without `Wire` library
- LCD control via **PCF8574 I/O expander**
- Modular driver architecture for maintainability
- Timing-safe GPIO manipulation
- Designed for portability across microcontrollers

---

## Hardware Requirements
- Arduino Mega 2560  
- DS1307 Real-Time Clock module  
- 16x2 LCD display  
- PCF8574 I2C I/O expander  
- Pull-up resistors (I2C lines)  
- Breadboard and jumper wires  

---

## Software Requirements
- Arduino IDE  
- AVR-GCC toolchain  
- Wokwi simulator (optional, for validation and testing)

---

## Project Structure

├── main.ino # Application entry point
├── i2c_master.c/.h # Software I2C master driver
├── ds1307rtc.c/.h # RTC abstraction layer
├── pcf8574.c/.h # I/O expander driver
├── lcd.c/.h # LCD control logic
├── lcd_system.h # LCD system definitions
├── timer.c/.h # Timing and delay utilities
├── diagram.json # Wokwi simulation diagram
└── wokwi-project.txt # Wokwi project configuration



---

## Technical Explanation

### 1. Software I2C (Bit-Banging)
Instead of using the microcontroller’s hardware I2C peripheral, this project implements the I2C protocol by **manually controlling GPIO pins**:

- START and STOP condition generation  
- Clock stretching via software delays  
- Byte-level read/write operations  
- ACK/NACK handling  

This approach provides:
- Complete protocol visibility  
- Microcontroller independence  
- Greater flexibility for custom hardware constraints  

---

### 2. RTC Driver (DS1307)
The RTC driver:
- Communicates over the custom I2C layer  
- Reads time registers in **BCD format**  
- Converts values into human-readable form  
- Abstracts hardware-specific details from the application layer  

This separation allows easy migration to other RTC modules.

---

### 3. LCD Interface via PCF8574
To minimize GPIO usage:
- The LCD is controlled through a **PCF8574 I/O expander**
- LCD commands and data are transmitted over I2C
- The design supports future UI expansion without redesigning the PCB

---

### 4. Timing and Determinism
- Software delays are handled through a dedicated timer module
- Ensures protocol timing compliance
- Improves signal reliability across different clock frequencies

---

## System Workflow
1. Initialize GPIO and software I2C layer  
2. Configure RTC and LCD peripherals  
3. Periodically read time from DS1307  
4. Format and display time on LCD  
5. Repeat in a deterministic loop  

---

## Applications
- Embedded firmware development and learning  
- RTC-based hardware products  
- Custom communication protocol research  
- Interview and internship portfolio projects  

---

## Learning Outcomes
- Low-level protocol design and implementation  
- Embedded C modular architecture  
- Hardware abstraction and driver development  
- Timing-sensitive firmware engineering  
- System-level debugging and validation  

---

## Future Enhancements
- Alarm and interrupt support  
- Date and day-of-week display  
- Migration to STM32 / ESP32 platforms  
- Low-power optimization strategies  
- Unit testing for driver modules  

---

## Author
**RAGHAV KANVA**  
Embedded Systems | Arduino | Embedded C  
LinkedIn: https://www.linkedin.com/in/raghavkanva/

---

## License
This project is open for educational and evaluation purposes.

