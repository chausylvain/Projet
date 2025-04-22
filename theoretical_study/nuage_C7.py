import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

#lecture du fichier
df3 = pd.read_csv("data3.csv")

#creation du nuage de points
plt.scatter(df3['n'], df3['proba'], color='green', label='nuage de points (n, P_approx(2,3,1,2,n)')


#lecture du fichier
df4 = pd.read_csv("data4.csv")
#creation de la doite
plt.plot(df4['N'], df4['y'], color='red', label=f'y = P( (C^2_1,C^2_2) = (2,3) | (C^1_1,C^1_2)=(1,2) ))')

#ajout des titres
plt.xlabel("N")
plt.ylabel("P_approx(2,3,1,2,N)")
plt.title ("Nuage de points")
plt.show()
