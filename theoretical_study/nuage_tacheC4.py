import pandas as pd
import matplotlib.pyplot as plt

# Lecture du fichier CSV
df = pd.read_csv('nuage_C4.csv') 

# Création du nuage de points
plt.scatter(df['n'], df['P_approx_1(i,j,n)'], color='blue', label='Points')

#lecture fichier de la droite
dfd = pd.read_csv('droite_C4.csv')

#tracé droite
plt.plot(df['n'],df['y'],color='red', label=f'Droite y=P( (C^1_1,C^1_2)=(1,2))')


# Ajouter des titres et labels
plt.title('Nuage de points')
plt.xlabel('n')
plt.ylabel('P_approx1(1,2,n)')

# Ajouter une légende
plt.legend()

# Afficher le graphique
plt.show()
