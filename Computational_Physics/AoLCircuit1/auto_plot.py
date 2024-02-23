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
plt.title("Currents")
plt.xlabel("Time")
plt.plot(np.array(df[0])[:, None], np.array(df[5])[:, None], label = "Ieq")
plt.plot(np.array(df[0])[:, None], np.array(df[4])[:, None], label = "I2")
plt.plot(np.array(df[0])[:, None], np.array(df[4])[:, None], label = "I3")
plt.legend()
plt.savefig("fig1.eps", format="eps")

plt.figure()
plt.title("Potential Differences")
plt.xlabel("Time")
plt.plot(np.array(df[0])[:, None], np.array(df[2])[:, None], label = "V1")
plt.plot(np.array(df[0])[:, None], np.array(df[1])[:, None], label = "V2")
plt.plot(np.array(df[0])[:, None], np.array(df[3])[:, None], label = "V3")
plt.legend()
plt.savefig("fig2.eps", format="eps")

plt.show()
