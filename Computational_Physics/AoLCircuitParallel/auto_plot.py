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
plt.plot(np.array(df[0])[:, None], np.array(df[6])[:, None], label = "VR1")
plt.plot(np.array(df[0])[:, None], np.array(df[7])[:, None], label = "VR2")
plt.plot(np.array(df[0])[:, None], np.array(df[8])[:, None], label = "VR3")
plt.legend()
plt.savefig("fig1.eps", format="eps")

plt.figure()
plt.title("Current")
plt.xlabel("Time")
plt.plot(np.array(df[0])[:, None], np.array(df[2])[:, None], label = "IR1")
plt.plot(np.array(df[0])[:, None], np.array(df[3])[:, None], label = "IR2")
plt.plot(np.array(df[0])[:, None], np.array(df[2])[:, None], label = "IR3")
plt.legend()
plt.savefig("fig2.eps", format="eps")

plt.figure()
plt.title("i1")
plt.xlabel("Time")
plt.plot(np.array(df[0])[:, None], np.array(df[2])[:, None], label = "i1")
plt.legend()
plt.savefig("fig3.eps", format="eps")

plt.figure()
plt.title("i2")
plt.xlabel("Time")
