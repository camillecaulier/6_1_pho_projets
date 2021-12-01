import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

ph_pb_data = pd.read_csv("data/philosopher_problem.CSV")
#Mean and standard deviation of the measures

mean = ph_pb_data.groupby(["n_thread"]).mean()["time"]
std_dev = ph_pb_data.groupby(["n_thread"]).std()["time"]

n_threads = ph_pb_data["n_thread"].unique()


#Creating the figure
fig = plt.figure()
plt.plot(n_threads, mean, linewidth=1.2)
plt.xlim(0, 20)
plt.ylim(0,3)

#Labels and Title
plt.xlabel("Number of Threads")
plt.ylabel("Execution time")
plt.title("Execution time according to the number of threads")
plt.grid(True)
plt.savefig("plot/philosopher_problem.PNG")

plt.show()
plt.close()
