# Recipe Data Feature Study
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

df = pd.read_csv("recipe_data.csv")

# ✅ Summary statistics
print(df[['ABV', 'IBU', 'Color']].describe())

# ✅ Pairplot between ABV, IBU, and Color
sns.pairplot(df[['ABV', 'IBU', 'Color']])
plt.suptitle("Feature Pairplot", y=1.02)
plt.show()

# ✅ Correlation heatmap
corr = df[['ABV', 'IBU', 'Color']].corr()
sns.heatmap(corr, annot=True, cmap='coolwarm')
plt.title("Correlation Heatmap")
plt.show()

# ✅ Identify redundant features (high correlation > 0.9)
redundant = corr[(corr > 0.9) & (corr < 1.0)]
print("Highly correlated (redundant) features:\n", redundant)

# ✅ Keep only useful (non-redundant) ones
useful_features = ['ABV', 'IBU', 'Color']  # adjust manually after viewing correlation
print("Useful features:", useful_features)
