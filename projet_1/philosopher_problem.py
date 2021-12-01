import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

ph_pb_data = pd.read_csv("philosopher_problem.CSV")

#Mean and standard deviation of the measures

mean = ph_pb_data.groupby(["n_threads"]).mean()["time"]
std = ph_pb_data.groupby(["n_threads"]).std()["time"]

n_threads = ph_pb_data["n_threads"]

#Labels and Title
plt.xlabel("Number of Threads")
plt.ylabel("Execution time")
plt.title("Execution time according to the number of threads")

fig = plt.figure()

plt.plot()