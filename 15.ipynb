# Regression Model for NBA Player Points
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_absolute_error, mean_squared_error, r2_score
import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns

# Load data
df = pd.read_csv("nba_player_stats.csv")

# ✅ Features and target
X = df[['FGA', '3PA', 'FT', 'AST', 'TRB', 'TOV', 'USG%', 'Age']]
y = df['PTS']

# Split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Model
model = LinearRegression()
model.fit(X_train, y_train)
y_pred = model.predict(X_test)

# ✅ Evaluation
rmse = np.sqrt(mean_squared_error(y_test, y_pred))
mae = mean_absolute_error(y_test, y_pred)
r2 = r2_score(y_test, y_pred)

print(f"RMSE: {rmse:.2f}")
print(f"MAE: {mae:.2f}")
print(f"R²: {r2:.2f}")

# ✅ Plots
plt.figure(figsize=(6,4))
sns.residplot(x=y_pred, y=y_test - y_pred, lowess=True, color='blue')
plt.title('Residual Plot')
plt.xlabel('Predicted Points')
plt.ylabel('Residuals')
plt.show()

plt.figure(figsize=(6,4))
plt.scatter(y_test, y_pred)
plt.title('Predicted vs Actual Points')
plt.xlabel('Actual Points')
plt.ylabel('Predicted Points')
plt.show()
