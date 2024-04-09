# Smart Load Management in a Grid using Battery Integration

***

This project showcases smart load management within a grid incorporating a battery system and three loads of varying criticality levels.

## Introduction:-

The integration of smart grid technologies is revolutionizing the way electricity is generated, distributed, and consumed, particularly in grid environments. This mini project focuses on the implementation of smart load management within a grid, aiming to enhance energy efficiency, reliability, and resilience. The grid includes a battery system connected to three loads with varying levels of criticality: most critical, less critical, and least critical. By employing a bidirectional DC-DC converter capable of operating in buck and boost modes, the project aims to optimize power flow within the grid. It involves prioritized load shedding as the battery's State of Charge (SOC) diminishes, ensuring the continuous supply of essential services. Furthermore, grid integration is utilized to recharge the battery when its SOC reaches a specified threshold, while also supplying power to the loads. This project showcases automatic load switching and smart power management techniques, with potential applications for integrating renewable energy sources such as solar photovoltaic (PV) and fuel cells (FC) into the grid infrastructure. Through this endeavor, the project seeks to contribute to the advancement of sustainable and resilient energy systems in the context of modern grid environments.

## Schematic Diagram:-

<img src="https://github.com/TabithaSneha/smart_grid_project/assets/87858655/86036172-d5ff-457f-a781-e7e2eb9f355b" height="250" width="800" >

A 9V Battery is connected to the Load, consisting of 3 LEDs- the Red LED indicates ‘Most Critical Load’, the Yellow LED indicates ‘Less Critical Load’ and the White LED indicates ‘Least Critical Load’, through a Boost Converter. On the Grid side, single-phase AC supply of 230V is taken and a 230/15V transformer steps down the voltage to 15V. The input AC voltage is passed through an AC-DC rectifier to get a DC output voltage. This is passed through a Buck Converter which is in turn connected to the Load.

## Methodology:-

### Components Used:

* Arduino Uno
* Arduino Nano
* XL6009 DC-DC Step-Up Power Converter Boost Module
* LM2596 DC-DC Buck Converter Module
* Hi-Watt 6F22M Battery (9V, 750 mAh)
* LCD 16×2 Blue/Green Display 1602
* MOSFET IRF540 N Channel
* 230 V/15V Step-down Transformer
* LED 5mm - Red, Yellow, White
* Resistors, Capacitors and Diodes

### Working of the Model:

#### Load Switching Using Battery SoC Measurement:-

* First, in the Discharge Cycle, switch S1 is closed and switches S2 and S3 are open. The battery discharges to the Load through the boost converter that steps up the battery voltage from 9V to 15V. 
* The battery is able to supply power to all 3 LEDs from 80% SoC to 25% SoC. 
* As soon as the SoC reaches 30%, the least critical load (White LED) turns off and when the SoC reaches 25%, the less critical load (Yellow LED) turns off.
* When the SoC reaches 25%, the Charge Cycle comes into action where switch S1 is open and switches S2 and S3 are closed. The grid (or the AC supply) supplies power to the Load and charges the Battery via a buck converter. The boost converter is bypassed in this cycle.
* A transformer steps down 230V to 15V AC supply. The 1-ph rectifier bridge converts 15V AC supply to 15 V DC supply.
* This voltage gets stepped down to 9V in order to charge the battery till it reaches 80% SoC and supply power to the 3 LEDs once again.
* Once the battery reaches 80% SoC, the Discharge Cycle comes back into action and the process repeats again.

#### Battery SoC Measurement:-

* Since the battery output voltage is 9V, a voltage divider circuit is used to obtain 4.5V from the battery side inorder to pass it as an input for Arduino Nano (which is within the measurable limits of the Arduino (The analog pin of the Arduino can read values between 0V - 5V)).
* This voltage is read from an analogue pin of Arduino Nano and for every 1 microsecond, the mAh is calculated by dividing it with the value of resistance used.
* The mA (milli Amphere) is averaged over a duration of 1 second. This gives us the mAh (milli Amphere hour) for the 1 second duration.
* As Battery SoC is directly proportional to the supplied Ah, we find the ratio of the measured mAh with the rated mAh of the battery, which in this case is 750 mAh. This gives us the SoC%.
* This value is then printed on the LCD display screen.

## Results:-

### Hardware Setup:

<img src="https://github.com/TabithaSneha/smart_grid_project/assets/87858655/c3dbe5be-9199-4ac9-a06d-887d40250ce7" height="450" width="600" >

### Link to View the Project:

Click [here](https://drive.google.com/file/d/1gxaMYeyEGTx3sYeRl6C_URGgqKKzR_hH/view?usp=drive_link) to view the demonstration of Smart Load Management in a Grid using Battery Integration.

## Future Scope:-

In conclusion, the implementation of smart load management in a grid represents a pivotal step towards enhancing grid efficiency and reliability. We have demonstrated how load can be efficiently managed in a grid using the SoC values measured from the battery and the bi-directional flow of power in the circuit using a buck and boost converter to and from the battery and grid side.

Some possible corrections and additions that can be done to this project as a future scope are:
* To incorporate the circuit of a Bi-directional DC-DC converter or module and perform load management.
* To include a charging circuitry to enable battery charging from the grid.
* To perform real-time load shedding by using the measured SoC values from the battery.
* To incorporate renewable energy sources like solar PV and extend this project to a Microgrid.
