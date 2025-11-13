# Rain Prediction Classification Model
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import confusion_matrix, roc_curve, auc, precision_recall_curve
import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np

# Load data
df = pd.read_csv("weather_aus.csv")

# Clean and encode
df = df[['MinTemp', 'MaxTemp', 'Humidity3pm', 'Pressure3pm', 'RainTomorrow']].dropna()
df['RainTomorrow'] = df['RainTomorrow'].map({'Yes': 1, 'No': 0})

X = df[['MinTemp', 'MaxTemp', 'Humidity3pm', 'Pressure3pm']]
y = df['RainTomorrow']

# Train/test split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Model
model = RandomForestClassifier(random_state=42)
model.fit(X_train, y_train)
y_pred_proba = model.predict_proba(X_test)[:,1]
y_pred = (y_pred_proba > 0.5).astype(int)

# ✅ Confusion Matrix
cm = confusion_matrix(y_test, y_pred)
sns.heatmap(cm, annot=True, fmt='d', cmap='Blues')
plt.title('Confusion Matrix')
plt.show()

# ✅ ROC Curve
fpr, tpr, thresholds = roc_curve(y_test, y_pred_proba)
roc_auc = auc(fpr, tpr)
plt.plot(fpr, tpr, label=f'AUC = {roc_auc:.2f}')
plt.plot([0,1],[0,1],'--')
plt.title('ROC Curve')
plt.xlabel('False Positive Rate')
plt.ylabel('True Positive Rate')
plt.legend()
plt.show()

# ✅ Precision-Recall Curve
prec, rec, thresholds_pr = precision_recall_curve(y_test, y_pred_proba)
plt.plot(rec, prec)
plt.title('Precision-Recall Curve')
plt.xlabel('Recall')
plt.ylabel('Precision')
plt.show()

# ✅ Find best threshold
best_idx = np.argmax(prec - rec)
best_threshold = thresholds_pr[best_idx]
print("Best Probability Threshold:", best_threshold)
