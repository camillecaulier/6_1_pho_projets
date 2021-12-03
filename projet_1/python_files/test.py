import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

#Writer and reader with parameters
writer_reader_data= pd.read_csv("../data/test_set.CSV")
mean = writer_reader_data.groupby(["n_thread"]).mean()["time"]
var = writer_reader_data.groupby(["n_thread"]).std()["time"]
n_thread =writer_reader_data["n_thread"].unique()

writer_reader_data= pd.read_csv("../data/test_test_set.CSV")
mean_mod = writer_reader_data.groupby(["n_thread"]).mean()["time"]
var_mod = writer_reader_data.groupby(["n_thread"]).std()["time"]

writer_reader_data= pd.read_csv("../data/posix.CSV")
mean_posix = writer_reader_data.groupby(["n_thread"]).mean()["time"]
var_posix = writer_reader_data.groupby(["n_thread"]).std()["time"]

fig1= plt.figure()
plt.legend(["","","test set", "test test set","native"])
plt.plot(n_thread, mean, linewidth=1.2)
plt.plot(n_thread, mean_mod, linewidth=1.2)
plt.plot(n_thread, mean_posix, linewidth=1.2)
plt.errorbar(n_thread, mean,color='blue', yerr=var, fmt='-o')
plt.errorbar(n_thread, mean_mod,color='orange', yerr=var_mod, fmt='-o')
plt.errorbar(n_thread, mean_posix,color='green', yerr=var_posix, fmt='-o')
plt.legend(["test set", "test test set","posix"])

plt.ylim(0)
plt.xlabel("Number of Threads")
plt.ylabel("Execution time[s]")
plt.title("Execution time according to the number of threads\n comparaison between test set , test test set and posix")
plt.grid(True)
plt.savefig("../plot/test.PNG")


plt.close()