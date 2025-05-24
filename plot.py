
import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('output/output.csv')
plt.plot(df['Time(s)'], df['F1(N)'], label='F1')
plt.plot(df['Time(s)'], df['F2(N)'], label='F2')
plt.plot(df['Time(s)'], df['F3(N)'], label='F3')

plt.xlabel("Time (s)")
plt.ylabel("Force (N)")
plt.title("Тягове зусилля електромагніта")
plt.legend()
plt.grid(True)
plt.show()
