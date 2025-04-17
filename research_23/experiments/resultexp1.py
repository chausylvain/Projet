import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("resultats1.csv")

# Courbe des victoires
victoires_par_n = df.groupby("n_tours")["victoires"].mean()
plt.plot(victoires_par_n.index, victoires_par_n.values, marker='o')
plt.title("Taux de victoire selon le nombre de tours")
plt.xlabel("Nombre de tours")
plt.ylabel("Taux de victoire (équipe avec la méthode probabiliste)")
plt.grid(True)
plt.show()

# Courbe du temps de calcul
temps_par_n = df.groupby("n_tours")["temps_ms"].mean()
plt.plot(temps_par_n.index, temps_par_n.values, color='orange', marker='s')
plt.title("Temps moyen de calcul (méthode D.1)")
plt.xlabel("Nombre de tours")
plt.ylabel("Temps (ms)")
plt.grid(True)
plt.show()

