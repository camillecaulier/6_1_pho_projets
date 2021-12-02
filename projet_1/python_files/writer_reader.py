import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

#Writer and reader with parameters
writer_reader_data= pd.read_csv("../data_complete/writer_reader.CSV")
mean = writer_reader_data.groupby(["n_thread"]).mean()["time"]
var = writer_reader_data.groupby(["n_thread"]).std()["time"]
n_thread =writer_reader_data["n_thread"].unique()

writer_reader_data= pd.read_csv("../data_complete/writer_reader_mod.CSV")
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
plt.title("Execution time according to the number of threads")
plt.grid(True)
plt.savefig("../plot/writer_reader.PNG")


plt.close()

#Testing with different values for one parameter
#UNCOMMENT TO SEE

writer_reader_data= pd.read_csv("../data_complete/writer_reader_2.CSV")
mean = writer_reader_data.groupby(["n_thread"]).mean()["time"]
var = writer_reader_data.groupby(["n_thread"]).std()["time"]


writer_reader_data= pd.read_csv("../data_complete/writer_reader_mod_2.CSV")
mean_mod = writer_reader_data.groupby(["n_thread"]).mean()["time"]
var_mod = writer_reader_data.groupby(["n_thread"]).std()["time"]


fig2= plt.figure()
plt.legend(["","","native semaphore/mutex", "active semaphore/mutex"])
plt.plot(n_thread, mean, linewidth=1.2)
plt.plot(n_thread, mean_mod, linewidth=1.2)
plt.errorbar(n_thread, mean,color='blue', yerr=var, fmt='-o')
plt.errorbar(n_thread, mean_mod,color='orange', yerr=var_mod, fmt='-o')
plt.legend(["native semaphore/mutex", "active semaphore/mutex"])

plt.ylim(0)
plt.xlabel("Number of Threads for readers")
plt.ylabel("Execution time[s]")
plt.title("Execution time according to the number of threads\n with 4 constant writers")
plt.grid(True)
plt.savefig("../plot/writer_reader_2.PNG")
plt.close()

writer_reader_data= pd.read_csv("../data_complete/writer_reader_3.CSV")
mean = writer_reader_data.groupby(["n_thread"]).mean()["time"]
var = writer_reader_data.groupby(["n_thread"]).std()["time"]

writer_reader_data= pd.read_csv("../data_complete/writer_reader_mod_3.CSV")
mean_mod = writer_reader_data.groupby(["n_thread"]).mean()["time"]
var_mod = writer_reader_data.groupby(["n_thread"]).std()["time"]


plt.figure()
plt.legend(["","","native semaphore/mutex", "active semaphore/mutex"])
plt.plot(n_thread, mean, linewidth=1.2)
plt.plot(n_thread, mean_mod, linewidth=1.2)
plt.errorbar(n_thread, mean,color='blue', yerr=var, fmt='-o')
plt.errorbar(n_thread, mean_mod,color='orange', yerr=var_mod, fmt='-o')
plt.legend(["native semaphore/mutex", "active semaphore/mutex"])

plt.ylim(0)
plt.xlabel("Number of Threads for readers")
plt.ylabel("Execution time[s]")
plt.title("Execution time according to the number of threads\n with 12 constant writers")
plt.grid(True)
plt.savefig("../plot/writer_reader_3.PNG")
plt.close()

writer_reader_data= pd.read_csv("../data_complete/writer_reader_4.CSV")
mean = writer_reader_data.groupby(["n_thread"]).mean()["time"]
var = writer_reader_data.groupby(["n_thread"]).std()["time"]

writer_reader_data= pd.read_csv("../data_complete/writer_reader_mod_4.CSV")
mean_mod = writer_reader_data.groupby(["n_thread"]).mean()["time"]
var_mod = writer_reader_data.groupby(["n_thread"]).std()["time"]


plt.figure()
plt.legend(["","","native semaphore/mutex", "active semaphore/mutex"])
plt.plot(n_thread, mean, linewidth=1.2)
plt.plot(n_thread, mean_mod, linewidth=1.2)
plt.errorbar(n_thread, mean,color='blue', yerr=var, fmt='-o')
plt.errorbar(n_thread, mean_mod,color='orange', yerr=var_mod, fmt='-o')
plt.legend(["native semaphore/mutex", "active semaphore/mutex"])

plt.ylim(0)
plt.xlabel("Number of Threads for writers")
plt.ylabel("Execution time[s]")
plt.title("Execution time according to the number of threads\n with 4 constant readers")
plt.grid(True)
plt.savefig("../plot/writer_reader_4.PNG")
plt.close()

writer_reader_data= pd.read_csv("../data_complete/writer_reader_5.CSV")
mean = writer_reader_data.groupby(["n_thread"]).mean()["time"]
var = writer_reader_data.groupby(["n_thread"]).std()["time"]

writer_reader_data= pd.read_csv("../data_complete/writer_reader_mod_5.CSV")
mean_mod = writer_reader_data.groupby(["n_thread"]).mean()["time"]
var_mod = writer_reader_data.groupby(["n_thread"]).std()["time"]


plt.figure()
plt.legend(["","","native semaphore/mutex", "active semaphore/mutex"])
plt.plot(n_thread, mean, linewidth=1.2)
plt.plot(n_thread, mean_mod, linewidth=1.2)
plt.errorbar(n_thread, mean,color='blue', yerr=var, fmt='-o')
plt.errorbar(n_thread, mean_mod,color='orange', yerr=var_mod, fmt='-o')
plt.legend(["native semaphore/mutex", "active semaphore/mutex"])

#plt.ylim(0)
plt.xlabel("Number of Threads for writers")
plt.ylabel("Execution time[s]")
plt.title("Execution time according to the number of threads\n with 12 constant readers")
plt.grid(True)
plt.savefig("../plot/writer_reader_5.PNG")
plt.close()