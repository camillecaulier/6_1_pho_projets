import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

#Writer and reader with parameters
writer_reader_data= pd.read_csv("../data_complete/philosopher_problem.CSV")
mean = writer_reader_data.groupby(["n_thread"]).mean()["time"]
var = writer_reader_data.groupby(["n_thread"]).std()["time"]
n_thread =writer_reader_data["n_thread"].unique()

writer_reader_data= pd.read_csv("../data_complete/philosopher_problem_mod.CSV")
mean_mod = writer_reader_data.groupby(["n_thread"]).mean()["time"]
var_mod = writer_reader_data.groupby(["n_thread"]).std()["time"]


fig1= plt.figure()
plt.legend(["","","native semaphore/mutex", "active semaphore/mutex"])
plt.plot(n_thread, mean, linewidth=1.2)
plt.plot(n_thread, mean_mod, linewidth=1.2)
plt.errorbar(n_thread, mean,color='blue', yerr=var, fmt='-o')
plt.errorbar(n_thread, mean_mod,color='orange', yerr=var_mod, fmt='-o')
plt.legend(["native semaphore/mutex", "active semaphore/mutex"])

plt.ylim(0)
plt.xlabel("Number of Threads")
plt.ylabel("Execution time[s]")
plt.title("Execution time according to the number of threads\n philosopher")
plt.grid(True)
plt.savefig("../plot/philosopher.PNG")


plt.close()