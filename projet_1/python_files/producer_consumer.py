import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

#Producer and consumer with parameters
prod_cons_data = pd.read_csv("data/producer_consumer.CSV")
mean= prod_cons_data.groupby(["n_thread"]).mean()["time"]
std_dev= prod_cons_data.groupby(["n_thread"]).std()["time"]
n_threads=prod_cons_data(["n_thread"]).unique()

fig1= plt.figure()
plt.plot(n_threads, mean, linewidth=1.2)
plt.xlim(0, 20)
plt.ylim(0,3)
plt.xlabel("Number of Threads")
plt.ylabel("Execution time")
plt.title("Execution time according to the number of threads")
plt.grid(True)
plt.savefig("plot/producer_consumer.PNG")

plt.show()
plt.close()
#Testing producer and consumer with different constant values for one parameter

#Test with prod_cons_2
prod_cons_2_data= pd.read_csv("data/producer_consumer_2.CSV")
mean2= prod_cons_2_data.groupby(["n_thread"]).mean()["time"]
std_dev2= prod_cons_2_data.groupby(["n_thread"]).std()["time"]
n_threads2=prod_cons_2_data(["n_thread"]).unique()

fig2= plt.figure()
plt.plot(n_threads2, mean, linewidth=1.2)
plt.xlim(0, 20)
plt.ylim(0,3)
plt.xlabel("Number of Threads")
plt.ylabel("Execution time")
plt.title("Execution time according to the number of threads")
plt.grid(True)
plt.savefig("plot/producer_consumer_2.PNG")

plt.show()
plt.close()
#Test with prod_cons_3
prod_cons_3_data= pd.read_csv("data/producer_consumer_3.CSV")
mean3= prod_cons_3_data.groupby(["n_thread"]).mean()["time"]
std_dev3= prod_cons_3_data.groupby(["n_thread"]).std()["time"]
n_threads3=prod_cons_3_data(["n_thread"]).unique()

fig3= plt.figure()
plt.plot(n_threads3, mean, linewidth=1.2)
plt.xlim(0, 20)
plt.ylim(0,3)
plt.xlabel("Number of Threads")
plt.ylabel("Execution time")
plt.title("Execution time according to the number of threads")
plt.grid(True)
plt.savefig("plot/producer_consumer_3.PNG")

plt.show()
plt.close()
#Test with prod_cons_4
prod_cons_4_data=pd.read_csv("data/producer_consumer_4.CSV")
mean4= prod_cons_4_data.groupby(["n_thread"]).mean()["time"]
std_dev4= prod_cons_4_data.groupby(["n_thread"]).std()["time"]
n_threads4=prod_cons_4_data(["n_thread"]).unique()

fig4= plt.figure()
plt.plot(n_threads4, mean, linewidth=1.2)
plt.xlim(0, 20)
plt.ylim(0,3)
plt.xlabel("Number of Threads")
plt.ylabel("Execution time")
plt.title("Execution time according to the number of threads")
plt.grid(True)
plt.savefig("plot/producer_consumer_4.PNG")

plt.show()
plt.close()
#Test with prod_cons_5
prod_cons_5_data=pd.read_csv("data/producer_consumer_5.CSV")
mean5= prod_cons_5_data.groupby(["n_thread"]).mean()["time"]
std_dev5= prod_cons_5_data.groupby(["n_thread"]).std()["time"]
n_threads5=prod_cons_5_data(["n_thread"]).unique()

fig5= plt.figure()
plt.plot(n_threads5, mean, linewidth=1.2)
plt.xlim(0, 20)
plt.ylim(0,3)
plt.xlabel("Number of Threads")
plt.ylabel("Execution time")
plt.title("Execution time according to the number of threads")
plt.grid(True)
plt.savefig("plot/producer_consumer_5.PNG")

plt.show()
plt.close()