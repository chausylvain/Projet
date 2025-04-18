import pandas as pd
import matplotlib.pyplot as plt

# Load data
df = pd.read_csv("resultats1.csv")

# Compute means
victoires_par_n = df.groupby("n_tours")["victoires"].mean()
temps_par_n = df.groupby("n_tours")["temps_ms"].mean()

# Setup figure
plt.figure(figsize=(10, 8))

# --- Subplot 1: Taux de victoire ---
plt.subplot(2, 1, 1)
plt.plot(victoires_par_n.index, victoires_par_n.values, marker='o', color='royalblue', label="Taux de victoire")
plt.axhline(y=0.5, color='red', linestyle='--', linewidth=1.5, label="Seuil 0.5")
plt.title("Taux de victoire selon le nombre de tours (0 : agressive, 1 : probabiliste)", fontsize=12)
plt.xlabel("Nombre de tours")
plt.ylabel("Taux de victoire")
plt.ylim(0, 1)
plt.grid(True, linestyle=':', alpha=0.7)
plt.legend()
plt.text(victoires_par_n.index[-1] + 0.2, 0.51, "0.5", color='red', fontsize=10)

# --- Subplot 2: Temps de calcul ---
plt.subplot(2, 1, 2)
plt.plot(temps_par_n.index, temps_par_n.values, color='darkorange', marker='s', label="Temps moyen")
plt.title("Temps moyen de calcul (méthode D.1)", fontsize=12)
plt.xlabel("Nombre de tours")
plt.ylabel("Temps (ms)")
plt.grid(True, linestyle=':', alpha=0.7)
plt.legend()

# Tight layout for spacing
plt.tight_layout()
plt.show()
