import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

#lecture du fichier
df1 = pd.read_csv("data1.csv")
#creation de l'histogramme
plt.hist=(df1['(i,j)'], df1['freq'], color='red', label='Histogramme de la loi empirique de (C^2_1,C^2_2)') 
#ajout des titres
plt.xlabel("Mains (C^2_1, C^2_2)")
plt.ylabel("Proportions")
plt.title("Histogramme de la loi empirique de (C^2_1,C^2_2) conditionnellement à (C^1_1, C^1_2)=(1,2)")
#lecture du fichier
df2 = pd.read_csv("data2.csv")
plt.hist=(df2['(i,j)'], df2['resultat'], color='blue', label = 'Histogramme de la loi théorique de (C^2_1,C^2_2)')
plt.title("Histogramme de la loi théorique de (C^2_1,C^2_2) conditionnellement à (C^1_1, C^1_2)=(1,2)")
plt.show()