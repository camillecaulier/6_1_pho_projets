import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

ph_pb_data = pd.read_csv("philosopher_problem.CSV")


plt.xlabel("Number of Threads")
plt.ylabel("Execution time")
plt.title("Execution time according to the number of threads")