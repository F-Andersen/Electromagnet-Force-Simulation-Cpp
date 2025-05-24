
# Electromagnet Force Simulation

This project simulates the traction force of a DC electromagnet with a periodically changing air gap using C++.  
It calculates force values for three different electromagnet configurations based on user-provided parameters and outputs results to a `.csv` file for analysis and visualization.

## Features

- Calculates traction force over time using configurable parameters
- Processes three electromagnet setups simultaneously
- Outputs data to a clean `output.csv` format
- Includes a Python script to visualize the results (`plot.py`)
- Easy input modification through `input.txt`

## Files

- `main.cpp` — core logic for simulation and data output
- `input.txt` — editable input parameters: time, step, and electromagnet data
- `output.csv` — generated result table (time vs. force values)
- `plot.py` — optional script to plot the output data using `matplotlib`

## How to Run

1. Compile the program:
   ```bash
   g++ main.cpp -o electromagnet

=== Інструкція ===

1. Скомпілюйте програму:
   g++ main.cpp -o electromagnet

2. Запустіть програму:
   ./electromagnet

3. Перевірте файл output.csv (там будуть результати обчислень)

4. Побудуйте графік за допомогою Python:
   python plot.py
1