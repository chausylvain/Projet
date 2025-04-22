import pandas as pd
import matplotlib.pyplot as plt

# Lecture du fichier CSV
df1 = pd.read_csv('P_approx_1.csv') 

# Création d'un premier diagramme en barre
plt.bar(df1['C¹_1'],df1['P_approx_1(n)'], color='green', label='Loi empirique')

# Ajout de titres
plt.title('Diagramme en barre P_approx_1(n)')
plt.xlabel('C¹_1, C¹_2')
plt.ylabel('Loi empirique')

# Lecture du fichier CSV
df2 = pd.read_csv('loi_theorique.csv')

# Création d'un deuxieme diagramme en barre
plt.bar(df2['C¹_1'], df2['P(C¹_1,C¹_2)'], color='orange', alpha=0.5, label='Loi théorique')

plt.legend()
plt.show()
