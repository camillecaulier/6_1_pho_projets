import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

#Writer and reader with parameters
writer_reader_data= pd.read_csv("data/writer_reader.CSV")
mean= writer_reader_data.groupby(["n_thread"]).mean()["time"]
std_dev= writer_reader_data.groupby(["n_thread"]).std()["time"]
n_threads=writer_reader_data(["n_thread"]).unique()

fig1= plt.figure()
plt.plot(n_threads, mean, linewidth=1.2)
plt.xlim(0, 20)
plt.ylim(0,3)
plt.xlabel("Number of Threads")
plt.ylabel("Execution time")
plt.title("Execution time according to the number of threads")
plt.grid(True)
plt.savefig("plot/writer_reader.PNG")

plt.show()
plt.close()

#Testing with different values for one parameter

#Test with writ_read_2
writer_reader_2_data= pd.read_csv("data/writer_reader_2.CSV")
mean2= writer_reader_2_data.groupby(["n_thread"]).mean()["time"]
std_dev2= writer_reader_2_data.groupby(["n_thread"]).std()["time"]
n_threads2=writer_reader_2_data(["n_thread"]).unique()

fig2= plt.figure()
plt.plot(n_threads2, mean, linewidth=1.2)
plt.xlim(0, 20)
plt.ylim(0,3)
plt.xlabel("Number of Threads")
plt.ylabel("Execution time")
plt.title("Execution time according to the number of threads")
plt.grid(True)
plt.savefig("plot/writer_reader_2.PNG")

plt.show()
plt.close()
#Test with writ_read_3
writer_reader_3_data= pd.read_csv("data/writer_reader_3.CSV")
mean3= writer_reader_3_data.groupby(["n_thread"]).mean()["time"]
std_dev3= writer_reader_3_data.groupby(["n_thread"]).std()["time"]
n_threads3=writer_reader_3_data(["n_thread"]).unique()

fig3= plt.figure()
plt.plot(n_threads3, mean, linewidth=1.2)
plt.xlim(0, 20)
plt.ylim(0,3)
plt.xlabel("Number of Threads")
plt.ylabel("Execution time")
plt.title("Execution time according to the number of threads")
plt.grid(True)
plt.savefig("plot/writer_reader_3.PNG")

plt.show()
plt.close()
#Test with writ_read_4
writer_reader_4_data= pd.read_csv("data/writer_reader_4.CSV")
mean4= writer_reader_4_data.groupby(["n_thread"]).mean()["time"]
std_dev4= writer_reader_4_data.groupby(["n_thread"]).std()["time"]
n_threads4=writer_reader_4_data(["n_thread"]).unique()

fig4= plt.figure()
plt.plot(n_threads4, mean, linewidth=1.2)
plt.xlim(0, 20)
plt.ylim(0,3)
plt.xlabel("Number of Threads")
plt.ylabel("Execution time")
plt.title("Execution time according to the number of threads")
plt.grid(True)
plt.savefig("plot/writer_reader_4.PNG")

plt.show()
plt.close()
#Test with writ_read_5
writer_reader_5_data= pd.read_csv("data/writer_reader_5.CSV")
mean5= writer_reader_5_data.groupby(["n_thread"]).mean()["time"]
std_dev5= writer_reader_5_data.groupby(["n_thread"]).std()["time"]
n_threads5=writer_reader_5_data(["n_thread"]).unique()

fig5= plt.figure()
plt.plot(n_threads5, mean, linewidth=1.2)
plt.xlim(0, 20)
plt.ylim(0,3)
plt.xlabel("Number of Threads")
plt.ylabel("Execution time")
plt.title("Execution time according to the number of threads")
plt.grid(True)
plt.savefig("plot/writer_reader_5.PNG")

plt.show()
plt.close()