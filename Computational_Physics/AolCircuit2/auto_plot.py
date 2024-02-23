import numpy as np
import matplotlib
import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv("ckt_output.dat", delim_whitespace=True)
df.columns = list(range(len(df.columns)))

font = {"family" : "normal",
"weight" : "normal",
"size"   : 12}
matplotlib.rc("font", **font)

plt.figure()
plt.title("Voltage")
plt.xlabel("Time")
plt.plot(np.array(df[0])[:, None], np.array(df[4])[:, None], label = "vLED")
plt.legend()
plt.savefig("fig1.eps", format="eps")

plt.figure()
plt.title("allofem")
plt.xlabel("Time")
plt.plot(np.array(df[0])[:, None], np.array(df[1])[:, None], label = "iSource")
plt.plot(np.array(df[0])[:, None], np.array(df[3])[:, None], label = "vSource")
plt.plot(np.array(df[0])[:, None], np.array(df[2])[:, None], label = "iLED")
plt.plot(np.array(df[0])[:, None], np.array(df[4])[:, None], label = "vLED")
plt.legend()
plt.savefig("fig2.eps", format="eps")

plt.figure()
plt.title("Current")
plt.xlabel("Time")
plt.plot(np.array(df[0])[:, None], np.array(df[2])[:, None], label = "iLED")
plt.legend()
plt.savefig("fig3.eps", format="eps")

plt.show()
